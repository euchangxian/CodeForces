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
  // remove any number of digit. Contains at least one digit, strictly > 0
  // Leading zeros are allowed.
  //
  // Want minimum cost. Number / sum of digits
  // Minimum is when only 1 digit.
  // Remove all > 0
  std::string s;
  std::cin >> s;

  int ops = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] >= '1') {
      ++ops;
    }
  }

  int zeros = 0;
  for (int i = s.size() - 1; i >= 0; --i) {
    if (s[i] == '0') {
      ++zeros;
    } else {
      break;
    }
  }

  std::cout << ops - 1 + zeros << '\n';
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
