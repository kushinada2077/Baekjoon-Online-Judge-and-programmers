#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;
using F = std::tuple<int, int, int, int>;

struct BaseBall {
  std::vector<int> location;
  std::vector<int>& players;
  int new_location[4];
  const std::vector<std::vector<int>>& res;
  int score, out, turn;

  BaseBall(std::vector<std::vector<int>>& res, std::vector<int>& players) : players(players), location(4), res(res), score(0), out(0), turn(0) {}

  void move(int dx) {
    std::fill(new_location, new_location + 4, 0);
    for (int i = 3; i >= 0; --i) {
      if (i > 0 && location[i] == 0) continue;
      if (i + dx >= 4) {
        score++;
      } else {
        new_location[i + dx] = 1;
      }
    }

    for (int i = 0; i < 4; ++i) location[i] = new_location[i];
  }

  void work() {
    int n = (int)res.size();
    for (int i = 0; i < n; ++i) {
      std::fill(location.begin(), location.end(), 0);
      out = 0;
      for (; out < 3; turn = (turn + 1) % 9) {
        int state = res[i][players[turn]];

        switch (state) {
          case 0:
            out++;
            break;

          default:
            move(state);
        }
      }
    }
  }
};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int n;
  std::cin >> n;
  std::vector res(n, std::vector<int>(9));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 9; ++j) {
      std::cin >> res[i][j];
    }
  }

  std::vector<int> p(8);
  std::iota(p.begin(), p.end(), 1);
  int ans = 0;

  do {
    std::vector<int> players(9);
    for (int i = 0, j = 0; i < 9; ++i) {
      if (i == 3) continue;
      else players[i] = p[j++];
    }
    BaseBall game(res, players);
    game.work();
    ans = std::max(ans, game.score);
  } while (std::next_permutation(p.begin(), p.end()));

  std::cout << ans << "\n";
}