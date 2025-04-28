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

constexpr std::array<i64, 31> ZEBRA = []() {
  std::array<i64, 31> zebra{};
  zebra[0] = 1;
  for (int i = 1; i < 31; ++i) {
    zebra[i] = (zebra[i - 1] << 2LL) + 1LL;
  }
  return zebra;
}();

void solve() {
  // zebra if LSB=1, alternate  till MSB.
  // e.g., 1, 101, 10101, 1010101, 101010101
  //       1   5     21      85       341
  //
  // Zebra value of a positive integer E is the minimum integer P such that
  // E can be expressed as the sum of P zebra-like numbers (possibly same,
  // possibly different).
  //
  // Given l, r, k, calculate number of integers x such that
  // - l <= x <= r
  // - Zebra(x) == k
  //
  // Zebra Number
  // - odd number
  // - odd number of bits
  //
  // If k is odd, then only Odd numbers are possible, since Odd + ... + Odd will
  // be Odd.
  // Else, consider Even numbers.
  // Cuts our search space into half.
  //
  // Try to construct E with Zebra numbers?
  // Greedily? We can precompute zebra numbers in O(63) time.
  // If the greedy reduction is equal to k zebra numbers, then this number is
  // valid. (binary search)
  //
  // But l, r <= 1e18, lmao. At most 1e17 (consider parity)
  // At most precompute and do prefix sums. But 1e17 is still too much.
  //
  // Sieve? Do a sieve-like?
  // for each Zebra: Set k * zebra[i]. Wait space is still absurd lmao.
  i64 l, r, k;
  std::cin >> l >> r >> k;
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
