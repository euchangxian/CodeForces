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

void solve() {
  // binary string of length n, typewriter with two buttons 0 and 1
  // initially at button 0.
  // operations:
  // - press button to type out the value.
  // - move to other button.
  // cost of binary string : min ops to type the string.
  //
  // Reverse at most one substring to find the minimum cost obtainable.
  // We want to avoid the second operation. Thus, if we remove one such ops,
  // then that string is minimum.
  // find the first '1', and the last '0', reverse.
  // then take the cost.
  //
  // Need to be more granular.
  // Reversing the substring can potentially remove two "button-move"
  // operations.
  // If the substring has opposite ends.
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;

  int cost = 0;
  int curr = 0;
  int switches = 0;
  for (char c : s) {
    if (c - '0' == curr) {
      ++cost;
    } else {
      ++switches;
      curr = 1 - curr;
      cost += 2;
    }
  }

  if (switches >= 3) {
    std::cout << cost - 2 << '\n';
  } else if (switches == 2) {
    std::cout << cost - 1 << '\n';
  } else {
    std::cout << cost << '\n';
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
