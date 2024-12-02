#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <ios>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
  int n;
  std::cin >> n;

  int toRemove = 0;

  int currMax;
  std::cin >> currMax;
  int repeats = 1;  // count the number of max elements

  int num;
  for (int i = 1; i < n; ++i) {
    std::cin >> num;

    // Increasing => remove, decreasing => stalin sort.
    if (num == currMax) {
      ++repeats;
      continue;
    }

    if (num > currMax) {
      toRemove += repeats;

      currMax = num;
      repeats = 1;
    }
  }
  std::cout << toRemove << '\n';
}

// Remove integers, then apply Stalin Sort on its subarrays to form a
// non-increasing array.
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
