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
  // n marbles. colors c[i]
  // Alice -> Bob -> Alice ...
  // Take one marble and remove. If there are no marbles left, game ends.
  //
  // Alice score:
  // - 1 point for every distinct color x.
  // - 1 point for every color that Alice takes completely.
  //
  // Suppose both players play optimally. Calculate Alice's score at the end.
  // Wow... minimax. Seems like dfs??
  //
  // No need for simulation. This is maffs.
  //
  // NOTE: tapped out.
  // Consider the total count of colors. If a certain color is only 1, then
  // either side will want to take it.
  // Thus, let the number of distinct colors with only one marble be x.
  // Alice will be able to get ceil(x/2) points * 2 (for taking the whole color)
  // while Bob will be able to get floor(x/2) of the marbles. (x2 for points)
  // Ceil for Alice, since Alice starts first.
  // Next, we want to consider colors with >1 marbles.
  // Starting small, suppose we have 3 marbles of the same color.
  // Alice takes 1, Bob takes 1, Alice takes the last. In any case, neither
  // Alice, nor Bob will be able to take the complete set if both players are
  // playing optimally.
  // Thus, let the number of colors where there are >1 marbles be y.
  // Alice can obtain y points from these set of colors.
  // Therefore, the total number of points obtainable by Alice is
  // 2 * ceil(x/2) + y.
  int n;
  std::cin >> n;

  std::vector<int> count(n, 0);
  for (int i = 0; i < n; ++i) {
    int color;
    std::cin >> color;

    ++count[color - 1];
  }

  int onlyOne = 0;
  int gtOne = 0;
  for (int c : count) {
    onlyOne += c == 1;
    gtOne += c > 1;
  }

  std::cout << 2 * ((onlyOne + 1) / 2) + gtOne << '\n';
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
