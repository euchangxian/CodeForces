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
  // Perform operations as many times to get maximum possible length of arr.
  // An operation has the steps:
  // 1. Choose i such that 1 < i <= arr.len && arr[i] = arr.len + 1 - i, or
  // 2. Append i - 1 zeros onto the end of arr.
  //
  // First insight is that any new elements added are zeros. They would not need
  // to be considered as candidates for operations.
  // Second point is that arr.len will change as zeros are added, potentially
  // invalidating, or add new candidates for operations.
  //
  // Is there a way to rewrite the equation to more easily identify valid
  // candidates for operations?
  //
  // arr[i] = arr.len + 1 - i
  // => arr[i] + i = arr.len + 1
  //
  // Multiple candidates may be valid. Greedy Choice will definitely not work.
  // Seems like DP? Backtracking? Input constraints definitely disallow
  // backtracking though.
  // Naively, O(n) time to determine candidates, pick one. Go next.
  // The decision tree has a maximum depth of n, where n is the original length
  // of the array.
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tc;  // Number of test cases
  std::cin >> tc;

  while (tc--) {
    // Read in inputs as necessary
    solve();
  }

  return 0;
}
