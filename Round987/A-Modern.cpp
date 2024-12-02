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
  // n pillars as an array h of positive integers. hi represents height.
  // h is in non-increasing order
  // want: non-decreasing
  //
  // Perform as many times:
  // 1. modify the height of a pillar to any positive integer.
  //
  // output: minimum number of operations.
  //
  // Monotonic stack?
  // Note that h is non-increasing, i.e., 10, 10, 9, 8...,
  // Want: non-decreasing i.e., 10, 10, 11, 12
  // Hm. Notice that we need to change the current number if it is less than
  // the previous.
  // If equal, no need.
  // TOO NAIVE.
  // Consider 10, 9, 9
  // Changing 10 is ideal, but this algorithm would change 9, 9
  // Can we visualize it in terms of partitions?
  // I.e., partition | 10, 10, 10 | 9, 9 | 8 |
  //
  // or | 10, 10 | 9, 9 | 8, 8, 8 |
  // Yeap, we can consider each adjacent partition cumulatively, i.e.,
  // | 9, 9 | 9, 9 | 8, 8 , 8| need to change the 8s.
  int n;
  std::cin >> n;

  std::vector<int> h(n);
  for (int& x : h) {
    std::cin >> x;
  }
  // WARNING: WRONG
  int largestGroup = 0;

  int currGroup = 1;
  for (int i = 1; i < n; ++i) {
    if (h[i] == h[i - 1]) {
      ++currGroup;
    } else {
      largestGroup = std::max(largestGroup, currGroup);
      currGroup = 1;
    }
  }

  largestGroup = std::max(largestGroup, currGroup);
  std::cout << n - largestGroup << '\n';
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
