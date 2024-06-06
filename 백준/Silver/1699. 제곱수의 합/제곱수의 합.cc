#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int N;
int t;
int d[100005];
vector<int> num;
const int INF = 0x3f3f3f3f;

int f(int n, int k) {
  if (k == t) return n ? INF : 0;
  if (d[n]) return d[n];

  int result = f(n, k + 1);
  if (num[k] <= n) result = min(result, f(n - num[k], k) + 1);
  d[n] = result;
  return result;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 1; i * i <= N; ++i) num.push_back(i * i);
  t = num.size();
  cout << f(N, 0);
}