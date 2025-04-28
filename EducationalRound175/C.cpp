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

void solve() {
  // n tiles, k operations
  // Each operation paints the cell blue.
  //
  // Initial color is not known.
  // tile[i] indicate the desired color
  // penalty[i] indicate the penalty if not the correct color.
  //
  // The final penalty is the maximum penalty among all cells that are painted
  // the wrong colour.
  //
  // Find minimum (maximum) penalty.
  //
  // If tile[i] is red, then avoid painting it to avoid incurring a penalty.
  // If tile[i] is blue, then the maximum penalty is penalty[i]
  // Sliding window?
  // k is the maximum number of reds in the window. Nope. doesnt seem so.
  // Prefix/Suffix?
  int n, k;
  std::cin >> n >> k;
  std::string tile;
  std::cin >> tile;
  std::vector<int> penalty(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> penalty[i];
  }

  auto feasible = [&tile, &penalty, n, k](int maxPenalty) -> bool {
    // if blue, then an operation is necessary.
    // if red, ignore,
    // if blue, and its penalty is greater than the acceptable target, then
    // greedily paint over subsequent cells,

    int ops = 0;
    int i = 0;
    while (i < n) {
      if (tile[i] == 'R') {
        ++i;  // okay to skip over the red.
        continue;
      }

      if (penalty[i] > maxPenalty) {
        ++ops;

        // greedy paint.
        while (i < n) {
          if (tile[i] == 'R' && penalty[i] > maxPenalty) {
            break;
          }
          ++i;
        }
      }
      ++i;  // okay to skip over the red.
    }

    return ops <= k;
  };

  int left = 0;
  int right = *std::max_element(penalty.begin(), penalty.end());

  while (left < right) {
    int mid = left + (right - left) / 2;

    if (!feasible(mid)) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  std::cout << left << '\n';
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
