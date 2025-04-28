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

constexpr int MOD = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> nums(n);
  for (auto& x : nums) {
    std::cin >> x;
  }

  int ones = 0;      // count of '1's seen so far
  int oneToTwo = 0;  // count of 1->2 patterns
  int beautifulSequences = 0;
  for (int x : nums) {
    if (x == 1) {
      ++ones;
    } else if (x == 2) {
      // For each 2, we can:
      // - Keep existing 1-2 patterns without using the current two
      // - Extend existing 1-2 patterns
      // - Create new 1-2 patterns with previous 1s
      oneToTwo = (2LL * oneToTwo + ones) % MOD;
    } else {
      beautifulSequences = (beautifulSequences + oneToTwo) % MOD;
    }
  }

  std::cout << beautifulSequences << '\n';
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
