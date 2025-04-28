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
  // s has n characters
  // n binary strings ai
  // ai created by copying s, then flipping the ith character
  // count number of 1s
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;

  int result = 0;
  int ones = std::count(s.begin(), s.end(), '1');
  for (int i = 0; i < n; ++i) {
    result += ones;
    if (s[i] == '1') {
      --result;
    } else {
      ++result;
    }
  }
  std::cout << result << '\n';
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
