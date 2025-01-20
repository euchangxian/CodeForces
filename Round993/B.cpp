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
  // 'p', 'w', 'q' string.
  // Visual reverse: 'p' => 'q', 'q' => 'p'. 'w' => 'w'
  // Positional reverse too!!.
  std::string a;
  std::cin >> a;

  std::reverse(a.begin(), a.end());
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] == 'p') {
      a[i] = 'q';
    } else if (a[i] == 'q') {
      a[i] = 'p';
    }
  }
  std::cout << a << '\n';
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
