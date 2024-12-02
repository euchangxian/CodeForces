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
  // The interval between two notes a and b is equal to |a-b| semitones.
  // A melody is perfect if the interval between ANY two adjacent notes is
  // either 5 or 7 semitones.
  // O(n) check works.
  int n;
  std::cin >> n;

  // Read in first, then compare adjacent
  int a;
  std::cin >> a;

  int b;
  bool isPerfect = true;
  for (int i = 1; i < n; ++i) {
    std::cin >> b;
    int diff = std::abs(a - b);
    if (!(diff == 5 || diff == 7)) {
      // will never be set back to true if non-perfect encountered.
      isPerfect = false;
    }
    a = b;
  }

  if (isPerfect) {
    std::cout << "YES" << '\n';
  } else {
    std::cout << "NO" << '\n';
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
