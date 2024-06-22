#define ll long long
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n;
int num[100005], d[100005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> num[i - 1];
    d[i] = max(num[i - 1], d[i - 1] + num[i - 1]);
  }
  cout << *max_element(d + 1, d + n + 1);
}