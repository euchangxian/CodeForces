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
  // first day: a kilometres
  // second: b km
  // third: c km
  // fourth: a km, again. i.e., mod 3.
  // determine which day complete n kilometres.
  int n, a, b, c;
  std::cin >> n >> a >> b >> c;

  int sum = a + b + c;
  int days = (n / sum) * 3;
  int remainder = n % sum;

  if (remainder > 0) {
    remainder -= a;
    ++days;
  }

  if (remainder > 0) {
    remainder -= b;
    ++days;
  }

  if (remainder > 0) {
    remainder -= c;
    ++days;
  }

  std::cout << days << '\n';
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
