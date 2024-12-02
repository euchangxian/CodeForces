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
  // Hm. The complicated equation ax + ay > az, ay + az > ax and az + ax > ay
  // is really just the triangle inequality. Put into words, it just means that
  // if the sum of the two shortest sides of the triangle is greater than the
  // largest side, then the triangle is non-degenerate.
  //
  // Therefore, what we can do is sort the array. sum the two minimum and
  // compare it against the largest.
  // Initially thought the minimum operations can be binary searched, with an
  // O(n) isFeasible check.
  // But that does not account for the "direction" of the operation, whether to
  // assign the smaller number or the larger number.
  //
  // REDUCE THE PROBLEM........
  // "Given a sorted array nums, find the largest subarray in which the first
  // two numbers in the subarray are larger than the last number in the
  // subarray."
  int n;
  std::cin >> n;

  // long long to avoid overflow when summing.
  std::vector<i64> nums(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> nums[i];
  }
  std::sort(nums.begin(), nums.end());

  int maxSize = 0;
  // expand two pointers from left
  size_t r = 2;
  for (size_t l = 0; l < n - 2; ++l) {
    while (r < n && nums[l] + nums[l + 1] > nums[r]) {
      ++r;
    }

    // no need +1, since r is already over-incremented by 1
    maxSize = std::max(maxSize, static_cast<int>(r) - static_cast<int>(l));
  }

  // minOps = n - maxSize
  std::cout << n - maxSize << '\n';
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
