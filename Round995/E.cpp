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
  // n customers.
  // Need to determine price of one tree.
  //
  // customer[i] = [ai, bi], where
  // ai: if the price of the tree is at most ai, customer buys and
  //     leave positive review.
  // bi: if the price is at most bi, customer buys, negative review.
  // Otherwise, no buy.
  //
  // Determine maximum earning so that no more than k negative reviews.
  // Feels like binary searching the price, with a feasible function.
  // i.e,. if feasible, increase the price. But we do not want the maximum
  // price, but the maximum profit.
  // Hm, BS still seems right, since if we maximize k negative reviews,
  // the remaining wont buy regardless of the price. The positive ones will buy
  // at a higher price.
  // Nope. Not monotonic. Consider
  // [5, 9], [15, 20], [8, 25].
  // price = 9 => revenue = 3 * 9 = 27
  // price = 10 => revenue = 2 * 10 = 20
  // price = 15 = >revenue = 2 * 15 = 30
  // price = 21 => revenue = 1 * 21 = 21
  //
  // Hmmmm. Notice that we kinda want to use the values as thresholds for the
  // prices..?
  // i.e., the checkpoints are 5, 8, 9, 15, 20, 25, i.e., the unique values.
  // If we do Line Sweep?
  // For each value,
  //   determine profit and feasibility.
  // O(n^2) though...
  int n, k;
  std::cin >> n >> k;

  // ai < bi, i.e., b is higher than a.
  std::vector<int> a(n);
  std::vector<int> b(n);
  for (int& i : a) {
    std::cin >> i;
  }
  for (int& i : b) {
    std::cin >> i;
  }

  // {price, isBThreshold}
  std::vector<std::pair<i64, bool>> events;
  events.reserve(2 * n);
  for (int i = 0; i < n; ++i) {
    events.emplace_back(a[i], false);
    events.emplace_back(b[i], true);
  }
  std::sort(events.begin(), events.end());

  i64 maxEarnings = 0LL;
  int buyers = n;
  int negReviews = 0;

  int i = 0;
  while (i < events.size()) {
    i64 currPrice = events[i].first;

    // WARNING: UPDATE PRICE BEFORE BOOKKEEPING. This is because thresholds
    // are LESS-THAN-OR-EQUAL. So the bookkeeping is for the NEXT price.
    if (negReviews <= k) {
      maxEarnings = std::max(maxEarnings, currPrice * buyers);
    }

    // Process all events at current price point
    while (i < events.size() && events[i].first == currPrice) {
      if (!events[i].second) {
        // is a[i], change to negative review.
        ++negReviews;
      } else {
        --negReviews;
        --buyers;
      }
      i++;
    }
  }
  std::cout << maxEarnings << '\n';
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
