#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using namespace std;

string i2s(int a) {
  string ret = "";
  while (a > 0) {
    ret += a % 10 + '0';
    a /= 10;
  }
  reverse(all(ret));
  return ret;
}

int main() {
  fastio;
  int n, cnt = 0, cur = 1;
  cin >> n;
  while (true) {
    string num = i2s(cur++);
    for (auto c : num) {
      cnt++;
      if (cnt == n) {
        cout << c << "\n";
        return 0;
      }
    }
  }
}