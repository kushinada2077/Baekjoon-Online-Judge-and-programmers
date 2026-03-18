#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using TP = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  const int n = 4;
  const int MAX_D = 8;
  int ct = 0;
  int m, s;
  std::cin >> m >> s;
  std::vector b(n, std::vector(n, std::vector<int>(MAX_D)));
  std::vector sm(n, std::vector<int>(n, -10));
  for (int i = 0; i < m; ++i) {
    int x, y, d;
    std::cin >> y >> x >> d;
    y--;
    x--;
    d--;
    b[y][x][d]++;
  }
  int sy, sx;
  std::cin >> sy >> sx;
  sy--;
  sx--;

  std::vector dy_f = {0, -1, -1, -1, 0, 1, 1, 1}, dx_f = {-1, -1, 0, 1, 1, 1, 0, -1};
  std::vector dy_s = {-1, 0, 1, 0}, dx_s = {0, -1, 0, 1};

  auto OOB = [&](int y, int x) { return y < 0 || y >= n || x < 0 || x >= n; };
  auto reachable_f = [&](int y, int x) {
    if (OOB(y, x) || (y == sy && x == sx) || sm[y][x] != -10) {
      return false;
    }
    return true;
  };

  auto move_f = [&]() {
    std::vector nb(n, std::vector(n, std::vector<int>(MAX_D)));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int dir = 0; dir < MAX_D; ++dir) {
          int num = b[i][j][dir];
          if (num == 0) {
            continue;
          }
          bool ok = false;
          for (int d = 0; d < 8; ++d) {
            int nDir = (dir + (8 - d)) % 8;
            int ny = i + dy_f[nDir];
            int nx = j + dx_f[nDir];
            if (reachable_f(ny, nx)) {
              nb[ny][nx][nDir] += num;
              ok = true;
              break;
            }
          }
          if (!ok) {
            nb[i][j][dir] += num;
          }
        }
      }
    }
    b = std::move(nb);
    return;
  };

  auto fn = [&](int y, int x) {
    int ret = 0;
    for (int dir = 0; dir < MAX_D; ++dir) {
      ret += b[y][x][dir];
    }
    return ret;
  };

  auto encode = [&](std::vector<int>& t) {
    int ret = 0;
    int bs = 100;
    for (auto dir : t) {
      ret += bs * (dir + 1);
      bs /= 10;
    }
    return ret;
  };

  auto move_s = [&]() {
    std::vector<P> r;
    for (int br = 0; br < 64; ++br) {
      std::vector<int> t(3);
      for (int i = 0, x = br; i < 3; ++i) {
        t[i] = x % 4;
        x /= 4;
      }

      int bs = fn(sy, sx);
      auto cnt = [&]() -> int {
        std::vector chk(n, std::vector<int>(n));
        int ret = bs;
        int y = sy;
        int x = sx;
        for (auto dir : t) {
          int ny = y + dy_s[dir];
          int nx = x + dx_s[dir];
          if (OOB(ny, nx)) {
            return -1;
          }
          if (!chk[ny][nx]) {
            ret += fn(ny, nx);
            chk[ny][nx] = 1;
          }
          y = ny;
          x = nx;
        }
        return ret;
      }();

      if (cnt != -1) {
        r.push_back({-cnt, encode(t)});
      }
    }

    std::ranges::sort(r);

    auto [cnt, rCode] = r.front();
    std::vector<int> rd;
    while (rCode) {
      rd.push_back(rCode % 10 - 1);
      rCode /= 10;
    }
    std::ranges::reverse(rd);
    for (auto dir : rd) {
      sy += dy_s[dir];
      sx += dx_s[dir];
      if (fn(sy, sx) > 0) {
        b[sy][sx].assign(MAX_D, 0);
        sm[sy][sx] = ct;
      }
    }
  };

  auto delete_smell = [&]() {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (sm[i][j] != -10 && sm[i][j] == ct - 2) {
          sm[i][j] = -10;
        }
      }
    }
    return;
  };

  for (; ct < s; ++ct) {
    auto cb = b;
    move_f();
    move_s();
    delete_smell();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int dir = 0; dir < MAX_D; ++dir) {
          b[i][j][dir] += cb[i][j][dir];
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ans += fn(i, j);
    }
  }
  std::println("{}", ans);
}