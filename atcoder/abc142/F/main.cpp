// atcoder/abc142/F/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { each (i, v) is >> i; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

const int N = 1000 + 5;

vector<int> g[N];
bool vis[N];
stack<int> S;
stack<int> T;
bool rec(int curr, int prev)
{
  vis[curr] = true;
  S.push(curr);

  int cnt = 0;
  each (next, g[curr]) {
    cnt += vis[next];
  }
  if (cnt == 1) {
    throw "";
  }
  if (cnt == 0) {
    each (next, g[curr]) {
      if (next == prev) continue;
      if (vis[next]) continue;
      rec(next, curr);
    }
  }

  S.pop();
  vis[curr] = false;
  return false;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    fill(g, g + N, vector<int>());
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
    }

    T = stack<int>();
    for (int i = 0; i < n+1; ++i) {
      T.push(i);
    }

    bool f = false;
    fill(vis, vis + N, false);
    for (int i = 0; i < n; ++i) {
      try {
        S = stack<int>();
        rec(i, -1);
      } catch (const char* e) {
        fill(vis, vis + N, false);
        f = true;
        if (S.size() < T.size()) T = S;
      }
    }

    if (n < T.size()) cout << -1 << endl;
    else {
      cout << T.size() << endl;
      while (T.size()) {
        cout << T.top() + 1 << endl;
        T.pop();
      }
    }
  }

  return 0;
}
