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
  // Points on two horizontal lines, y=0 and y=2
  // e.g., (a, 0), ... (b, 2), ...
  //
  // In one operation:
  // - Pick three distinct points that are not collinear, i.e., at least one
  //   from each y=0|2
  // - Increase score by the area of the triangle formed, 1/2 * b * h.
  //   i.e., just base, since h = 2 always.
  // - Erase the three points picked.
  //
  // k_max is the maximum number of operations that can be performed.
  // f(k) is the maximum score achievable by performing the operation k times.
  //
  // Output k_max, and values of f(k) for all k=1,2,...k_max.
  //
  // k_max should be trivial (relative to f(k)...) to find, reducible to a
  // formula?
  //
  // To maximise f(k), each operation should pick two points on the same line
  // that are as far apart as possible.
  // However, since the third point would lie on the other line, where we may
  // need to pick two points from in the next operation, this choice is not
  // arbitrary (again, it depends on whether there is a need to optimize the
  // choices here...)
  // e.g.,
  // a = {0, 200}
  // b = {-100, -50, 0, 50}
  //
  // k_max = 2,
  // f(1) => pick (0, 0), (200, 0) and any point on y=2.
  // f(2) => pick (-100, 2), (50, 2) and any point on y=0.
  //         pick (-50, 2), (0, 2) and any point on y=0
  int n, m;
  std::cin >> n >> m;

  // points on y=0 and y=2 respectively.
  std::vector<i64> a(n), b(m);
  for (i64& x : a) {
    std::cin >> x;
  }
  for (i64& x : b) {
    std::cin >> x;
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
