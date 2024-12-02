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
  // Construct of permutation p of integers 1,2,...,n that maximises the value
  // of k (which is initially 0) with the operations
  // Perform n operations. On the ith operation (i = 1, 2, ..., n)
  // - if i is odd, k = k & pi
  // - if i is even, k = k | pi
  //
  // AND operations will preserve or reduce set bits.
  // OR operations will preserve or increase set bits.
  // What about greedily alternating? Set bits are maximised with 2^i - 1.
  // Suppose n is a power of 2 though, can we preserve the leftmost bit? i.e.,
  // OR operation with n as the last operation. Trivially, yes, lol.
  // So the aim is to maximise the last few operations? I.e., if n is a power of
  // 2, then
  // ...
  // k |= some odd number // set the LSB.
  // k &= some odd number // retain the LSB
  // k |= n - 2 // sets every bit except the least significant bit.
  // k &= n - 1 // retains every set bit.
  // k |= n // sets leftmost bit.
  // Sounds sound...? Especially, given the constraints 5 <= n
  // For non-powers of 2, it seems like the parity of n needs to be taken into
  // account.
  // The subsequent numbers that are greater than the largest power of 2,
  // have the leftmost bits, and the rightmost bits set.
  // i.e., 9 = 1001, 10 = 1010, 11 = 1011, 12 = 1100, ...
  //
  // Thus, for odd parities, the process ends with an AND. However, we want to
  // retain the leftmost bit. Thus, it seems we must end with n, k &= n.
  // this results in the maximum being just n.
  //
  // For even parities, the previous rule can be followed.
  int n;
  std::cin >> n;

  if (n & 1) {
    // For odd parities, end with n. therefore just output a linear array
    std::cout << n << '\n';
    for (int i = 1; i <= n; ++i) {
      std::cout << i << ' ';
    }
    std::cout << '\n';
    return;
  }

  // Even parities, first reserve the last 5 numbers. For simplicity, determine
  // the largest power of 2.
  int msbPos = 32 - __builtin_clz(n) - 1;  // minus 1 because we want 0-indexed.
  int largestPowerOf2 = 1 << msbPos;

  // Output maximum, where every bit up till 2^i is set.
  int maximum = largestPowerOf2 * 2 - 1;
  std::cout << maximum << '\n';

  std::vector<int> perm(n, 0);
  // Guaranteed to work on the smallest input size of n = 5, {1, 5, 2, 3, 4}
  perm[n - 1] = largestPowerOf2;      // OR
  perm[n - 2] = largestPowerOf2 - 1;  // AND
  perm[n - 3] = largestPowerOf2 - 2;  // OR
  perm[n - 4] = 5;                    // AND
  perm[n - 5] = 1;                    // OR

  int next = 2;
  for (int i = 0; i < n - 5; ++i) {
    while (next == 5 || next == largestPowerOf2 ||
           next == largestPowerOf2 - 1 || next == largestPowerOf2 - 2) {
      ++next;
    }
    perm[i] = next;
    ++next;
  }

  int k = 0;
  for (int i = 1; i <= n; ++i) {
    if (i % 2 == 0) {
      k |= perm[i - 1];
    } else {
      k &= perm[i - 1];
    }

    std::cout << perm[i - 1] << ' ';
  }
  std::cout << '\n';

  if (k != maximum) {
    std::cout << "WTF k: " << k << '\n';
  }
  return;
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
