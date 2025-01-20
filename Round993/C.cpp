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
  // 2 rows, m seats each.
  // a monkeys sit in row 1,
  // b monkeys sit in row 2,
  // c monkeys no preference.
  // 1 monkey <=> 1 seat
  int m, a, b, c;
  std::cin >> m >> a >> b >> c;

  int row1 = std::min(m, a);
  int row2 = std::min(m, b);

  if (row1 < m) {
    int noPref = std::min(m - row1, c);
    c -= noPref;
    row1 += noPref;
  }

  if (row2 < m) {
    int noPref = std::min(m - row2, c);
    c -= noPref;
    row2 += noPref;
  }

  std::cout << row1 + row2 << '\n';
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
