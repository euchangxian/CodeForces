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
#include <sstream>
#include <stack>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using i64 = long long;
constexpr int MOD = 1'000'000'007;

// need offset, too
std::pair<i64, i64> coords(i64 N, i64 D) {
  if (N == 0) {
    return {1, 1};
  }

  if (N == 1) {
    if (D == 1) {
      return {1, 1};
    }
    if (D == 2) {
      return {2, 2};
    }
    if (D == 3) {
      return {2, 1};
    }
    if (D == 4) {
      return {1, 2};
    }
  }
  // Size calculations
  i64 quarter = 1LL << (2 * (N - 1));  // 4^(n-1)
  i64 half = 1LL << (N - 1);           // 2^(n-1)

  if (D <= quarter) {
    return coords(N - 1, D);
  }

  if (D <= 2 * quarter) {
    auto [x, y] = coords(N - 1, D - quarter);
    return {x + half, y + half};
  }

  if (D <= 3 * quarter) {
    auto [x, y] = coords(N - 1, D - 2 * quarter);
    return {x + half, y};
  }

  // otherwise
  auto [x, y] = coords(N - 1, D - 3 * quarter);
  return {x, y + half};
}

i64 findDigit(i64 N, i64 x, i64 y) {
  if (N == 0) {
    return 1;
  }

  if (N == 1) {
    if (x == 1 && y == 1) {
      return 1;
    }
    if (x == 2 && y == 2) {
      return 2;
    }
    if (x == 2 && y == 1) {
      return 3;
    }
    if (x == 1 && y == 2) {
      return 4;
    }
  }

  i64 half = 1LL << (N - 1);           // 2^(n-1)
  i64 quarter = 1LL << (2 * (N - 1));  // 4^(n-1)

  if (x <= half && y <= half) {
    // topLeft
    return findDigit(N - 1, x, y);
  } else if (x > half && y > half) {
    // bottomRight
    return findDigit(N - 1, x - half, y - half) + quarter;
  } else if (x > half && y <= half) {
    // bottomLeft
    return findDigit(N - 1, x - half, y) + 2 * quarter;
  } else {
    // topRight
    return findDigit(N - 1, x, y - half) + 3 * quarter;
  }
}

void solve() {
  // 1. Top Left
  // 2. Bottom Right
  // 3. Bottom Left
  // 4. Top Right
  //
  // Two types of queries: what number at row x, col y
  //                       which (r, c) is number d at
  //
  // WE can determine which quadrant, recursively.
  // first 2^n will be in the top-left, second bottom left, ...
  // Doing this 30*20,000 times is sufficient
  i64 n, q;
  std::cin >> n >> q;

  while (q--) {
    std::string op;
    std::cin >> op;
    if (op == "->") {
      i64 x, y;
      std::cin >> x >> y;
      std::cout << findDigit(n, x, y) << '\n';
      // std::cout << findDigit(n, x, y) << std::endl;

    } else {
      i64 d;
      std::cin >> d;

      auto [x, y] = coords(n, d);
      std::cout << x << ' ' << y << '\n';
      // std::cout << x << ' ' << y << std::endl;
    }
  }
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
