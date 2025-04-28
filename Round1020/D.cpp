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

constexpr int INF = 2e9;

void solve() {
  // n flowers, integer sequence ai
  // walk left to right to collect m flowers exactly.
  // The ith flower collected must have at least beauty bi
  //
  // Might be impossible to satisfy m flower collected.
  // Perform single operation: grow a new flower of beauty k anywhere.
  // Naively,
  // for each i in B, decide whether to grow or find a flower that can fulfil.
  // O(mn) minimally.
  //
  // nextGreater[i] = j, where A[j] >= B[i], j is the leftmost.
  int n, m;
  std::cin >> n >> m;

  std::vector<int> A(n), B(m);
  for (int i = 0; i < n; ++i) {
    std::cin >> A[i];
  }
  for (int i = 0; i < m; ++i) {
    std::cin >> B[i];
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
