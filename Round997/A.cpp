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
  // m by m stamp on infinite paper.
  // Bottom left of stamp aligned with bottom left paper.
  // two sequences x and y, length n each.
  // for each i in [1..n]
  // 1. Move stamp xi units to right, yi units up.
  // 2. Press stamp, leaving m by m colored square.
  //
  // 1 <= xi, yi <= m-1
  //
  // There will be at most 2 squares overlapping, not 3.
  int n, m;
  std::cin >> n >> m;

  std::vector<std::pair<int, int>> v(n);
  for (auto& [x, y] : v) {
    std::cin >> x >> y;
  }
  // start at v[0].
  // each of the n squares, if no overlap will contribute m to the length.
  // The amount of overlap is then (m - xi) + (m-yi) (times 2 for 4 sides).
  // therefore, from the second square, determine overlap and minus from overall
  int sum = 4 * m * n;
  for (int i = 1; i < n; ++i) {
    int overlap = (m - v[i].first) + (m - v[i].second);
    sum -= 2 * overlap;
  }
  std::cout << sum << '\n';
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
