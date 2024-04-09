#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m, op, a, b;
int p[1000001];

int find(int n) {
  if (p[n] < 0) return n;
  p[n] = find(p[n]);
  return p[n];
}

void merge(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) return;
  p[a] = b;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;

  fill(p, p + n + 1, -1);
  while (m--) {
    cin >> op >> a >> b;

    if (op) {
      a = find(a);
      b = find(b);
      if (a == b)
        cout << "YES\n";
      else
        cout << "NO\n";
    } else {
      merge(a, b);
    }
  }
}