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
  // want to buy houses numbered from 1 to 1e9
  // n bars on street, located in houses with numbers ai.
  // May have multiple bars in the same house.
  // by time of purchase some bars are closes. no more than k bars can close.
  //
  // for house x. f(x) is the sum of |x-y| over all open bars y.
  // Buy house x IFF k bars can be closed such that f(x) is minimised.
  // Return how many houses can be bought.
  //
  // distance is minimised at median house. Remove leftmost and rightmost houses
  // to choose between left and right, take the one with the larger difference.
  int n, k;
  std::cin >> n >> k;
  std::vector<int> bars(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> bars[i];
  }

  std::ranges::sort(bars);

  // index of the left and right median. l == r if odd.
  int l = (n - 1) >> 1;  // floor(n-1)
  int r = n >> 1;        // floor div

  // K is the size of the window nums[l..r] of possible medians.
  // n&1 accounts for the difference in the behavior of the median shifting
  // in odd vs even sized array.
  // if odd, the median is a single element. To move the median by 1 position,
  // TWO elements need to be removed: from the left OR from the right
  // if even, the median is between two elements. To shift this median, only
  // one element need to be removed (to turn this array into an odd-sized one).
  int d = (k + (n & 1)) >> 1;

  l -= d;
  r += d;

  std::cout << bars[r] - bars[l] + 1 << '\n';
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
