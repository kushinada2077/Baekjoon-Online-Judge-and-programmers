#define ll long long
#define PAIR pair<int, int>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <vector>
using namespace std;

int n, v, a[1005], d[1005], p[1005];

void print(int i) {
  if (i == -1) return;
  print(p[i]);
  cout << a[i] << " ";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  fill(p, p + n, -1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    d[i] = 1;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (a[i] > a[j] && d[j] + 1 > d[i]) {
        d[i] = d[j] + 1;
        p[i] = j;
      }
    }
  }
  int i = distance(d, max_element(d, d + n));
  cout << d[i] << "\n";
  print(i);
}