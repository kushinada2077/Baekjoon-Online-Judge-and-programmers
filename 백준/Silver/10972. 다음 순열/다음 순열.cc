#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
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

bool my_next_permutation(vector<int>& arr) {
  int pivot = si(arr) - 2;
  for (; pivot >= 0; --pivot) {
    if (arr[pivot] < arr[pivot + 1]) break;
  }

  if (pivot < 0) return 0;

  int j = si(arr) - 1;
  for (; j > pivot; --j) {
    if (arr[pivot] < arr[j]) break;
  }

  swap(arr[pivot], arr[j]);
  reverse(arr.begin() + pivot + 1, arr.end());
  return 1;
}

int main() {
  fastio;
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& i : arr) cin >> i;
  if (my_next_permutation(arr)) {
    for (auto& i : arr) cout << i << " ";
  } else cout << "-1\n";
}