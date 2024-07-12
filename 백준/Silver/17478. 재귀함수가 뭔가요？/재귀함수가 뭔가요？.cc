#include <algorithm>
#include <iostream>
#include <queue>
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

const string s = R"("재귀함수가 뭔가요?"
"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.
마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.
그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.")";
vector<string> a, a2;
const string s2 = R"("재귀함수가 뭔가요?"
"재귀함수는 자기 자신을 호출하는 함수라네"
라고 답변하였지.)";
vector<string> split(const string& s, const string& sep) {
  int pos = 0;
  vector<string> ret;
  while (pos < si(s)) {
    int nxt_pos = s.find(sep, pos);
    if (nxt_pos == -1) nxt_pos = si(s);
    if (nxt_pos - pos > 0) ret.pb(s.substr(pos, nxt_pos - pos));
    pos = nxt_pos + si(sep);
  }
  return ret;
}
int n;
void f(int k) {
  if (k == n) {
    for (auto l : a2) {
      for_in(k * 4) cout << "_";
      cout << l << "\n";
    }
    return;
  }
  for (auto l : a) {
    for_in(k * 4) cout << "_";
    cout << l << "\n";
  }
  f(k + 1);
  for_in(k * 4) cout << "_";
  cout << "라고 답변하였지.\n";
}
int main() {
  fastio;
  cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
  a = split(s, "\n");
  a2 = split(s2, "\n");
  cin >> n;
  f(0);
}