#define ll long long
#include <iostream>
#include <set>
#include <vector>
using namespace std;

string pad(int n) {
  if (n < 10) return "0" + to_string(n);
  return to_string(n);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, h, w, n;
  cin >> t;
  while (t--) {
    cin >> h >> w >> n;
    cout << (n - 1) % h + 1 << pad((n - 1) / h + 1) << "\n";
  }
}