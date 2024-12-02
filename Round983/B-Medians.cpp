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
  // Given a = [1..n], where n is odd, and k.
  // Choose odd integer m, split a into m subarrays b1, b2, .. bm, such that
  // - each element of a belongs to exactly one subarray
  // - for all 1 <= i <= m, |bi| is odd, i.e, length of subarrays is odd.
  // - median([median(b1), median(b2), ..., median(bm)]) = k. I.e, the median
  //   of the array of all medians is equal to k.
  //
  // Sum of n over all test cases does not exceed 2*10^5 => n^2 solution or btr.
  //
  // output:
  // - an odd integer m, (1 <= m <= n).
  // - m distinct integers p1, p2, p3, ... pm, where each p denotes the left
  //   borders of each subarray!!! important hint. To determine where to split.
  //   1 = p1  < p2 < p3 < ... < pm <= n, i.e., sorted order starting from 1.
  //
  // Notice, since we are splitting a sorted array into subarrays of odd length
  // only, the median of the resultant subarrays can be deduced. The median
  // increases by 1 for every 2 elements added. LMAO. This "insight" is useless.
  // Instead of that, we can determine the median based off the start of the
  // subarray and the length. I.e., median = start + (len-1)/2;
  // This still does not help us though.
  //
  // How do we decide on the sizes of each subarray? This has to be related to
  // k.
  // I think there is some sort of binary search, given we have to choose m, the
  // number of subarrays.
  // This is because the more splits are done, i.e., for n = 15, we can have
  // m = [1, 3, 5, 15] // split 1 and split m = n is the same.
  // if we split into 3 subarrays, there can be multiple combinations of sizes:
  // [5, 5, 5], [7, 7, 1], [3, 3, 9], [1, 3, 11], [1, 5, 9]...
  // But does the combinations matter? The resulting median be the centre of
  // the middle subarray. Therefore, by adjusting the number of elements in the
  // first subarray, we can effectively shift the median. The individual
  // elements within do not matter.
  //
  // The effect of this means that there is a maximum possible median (still
  // pretty high). For n = 15, the medians possible are 8 (split m = 1),
  // split m = 3 => {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}
  // the middle array can be one of [1, 3, 5, 7, 9, 11, 13].
  // By adjusting the first array, we adjust the offsets too, widening the range
  // of medians.
  // The medians that are unattainable are when all but the middle subarray is
  // of length 1. i.e., the smaller the split, the wider the range (except m=n).
  //
  // Okay. So now we have something to work on?
  // We can always attain a 3-split?? odd + odd + odd = n (n is odd).
  // That means we can always attain most of the medians except the first and
  // last.
  int n, k;
  std::cin >> n >> k;

  // Edge case, n = 1.
  if (n == 1) {
    std::cout << 1 << '\n';
    std::cout << 1 << '\n';
    return;
  }

  if (k == 1 || k == n) {
    std::cout << -1 << '\n';
    return;
  }

  // For a 3-split, determine the number of elements necessary in the first
  // subarray
  std::cout << 3 << '\n';
  if (k & 1) {
    // odd-k case, middle subarray must be odd.
    std::cout << 1 << ' ' << k - 1 << ' ' << k + 2 << '\n';
  } else {
    // even-k case, middle subarray can be size 1, the target median.
    std::cout << 1 << ' ' << k << ' ' << k + 1 << '\n';
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
