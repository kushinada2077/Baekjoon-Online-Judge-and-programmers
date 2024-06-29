#define ll long long
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  set<int> val;
  int v;
  for (int i = 0; i < 10; ++i) {
    cin >> v;
    val.insert(v % 42);
  }
  cout << val.size();
}