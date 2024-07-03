#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define FOR_IN_1(n) for (int i = 0; i < n; ++i)
#define FOR_IN_2(i, n) for (int i = 0; i < n; ++i)
#define FOR_IN_3(i, m, n) for (int i = m; i < n; ++i)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define for_in(...) GET_MACRO(__VA_ARGS__, FOR_IN_3, FOR_IN_2, FOR_IN_1)(__VA_ARGS__)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
using namespace std;

int round_up(int a, int b) { return (a + b - 1) / b; }
int max_distance(vector<int>& dis, vector<int>& div) {
  int idx = 0;
  for_in(si(dis)) if (round_up(dis[i], div[i]) > round_up(dis[idx], div[idx])) idx = i;
  return idx;
}
int main() {
  fastio;
  int n, m, l;
  cin >> n >> m >> l;
  vector<int> a(n + 1);
  a[0] = 0;
  for_in(i, 1, n + 1) cin >> a[i];
  a.pb(l);
  sort(all(a));
  vector<int> dis;
  for_in(i, 1, n + 2) dis.pb(a[i] - a[i - 1]);
  vector<int> div(si(dis), 1);
  while (m--) {
    int idx = max_distance(dis, div);
    div[idx]++;
  }
  int ans_idx = max_distance(dis, div);
  cout << round_up(dis[ans_idx], div[ans_idx]);
}