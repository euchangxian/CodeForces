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
#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <numeric>
#include <ostream>
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
  // n rows, m columns. color aij
  // two cells are strangers if they dont share a side.
  // A set of cells are a set of strangers if all pairs are strangers.
  // Set of sizes 1 is trivially a set of strangers.
  // Choose any set of strangers such that all cells in it have the same color,
  // paint them in some other color.
  // Minimum steps to make all same color.
  // Maximum is n * m.
  // 1 <+ aij <= n * m.
  // Note that each set of colours only need to be splitted at most twice.
  // Or kept at 1.
  // Greedily keep the max cost, change every other colors.
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> grid(n, std::vector<int>(m));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> grid[i][j];
    }
  }

  // cost of splitting groups
  std::vector<int> cost(n * m + 1, 0);
  // order-of-traversal, only need to check right and down.
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int idx = grid[i][j];
      if (cost[idx] == 0) {
        cost[idx] = 1;
      }

      // check right, down
      if (j + 1 < m && grid[i][j + 1] == grid[i][j]) {
        cost[idx] = 2;
      }

      if (i + 1 < n && grid[i + 1][j] == grid[i][j]) {
        cost[idx] = 2;
      }
    }
  }

  int total = std::reduce(cost.begin(), cost.end(), 0, std::plus<>{});
  int maxCost = *std::max_element(cost.begin(), cost.end());
  std::cout << total - maxCost << '\n';
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
