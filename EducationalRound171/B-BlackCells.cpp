#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <ios>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using i64 = long long;

// Strip of white cells, numbered from [0..10e18]
//
// Operation available:
// - Choose two white cells i, j such that i != j and |i - j| <= k. Paint black.
//
// Given a list of cells,
// all cells must be painted black. At most one cell not in this list can be
// painted black (for odd length strips).
//
// Determine minimum k. k is the minimum length of the distances between cells
// in the given list
// 1, 11
// firstMax = 10
// secondMax = 1
//
// size 1 => return 1 trivially.
// even => pair adjacent => take firstMax.
// odd => take second max. Nope. Consider {0, 1, 5, 9, 10}
// firstMax = 4 (1, 5) or (5, 9)
// secondMax = 4 (1, 5) or (5, 9)
//
// But the optimal pairing is (0, 1), (5, 6), (9, 10) => introduce 6.
constexpr size_t kMaxN = 2001;  // 1 <= n <= 2000.
void solve() {
  i64 n;
  std::cin >> n;

  std::array<i64, kMaxN> nums{};
  size_t idx = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> nums[idx++];
  }

  if ((n & 1) == 0) {
    // if even, all adjacent elements must be paired. return max dist
    // k, largest distance between adjacent elements.
    i64 maxDist = 1;
    for (size_t i = 0; i < n; i += 2) {
      maxDist = std::max(maxDist, nums[i + 1] - nums[i]);
    }

    std::cout << maxDist << '\n';
    return;
  }

  // If odd.
  // Notice that by inserting an extra element not from the given list,
  // the effects are as though we removed that element.
  // therefore, simplifying the algorithm.
  // for num in nums
  //   calculate maxDist without num
  //
  // 0, 1, 2, 3, 4
  //             ^
  i64 minResult = 1e18;
  for (size_t skip = 0; skip < n; ++skip) {
    i64 maxDist = 1;

    for (size_t i = 0; i < n; ++i) {
      if (i == skip) {
        continue;
      }

      size_t next = i + 1 == skip ? i + 2 : i + 1;
      maxDist = std::max(maxDist, nums[next] - nums[i]);
      i = next;  // advance. Therefore each iteration can plus 2, or plus 3 to i
    }

    minResult = std::min(minResult, maxDist);
  }

  std::cout << minResult << '\n';
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
