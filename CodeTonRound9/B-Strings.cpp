#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdint>
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
  // string p.
  // f(p) is the number of unique, non-empty substrings of p.
  // A string a is a substring of b if a can be obtained from b by deleting
  // >= 0 characters from the beginning and the end.
  // i.e., contiguous subarray.
  //
  // Find non-empty string p such that p is a substring of s, and f(p) is even.
  // -1 if no such string p exists.
  // parity-problem. Consider unique characters too.
  // Sliding window?
  // I.e., find any window such that the number of unique characters is = 2.
  // Ah... Nope. e.g., "ab", substrings are {a, b, ab}. 3 is not even.
  //
  // length 2 with even number of substrings, must be same characters.
  // E.g., "aa" => {a, aa}
  // length 3? 3 unique: "abc" => {a, b, c, ab, bc, abc}
  // length 4? 4 unique
  // "bang" => b a n g ba an ng ban ang bang
  // "aab" => a b aa ab aab (cannot)
  // Given that the number of lowercase alphabets is 26, can we exploit this?
  std::string s;
  std::cin >> s;

  // check pair-wise
  for (int i = 0; i < static_cast<int>(s.size()) - 1; ++i) {
    if (s[i] == s[i + 1]) {
      std::cout << s[i] << s[i] << '\n';
      return;
    }
  }

  // check length 3 unique characters
  for (int i = 0; i < static_cast<int>(s.size()) - 2; ++i) {
    if (s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i] != s[i + 2]) {
      std::cout << s[i] << s[i + 1] << s[i + 2] << '\n';
      return;
    }
  }

  std::cout << -1 << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tc;  // Number of test cases
  std::cin >> tc;

  while (tc--) {
    solve();
  }

  return 0;
}
