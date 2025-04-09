#include <bits/stdc++.h>
using i64 = long long;

const int MAX = 1 << 17;
int info[MAX << 1];
void construct() {
  for (int i = MAX - 1; i != 0; --i) {
    info[i] = info[2 * i] + info[2 * i + 1];
  }
}
void update(int node, int x) {
  node += MAX;
  info[node] += x;
  while (node > 1) {
    node /= 2;
    info[node] = info[2 * node] + info[2 * node + 1];
  }
}
int find(int node, int st, int en, int k) {
  if (st + 1 == en) {
    return st;
  }
  int l = info[2 * node];
  int mid = (st + en) / 2;
  if (k > l) {
    return find(2 * node + 1, mid, en, k - l);
  }
  return find(2 * node, st, mid, k);
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, K;
  std::cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    info[MAX + i] = 1;
  }
  construct();

  K--;
  int n = N, k = K;
  std::cout << "<";
  for (int i = 0; i < N; ++i) {
    int x = find(1, 0, MAX, k + 1);
    update(x, -1);
    n--;
    std::cout << x + 1;
    if (i != N - 1) {
      std::cout << ", ";
    }
    if (n > 0) {
      k = (k + K) % n;
    }
  }

  std::cout << ">\n";
}