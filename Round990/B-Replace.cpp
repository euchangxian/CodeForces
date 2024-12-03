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
  // choose any two indices i, j. i can be the same as j.
  // Set s[i] = s[j].
  // Minimize distinct permutations. Output the string after performing one
  // operation.
  // We want to minimize the number of distinct characters
  int n;
  std::cin >> n;  // n <= 10.
  std::string s;
  std::cin >> s;

  if (n == 1) {
    std::cout << s << '\n';
    return;
  }

  std::array<int, 26> count{};
  for (char c : s) {
    ++count[c - 'a'];
  }

  int maxIdx = -1, minIdx = -1;
  int maxCount = 0, minCount = n;

  for (int i = 0; i < 26; ++i) {
    if (count[i] > 0) {
      if (count[i] > maxCount) {
        maxCount = count[i];
        maxIdx = i;
      }
      if (count[i] < minCount) {
        minCount = count[i];
        minIdx = i;
      }
    }
  }

  if (minIdx == maxIdx) {
    for (int i = 0; i < 26; ++i) {
      if (count[i] == minCount && i != minIdx) {
        minIdx = i;
        break;
      }
    }
  }

  if (minIdx == maxIdx) {
    std::cout << s << '\n';
    return;
  }

  bool changed = false;
  for (int i = 0; i < n; ++i) {
    if (s[i] == minIdx + 'a' && !changed) {
      std::cout << char(maxIdx + 'a');
      changed = true;
    } else {
      std::cout << s[i];
    }
  }
  std::cout << '\n';
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
