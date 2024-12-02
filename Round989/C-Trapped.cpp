#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <ios>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using i64 = long long;

#include <vector>

/**
 * @brief UnionFind (Disjoint Set) data structure
 *
 * This class implements a Union-Find data structure, also known as a Disjoint
 * Set. It provides efficient operations for maintaining disjoint sets and
 * determining if two elements belong to the same set.
 *
 * Time Complexity:
 * - Construction: O(n)
 * - Find: O(α(n)) amortized
 * - Union: O(α(n)) amortized
 * - IsConnected: O(α(n)) amortized
 *
 * where α(n) is the inverse Ackermann function, which grows extremely slowly
 * and is effectively constant (≤4) for all practical values of n.
 *
 * Space Complexity: O(n)
 */
class UnionFind {
 private:
  // parent stores the parent of each element
  std::vector<int> parent;

  // rank stores the approximate depth of each tree rooted at i
  std::vector<int> rank;

 public:
  /**
   * @brief Construct a new UnionFind object
   *
   * @param size The number of elements in the UnionFind structure
   *
   * Initially, each element is in its own set (i.e., is its own parent).
   * Time Complexity: O(n)
   * Space Complexity: O(n)
   */
  UnionFind(int size) : parent(size), rank(size, 0) {
    for (int i = 0; i < size; ++i) {
      parent[i] = i;
    }
  }

  /**
   * @brief Find the representative (root) of the set containing x
   *
   * @param x The element to find the representative for
   * @return int The representative of the set containing x
   *
   * This method uses path compression: all nodes along the path to the root
   * are made to point directly to the root. This flattens the tree structure,
   * significantly improving the efficiency of future operations.
   *
   * Time Complexity: O(α(n)) amortized
   * - Worst case (rare): O(log n)
   * - Best case: O(1) if x is the root or has been previously compressed
   */
  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);  // Path compression
    }
    return parent[x];
  }

  /**
   * @brief Check if two elements are in the same set
   *
   * @param x First element
   * @param y Second element
   * @return true if x and y are in the same set, false otherwise
   *
   * Time Complexity: O(α(n)) amortized (same as find)
   */
  bool isConnected(int x, int y) { return find(x) == find(y); }

  /**
   * @brief Unite the sets containing elements x and y
   *
   * @param x Element from the first set
   * @param y Element from the second set
   *
   * This method uses union by rank: the shorter tree is always attached to the
   * root of the taller tree. This ensures that the resulting tree remains
   * balanced, keeping operations efficient.
   *
   * Time Complexity: O(α(n)) amortized
   * - The actual union is O(1), but it requires two find operations
   */
  void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
      if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
      } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
      } else {
        parent[rootY] = rootX;
        ++rank[rootX];
      }
    }
  }
};

constexpr std::array<std::array<int, 2>, 4> directions{{
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
}};

void dfs(std::vector<std::string>& maze,
         std::vector<std::vector<char>>& visited,
         UnionFind& uf,
         int i,
         int j) {
  const int n = maze.size();
  const int m = maze[0].size();
  const int ESCAPABLE = n * m;

  while (true) {
    if (visited[i][j] || maze[i][j] == '?') {
      break;
    }
    visited[i][j] = true;
    int cellId = i * m + j;  // convert to 1D for UF.

    // Check if current cell is on border and points outward (escapable)
    if ((i == 0 && maze[i][j] == 'U') || (i == n - 1 && maze[i][j] == 'D') ||
        (j == 0 && maze[i][j] == 'L') || (j == m - 1 && maze[i][j] == 'R')) {
      uf.unite(cellId, ESCAPABLE);
      break;
    }

    // need this so we can unite with the current cell.
    int nextI = i;
    int nextJ = j;
    char dir = maze[i][j];
    if (dir == 'U') {
      --nextI;
    } else if (dir == 'D') {
      ++nextI;
    } else if (dir == 'L') {
      --nextJ;
    } else if (dir == 'R') {
      ++nextJ;
    }

    // check out of bounds.
    if (nextI < 0 || nextJ < 0 || nextI >= n || nextJ >= m) {
      break;
    }

    int nextCellId = nextI * m + nextJ;
    uf.unite(cellId, nextCellId);

    i = nextI;
    j = nextJ;
  }
}

void solve() {
  // two integers n and m (1 <= n, m <= 1000), rows and columns.
  // next n lines contain string of m characters representing directions in the
  // maze.
  // Either:
  // 'U' up
  // 'D' down
  // 'L' left
  // 'R' right
  // '?' unspecified.
  // Want to assign directions to unspecified cells so that the number of
  // starting cells from which there is no path out is maximized.
  // Find maximum number of starting cells that have no path out.
  //
  // O(n^2) solution allowed based on input n * m <= 10^6.
  //
  // First notice that cells with opposite directions e.g., | -> | <- |
  // will forever have no path out, i.e., trapped.
  // If an unspecified cell is reachable from another cell, can make trap.
  //
  // Feels like UF.
  // Have a dummy Component ESCAPABLE. Border cells with directions outwards
  // are ESCAPABLE no matter what. Paths to these cells will never be trapped.
  // Another component TRAPPED. If following the path contains a '?', then
  // we can trap.
  //
  // How to count?
  // Size of the trapped Component.
  int n, m;
  std::cin >> n >> m;
  int total = n * m;
  std::vector<std::string> maze(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> maze[i];
  }

  const int ESCAPABLE = n * m;
  UnionFind uf(total + 1);
  std::vector<std::vector<char>> visited(n, std::vector<char>(m, false));
  std::vector<std::array<int, 2>> unspecifiedCells;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (maze[i][j] == '?') {
        unspecifiedCells.push_back({i, j});
        continue;
      }

      if (visited[i][j]) {
        continue;
      }
      dfs(maze, visited, uf, i, j);
    }
  }

  // check the '?' cells cardinal directions. If all are ESCAPABLE, then
  // this unspecified cannot be a trap.
  for (const auto [i, j] : unspecifiedCells) {
    bool canEscape = true;
    for (const auto [di, dj] : directions) {
      int ni = i + di;
      int nj = j + dj;

      if (ni < 0 || nj < 0 || ni >= n || nj >= m) {
        continue;
      }
      int neighbourId = ni * m + nj;

      if (!uf.isConnected(ESCAPABLE, neighbourId)) {
        canEscape = false;
        break;
      }
    }

    if (canEscape) {
      uf.unite(i * m + j, ESCAPABLE);
    }
  }

  int numEscapable = 0;
  for (int i = 0; i < n * m; ++i) {
    if (uf.isConnected(i, ESCAPABLE)) {
      ++numEscapable;
    }
  }

  std::cout << total - numEscapable << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tc;  // Number of test cases
  std::cin >> tc;

  while (tc--) {
    solve();
  }

  return 0;
}
