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
#include <numeric>
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
  // Sequence a of n integers.
  // Two integers x and y.
  // A pair of integers (i, j) is interesting iff:
  // - 1 <= i < j <= n, i.e., indices i and j are distinct.
  // - if both are removed, then the sum of the remaining seq, x <= sum <= y
  //
  // Want: number of interesting pairs.
  // Can brute force n^2?
  // Sort?
  // Then for each element, find the threshold.
  // i.e,. set i, then find minimum and maximum j such that sum -= nums[j]
  // is within the range.
  // Count = max - min
  i64 n, x, y;
  std::cin >> n >> x >> y;

  std::vector<i64> a(n);
  for (i64& i : a) {
    std::cin >> i;
  }

  std::sort(a.begin(), a.end());
  i64 total = std::reduce(a.begin(), a.end(), 0LL, std::plus<>{});
  i64 count = 0LL;

  for (int i = 0; i < n - 1; ++i) {
    i64 minJ = total - y - a[i];
    i64 maxJ = total - x - a[i];

    auto upper = std::upper_bound(a.begin() + i + 1, a.end(), maxJ);
    auto lower = std::lower_bound(a.begin() + i + 1, a.end(), minJ);

    count += (upper - lower);
  }

  std::cout << count << '\n';
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
