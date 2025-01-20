#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <deque>
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
  // Seems like binary search. For x in [l1, r1], search for corresponding
  // y in [l2, r2].
  // Not sure about the bounds / input constraints / time limit though..
  int k, l1, r1, l2, r2;
  std::cin >> k >> l1 >> r1 >> l2 >> r2;

  for (int x = l1; x <= r2; ++x) {
    int target =
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
