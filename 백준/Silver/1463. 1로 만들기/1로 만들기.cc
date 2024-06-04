#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int ans = 0x3f3f3f3f;
int d[1000005];
void sol(int x, int cnt) {
  if (d[x] && d[x] < cnt) return;
  d[x] = cnt;
  if (x == 1) return;

  if (x % 3 == 0) sol(x / 3, cnt + 1);
  if (x % 2 == 0) sol(x / 2, cnt + 1);
  sol(x - 1, cnt + 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int x;
  cin >> x;
  sol(x, 0);
  cout << d[1];
}