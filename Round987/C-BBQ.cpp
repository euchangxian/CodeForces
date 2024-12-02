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
  // n BBQ buns left to right. 10^6 available fillings numbered [1..10^6]
  // - each filling must be used 0 times, or more than once.
  // - For any two buns i, j that have same fillings, distance between them,
  //   |i - j| must be a perfect square. i.e, some x * x == |i-j|
  // Seems like a construction problem. Cant we just use the same fillings
  // consecutively? Distance is 1 which will be a perfect square.
  // Nope, ALL pairs must be perfect squares.
  // Even/Odd cases? Even just alternate. Will always be true given size of n.
  // 1, 1, 2, 2
  //
  // Also, PAIRWISE, means cannot just place at 1, 4, 9
  // 4 will be distance 5 away.
  //
  // 0, 4, 45
  // Odd? Tough. n = 3, n = 5 are impossible
  // 1, 2, 2, _, 1
  // 1, 2, _, _, 1, 2, _
  //
  // NOTE:
  // For odd cases, we know that one number must occur at least thrice.
  // rewrite the equation. x < y < z such that (y - x), (z - y), (z - x) are all
  // perfect squares.
  // We can form an equation, knowing that x < y < z implies that (y-x) and
  // (z-y) is contained within (z-x):
  // z - x = (z - y) + (y - x)
  // The smallest solution is z - x = 25, (z-y) + (y-x) = 9 + 16
  // In hindsight, should have remembered 3^2 + 4^2 = 5^2, which is quite a
  // "special" sequence of perfect squares.
  // Therefore, with this, for odd n <= 25, there is no solution.
  // For odd n > 25, i.e, n=27, we can construct a solution by selecting
  // one number i, and place i at positions 0, 9, 25, corresponding to x,y,z
  // derived above.
  int n;  // number of buns
  std::cin >> n;
  if (n & 1) {
    if (n <= 25) {
      std::cout << "-1\n";
      return;
    }

    // hardcode the first 27 numbers.
    std::cout
        << "1 2 2 3 3 4 4 5 5 1 6 6 7 7 8 8 9 9 10 10 11 11 12 12 13 1 13 ";

    // safe division odd - odd is even.
    for (int i = 0; i < (n - 27) / 2; ++i) {
      std::cout << (i + 14) << ' ' << (i + 14) << ' ';
    }
    std::cout << '\n';
  } else {
    // safe to divide by 2.
    for (int i = 0; i < n / 2; ++i) {
      std::cout << i + 1 << ' ' << i + 1 << ' ';
    }
    std::cout << '\n';
  }
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
