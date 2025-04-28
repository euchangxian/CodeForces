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

void solve() {
  // binary string s, length n, emptybinary string t.
  // Remove some suffix s and place at the end of t, or
  // remove suffix from t and place at the end of s.
  // Find the minimum number of moves rqeuired to make s contain only 0, t
  // contain only 1.
  // n <= 1000
  // Feels tower of hanoi-ish
  //
  // 0101001
  // 010100 | 1
  // 010    | 1100
  // 01000  | 11
  // 0      | 111000
  // 0000
  // Move each 1 and all suffix 0s, then move the 0s back. Repeat.
  // Therefore, number of ops is the number of '1's in s, and if there are
  // 0s to its right.
  // Not exactly. can move multiple ones. Lol
  int n;
  std::cin >> n;

  std::string s;
  std::cin >> s;

  bool hasZero = false;
  int operations = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == '0') {
      hasZero = true;
    } else {
      while (i >= 0 && s[i] == '1') {
        --i;
      }
      ++i;  // over decremented.
      ++operations;
      operations += hasZero;
      hasZero = false;
    }
  }
  std::cout << operations << '\n';
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
