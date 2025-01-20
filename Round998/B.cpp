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
  // n x m cards numbered from [0..n * m - 1]
  // Distribute m cards to each of n cows.
  // Fair => each cow plays 1 card per round.
  // Turn order determined by a permutation p of length n,
  // p[i] cow be the ith cow to place a card on top of the centre pile.
  //
  // Therefore, in each round:
  // p1 places any card
  // p2 places any card
  // ...
  // pn places any card.
  //
  // Initial card contains -1. To place a card, the number must be greater.
  // If a cow cannot place any card => lose.
  // Determine the permutation.
  // Small constraints n * m <= 2000
  //
  // Suppose the cards of each cow are sorted. Then the goal is to find an
  // order of rows such that column-wise, the cards are sorted in increasing
  // order.
  //
  int n, m;
  std::cin >> n >> m;

  // distinct.
  std::vector<std::pair<int, int>> cards(n * m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x;
      std::cin >> x;
      cards[i * m + j] = {x, i};
    }
  }

  std::sort(cards.begin(), cards.end());

  std::vector<int> permutation(n);
  for (int i = 0; i < n; ++i) {
    permutation[i] = cards[i].second;
  }

  // check permutation is repeating.
  for (int i = n; i < n * m; ++i) {
    if (cards[i].second != permutation[i % n]) {
      std::cout << -1 << '\n';
      return;
    }
  }

  for (int i : permutation) {
    std::cout << i + 1 << ' ';
  }
  std::cout << '\n';
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
