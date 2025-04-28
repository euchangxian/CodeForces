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

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::string s;
  std::cin >> s;

  if (k == 0) {
    std::string r = s;
    std::reverse(r.begin(), r.end());

    std::cout << (s < r ? "YES" : "NO") << '\n';
    return;
  } else {
    char c = s[0];
    for (char cc : s) {
      if (c != cc) {
        std::cout << "YES\n";
        return;
      }
    }
    std::cout << "NO\n";
  }
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
