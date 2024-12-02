#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <ios>
#include <iostream>
#include <iterator>
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
  // n countries with k regions each.
  // For the jth region of the ith country, aij represents the amount of water
  // create channels bettwen the jth region of the ith and (i+1)th country for
  // all 1 <= i <= (n-1). Basically all adjacent countries.
  // Water flows towards country with the highest number, i.e., left to right.
  // After the channel system is created, the new value aij will be
  // bij = a1j | a2j | ... | aij , i.e., the prefix bitwise OR sum of the same
  // numbered region of all countries
  //
  // After redistributing,
  // q queries, each with m requirements.
  // region number r, sign '<' or '>', and value c.
  // In the rth region of the chosen country (by us), the new value must be
  // strictly less/greater than the limit c.
  //
  // Seems simple enough. Just update the 2D arr in place to get the prefix OR.
  // But how to get the country efficiently? Sort? Requires collecting every
  // column and sorting it individually?
  //
  // Initial would have been each row is a country.
  // What about each row being the ith region, where each column represents
  // the jth country?
  // the bitwise OR would then be simpler too.
  int n, k, q;
  std::cin >> n >> k >> q;

  // Store {value, country}
  std::vector<std::vector<int>> waters(k, std::vector<int>(n));
  // for each country,
  for (int i = 0; i < n; ++i) {
    // for each region
    for (int j = 0; j < k; ++j) {
      // effectively transposes the input array
      std::cin >> waters[j][i];
    }
  }

  // update to new values
  // for each region of every country
  // NO NEED TO SORT. BITWISE ORS ensures the result is at least equal to or
  // greater
  for (int i = 0; i < k; ++i) {
    for (int j = 1; j < n; ++j) {
      waters[i][j] |= waters[i][j - 1];
    }
  }

  for (int i = 0; i < q; ++i) {
    int m;  // number of requirements
    std::cin >> m;

    std::vector<int> countryIdx(n, -1);
    for (int j = 0; j < m; ++j) {
      int r;
      char sign;
      int c;
      std::cin >> r >> sign >> c;
      --r;

      for (int i = 0; i < n; ++i) {
        std::cout << '(' << waters[r][i] << ", " << waters[r][i] << ')' << ' ';
      }
      std::cout << '\n';

      // WARNING: Not completed.
      if (sign == '<') {
        // the new value must be less than c. use std::upper_bound
        // find the first value that is GTE c, i.e., lower_bound then minus 1
        auto iter = std::lower_bound(waters[r].begin(), waters[r].end(), c);
        int idx = std::distance(waters[r].begin(), iter) - 1;

        if (idx < 0) {
          std::cout << -1 << '\n';
        } else {
          std::cout << waters[r][idx] + 1 << '\n';
        }
      } else {
        auto iter = std::upper_bound(waters[r].begin(), waters[r].end(), c);

        if (iter == waters[r].end()) {
          std::cout << -1 << '\n';
        } else {
          std::cout << std::distance(waters[r].begin(), iter) + 1 << '\n';
        }
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tc = 1;  // Number of test cases
  // std::cin >> tc;

  while (tc--) {
    solve();
  }

  return 0;
}
