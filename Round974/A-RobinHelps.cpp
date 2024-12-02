#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int solve(const std::vector<int> &gold, const int k) {
  int goldRemaining{0};
  int count{0};

  for (const int &g : gold) {
    if (g >= k) {
      goldRemaining += g;
      continue;
    }

    if (g == 0 && goldRemaining > 0) {
      --goldRemaining;
      ++count;
    }
  }
  return count;
}

int main() {
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  // Encounters n people starting from the 1st, ending with the nth.
  // i-th person has ai gold. If ai >= k, take all the gold.
  // If ai = 0, give 1 gold if Robin has any.
  // Start with 0 gold.
  int t; // test cases
  std::cin >> t;

  while (t--) {
    int n; // number of people
    int k; // gold threshold
    std::cin >> n >> k;

    std::vector<int> gold(n, 0);
    for (int i = 0; i < n; ++i) {
      std::cin >> gold[i];
    }

    // Solve
    std::cout << solve(gold, k) << '\n';
  }
}
