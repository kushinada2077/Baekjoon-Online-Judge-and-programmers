#define TUPLE tuple<int, int, int>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> cnt(26, -1);
  string str;
  cin >> str;

  for (int i = 0; i < str.size(); i++) {
    char c = str[i];
    if (cnt[c - 'a'] != -1) continue;
    cnt[c - 'a'] = i;
  }

  for (auto v : cnt) cout << v << " ";
}