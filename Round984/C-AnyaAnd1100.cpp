#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
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
#include <vector>

using i64 = long long;

void solve() {
  // beautiful string s consisting of 0s and 1s only.
  // Perform q operations.
  // Each operation is described by two integers i (1 <= i <= |s|) and
  // v (v = 0 | 1). i.e., ith character is assigned to the value v.
  // After each query, check if the substring 1100 is present.
  // Naive O(n) search per query would probably encounter TLE
  std::string s;
  std::cin >> s;

  // store the idx of the start of each pattern
  std::unordered_set<int> patternIdx;

  // preprocess to find the start index of each "1100" pattern
  for (int i = 0; i <= static_cast<int>(s.length()) - 4; ++i) {
    bool isPattern =
        s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0';

    if (isPattern) {
      patternIdx.insert(i);
    }
  }

  int q;
  std::cin >> q;
  while (q--) {
    int i, v;
    std::cin >> i >> v;
    --i;  // 1-indexed to 0-indexed
    s[i] = '0' + v;

    // Possibly start at i, or includes i as the 2nd, 3rd or 4th char.
    for (int pos = std::max(0, i - 3); pos <= i; ++pos) {
      patternIdx.erase(pos);
    }

    for (int j = std::max(0, i - 3);
         j <= std::min(static_cast<int>(s.length()) - 4, i); ++j) {
      bool isPattern =
          s[j] == '1' && s[j + 1] == '1' && s[j + 2] == '0' && s[j + 3] == '0';

      if (isPattern) {
        patternIdx.insert(j);
      }
    }

    if (patternIdx.empty()) {
      std::cout << "NO" << '\n';
    } else {
      std::cout << "YES" << '\n';
    }
  }
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
