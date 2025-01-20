#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <deque>
#include <functional>
#include <ios>
#include <iostream>
#include <map>
#include <numeric>
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

i64 factorialMod9(i64 n) {
  i64 f = 1;
  for (int i = 1; i <= n; ++i) {
    f = (f * i) % 9;
  }
  return f;
}

void solve() {
  // digit d n! times in a row.
  // Which odd digits from 1 to 9 divide the number written
  // Seem to be a parity problem? n! is huge.
  // 1 is definite.
  //
  // Notice that writing digits a factorial number of times means
  // d * (1111..11) k number of ones
  //
  // factorise d out: d * ((10^k - 1) / 9)
  // lg(d) + (k - 1) - lg(9)
  i64 n, d;
  std::cin >> n >> d;

  std::vector<int> result;
  result.push_back(1);
  if (n >= 3 || (n == 2 && d % 3 == 0)) {
    result.push_back(3);
  }

  if (d == 5) {
    result.push_back(5);
  }

  if (n >= 3 || (n == 2 && d == 7)) {
    result.push_back(7);
  }

  if (n >= 6) {
    result.push_back(9);
  } else {
    i64 fm9 = factorialMod9(n);
    if ((fm9 * (d % 9)) % 9 == 0) {
      result.push_back(9);
    }
  }

  for (int i : result) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tc;
  std::cin >> tc;

  while (tc--) {
    solve();
  }

  return 0;
}
