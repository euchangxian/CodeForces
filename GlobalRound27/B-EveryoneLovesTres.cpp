#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <ios>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using i64 = long long;

void solve() {
  // given positive integer n, find smallest integer whose decimal
  // representation has length n, consists only of 3s and 6s, such that it is
  // divisible by both 33 and 66.
  // Otherwise, return -1.
  // Brute force? Something like backtracking/permutations of 3s and 6s.
  // 1 <= n <= 500 => 500 digit long...

  int n;
  std::cin >> n;

  if (n == 1) {
    std::cout << -1 << '\n';
    return;
  }

  // Form string of all 3s
  std::string numStr = std::string(n, '3');

  for (int i = n - 1; i >= 0; --i) {
    for (char digit : {'3', '6'}) {
      numStr[i] = digit;

      i64 num = std::stoi(numStr);
      if (num)
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
