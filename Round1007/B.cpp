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
  // perfect permutation of length n if
  // sum of first i elements is not a perfect square.
  // Construction
  // prolly need to insert 1 somewhere strategic.
  // Need to handle the first pythagorean triple.
  int n;
  std::cin >> n;

  // if the entire prefix is a square, then not possible.
  auto isSumSquare = [](i64 i) {
    i64 sum = i * (i + 1) / 2;
    i64 root = std::sqrt(sum);
    return root * root == sum;
  };

  if (isSumSquare(n)) {
    std::cout << -1;
  } else {
    // some permutation exists. But need to avoid intermediate prefixes
    // that sum to a square.
    // maintain running prefix?
    i64 i = 1;
    while (i <= n) {
      if (isSumSquare(i)) {
        // guaranteed to have at least 1 ahead.
        std::cout << i + 1 << ' ' << i << ' ';
        i += 2;
      } else {
        std::cout << i << ' ';
        ++i;
      }
    }
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
