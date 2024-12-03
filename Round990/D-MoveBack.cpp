#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <deque>
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
  // array of integers a, of length n.
  // perform any times:
  //   choose ai, increment and move to the back of the array.
  //
  // find lexicographical smallest
  // If there were no increment, then sorting it works.
  //
  // Hm... How do i prove that the current array is the lexicographically
  // smallest, and most optimal.
  //
  // The key is that we can form a sorted order of moved values.
  // We can first collect out-of-place values?
  // How do we determine if a value is out-of-place.
  int n;
  std::cin >> n;
  std::vector<int> arr(n);
  for (int& a : arr) {
    std::cin >> a;
  }

  std::vector<char> needToMove(n);  // bool flag
  std::vector<int> moved;
  moved.reserve(n);

  // first pass: Check if an element is greater than anything on the right.
  // If so, then we know that this element must be moved to the back.
  int currMin = INT_MAX;
  for (int i = n - 1; i >= 0; --i) {
    if (arr[i] > currMin) {
      needToMove[i] = true;
      moved.push_back(arr[i] + 1);
    }

    currMin = std::min(currMin, arr[i]);
  }

  currMin = INT_MAX;
  for (int i = 0; i < n; ++i) {
    if (needToMove[i]) {
      // adjust the value, since this number would be at the back.
      currMin = std::min(currMin, arr[i] + 1);
    } else if (arr[i] > currMin) {
      needToMove[i] = true;
      moved.push_back(arr[i] + 1);
    }
  }

  std::sort(moved.begin(), moved.end());

  for (int i = 0; i < n; ++i) {
    if (!needToMove[i]) {
      std::cout << arr[i] << ' ';
    }
  }
  for (int m : moved) {
    std::cout << m << ' ';
  }
  std::cout << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tc;
  std::cin >> tc;

  while (tc--) {
    solve();
  }

  return 0;
}
