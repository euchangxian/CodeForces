#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <ios>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using i64 = long long;

void solve() {
  // n rows of m people.
  // numbered starting from [1..m] inclusive.
  // person at (r, c) (1-indexed) leaves. Every person to the right, in
  // 1D coordinates will move left (in 1D).
  // output a single integer denoting the sum of manhanttan distances
  // dist = |r0 - r1| + |c0 - c1|
  i64 n, m, r, c;
  std::cin >> n >> m >> r >> c;

  // sum manhanttan distances of people to the right (in 1D coordinates)
  // notice, same row just move left one unit each.
  // for each subsequent row, the leftmost will go up to become the rightmost
  // i.e., +m
  // the others would move left.
  i64 sum = 0LL;
  sum += m - c;              // each person move left
  sum += (m - 1) * (n - r);  // each subsequent row, m-1 people move left.
  sum += m * (n - r);        // each subsequent row, leftmost move to up, right
  std::cout << sum << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tc;  // Number of test cases
  std::cin >> tc;

  while (tc--) {
    solve();
  }

  return 0;
}
