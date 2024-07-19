
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using namespace std;

int main() {
  fastio;
  int n;
  cin >> n;
  cout << fixed;
  cout.precision(3);
  vector<double> stu(n);
  for (auto& i : stu) cin >> i;
  sort(all(stu));
  for (int i = 0; i < 7; ++i) cout << stu[i] << "\n";
}