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
  // Given a and b,
  // output m.
  // m >= a || m >= b, and
  // m % a == m % b
  // Seems like GCD.
  //
  // inputs are 1 <= a, b <= 1000.
  // Binary Search?
  int a, b;
  std::cin >> a >> b;
  if (b < a) {
    // ensure a is smaller.
    std::swap(a, b);
  }

  // What about brute force?
  // for each 1 <= k <= b, multiply with a, check divisor.
  for (int k = 1; k <= b; ++k) {
    i64 prod = k * static_cast<i64>(a);

    if (prod % a == prod % b) {
      std::cout << prod << '\n';
      return;
    }
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
