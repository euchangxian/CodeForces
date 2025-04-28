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
  int n, m;
  std::cin >> n >> m;
  std::vector<i64> nums(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> nums[i];
    nums[i] = std::min(nums[i], static_cast<i64>(n) - 1);  // need 2 colors
  }
  std::sort(nums.begin(), nums.end());

  std::vector<i64> prefix(m + 1, 0);
  for (int i = 1; i <= m; ++i) {
    prefix[i] = prefix[i - 1] + nums[i - 1];
  }

  i64 result = 0;
  for (i64 num : nums) {
    i64 threshold = n - num;
    auto it = std::lower_bound(nums.begin(), nums.end(), threshold);

    if (it == nums.end()) {
      continue;
    }

    int idx = it - nums.begin();

    // add the excess above the threshold.
    result += (prefix[m] - prefix[idx]) - ((m - idx) * threshold);
  }

  std::cout << result << '\n';
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
