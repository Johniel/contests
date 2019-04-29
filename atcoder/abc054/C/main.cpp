// atcoder/abc054/C/main.cpp
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

  int n, m;
  while (cin >> n >> m) {
    bool g[n][n];
    fill(&g[0][0], &g[n - 1][n - 1] + 1, false);
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a][b] = g[b][a] = true;
    }
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      v.push_back(i);
    }
    int cnt = 0;
    sort(v.begin(), v.end());
    do {
      bool f = (v.front() == 0);
      for (int i = 0; i + 1 < v.size(); ++i) {
        f = f && g[v[i]][v[i + 1]];
      }
      cnt += f;
    } while (next_permutation(v.begin(), v.end()));
    cout << cnt << endl;
  }
  
  return 0;
}
