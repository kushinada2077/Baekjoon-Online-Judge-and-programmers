#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  priority_queue<int, vector<int>, greater<int>> pq;
  int N, x, c1, c2, ans = 0;
  cin >> N;
  while (N--) {
    cin >> x;
    pq.push(x);
  }

  while (pq.size() > 1) {
    c1 = pq.top();
    pq.pop();
    c2 = pq.top();
    pq.pop();
    ans += c1 + c2;
    pq.push(c1 + c2);
  }

  cout << ans;
}