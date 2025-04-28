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
#include <ostream>
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

void solve() {
  // INTERACTIVE
  // x1..xn of integers from [1..n]
  // Fixed but hidden y1 ... yn from [1..n].
  // For all i, xi != yi and all pairs (xi, yi) are distinct.
  //
  // Jury thought of two objects (secretly), need to determine which:
  // - A: directed graph with n vertices from 1 to n, n edges xi -> yi
  // - B: n points on a coordinate plane, ith point has (xi, yi)
  //
  // In one query: specify i, j
  // Receive:
  // - If A, then the length of the shortest path from nodes i, j is returned.
  //   (xi, yi) thus represents edges.
  // - If B, manhattan distance between points i and j is returned.
  //   (xi, yi) represents two points.
  //
  // DETERMINE WITH TWO QUERIES.
  // Symmetry? if graph, i -> j and j -> i should be 1/0, not more than that.
  // If both are same, then Graph, since no duplicate points.
  //
  // Triangle inequality?
  // Duplicate x?
  // If there are duplicate x, then take arbitrary 3rd point y.
  // query both x1->y and x2->y, both should be equal.
  //
  // If all distinct, then query symmetry. NO. MD is NOT UNIQUE.
  int n;
  std::cin >> n;
  std::vector<int> X(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> X[i];
  }

  auto query = [](int i, int j) -> int {
    std::cout << "? " << i << ' ' << j << std::endl;
    int ans;
    std::cin >> ans;
    return ans;
  };

  auto answer = [](char c) { std::cout << "! " << c << std::endl; };

  bool hasDuplicate = false;
  std::unordered_set<int> uniq{X.begin(), X.end()};
  hasDuplicate = uniq.size() < X.size();

  hasDuplicate = uniq.size() < X.size();
  if (hasDuplicate) {
    // find missing node.
    for (int i = 1; i <= n; ++i) {
      if (!uniq.contains(i)) {
        // There should be NO edge starting from the missing number, to any
        // arbitrary node.
        // Note that if the object is a Graph, then the queried i, j are the
        // node labels.
        int x = query(i, i % n + 1);
        if (x) {
          answer('B');
        } else {
          answer('A');
        }
        break;
      }
    }

  } else {
    // MD can be same, but MUST be at least bigger than the difference in the
    // X-Coordinate.
    int i, j;

    for (int k = 0; k < n; ++k) {
      if (X[k] == 1) {
        i = k;
      }
      if (X[k] == n) {
        j = k;
      }
    }

    int first = query(i + 1, j + 1);
    int second = query(j + 1, i + 1);
    if (first >= n - 1 && second >= n - 1) {
      answer('B');
    } else {
      answer('A');
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
