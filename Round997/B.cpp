#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <ios>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <span>
#include <stack>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using i64 = long long;

constexpr int MOD = 1'000'000'007;

constexpr std::array<std::array<int, 2>, 4> directions{{
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
}};

void solve() {
  // undirected graph with n vertices, labelled 1 to n.
  // Encodes a permutation p of size n.
  // - For every pair (i, j), 1 <= i < j <= n, an undirected edge is added
  // between vertices pi and pj, if pi < pj (the number in the permutation p).
  // Reconstruct permutation p given the adjacency matrix.
  // Feels like Topological Sort.
  // An edge from u to v indicate indegree[v]++
  // Or rather, count edges to nodes with lower indices.
  // 00101
  // 00101
  // 11001
  // 00001
  // 11110
  // count = {0, 0, 2, 0, 4}

  int n;
  std::cin >> n;

  std::vector<std::string> adjMat(n);
  for (int i = 0; i < n; ++i) {
    adjMat[i].reserve(n);
    std::cin >> adjMat[i];
  }

  std::vector<int> indegree(n, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i < j && adjMat[i][j] == '1') {
        ++indegree[j];
      }
    }
  }

  std::vector<int> result(n, -1);
  std::vector<bool> used(n, false);
  // Not exactly topological sort....
  for (int i = n - 1; i >= 0; --i) {
    // find pos with exactly indegree[i] unused, smaller positions before it.
    int pos = 0;
    int unusedSmaller = 0;

    while (unusedSmaller < indegree[i]) {
      if (!used[pos]) {
        ++unusedSmaller;
      }
      ++pos;
    }

    while (used[pos]) {
      ++pos;
    }

    result[pos] = i;
    used[pos] = true;
  }

  for (int x : result) {
    std::cout << x + 1 << ' ';
  }
  std::cout << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tc{1};
  std::cin >> tc;

  while (tc--) {
    solve();
  }

  return 0;
}
