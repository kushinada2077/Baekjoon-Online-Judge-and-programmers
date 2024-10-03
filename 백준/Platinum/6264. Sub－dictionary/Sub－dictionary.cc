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

const int MX = 3001;
int n, cnt, SN, hash_cnt;
int dfsn[MX], scc[MX], indg[MX], scc_indg[MX];
bool finished[MX], chk[MX], in_ans[MX], scc_chk[MX][MX];
vector<int> scc_elem[MX], adj[MX], scc_r_adj[MX], ans;
vector<string> r_hash;
vector<pair<int, int>> edge;
stack<int> s;
string line;
unordered_map<string, int> w_hash;
vector<string> split(const string& s, const string& sep) {
  int pos = 0;
  vector<string> ret;
  while (pos < si(s)) {
    int nxt_pos = s.find(sep, pos);
    if (nxt_pos == -1) nxt_pos = si(s);
    if (nxt_pos > pos) ret.pb(s.substr(pos, nxt_pos - pos));
    pos = nxt_pos + si(sep);
  }
  return ret;
}
void trace(int cur) {
  for (auto& nxt : scc_r_adj[cur]) {
    trace(nxt);
    for (auto& e : scc_elem[nxt]) {
      if (in_ans[e] == 0) {
        in_ans[e] = 1;
        ans.pb(e);
      }
    }
  }
}
void init() {
  cnt = SN = hash_cnt = 0;
  edge.clear();
  w_hash.clear();
  r_hash = vector<string>(MX);
  ans.clear();
  for (int i = 0; i < n + 1; ++i) {
    in_ans[i] = dfsn[i] = scc[i] = finished[i] = indg[i] = scc_indg[i] = chk[i] = 0;
    scc_elem[i].clear();
    adj[i].clear();
    scc_r_adj[i].clear();
    for (int j = 0; j < n + 1; ++j) scc_chk[i][j] = 0;
  }
}
int dfs(int cur) {
  dfsn[cur] = ++cnt;
  s.push(cur);
  int res = dfsn[cur];

  for (auto& nxt : adj[cur]) {
    if (dfsn[nxt] == 0) res = min(res, dfs(nxt));
    else if (finished[nxt] == 0) res = min(res, dfsn[nxt]);
  }

  if (dfsn[cur] == res) {
    while (1) {
      int curr = s.top();
      s.pop();
      finished[curr] = 1;
      scc[curr] = SN;
      scc_elem[SN].pb(curr);
      if (cur == curr) break;
    }
    SN++;
  }
  return res;
}

int main() {
  fastio;
  while (1) {
    cin >> n;
    cin.ignore(1);
    if (n == 0) break;
    init();
    for (int i = 0; i < n; ++i) {
      getline(cin, line);
      vector<string> word = split(line, " ");
      int v;
      if (w_hash[word[0]] == 0) {
        v = ++hash_cnt;
        w_hash[word[0]] = v;
        r_hash[v] = word[0];
      } else {
        v = w_hash[word[0]];
      }
      unordered_set<string> dup;
      for (int i = 1; i < si(word); ++i) {
        string& w = word[i];
        if (dup.contains(w)) continue;
        int u;
        if (w_hash[w] == 0) {
          u = ++hash_cnt;
          w_hash[w] = u;
          r_hash[u] = w;
        } else {
          u = w_hash[w];
        }
        adj[u].pb(v);
        edge.pb({u, v});
        dup.insert(w);
      }
    }

    for (int i = 1; i <= hash_cnt; ++i) {
      if (dfsn[i] == 0) dfs(i);
    }

    for (auto& [u, v] : edge) {
      indg[v]++;
      if (scc[u] != scc[v]) {
        scc_indg[scc[v]]++;
        if (scc_chk[scc[v]][scc[u]] == 0) {
          scc_r_adj[scc[v]].pb(scc[u]);
          scc_chk[scc[v]][scc[u]] = 1;
        }
      }
    }

    queue<int> q;

    for (int i = 0; i < SN; ++i) {
      if (scc_indg[i] == 0) q.push(i);
    }

    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      auto& cur_elem_arr = scc_elem[cur];
      bool f = 0;
      for (auto& cur_elem : cur_elem_arr) {
        if (!chk[cur_elem]) {
          f = 1;
          break;
        }
      }

      if (f) {
        for (auto& cur_elem : cur_elem_arr) {
          if (!chk[cur_elem]) {
            ans.pb(cur_elem);
            chk[cur_elem] = 1;
            in_ans[cur_elem] = 1;
          }
        }
        trace(cur);
      }

      for (auto& cur_elem : cur_elem_arr) {
        for (auto& nxt_elem : adj[cur_elem]) {
          if (scc[cur_elem] == scc[nxt_elem]) continue;
          if (--indg[nxt_elem] == 0) chk[nxt_elem] = 1;
          if (--scc_indg[scc[nxt_elem]] == 0) q.push(scc[nxt_elem]);
        }
      }
    }

    sort(all(ans));
    ans.erase(unique(all(ans)), ans.end());
    vector<string> tmp;
    for (auto& a : ans) tmp.pb(r_hash[a]);
    sort(all(tmp));
    cout << si(ans) << "\n";
    for (auto& word : tmp) cout << word << " ";
    cout << "\n";
  }
}