#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <ranges>
#include <set>
#include <span>
#include <sstream>
#include <stack>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using i64 = long long;
constexpr int MOD = 1'000'000'007;

void solve() {
  // boarding by bus or bridge.
  // bet with n students.
  // With ith student, make bet on day ai
  // Win bet if predicted boarding on day ai+1 and ai+2 is corrected.
  // Win the bet with at LEAST one student.
  // 4 different permutations => if 4 same day bets then win
  //
  // NOTE: From editorial
  // 1. Quadruple of students.
  // 2. Let day i and day j such that i < j (NOT NECESSARILY CONSECUTIVE)
  //    Then, nums[i] = 2 and nums[j] = 2, AND
  //    for all i < k < j such that nums[k] = 1
  int n;
  std::cin >> n;

  std::vector<int> nums(n);
  std::map<int, int> days;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    nums[i] = x;
    ++days[x];
  }

  int prevDay = 0;
  int hasTwo = 0;
  for (auto [day, count] : days) {
    // Case 1: 4+ students on a day
    if (count >= 4) {
      std::cout << "Yes\n";
      return;
    }

    // Case 2: 2+ students on current day
    if (count >= 2) {
      // If previous day had exactly 1 student and was consecutive
      if (prevDay == day - 1 && hasTwo == 1) {
        std::cout << "Yes\n";
        return;
      } else {
        prevDay = day;
        hasTwo = 1;
      }
    }
    // Case 3: Exactly 1 student on current day
    else {
      // If not consecutive, reset the chain
      if (prevDay != day - 1) {
        hasTwo = 0;
      }
      prevDay = day;
    }
  }
  std::cout << "No\n";
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tc{1};
  std::cin >> tc;

  while (tc--) {
    solve();
  }

  return 0;
}
