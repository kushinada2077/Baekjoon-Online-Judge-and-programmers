#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct cmp {
  bool operator()(int a, int b) {
    if (abs(a) == abs(b)) return a > b;
    return abs(a) > abs(b);
  };
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  priority_queue<int, vector<int>, cmp> pq;
  int N, x;
  cin >> N;

  while (N--) {
    cin >> x;
    if (x)
      pq.push(x);
    else {
      if (pq.empty())
        cout << "0\n";
      else {
        cout << pq.top() << "\n";
        pq.pop();
      }
    }
  }
}