#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
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
#include <vector>

using i64 = long long;

void solve() {
  // n lights, 2n switches. Each component (light/switch) has two states:
  // on/off.
  // - Each light is connected to exactly two switches.
  // - Each switch is connected to exactly one light. It is unknown which.
  // - When all switches are off, all lights are off
  // - If a switch is toggled, the light connected will aos toggle.
  //
  // Given the state of the 2n switches (on/off), what is the minimum and
  // maximum number of lights that can be turned on. NOT toggled on.
  // Weird wording.
  //
  // PIGEONHOLE PRINCIPLE...?
  //
  // For minimum, arrange the switches in a way such that as many of the ON
  // switches connected to the same lightbulb. i.e., Pair ON switches together.
  // Any unpaired switches remaining is the number of bulbs ON.
  // {1, 1} => bulb is OFF. {1, 0} => bulb is ON. {0, 0} => bulb is OFF.
  //
  // For maximum, arrange the switches in a way such that as many of the ON
  // switches are paired with an OFF switch.
  //
  // Count ON/OFF switches.
  // For minimum, take floor(onCount / 2).
  // For maximum, take onCount. For any excess beyond n, minus the excess from
  // the result.
  int n;  // n <= 50. Describes a1 a2 ... a2n (ai = 0 (off) | 1 (on))
  std::cin >> n;

  int onCount = 0;
  int switchState;
  for (int i = 0; i < 2 * n; ++i) {
    std::cin >> switchState;
    onCount += switchState;
  }

  int min = onCount & 1;  // mod 2
  int max = onCount <= n ? onCount : n - (onCount - n);

  std::cout << min << ' ' << max << '\n';
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
