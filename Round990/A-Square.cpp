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
  // n days, 1 <= n <= 100.
  // First day, place central piece.
  // Subsequent days: spiral clockwise, finish each square layer, before
  // starting the next one.
  // At the end of the n day, no unfinished layer.
  //
  // Happy if the puzzle does not have any started but unfinished layers.
  // Find number of happy days.
  // First day: square size 1
  // 2nd to 9th day: 9 pieces.
  // {1, 3, 5, 7, ...}
  int n;
  std::cin >> n;

  std::vector<int> arr(n);
  for (int& a : arr) {
    std::cin >> a;
  }

  int pieces = 0;
  int happy = 0;
  int k = 1;  // next square size.

  for (int i = 0; i < n; ++i) {
    pieces += arr[i];

    while (pieces >= k * k) {
      if (pieces == k * k) {
        ++happy;
      }
      k += 2;
    }
  }

  std::cout << happy << '\n';
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
