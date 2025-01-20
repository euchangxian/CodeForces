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
  // n days
  // Monocarp solve ai problems. Train on any day.
  // Stereocarp solve bi problems. If Monocarp trains on the ith day and
  // i + 1 < n, then Stereocarp trains on (i+1) day.
  // Wants to maximise (m - s).
  // Hmmm. Greedy? Monocarp trains on days i such that a[i] > b[i+1], and the
  // last day.
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  std::vector<int> b(n);
  for (int& i : a) {
    std::cin >> i;
  }
  for (int& i : b) {
    std::cin >> i;
  }

  int maxDiff = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (a[i] > b[i + 1]) {
      maxDiff += a[i] - b[i + 1];
    }
  }
  std::cout << maxDiff + a.back() << '\n';
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
