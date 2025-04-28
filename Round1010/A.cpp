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
  // Binary matrix n * m
  int n, m;
  std::cin >> n >> m;

  std::vector<std::string> grid(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> grid[i];
  }

  // count rows/cols with XOR sum == 1
  int row = 0;
  int col = 0;

  for (int r = 0; r < n; ++r) {
    int rowXOR = 0;
    for (int c = 0; c < m; ++c) {
      rowXOR ^= grid[r][c] - '0';
    }
    row += rowXOR;
  }

  for (int c = 0; c < m; ++c) {
    int colXOR = 0;
    for (int r = 0; r < n; ++r) {
      colXOR ^= grid[r][c] - '0';
    }
    col += colXOR;
  }

  std::cout << std::max(row, col) << '\n';
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
