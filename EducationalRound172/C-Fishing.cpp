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
  // n fishes. Some caught by Alice, some Bob. Ordered in ascending order of
  // size.
  // choose integer m. split all the fishes into m non-empty groups.
  // Each group should be contiguous.
  // First group should contain at least one of the
  // smallest fishes,
  // second group should contain the next smallest fishes, etc.
  // i.e., fishes from the second group cannot be smaller than the first
  // group's.
  //
  // Each group will be assigned (i-1) points for each fish in the group.
  // i.e., first group, each fish is 0 points. second group, 1 points each.
  //
  // We want to maximize Bob's point, while minimizing Alice's point, such
  // that Bob's points exceed Alice's by at least k.
  // Return -1 otherwise.
  //
  // Can we do a greedy approach?
  // Group as many 0s as possible in the same group. For 1s (belongs to Bob),
  // make the group as small as possible, i.e., size = 1.
  //
  // Though, for '1' followed by '0', we want to "sacrifice" one fish to
  // group all subsequent '0's in the same group, so that the next '1' will be
  // higher valued. But we also want the minimum number of splits...
  // Do we keep track of the number of fishes in each group, so we can coalesce
  // to get a smaller, but still sufficient score.
  //
  // Is there a cleaner implementation?
  // Something about the binary string, leading/trailing zeroes/ones?
  // Lmao. This is just prefix/suffix.
  //
  // Suffix sum. Notice that the points assigned to the i-th fish depends on
  // the number of groups before it.
  // Therefore, when we create a group, all fish to the RIGHT of the split gets
  // more valuable. As such, we care about the net gain to the right of each
  // position.
  // Since in each group, the number of Bob's fish must exceed Alice's fish for
  // Bob to have an overall gain in points, we can maintain a SUFFIX sum. +1
  // for Bob's fish, -1 for Alice's.
  // At the end, we would have points where Bob has more to the right, or less
  // than Alice.
  // The constraint is that we want to split as little as possible. Thus, by
  // greedily selecting the boundary where Bob has the most fish as compared to
  // Alice, we can obtain the minimum number of groups possible.
  int n, k;
  std::cin >> n >> k;

  std::string s;
  std::cin >> s;

  // Difference between Bob and Alice's fish.
  // We can optimize this to only store suffixes where Bob has a net gain over
  // Alice's.
  std::vector<int> suffixes;
  suffixes.reserve(n);
  int suffix = 0;

  // WARNING: note iterate to i>0, NOT i>=0.
  // This is because we are iterating over SPLITS. Not Fish. i.e., split at
  // each point such that the subsequent fishes are in a group.
  // It is wrong to split before the very first fish, as it indicates two
  // groups where there can only be one, i.e., an Empty Group which is not
  // possible from problem constraints.
  for (int i = n - 1; i > 0; --i) {
    suffix += s[i] == '1' ? 1 : -1;

    if (suffix > 0) {
      suffixes.push_back(suffix);
    }
  }

  std::sort(suffixes.rbegin(), suffixes.rend());

  // greedily split, to obtain a difference in k points.
  int groups = 1;
  int netPoints = 0;
  for (int i = 0; i < suffixes.size() && netPoints < k; ++i) {
    netPoints += suffixes[i];
    ++groups;
  }

  if (netPoints < k) {
    std::cout << -1 << '\n';
    return;
  }
  std::cout << groups << '\n';
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
