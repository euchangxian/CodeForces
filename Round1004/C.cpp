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
#include <ios>
#include <iostream>
#include <istream>
#include <iterator>
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

constexpr int MOD = 1'000'000'007;

constexpr std::array<std::array<int, 2>, 4> directions{{
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
}};

void solve() {
  // Positive integer n
  // add any positive integer whose decimal represntation contains ONLY the
  // digit '9'.
  // Min ops to make n contain at least one '7'.
  // Try 9, 90, 99, ...,
  // 2^10, since n<=10e9
  // But multiple operations may be necessary. DP? Definitely not DP on
  // values of N, since 10e9. Some maffs.
  // from ones place, if ones = 8, then +9, extra +9 for ones=9, ... 0: 3 ops.
  //                     tens = 6, then +9 + 9, extra 9 for 7, 8, 9
  // At some point, it becomes less optimal to add 9 repeatedly.
  // i.e., if 11 singular '9's is necessary, then one 99 is better.
  // But there should never be a case where 11 ops is necessary.
  // At most 8, since worst case n = 6, then +9 8 times to get 78
  // what about n = 86, +9 9 times.
  //
  // Can brute force search since 9 ops per place, 10 places only.
  //
  // We cant get past 10 ops.
  // How to model the r/s?
  // Ah look for a 7, then 6, then 5, 4..., wrapping around to 8.
  // 7 requires 0 ops.
  // 6 requires 1.
  // 5 requires 2...
  // NOPE. We can determine the required ops based off each place in n.
  i64 n;
  std::cin >> n;

  std::string nStr = std::to_string(n);
  if (nStr.find('7') != std::string::npos) {
    std::cout << 0 << '\n';
    return;
  }

  int minOps = INT_MAX;
  int length = 1;
  i64 x = 9;
  while (length <= nStr.length()) {  // +9 to handle single digit case.
    i64 temp = n;
    for (int ops = 1; ops <= 9; ++ops) {
      temp += x;
      std::string s = std::to_string(temp);
      if (s.find('7') != std::string::npos) {
        minOps = std::min(minOps, ops);
        break;
      }
    }

    ++length;
    x = x * 10 + 9;
  }
  std::cout << minOps << '\n';
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
