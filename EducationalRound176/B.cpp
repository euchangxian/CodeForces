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
  // n elements, all red at first
  // Choose k elements, paint blue.
  // While there are red elements with a blue neighbour, paint them blue.
  // cost is the sum of the first k chosen elements, and the last painted
  // element.
  // Maximum cost.
  int n, k;
  std::cin >> n >> k;
  std::vector<int> nums(n), indices(n);
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    nums[i] = x;
    indices[i] = i;
  }
  std::sort(indices.begin(), indices.end(),
            [&nums](int i, int j) -> bool { return nums[i] < nums[j]; });

  // largest k elements.
  std::deque<int> window;
  std::vector<bool> initialBlue(n, false);
  int sum = 0;
  for (int i = 0; i < k; ++i) {
    sum += nums[indices[i]];
    window.push_back(indices[i]);
    initialBlue[indices[i]] = true;
  }

  int best = 0;
  for (int i = 0; i < k + 1; ++i) {
    std::vector<bool> blue = initialBlue;
    std::queue<int> q;
    for (int idx : window) {
      if (idx - 1 >= 0 && !blue[idx - 1]) {
        blue[idx - 1] = true;
        q.push(idx - 1);
      }

      if (idx + 1 < n && !blue[idx + 1]) {
        blue[idx + 1] = true;
        q.push(idx + 1);
      }
    }

    int candidate = 0;
    while (!q.empty()) {
      auto idx = q.front();
      q.pop();

      bool hasNeighbours = false;
      if (idx - 1 >= 0 && !blue[idx - 1]) {
        blue[idx - 1] = true;
        hasNeighbours = true;
        q.push(idx - 1);
      }

      if (idx + 1 < n && !blue[idx + 1]) {
        blue[idx + 1] = true;
        hasNeighbours = true;
        q.push(idx + 1);
      }

      // candidate for last
      if (!hasNeighbours) {
        candidate = std::max(candidate, nums[idx]);
      }
    }

    // update best
    best = std::max(best, sum + candidate);

    if (k + i >= n) {
      break;
    }

    // update window
    auto largestIdx = window.front();
    window.pop_front();
    sum -= nums[largestIdx];
    initialBlue[largestIdx] = false;

    window.push_back(indices[k + i]);
    sum += nums[indices[k + i]];
    initialBlue[indices[k + i]] = true;
  }

  std::cout << best << '\n';
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
