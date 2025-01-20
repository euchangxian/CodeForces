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

class UnionFind {
 private:
  int components;

  std::vector<int> parent;
  std::vector<int> rank;

 public:
  UnionFind(int n) : parent(n), rank(n, 0), components(n) {
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }
  }

  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }

    return parent[x];
  }

  bool connected(int x, int y) { return find(x) == find(y); }

  void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY) {
      return;
    }

    --components;
    if (rank[rootX] < rank[rootY]) {
      parent[rootX] = rootY;
      return;
    }

    if (rank[rootX] == rank[rootY]) {
      ++rank[rootX];
    }
    parent[rootY] = rootX;
  }

  int size() { return components; }
};

void solve() {
  // two undirected graphs F and G with n vertices.
  // F has m1 edges, G has m2 edges.
  //
  // Any number of times, do one of these:
  // - Select two integers u and v such that there is an edge between u and v
  //   in F. Remove that edge.
  // - Select two integers u and v such that there is NO edge between u and v
  //   in F. Add that edge.
  //
  // Determine min number of operations such that for all u and v, there is a
  // path from u to v in F, IF AND ONLY IF there is a path from u to v in G.
  //
  // i.e., G is our reference Graph. We need to remove edges that are in F
  // but not G, and add edges in G but not in F.
  // NOT EXACTLY. We want PATHS. i.e., connectivity.
  // if u and v are connected via some intermediate node in G, but F is not,
  // then we need to add some edges.
  // sum of n, m1 and m2 <= 2 * 10^5
  //
  // Given that we want connectivity, and not shortest paths? UnionFind?
  // But we do want the minimum number of operations though.
  // UnionFind can only help us determine YES/NO operations are needed.
  //
  // Not sure... Graph could be complex.
  // HMM. what about Trees? i.e., number of edges == n-1??
  //
  // I.e., How do we determine if an indirect edge should be added/removed?
  // and would an indirect edge result in a smaller number of ops?
  //
  // weeeew this seems like a MIN-CUT kind of problem to separate components.
  int n, m1, m2;
  std::cin >> n >> m1 >> m2;

  std::vector<std::pair<int, int>> edges1(m1);
  std::vector<std::pair<int, int>> edges2(m2);
  for (auto& [u, v] : edges1) {
    std::cin >> u >> v;
    --u, --v;  // 1-indexed to 0-indexed.
  }
  for (auto& [u, v] : edges2) {
    std::cin >> u >> v;
    --u, --v;
  }

  UnionFind G(n);
  for (auto [u, v] : edges2) {
    G.unite(u, v);
  }

  int toAdd = 0;
  int toRemove = 0;
  UnionFind F(n);
  for (auto [u, v] : edges1) {
    if (!G.connected(u, v)) {
      ++toRemove;
    } else {
      // possibly extra edge?
      F.unite(u, v);
    }
  }

  for (auto [u, v] : edges2) {
    if (!F.connected(u, v)) {
      F.unite(u, v);
      ++toAdd;
    }
  }

  std::cout << toAdd + toRemove << '\n';
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
