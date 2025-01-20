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

std::pair<i64, i64> getRangeSums(std::span<i64> a) {}

void solve() {
  // Find two integers l <= A <= B <= r such that their GCD is G and |A-B| is
  // maximised.
  //
  // Seeing ranges like this feels like Binary Search. constraints does
  // indeed seem like logn is required.
  i64 l, r, G;
  std::cin >> l >> r >> G;
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
