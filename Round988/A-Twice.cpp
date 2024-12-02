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
  // array a with n integers
  // Perform operation any number of times:
  // select two indices i, j such that neither i nor j has been chosen in
  // previous operations, and that ai = aj. Add one to the score.
  // 1 <= n <= 20
  // just brute force.
  int n;
  std::cin >> n;

  std::array<int, 21> count{};
  for (int i = 0; i < n; ++i) {
    int val;
    std::cin >> val;

    ++count[val];
  }

  int score = 0;
  for (int freq : count) {
    score += freq / 2;  // choose two
  }
  std::cout << score << '\n';
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
