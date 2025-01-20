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
#include <ios>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
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

constexpr std::array<std::array<int, 2>, 4> directions{{
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
}};

void solve() {
  // sequence a consisting of n positive integers.
  // Any number of times:
  // - Select index i and subtract min(ai, ai+1) from both ai and ai+1
  //
  // Determine if a can be made non-decreasing (i.e,. equal or increasing).
  // Hm. if a[0] > a[i], then the sequence can not be made non-decreasing.
  // Therefore, check if the sequence a[i] <= a[i+1] will be sufficient?.
  // NOPE. Need to simulate the actual operation. i.e., if a[i] <= a[i+1],
  // then make a[i] == 0, a[i+1] -= a[i].
  // e.g.,
  // {4, 5, 2, 3}
  // {0, 1, 2, 3}
  // {0, 0, 1, 3}
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  for (int i = 0; i < n - 1; ++i) {
    if (a[i] <= a[i + 1]) {
      int x = std::min(a[i], a[i + 1]);
      a[i] -= x;
      a[i + 1] -= x;
      continue;
    }
  }

  for (int i = 0; i < n - 1; ++i) {
    if (a[i] > a[i + 1]) {
      std::cout << "NO\n";
      return;
    }
  }
  std::cout << "YES\n";
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
