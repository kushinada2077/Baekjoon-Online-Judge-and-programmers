#define PAIR pair<long long, int>
#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, cnt = 0;
  string s;
  cin >> n >> m;
  unordered_set<string> h;
  while (n--) {
    cin >> s;
    h.insert(s);
  }
  while (m--) {
    cin >> s;
    if (h.find(s) != h.end()) cnt++;
  }
  cout << cnt;
}