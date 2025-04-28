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

void solve() {
  // note we need the median to be <= k.
  // Thus, two of the subarrays's medians need to be <= k
  // Thus, we do not have to search [l, r]. We can search starting from nums[2],
  // for a split point, or not? i think not optimal.
  // Rather, try to set each subarray median to <= k, greedily.
  // If the median is <= k, and the subarray is currently odd sized, adding
  // the next value, if its > k is optimal.
  // how to maintain running median?
  // Should just maintain count of greater and lessThanEqual.
  // NOTE:
  // We can transform the array such that arr[i] = 1 if nums[i] <= k,
  //                                              -1 otherwise
  // Thus, the problem becomes finding two subarrays with non-negative sums.
  // Case 1: 1st and 2nd subarrays have non-negative sums.
  // Case 2: 2nd and 3rd subarrays have non-negative sums.
  // Case 3: 1st and 3rd subarrays have non-negative sums.
  // To solve Case 3: find the prefix sum p[l] >= 0, and suffix sum s[r] >= 0.
  // The split is only valid if the middle subarray is non-empty, i.e.,
  // r-l+1 >= 1
  // Case 1 and Case 2 are symmetric: reverse the array.
  // Thus, WLOG:
  // - determine the suffix sum s[i] = nums[i] + ...
  // - With this, if we have the MINIMUM suffix sum at i, i.e.,
  //   min(s[i], s[i+1], ...), we can determine if the array has a valid split
  //   by iterating over [0..n-1]. This is because suffix[i] - minSuffix[i] >=0
  //   indicate that there exists some [l, r] such that nums[l..r]
  //   is non-negative (we do not need to know the exact value of r)
  //   Thus, the array has a valid split IF:
  //   - prefix[i] >= 0, AND
  //   - suffix[i+1] - minSuffix[i+2] >= 0
  int n, k;
  std::cin >> n >> k;
  std::vector<int> nums(n + 1);

  // 1-indexed
  for (int i = 1; i <= n; ++i) {
    std::cin >> nums[i];
    nums[i] = nums[i] <= k ? 1 : -1;  // transform the array
  }

  auto checkFirstAndSecond = [n, k](std::vector<int>& nums) -> bool {
    std::vector<int> suffix(n + 1), minSuffix(n + 1);
    suffix[n] = minSuffix[n] = nums[n];
    for (int i = n - 1; i >= 1; --i) {
      suffix[i] = suffix[i + 1] + nums[i];
      minSuffix[i] = std::min(minSuffix[i + 1], suffix[i]);
    }

    int prefix = 0;
    // iterate over all possible split points, while ensuring at least one
    // element in the second and third subarrays.
    // i.e., [1..n-2]
    for (int i = 1; i <= n - 2; ++i) {
      prefix += nums[i];
      if (prefix < 0) {
        continue;
      }

      // non-zero subarray on the right
      if (suffix[i + 1] >= minSuffix[i + 2]) {
        return true;
      }
    }
    return false;
  };

  // check case3: first and third
  int l = n + 1;
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    sum += nums[i];
    if (sum >= 0) {
      l = i;
      break;
    }
  }

  int r = -1;
  sum = 0;
  for (int i = n; i >= 1; --i) {
    sum += nums[i];
    if (sum >= 0) {
      r = i;
      break;
    }
  }

  if (r - l - 1 >= 1) {
    std::cout << "YES\n";
    return;
  }

  if (checkFirstAndSecond(nums)) {
    std::cout << "YES\n";
    return;
  }

  // 1-indexed
  std::reverse(nums.begin() + 1, nums.end());
  std::cout << (checkFirstAndSecond(nums) ? "YES\n" : "NO\n");
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
