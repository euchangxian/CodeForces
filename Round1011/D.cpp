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
  // N plates, each plate has k sushis.
  // ith plate have deliciousness di
  //
  // n minutes, must eat up all taken sushi.
  //
  // Consider counter r for uneaten sushis.
  // In the ith minute, only ith sushi will be delivered, choose ONLY 1:
  // - Take ith plate, r += k
  // - Eat 1 uneaten sushi previously taken. r -= 1.
  // - Do nothing. r remains unchanged
  // After n minutes, r must be 0.
  //
  // Maximise sum of deliciousness.
  // Hm. Greedy? Determine how many plates can be taken. Its a careful balance
  // though, since cannot take and eat sushi in the same minute.
  // After a certain time, plates cannot be taken already.
  // i.e., at time t, such that t + 1 + k  > n;
  //
  // Feels like buy and sell stock.
  // DP? Consider number of sushis.
  //
  // I think DP. Only need to consider the prefix array nums[0..n-k]
  // Then within, the maximum number of plates that can be taken to be able to
  // take the current plate?
  //
  // ... Hard. Consider the Sample TC
  // n=6, k=2
  // nums = {1, 3, 5, 2, 4, 6}
  // Optimal: take nums[1], eat 1/2, take nums[3], eat 2/4, eat 3/4, eat 4/4.
  // Score = 6.
  //
  // Okay, we can have the max sushi remaining at index i == n-i
  // dp needs a sushisRemaining state. If sushisRemaining + k > max, then
  // cannot take.
  // Otherwise, try taking, and try skipping.
  // dp[i][j] = maxDeliciousness of first i plates, with j sushis remaining.
  //
  // Feels knapsack like.
  // memo[n][0] = memo[n-k-1] +

  int n, k;  // k < n
  std::cin >> n >> k;

  std::vector<i64> nums(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> nums[i];
  }

  // 0 plates, 0 sushis, 0 deliciousness. 000
  std::vector<i64> dp(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    std::vector<i64> temp(n + 1, 0);
    for (int j = 0; j <= n - i + 1; ++j) {
      if (j > 0) {
        // EAT
        temp[j - 1] = std::max(temp[j - 1], dp[j]);
      }

      if (j + k <= n - i) {
        // TAKE
        temp[j + k] = std::max(temp[j + k], dp[j] + nums[i - 1]);
      }

      // DO NOTHING
      temp[j] = std::max(temp[j], dp[j]);
    }
    dp = std::move(temp);
  }
  std::cout << dp[0] << '\n';
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
