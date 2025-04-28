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

void solve() {
  //
  int N, K;
  std::cin >> N >> K;

  std::vector<int> nums(N);
  int right = 0;
  for (int i = 0; i < N; ++i) {
    std::cin >> nums[i];
    right = std::max(right, nums[i]);
  }
  ++right;

  auto feasible = [&nums, N, K](int mex) {
    int subarrays = 1;
    std::unordered_set<int> seen;
    for (int i = 0; i < N; ++i) {
      seen.insert(nums[i]);

      bool found = true;
      for (int j = 0; j < mex; ++j) {
        if (seen.find(j) == seen.end()) {
          found = false;
          break;
        }
      }

      if (found) {
        ++subarrays;
        seen.clear();
      }
    }

    return subarrays > K;
  };

  int left = 0;
  while (left < right) {
    int mid = left + (right - left + 1) / 2;

    if (feasible(mid)) {
      left = mid;
    } else {
      right = mid - 1;
    }
  }
  std::cout << left << '\n';
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
