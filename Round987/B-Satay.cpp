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
  // seems like bubble sort. Swap adjacent if difference is equal to 1.
  // What would make it unsortable?
  // Something like partitioning the array into subarrays such that adjacent
  // elements within differ by at most 1.
  // Then, for each adjacent partition, check the max of the previous subarray
  // and the minimum of the current subarray differs by 1.
  // Nope. Fails on basic TC {4, 3, 2, 1}.
  // Hmmmm. Notice that each element can be swapped at most once?
  // Are we able to prove it?
  // If we use this property, then if the element is more than 1 unit away from
  // its sorted position, we can return false?
  // {4, 3, 2, 1} => false
  // {2, 1, 3, 4} => true
  int n;
  std::cin >> n;

  std::vector<int> p(n);
  for (int& x : p) {
    std::cin >> x;
  }

  for (int i = 0; i < n; ++i) {
    int expectedPos = p[i] - 1;

    if (std::abs(expectedPos - i) > 1) {
      std::cout << "NO" << '\n';
      return;
    }
  }

  std::cout << "YES" << '\n';
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
