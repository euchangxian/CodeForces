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
  // want: nth row of Great Magical Triangle.
  //
  // Defined as:
  // - ith row has i integers
  // - base case: 1st row integer is k
  // - let jth element be denoted as Tij, then,
  //       t[i-1][j-1] XOR t[i-1][j] if 1 < j < i (XOR adjacent elements)
  // Tij = t[i-1][j]                 if j = 1 (first element is previous first)
  //       t[i-1][j-1]               if j = i (last element is previous last)
  //
  // can just DP?
  // Need O(N), though.
  // Can we figure out based on XOR properties?
  // Yeah, parity based question i believe, given XOR toggles.
  // row2 = [k, k]
  // row3 = [k, k^k, k]
  // row4 = [k, (k^k)^k == k, (k^k)^k == k, k]
  // row5 = [k, ((k^k)^k)^k == 0, (k^k)^k ^ (k^k)^k == 0, ((k^k)^k)^k == 0, k]
  //      = [k, 4k, 6k, 4k, k]
  // row6 = [k, 5k, 10k, 10k, 5k, k]
  // row7 = [k, 6k, 15k, 20k, 15k, 6k, k]
  int n, k;
  std::cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    bool isOddCoeff = ((n - 1) & i) == i;
    std::cout << (isOddCoeff ? k : 0) << ' ';
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
