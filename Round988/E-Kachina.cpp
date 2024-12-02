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
  // INTERACTIVE
  // Guess a binary string s of length n.
  // f(l, r) is the number of subsequences of "01" in sl...sr
  // Two subsequences are considered different if they are formed from deleting
  // characters from different POSITIONS, even if they form the same string.
  // To determine s, question can be asked:
  // choose two indices l, r and ask for the value of f(l, r)
  //
  // Determine and output s after asking no more than n questions.
  // If impossible, output IMPOSSIBLE.
  //
  // Question: "? l r", 1 <= l < r <= n
  // l, r are 1-indexed.
  //
  // OKAY. FIRST.
  // each "01" is able to pair with every other "01" to create another "01".
  // by deleting "10" in the middle.
  // "0101" => "01" and "01",
  // delete "10" in the middle to get "01"
  //
  // If there are any '0's before the "01", '0's can be deleted to get another
  // "01", i.e., one subsequence for each leading '0'.
  //
  // If there are trailing '1's after "01", '1's can be deleted.
  // one subsequence for each trailing '1'.
  //
  // okay. refined a little.
  // For any '1's, the number of "01"s that can be formed with it is
  // the number of leading '0's.
  // OR
  // For any '0's, the number of "01"s that can be formed with it is
  // the number of trailing '1's.
  //
  // Now how do we use these? What information can we get from knowing the
  // number of subsequences in a range?
  //
  // The most number of "01"s occur when the string is monotonic, ie.
  // "00001111", all the '0s' are in front of the '1's.
  // The least number is 0, the opposite.
  //
  // We can narrow down the maximum number of '0's/'1's in the Range.
  // where the maximum is equal to numZeros * numOnes
  //
  // i.e,. with n = 5, "00011" or "00111", etc...
  // max(f(1, 5)) = 6,
  //
  // If, f(1, 5) = 4, that means? Not monotonic only? any other information?
  // n queries, we can narrow down a lot though. No need to search?
  //
  // Cant we just query every pair (i, i+1)?
  // There is the odd-case though, the last element.
  // There are a few combinations, consider the previous pair first. I.e,.
  // if previous pair has no subsequence, then the previous pair must be 00, 10,
  // or 11. Else, it must be 01.
  // Then, if including the last element. If the count increases, the
  // subsequence must be either 001, or 011. Both have a count of two, but one
  // was previously 0. No ambiguity.
  //
  // Ah.... The ambiguity comes from count == 0...
  // Ahhhhhh no....
  // we query (i, i+1), then query (i+1, i+2).
  // Is there still ambiguity?
  // suppose previous is 00, 10 or 11, i.e., count = 0
  // then, if count = 0, we have 000, 100, 110, 111
  // if count > 0, we have 010, 011, 001, 101, which can be disambiguated
  // based on the prev and curr value.
  //
  // Can we continue increasing i then...? Not trivial.
  int n;
  std::cin >> n;

  std::string result(n, '0');

  // n-1 queries.
  for (int i = 1; i < n; ++i) {
  }
}

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
