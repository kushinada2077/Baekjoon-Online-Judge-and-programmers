#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int lc[100001], rc[100001], p[100001], vis[100001];
int a, b, c, N, tot, last;
bool flag;

void inorder(int cur) {
  last = cur;
  if (lc[cur]) {
    p[lc[cur]] = cur;
    inorder(lc[cur]);
  }
  last = cur;
  if (rc[cur]) {
    p[rc[cur]] = cur;
    inorder(rc[cur]);
  }
}

void custom_order(int cur) {
  if (flag) return;
  vis[cur] = 1;
  tot++;
  if (lc[cur] && !vis[lc[cur]]) custom_order(lc[cur]);
  if (rc[cur] && !vis[rc[cur]]) custom_order(rc[cur]);
  if (cur == last) {
    flag = true;
    return;
  }
  if (p[cur]) custom_order(p[cur]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a >> b >> c;
    if (b == -1) b = 0;
    if (c == -1) c = 0;
    lc[a] = b;
    rc[a] = c;
  }

  inorder(1);
  custom_order(1);
  cout << tot - 1;
}