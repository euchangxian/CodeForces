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
  // two player compete, third watches.
  // no playing three times in a row.
  // play twice -> sit out in third.
  // winner stays, loser out.
  // given k, determine if spectator of first match can be spectator in kth
  // match.
  // Spectator has to be swapped in every second round.
  // Not exactly.
  // If ev
  // 2nd: swap in
  // 3rd: win | lose
  // 4th: spectate
  // THE two-wins rule. Troublesome. Some branchses are invalid.
  // DRAW till depth=4
  // pattern repeats every 4th round.
  // can spectate in 1st, 4th
  int k;
  std::cin >> k;

  bool can = (k % 3) == 1;

  std::cout << (can ? "YES" : "NO") << '\n';
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
