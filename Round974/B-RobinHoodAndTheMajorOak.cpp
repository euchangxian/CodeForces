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

// TLE-ed
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    int k;
    std::cin >> n >> k;

    int leaves = 0;
    for (int i = 0; i < k; ++i) {
      leaves += n--;
    }

    if (leaves & 1) {
      // if odd
      std::cout << "NO";
    } else {
      std::cout << "YES";
    }
    std::cout << '\n';
  }
}
