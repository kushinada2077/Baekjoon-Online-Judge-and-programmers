#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <tuple>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
using ll = long long;
using namespace std;

int n, rA, rB, rD;
vector<string> opcode_to_n({"ADD", "ADDC", "SUB", "SUBC", "MOV", "MOVC", "AND", "ANDC", "OR", "ORC", "NOT", "DUMMY", "MULT", "MULTC", "LSFTL", "LSFTLC", "LSFTR", "LSFTRC", "ASFTR", "ASFTRC", "RL", "RLC", "RR", "RRC"});
string b(int n, int p) {
  string ret = "";
  while (n) {
    ret += n % 2 + '0';
    n >>= 1;
  }
  reverse(all(ret));
  string pad = "";
  for (int i = 0; i < p - si(ret); ++i) pad += '0';
  return pad + ret;
}
int main() {
  fastio;
  cin >> n;
  while (n--) {
    string opcode, ans;
    cin >> opcode >> rD >> rA >> rB;
    int opcode_num = find(all(opcode_to_n), opcode) - opcode_to_n.begin();
    ans = b(opcode_num, 5);
    ans += '0';
    ans += b(rD, 3);
    ans += b(rA, 3);
    if (ans[4] == '0') {
      ans += b(rB, 3);
      ans += '0';
    } else ans += b(rB, 4);
    cout << ans << "\n";
  }
}