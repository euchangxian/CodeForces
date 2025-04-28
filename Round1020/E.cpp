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
#include <sstream>
#include <stack>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using i64 = long long;
constexpr int MOD = 1'000'000'007;

#include <vector>

void solve() {
  // might be offline queries
  int n, q;
  std::cin >> n >> q;

  std::vector<int> nums(n + 1);
  std::vector<int> index(n + 1);
  for (int i = 1; i <= n; ++i) {
    int x;
    std::cin >> x;
    nums[i] = x;
    index[x] = i;
  }

  std::vector<std::tuple<int, int, int>> queries;
  queries.reserve(q);
  for (int i = 0; i < q; ++i) {
    int l, r, k;
    std::cin >> l >> r >> k;
    queries.emplace_back(l, r, k);
  }

  auto countHops = [n, &nums, &index](int l, int r, int k) -> int {
    int goodLess = 0, goodGreater = 0;  // correctly placed elements
    int badLess = 0, badGreater = 0;    // incorrectly placed elements
    int idx = index[k];

    while (l <= r) {
      int m = (l + r) / 2;
      if (m == idx) {
        break;
      }

      if (idx < m) {
        if (nums[m] > k) {
          // if should go left (correct)
          goodGreater++;
        } else {
          // if should go right (incorrect)
          badGreater++;
        }
        r = m - 1;  // recurse left
      } else {
        if (nums[m] < k) {
          goodLess++;
        } else {
          badLess++;
        }
        l = m + 1;
      }
    }

    // check if we have enough numbers available
    if (goodLess + badLess > k - 1 || goodGreater + badGreater > n - k) {
      return -1;
    }

    // return the maximum of bad elements times 2
    return std::max(badLess, badGreater) * 2;
  };

  for (auto [l, r, k] : queries) {
    int idx = index[k];
    if (idx < l || idx > r) {
      std::cout << -1 << ' ';
      continue;
    }

    // check how many hops is necessary to reach idx
    int swaps = countHops(l, r, k);
    std::cout << swaps << ' ';
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
