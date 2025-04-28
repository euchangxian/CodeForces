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
  // S(n) = x, S(n+1) = y
  // Sum of the digits of number a.
  // Brute force wont work. Fourth TC is huge.
  // Single digit x, y => return y-x == 1.
  // Double digit x, y => a1*10 + a2 = x, a1*10 + a2 + 1 = y
  // Three digit x, y => a1*100 + a2*10 +a3 = x, a1*100 + a2*10 + a3 + 1 = y
  // 999, 1
  // a1 = 9, a2 = 9, a3 = 9, y_required = a1*100 + a2*10 + a3 + 1 = 1000
  //
  // Hm. Adding 1 would increase the sum by1, or rotate circular to 1.
  int x, y;
  std::cin >> x >> y;
  if (y - x == 1) {
    std::cout << "YES\n";
    return;
  }

  if (x > y && ((x - y) - 8) % 9 == 0) {
    std::cout << "YES\n";
    return;
  }

  std::cout << "NO\n";
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
