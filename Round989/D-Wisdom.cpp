#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <ios>
#include <iostream>
#include <map>
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
  int n;
  std::cin >> n;
  std::vector<int> arr(n);
  for (int& x : arr) {
    std::cin >> x;
  }

  // Count frequencies of 0,1,2
  std::array<int, 3> freq{};
  for (int i = 0; i < n; ++i) {
    ++freq[arr[i]];
  }

  // First phase: handle 2's
  std::vector<int> twosPos;  // positions of 2's that need to move
  for (int i = 0; i < n - freq[2]; ++i) {
    if (arr[i] == 2) {
      twosPos.push_back(i);
    }
  }

  // Find 1's and 0's that are too far right
  std::vector<int> onesPos, zerosPos;
  for (int i = n - freq[2]; i < n; ++i) {
    if (arr[i] == 1) {
      onesPos.push_back(i);
    }
    if (arr[i] == 0) {
      zerosPos.push_back(i);
    }
  }

  std::vector<std::array<int, 2>> operations;

  // Move 1's first
  int lastSwapPos = -1;
  for (int pos : onesPos) {
    std::swap(arr[pos], arr[twosPos.back()]);
    operations.push_back({twosPos.back(), pos});
    lastSwapPos = twosPos.back();
    twosPos.pop_back();
  }

  // Find a 1 if we haven't used any yet
  if (lastSwapPos == -1) {
    for (int i = 0; i < n - freq[2]; ++i) {
      if (arr[i] == 1) {
        lastSwapPos = i;
        break;
      }
    }
  }

  // Handle zeros using two-step swaps
  for (int pos : zerosPos) {
    std::swap(arr[pos], arr[lastSwapPos]);
    operations.push_back({lastSwapPos, pos});
    std::swap(arr[pos], arr[twosPos.back()]);
    operations.push_back({twosPos.back(), pos});
    lastSwapPos = twosPos.back();
    twosPos.pop_back();
  }

  // Second phase: fix any remaining 0-1 inversions
  std::vector<int> remainingOnes;
  for (int i = 0; i < freq[0]; ++i) {
    if (arr[i] == 1) {
      remainingOnes.push_back(i);
    }
  }

  for (int i = freq[0]; i < freq[0] + freq[1]; ++i) {
    if (arr[i] == 0 && !remainingOnes.empty()) {
      std::swap(arr[i], arr[remainingOnes.back()]);
      operations.push_back({remainingOnes.back(), i});
      remainingOnes.pop_back();
    }
  }

  std::cout << operations.size() << '\n';
  for (const auto& op : operations) {
    std::cout << op[0] + 1 << ' ' << op[1] + 1 << '\n';
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tc;
  std::cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
