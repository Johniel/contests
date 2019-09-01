// atcoder/abc139/E/main.cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    const int N = 1000 + 5;

    static int g[N][N];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n - 1; ++j) {
        cin >> g[i][j];
        --g[i][j];
      }
    }

    queue<int> q[n];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n - 1; ++j) {
        q[i].push(g[i][j]);
      }
    }

    static bool vis[N];
    int x = 0;
    while (true) {
      bool f = false;
      fill(vis, vis + N, false);
      for (int i = 0; i < n; ++i) {
        if (vis[i] || q[i].empty()) continue;
        int j = q[i].front();
        if (vis[j] || q[j].empty()) continue;
        if (q[j].front() == i) {
          q[i].pop();
          q[j].pop();
          vis[i] = true;
          vis[j] = true;
          f = true;
        }
      }
      if (!f) break;
      ++x;
    }
    bool f = true;
    for (int i = 0; i < n; ++i) {
      f = f && q[i].empty();
    }
    cout << (f ? x : -1) << endl;
  }

  return 0;
}
