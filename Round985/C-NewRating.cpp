#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cstddef>
#include <cstdint>
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
  // n contests.
  // in the ith contest, performance rating is ai.
  // Choose interval [l, r] such that 1 <= l <= r <= n, and skip these contests,
  // excluding the ratings from consideration.
  //
  // Calculation of rating:
  // - Initially, x = 0.
  // - Starting from i in 0..n-1, if l <= i <= r, skip.
  //   Otherwise, the ith contest has rating ai.
  //   if ai > x => x += 1
  //   if ai == x => unchanged
  //   if ai < x => x -= 1
  // At least 1 contest must be skipped.
  //
  // At first glance, this seems like a longest increasing subsequence problem.
  // But pretty sure its not so straightforward. For one, the skipped contests
  // must be contiguous. For another one!! if the performance is always super
  // high, then ai > x means that the rating will always increase!!
  // i.e., suppose that we have no skips, then nums[i] > i ensures we will
  // always increase our rating.
  // This also allows us to deduce the MINIMUM number of skips necessary to
  // guarantee an increase AT nums[i]?
  // One things is that, if nums[i] > i, we can ALWAYS take it without skipping
  // it.
  //
  // Think DP needs more than 1 state. Prolly a extend/skip state.
  // i    = 0 1 2 3 4 5 6 7 8
  // nums = 9 9 8 2 4 4 3 5 3
  // dp   = 1 2 3 3
  // skips= 0 0 0 2 1
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
