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

void solve() {
  // n: floor ops
  // m: ceiling ops
  int x, n, m;
  std::cin >> x >> n >> m;

  // clamp the values
  n = std::min(n, 32);
  m = std::min(m, 32);

  // min value
  auto ceilThenFloor = [n, m](int x) -> int {
    for (int i = 0; i < m; ++i) {
      x = (x + 1) >> 1;
    }

    for (int i = 0; i < n; ++i) {
      x >>= 1;
    }
    return x;
  };

  // if upper m bits have a 1, then this will give the max value.
  auto floorThenCeil = [n, m](int x) -> int {
    for (int i = 0; i < n; ++i) {
      x >>= 1;
    }

    for (int i = 0; i < m; ++i) {
      x = (x + 1) >> 1;
    }
    return x;
  };

  std::cout << ceilThenFloor(x) << ' ' << floorThenCeil(x) << '\n';
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
