#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <ios>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using i64 = long long;

void solve() {
  // n shelves, k bottles.
  // ith bottle is characterized by brand index bi and cost ci.
  // Place any number of bottles on each shelf, but all bottles on the same
  // shelf must be the same brand.
  // All bottles placed on shelves will be sold. Find the maximum.
  // If k <= n, then return the sum.
  // Otherwise, choose the top n brands with the highest combined cost (bottles
  // of the same brand may have different cost)
  // Just sort. The input allows nlogn
  int n, k;
  std::cin >> n >> k;

  std::vector<int> brandCosts(k, 0);
  for (int i = 0; i < k; ++i) {
    int brand, cost;
    std::cin >> brand >> cost;
    brandCosts[brand - 1] += cost;
  }

  if (k <= n) {
    int sum = 0;
    for (int i = 0; i < k; ++i) {
      sum += brandCosts[i];
    }
    std::cout << sum << '\n';
    return;
  }

  std::sort(brandCosts.rbegin(), brandCosts.rend());
  int totalProfit = 0;
  for (int i = 0; i < n; ++i) {
    totalProfit += brandCosts[i];
  }
  std::cout << totalProfit << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tc;  // Number of test cases
  std::cin >> tc;

  while (tc--) {
    solve();
  }

  return 0;
}
