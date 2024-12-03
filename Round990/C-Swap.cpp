#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <deque>
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

void solve() {
  // 2 rows, n columns.
  // integer in cell (i, j) is aij
  // Any number of times:
  // choose two columns and swap them.
  //
  // Choose a path from the cell (1, 1) to the cell (2, n).
  // For every (i, j) in the path, the next cell should be either (i+1, j),
  // or (i, j + 1). Move downwards or rightwards only.
  //
  // Cost is sum of integers belonging to the path. Maximize.
  //
  // Swapping columns is costly. Transpose the input? Tricky.
  // The last column can take 2 values.
  int n;
  std::cin >> n;
  std::array<std::vector<int>, 2> grid{};
  for (int i = 0; i < 2; ++i) {
    grid[i] = std::vector<int>(n);

    for (int j = 0; j < n; ++j) {
      std::cin >> grid[i][j];
    }
  }

  int result = 0;  // no overflow potential due to inputs.
  int maxOfMins = INT_MIN;

  for (int j = 0; j < n; ++j) {
    // given that we can rearrange columns arbitrarily, we want to take the
    // maximum value where possible.
    result += std::max(grid[0][j], grid[1][j]);

    // We also want to take the next biggest value for each column.
    maxOfMins = std::max(maxOfMins, std::min(grid[0][j], grid[1][j]));
  }

  std::cout << result + maxOfMins << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tc;
  std::cin >> tc;

  while (tc--) {
    solve();
  }

  return 0;
}
