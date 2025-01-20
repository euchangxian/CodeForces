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
#include <span>
#include <stack>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using i64 = long long;

std::pair<int, int> getRangeMaxMin(std::span<i64> a) {
  const int n = a.size();
  if (n <= 0) {
    return {0, 0};
  }

  std::vector<i64> prefix(n);
  prefix[0] = a[0];
  for (int i = 1; i < n; ++i) {
    prefix[i] = prefix[i - 1] + a[i];
  }

  std::vector<i64> prefixMax(n);
  std::vector<i64> prefixMin(n);
  prefixMax[0] = std::max(0LL, prefix[0]);
  prefixMin[0] = std::min(0LL, prefix[0]);
  for (int i = 1; i < n; ++i) {
    prefixMax[i] = std::max(prefixMax[i - 1], prefix[i]);
    prefixMin[i] = std::min(prefixMin[i - 1], prefix[i]);
  }

  i64 maxSum = LLONG_MIN;
  i64 minSum = LLONG_MAX;
  for (int i = 0; i < n; ++i) {
    maxSum = std::max(maxSum, prefix[i] - prefixMin[i]);
    minSum = std::min(minSum, prefix[i] - prefixMax[i]);
  }

  return {minSum, maxSum};
}

void solve() {
  // array a of n integers
  // all elements except one or possibly none is equal to -1 or 1.
  // The remaining element x satisfies -10^9 <= x <= 10^9
  //
  // Find all possible sums of subarrays of a, including the empty subarray.
  // i.e., find all x such that a has at least one subarray with sum equal to x.
  // Print distinct in ascending order.
  //
  // Exploit {-1, 1} and x?
  // Prefix sums? most subarrays have sums in the range [-k, k]
  // If x is included, then the range becomes [-k+x, k+x]
  // Count prefixes.
  //
  // Hm. Try a simpler variant. All -1s or 1s?
  int n;
  std::cin >> n;
  std::vector<i64> a(n);

  int specialIdx = -1;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];

    if (a[i] != -1 && a[i] != 1) {
      specialIdx = i;
    }
  }

  // easier case.
  if (specialIdx == -1) {
    auto [minSum, maxSum] = getRangeMaxMin(a);

    std::cout << maxSum - minSum + 1 << '\n';
    for (i64 sum = minSum; sum <= maxSum; ++sum) {
      std::cout << sum << ' ';
    }
    std::cout << '\n';
    return;
  }

  // find unique sums excluding special element.
  auto [leftMin, leftMax] = getRangeMaxMin(std::span(a.begin(), specialIdx));
  auto [rightMin, rightMax] =
      getRangeMaxMin(std::span(a.begin() + specialIdx + 1, a.end()));

  i64 special = a[specialIdx];
  std::set<i64> sums{0, special};  // Empty subarray
  for (i64 sum = leftMin; sum <= leftMax; ++sum) {
    sums.insert(sum);
    sums.insert(sum + special);
  }
  for (i64 sum = rightMin; sum <= rightMax; ++sum) {
    sums.insert(sum);
    sums.insert(sum + special);
  }

  int l = specialIdx - 1;
  int r = specialIdx + 1;

  i64 sum = special;
  while (l >= 0 && r < n) {
    sum += a[l--] + a[r++];
    sums.insert(sum);
  }

  std::cout << sums.size() << '\n';
  for (i64 sum : sums) {
    std::cout << sum << ' ';
  }
  std::cout << '\n';
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
