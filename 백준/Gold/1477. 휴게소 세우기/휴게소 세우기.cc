#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using TPi = tuple<int, int, int>;
using Pi = pair<int, int>;

int n, m, l;
priority_queue<TPi> pq;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m >> l;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  a.push_back(l);
  sort(a.begin(), a.end());
  for (int i = 0; i < n + 1; ++i) {
    pq.push(TPi(a[i + 1] - a[i], a[i + 1] - a[i], 1));
  }
  while (m--) {
    auto [curDiff, oriDiff, numDiv] = pq.top();
    pq.pop();
    numDiv++;
    pq.push(TPi((oriDiff + numDiv - 1) / numDiv, oriDiff, numDiv));
  }

  cout << get<0>(pq.top()) << "\n";
}