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
#include <ios>
#include <iostream>
#include <istream>
#include <iterator>
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

constexpr int MOD = 1'000'000'007;

constexpr std::array<std::array<int, 2>, 4> directions{{
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
}};

void solve() {
  // tree of n vertices => n-1 edges.
  // Perform twice:
  // - Select a vertex v and remove all edges incident to v, and the vertex v.
  // Find maximum number of connected components after performing twice.
  //
  // Hm.
  // Removing a parent always result in two connected components?
  // Not always, components may be empty. Also, that is for a Binary Tree...
  // Remove the node with most edges? i.e., degree.
  // Then count the number of components remaining. How though?
  // Set degree to -1. Then count >= 0 only.
  int n;
  std::cin >> n;

  std::vector<std::vector<int>> adj(n);
  std::vector<int> degree(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u, --v;

    adj[u].push_back(v);
    adj[v].push_back(u);
    ++degree[u];
    ++degree[v];
  }

  int components = 1;
  int first = std::max_element(degree.begin(), degree.end()) - degree.begin();
  components = components - 1 + degree[first];
  degree[first] = -1;
  for (int next : adj[first]) {
    --degree[next];
  }

  int second = std::max_element(degree.begin(), degree.end()) - degree.begin();
  components = components - 1 + degree[second];

  std::cout << components << '\n';
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
