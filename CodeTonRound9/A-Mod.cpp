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
  // integer n, want: increasing integer sequence 1 <= ai < a2 < ... < an <= 100
  // such that ai mod i != aj mod j is satisified for all pairs.
  // Hm. Construction problem.
  // Number mod its position must be unique.
  // x % 1 = 0
  // x % 2 = [0, 1]
  // x % 3 = [0, 1, 2]
  //
  // Pick (i - 1) generally.
  // Start with 1, cannot choose 2, since 2%2 = 0. Need to start from 3.
  // Continue with (2*i - 1), i.e., pick {1, 3, 5, 7, ...}
  int n;  // 2 <= n <= 50. But we are allowed to pick up to 100.
  std::cin >> n;

  for (int i = 1; i <= n; ++i) {
    std::cout << (2 * i) - 1 << ' ';
  }
  std::cout << '\n';
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
