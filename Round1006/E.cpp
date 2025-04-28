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
  // need to place n <= 500 staff at DISTINCT integer coordinates such that
  // there will be exactly k pairs (i, j), i < j
  // p(i, j) = d(i, j)
  // p(i, j) is the euclidean distance
  // d(i, j) is the manhattan distance.
  //
  // Wew. The points must all fulfil this constraint.
  // Adding one point will need to match all previous points.
  // Expand from centre?
  // Palindromic-like.
  // Note that the equation
  // |x₁-x₂| + |y₁-y₂| = √[(x₁-x₂)² + (y₁-y₂)²]
  // holds when either points are on the same horizontal/vertical line.
  // Thus, we can reduce this to a construction problem.
  // Also, a graph problem, since we need exactly k, so we need to combine
  // components/lines.
  // Given that we can only output 500 points, we need to do some combinations!
  // numPoints = 2   3   4
  //             1 + 2 + 3 + ... = k
  //
  // Can we do it greedily?
  // Can we prove we wont exceed 500?
  // n*(n+1)/2
  // Lets try proof by AC...

  int k;
  std::cin >> k;
  std::vector<std::pair<int, int>> answer;
  answer.reserve(500);

  answer.emplace_back(0, 0);
  std::array<int, 501> line{};
  line[0] = 1;

  int satisfy = 0;
  int curr = 0;
  for (int y = 1; y <= 500 && satisfy < k; ++y) {
    if (satisfy + line[curr] <= k) {
      satisfy += line[curr]++;
      answer.emplace_back(curr, y);
    } else {
      line[++curr] = 1;
      answer.emplace_back(curr, y);
    }
  }

  std::cout << answer.size() << '\n';
  for (const auto [x, y] : answer) {
    std::cout << x << ' ' << y << '\n';
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
