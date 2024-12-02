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
  // array a with length n, a[i] = b * (i - 1) + c for 1 <= i <= n
  //                        a[i] = b*i + c
  // transform a into a permutation, using the operation:
  // - replace the maximum element of a with the MEX, which is the smallest
  //   non-negative integer that does not belong to the array.
  // - If there are multiple maximum elements, choose the leftmost one.
  //
  // A permutation of length n is an array consisting of n distinct integers
  // from 0 to n-1 in arbitrary order.
  // Hm. first glance is that the input array a represents the line
  // y = mx + c.
  // Visualizing as such, we want elements to lie on y = x, i.e., downwards
  // shift.
  //
  // We want to figure out how many elements are already correct. The difficulty
  // lies in determining if a sequence can/cannot be converted.
  // 1, 1, 1, 1
  // 0, 1, 1, 1
  // 0, 2, 1, 1
  // 0, 3, 1, 1
  // ... continues forever
  //
  // 1, 1, 1
  // 0, 1, 1
  // 0, 2, 1 is correct.
  // The case where the element replaced increases/becomes the new maximum is
  // dangerous. This happens when the gradient is 0, and c is smaller some
  // threshold.
  // i.e., n = 2, b = 0, c = 0 is still possible to get {0, 1} in 1 operation.
  //       n = 3, b = 0, c = 0, not possible {0, 2, 0}, need c = 1
  //       n = 4, b = 0, c = 2, possible {0, 1, 3, 2}, 3 operations
  // Something like counting the gaps to between the MEX and c, the number of
  // operations that can be done without degenerating into an infinite loop.
  // c + 1 operations at most. Therefore, 2 elements, plus the largest one
  //
  // Lets try the case where the array can be converted first.
  // Combination of n and c determines whether part of the array is already
  // in the sequence.
  // If so, then the gradient determines how many. i.e., n divided
  // n = 11, b = 2, c = 1
  // {1, 3, 5, 7, 9, 11, ..., 21}
  // ceil((n - c) / b)
  // (100 - 1) / 2 = 49.5 = 50
  i64 n, b, c;
  std::cin >> n >> b >> c;

  // would go into infinite loop
  if (b == 0 && c + 2 < n) {
    std::cout << -1 << '\n';
    return;
  }

  // check if c >= n, if so, then n operations are required
  if (c >= n) {
    std::cout << n << '\n';
    return;
  }

  if (b == 0) {
    std::cout << n - 1 << '\n';
    return;
  }

  // otherwise, check the number of elements already in the sequence.
  int inSeq = ((n - 1) - c) / b;

  std::cout << n - 1 - inSeq << '\n';
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
