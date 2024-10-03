#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using ll = long long;
using namespace std;

bool n_permutation(vector<int>& a) {
  int pivot = si(a) - 2;
  for (; pivot >= 0; --pivot) {
    if (a[pivot] < a[pivot + 1]) break;
  }

  if (pivot < 0) return 0;

  int j = si(a) - 1;
  for (; j > pivot; --j) {
    if (a[pivot] < a[j]) break;
  }

  swap(a[pivot], a[j]);
  reverse(a.begin() + pivot + 1, a.end());
  return 1;
}
int main() {
  fastio;
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& i : a) cin >> i;
  bool f = n_permutation(a);
  if (f)
    for (auto& i : a) cout << i << " ";
  else cout << "-1\n";
}