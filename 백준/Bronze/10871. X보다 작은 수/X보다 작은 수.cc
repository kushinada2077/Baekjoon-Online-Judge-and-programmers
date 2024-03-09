#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    if (num < x) cout << num << " ";
  }
}