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
  // n integers, x1, x2, ..., xn (n is even)
  // integer k,
  // integer score = 0.
  // n/2 turns.
  //
  // each turn:
  // 1. Alice erases an integer a
  // 2. Bob erases an integer b
  // 3. If a + b == k, score+=1.
  //
  // Alice is minimizing, Bob is maximizing. Assume optimal.
  // n <= 2*10^5, 1 <= k <= 2 * n
  //
  // Alice wants to pick a integer for which no complements exists.
  // Bob will pick the complement, or pick the number for which no complements
  // exist.
  // Finding the no-complement/complement is abit costly though?
  // Wait, there is no need to keep track of the actual number, just the
  // number of complements and no-complements.
  //
  // Okok.
  // score == complements.
  int n, k;
  std::cin >> n >> k;

  std::vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> v[i];
  }

  // twosum!!!
  std::unordered_multiset<int> seen;
  int complements = 0;
  for (int i = 0; i < n; ++i) {
    if (seen.find(k - v[i]) != seen.end()) {
      ++complements;
      seen.extract(k - v[i]);
      continue;
    }
    seen.insert(v[i]);
  }

  std::cout << complements << '\n';
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
