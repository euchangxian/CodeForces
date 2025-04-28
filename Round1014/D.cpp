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
  // string s of length n,
  // s[i] = L | I | T
  // Each operation:
  // - choose i such that s[i] != s[i+1]
  // - Insert x where x is the third character != s[i] != s[i+1].
  //
  // s is balanced if it has equal number of all substances.
  // Perform no more than 2n operations, or report impossible.
  // Count LT and TL sequences: Can increment I, and either T or L
  // Count LI and IL sequences: Can increment T, and either I or L
  // Count IT and TI sequences: Can increment L, and either I or T
  // sum must be equal.
  //
  // let x <= y <= z be the count.
  // Then, if x==y, can pick the pattern containing XZ/ZX or YZ/ZY until equal z
  //       if x<y<z, pick the patterns YZ/ZY until equal. This adds the
  //                 patterns YX and XZ.
  //                 Then, handle x==y < z case.
  //       if x<y==z, then pick YZ/ZY only.
  int n;
  std::string s;
  std::cin >> n >> s;

  std::array<int, 256> count{};
  for (int i = 0; i < n; ++i) {
    ++count[s[i]];
  }

  int lcm = std::lcm(std::lcm(count['L'], count['I']), count['T']);
  if (lcm - std::min({count['L'], count['I'], count['T']}) > 2 * n) {
    std::cout << -1 << '\n';
    return;
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
