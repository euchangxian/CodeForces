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
  // if 10 digits, ith digit from the left is at LEAST 10-i. (1-indexed)
  // rearrange to get smallest.
  // satisfy until i=9 => >= 1, then ascending order.
  std::string s;
  std::cin >> s;

  std::array<int, 10> freq{};
  for (char c : s) {
    ++freq[c - '0'];
  }

  std::string t = s;
  for (int i = 0; i < s.size(); ++i) {
    for (int j = 9 - i; j < 10; ++j) {
      if (freq[j]) {
        --freq[j];
        t[i] = (j + '0');
        break;
      }
    }
  }
  std::cout << t << '\n';
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
