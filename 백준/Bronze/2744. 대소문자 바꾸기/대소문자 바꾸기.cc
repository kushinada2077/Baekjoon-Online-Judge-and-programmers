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

int main() {
  fastio;
  string s;
  cin >> s;
  for (auto& c : s) {
    if ('a' <= c && c <= 'z') cout << (char)(c - ('a' - 'A'));
    if ('A' <= c && c <= 'Z') cout << (char)(c + ('a' - 'A'));
  }
}