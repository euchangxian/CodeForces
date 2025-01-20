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
  // find max, take difference between k? Not so simple. May not even need to
  // add. Sort, start taking from max element. if exceed, then remove that
  // element and take the difference.
  int n, k;
  std::cin >> n >> k;

  std::vector<int> arr(n);
  for (int& a : arr) {
    std::cin >> a;
  }
  std::sort(arr.rbegin(), arr.rend());

  int sum = 0;
  for (int a : arr) {
    sum += a;

    if (sum == k) {
      std::cout << 0 << '\n';
      return;
    }

    if (sum > k) {
      sum -= a;
      break;
    }
  }

  std::cout << k - sum << '\n';
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
