#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <ranges>
#include <set>
#include <span>
#include <stack>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using i64 = long long;
constexpr int MOD = 1'000'000'007;

i64 count(const std::vector<int>& nums, int l, int r) {
  i64 gain = 0;
  for (int i = l; i <= r; ++i) {
    if (nums[i] < nums[l]) {
      ++gain;
    } else if (nums[i] > nums[l]) {
      --gain;
    }
  }
  return gain;
}

void solve() {
  // minimize number of inversions after applying spell exactly once.
  // choose l, r and shift the subarray to the left (cyclic).
  // seems like prefix suffix. Something like find the element that has the
  // most number of smaller elements to its right.
  // Thats for picking l.
  // How to pick r?
  // the last element that is smaller than nums[l]?
  // To count smaller, fenwick tree, or just brute force.
  // Given ai <= 2000, fenwick trees work easily.
  //
  // Wait. consider the effects of the shift.
  // If the number of elements bigger to the right is greater, then the effect
  // of the shift may be negative.
  // The net shift is thus suffixSmaller[l] - suffixGreater(l, r)
  // where we want to minimize the suffixGreater.
  // We can brute force that given small constraints.
  //
  // Hm, think this is to determine r.
  // i.e., [l, r] such that nums[i] < nums[l] is maximised and vice versa.
  int n;
  std::cin >> n;
  std::vector<int> nums(n);
  for (int& x : nums) {
    std::cin >> x;
  }

  bool sorted = std::is_sorted(nums.begin(), nums.end());
  if (sorted) {
    std::cout << "1 1\n";
    return;
  }

  int bestL = 0;
  int bestR = 0;
  i64 bestGains = LLONG_MIN;
  for (int l = 0; l < n; ++l) {
    std::vector<int> smaller(n);
    std::vector<int> greater(n);
    smaller[l] = 0, greater[l] = 0;
    for (int i = l + 1; i < n; ++i) {
      smaller[i] = smaller[i - 1] + (nums[i] < nums[l]);
      greater[i] = greater[i - 1] + (nums[i] > nums[l]);
    }
    for (int r = l + 1; r < n; ++r) {
      i64 gain = smaller[r] - greater[r];
      if (gain > bestGains) {
        bestGains = gain;
        bestL = l;
        bestR = r;
      }
    }
  }
  std::cout << bestL + 1 << ' ' << bestR + 1 << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tc{1};
  std::cin >> tc;

  while (tc--) {
    solve();
  }

  return 0;
}
