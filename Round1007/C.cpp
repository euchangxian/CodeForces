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

bool dfs(const std::vector<std::vector<int>>& adj,
         int current,
         int end,
         std::vector<bool>& seen,
         std::vector<bool>& onPath,
         std::vector<int>& path) {
  seen[current] = true;

  if (current == end) {
    return true;
  }

  for (int next : adj[current]) {
    if (seen[next]) {
      continue;
    }

    path.push_back(next);

    if (dfs(adj, next, end, seen, onPath, path)) {
      onPath[next] = true;
      return true;
    }

    // backtrack if not correct path.
    path.pop_back();
  }

  return false;
}

void dfsNonPath(const std::vector<std::vector<int>>& adj,
                int current,
                const std::vector<bool>& onPath,
                std::vector<bool>& seen) {
  seen[current] = true;

  if (!onPath[current]) {
    std::cout << current << ' ';
  }

  // Visit all unseen neighbors
  for (int next : adj[current]) {
    if (!seen[next]) {
      dfsNonPath(adj, next, onPath, seen);
    }
  }
}

void solve() {
  // Start at vertex st on a given tree with n vertices.
  //
  // permutation p of length n, n steps.
  // for the ith step:
  // - parmesan cheese at vertex pi. If the mouse is at pi, eat it.
  //   otherwise, move along the simple path to pi by 1 edge.
  //
  // Find a permutation pi such that after all n steps, mouse arrives at
  // vertex en. May be earlier than n steps.
  //
  // A tree. Only 1 path between all pair of nodes.
  // Given tree!!!
  // DFS? from start to end?? why would this not trivially work??
  int n, start, end;
  std::cin >> n >> start >> end;

  std::vector<std::vector<int>> adj(n + 1);
  // n-1 edges.
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  std::vector<bool> seen(n + 1, false);
  std::vector<bool> onPath(n + 1, false);
  std::vector<int> path;
  path.reserve(n);
  path.push_back(start);

  onPath[start] = true;
  dfs(adj, start, end, seen, onPath, path);

  std::fill(seen.begin(), seen.end(), false);
  dfsNonPath(adj, start, onPath, seen);

  for (int node : path) {
    std::cout << node << ' ';
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
