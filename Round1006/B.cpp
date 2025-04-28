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
  // numbers represented as string s of '-' and '_'
  // value represented by the string s is the number of distinct subsequences
  // of s that are equal to "-_-".
  // Rearrange characters in s to maximise the value.
  // Construction problem.
  // Alternating sequence? Note we are considering subsequences.
  int n;
  std::string s;
  std::cin >> n >> s;

  i64 dash = 0;
  i64 underscore = 0;
  for (char c : s) {
    dash += (c == '-');
    underscore += (c == '_');
  }

  // no valid subsequence at all.
  if (dash < 2 || underscore < 1) {
    std::cout << 0 << '\n';
    return;
  }

  i64 l = dash / 2;        // floor
  i64 r = (dash + 1) / 2;  // ceiling
  std::cout << (l * r * underscore) << '\n';
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
