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
constexpr int MOD = 998'244'353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> parent(n + 1);
  parent[1] = -1;
  std::vector<std::vector<int>> adj(n + 1);
  for (int i = 2; i <= n; ++i) {
    std::cin >> parent[i];
    adj[parent[i]].push_back(i);
  }

  std::queue<std::pair<int, i64>> frontier;
  frontier.emplace(1, 1);  // 1 way
  while (!frontier.empty()) {
    int sz = frontier.size();
    while (sz--) {
      auto [curr, count] = frontier.front();
      frontier.pop();
    }
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
