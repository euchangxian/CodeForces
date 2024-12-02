#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
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
  // two integers x and m.
  // Count number of integers 1 <= y <= m such that
  // 1. x != y, and
  // 2. x XOR y is a divisor of either x or y.
  // i.e., x % (x^y) == 0 or y % (x^y) == 0
  //
  // or more precisely,
  // there exists a k, k >= 0, such that
  // x = k * (x^y) or
  // y = k * (x^y)
  //
  // clearly, cant test every integer in the range {1..m}\{x}, since
  // m <= 10^18 (61 bits)
  // Has to be based on x.
  // What about based on 61 bits though.
  //
  // Let's try to look at the bits?
  //
  // if x is divisible by (x^y), what does it mean?
  // Does looking at the bit even help us determine a is divisble by b...?
  //
  // x = 6 = 0110,    m = 9 = 1001
  // divisors = 1, 2, 3, 6. Skip 6 since y=0 is not allowed.
  //
  // i.e., construct y such that (x^y) == d where d is a divisor of x.
  // Finding divisors of x can be done in sqrt(x) time.
  //
  // But what about finding divisors of y?
  // And what about numbers beyond x up till m?
  //
  // Hmmm. First, does any (x^y) give us a x < d <= m such that y is divisible
  // by d.
  // x = 6 = 0110
  // That means the leading zeroes of x must be set to '1's.
  // But any such of these constructed y, will have an XOR larger than y itself
  // IF the bits representing x are not XOR-ed to become 0.
  // i.e., in easier words, y = 1111 1|110 will have an XOR of 1111 1|000.
  //
  // y = 1111 1|001 will have an XOR of 1111 1|110 which is larger than y itself
  // already, and do not need to be considered.
  // Hmmmm. i.e., y can only differ in positions of x smaller than its MSB?
  // y = 01__
  // therefore, possible x^y are {0000, 0001, 0010, 0011}.
  // Thats too much to check though. Can we do it more smartly.
  // ....
  // It wasnt too much. x is upper bounded by 10^6. O(n) works already.
  int x;
  i64 m;
  std::cin >> x >> m;

  // get MSB position of x
  int msb = 31 - __builtin_clz(x);

  // count valid numbers y that:
  // 1. share same MSB as x,
  // 2. satisfy x % (x^y) == 0 or y % (x^y) == 0
  int count = 0;

  // Start from smallest number with the same MSB.
  // End at either the next power of 2, or m, whichever is smaller.
  i64 end = std::min(m, (1LL << (msb + 1)) - 1);

  for (int y = 1 << msb; y <= end; ++y) {
    if (y == x) {
      continue;
    }

    int xy = x ^ y;

    // check if xy divides either x or y
    if ((xy != 0) && (x % xy == 0 || y % xy == 0)) {
      ++count;
    }
  }

  std::cout << count << '\n';
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
