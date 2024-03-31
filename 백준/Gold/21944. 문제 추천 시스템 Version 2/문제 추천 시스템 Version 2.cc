#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <unordered_map>

using namespace std;

int N, P, L, G, x;
string op;

pair<int, int> probLevel[100001];
set<int> probByL[101];
set<int> probByGL[101][101];

void insert_prop(int P, int L, int G) {
  probLevel[P] = {L, G};
  probByL[L].insert(P);
  probByGL[G][L].insert(P);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  while (N--) {
    cin >> P >> L >> G;
    insert_prop(P, L, G);
  }
  cin >> N;
  while (N--) {
    cin >> op;

    if (op == "recommend") {
      cin >> G >> x;
      if (x == 1) {
        for (int i = 100; i > 0; i--) {
          if (probByGL[G][i].empty()) continue;
          cout << *prev(probByGL[G][i].end()) << "\n";
          break;
        }
      } else {
        for (int i = 1; i < 101; i++) {
          if (probByGL[G][i].empty()) continue;
          cout << *probByGL[G][i].begin() << "\n";
          break;
        }
      }
    } else if (op == "recommend2") {
      cin >> x;
      if (x == 1) {
        for (int i = 100; i > 0; i--) {
          if (probByL[i].empty()) continue;
          cout << *(prev(probByL[i].end())) << "\n";
          break;
        }
      } else {
        for (int i = 1; i < 101; i++) {
          if (probByL[i].empty()) continue;
          cout << *probByL[i].begin() << "\n";
          break;
        }
      }
    } else if (op == "recommend3") {
      cin >> x >> L;
      int ans = -1;
      if (x == 1) {
        for (int i = L; i < 101; i++) {
          if (probByL[i].empty()) continue;
          ans = *probByL[i].begin();
          break;
        }
      } else {
        for (int i = L - 1; i > 0; i--) {
          if (probByL[i].empty()) continue;
          ans = *prev(probByL[i].end());
          break;
        }
      }
      cout << ans << "\n";
    } else if (op == "add") {
      cin >> P >> L >> G;
      insert_prop(P, L, G);
    } else {
      cin >> P;
      tie(L, G) = probLevel[P];
      probByL[L].erase(P);
      probByGL[G][L].erase(P);
    }
  }
}