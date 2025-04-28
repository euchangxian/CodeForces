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
  // x, y <= 10^9
  // find k >= 0, k <= 10^18 such that (x+k) + (y+k) == (x+k)XOR(y+k),
  // or determine if it doesnt exist.
  //
  // (x+k) ^ (y+k) = x^y + x^k + y^k
  // (x+k) + (y+k) = x + y + 2k
  //
  // x + y + 2k == x^y + x^k + y^k
  // x^k + y^k - 2k = x + y + x^y
  // (x+y)^k - 2k = RHS
  // Unknowns on left. Doesnt seem to help.
  //
  // When x and y dont share any bits, then possible, since x+y == x^y
  //
  // Then, we need to find k such that x+k and y+k dont share bits.
  // Ah. Unless x == y, WLOG, assume x < y. Then, increment y till power of 2.
  i64 x, y;
  std::cin >> x >> y;

  if ((x & y) == 0) {
    std::cout << 0 << '\n';
    return;
  }

  if (x == y) {
    std::cout << -1 << '\n';
    return;
  }

  if (x > y) {
    std::swap(x, y);
  }

  i64 powOfTwo = 0;
  for (i64 i = 1; i < LLONG_MAX; i <<= 1) {
    if (i > y) {
      powOfTwo = i;
      break;
    }
  }

  i64 k = powOfTwo - y;
  std::cout << k << '\n';
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
