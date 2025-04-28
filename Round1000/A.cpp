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
  // [l, r] is called coprime if l and r is coprime.
  // a coprime segment is called minimal coprime if it does not contain any
  // coprime segment not equal to itself.
  //
  // coprime: No common divisor except for 1.
  // a segment [l', r'] is contained in the segment [l, r] if and only if
  // l <= l' <= r' <= r.
  //
  // Given [l, r], find the number of minimal coprime segments contained.
  // GCD for coprime. What about minimal?
  //
  // ................
  // Adjacent numbers are always coprime...
  i64 l, r;
  std::cin >> l >> r;
  if (l == 1 && r == 1) {
    std::cout << 1 << '\n';
    return;
  }
  std::cout << r - l << '\n';
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
