#include <vector>

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
