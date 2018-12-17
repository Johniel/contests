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

  int n, m, r;
  while (cin >> n >> m >> r) {
    const lli inf = 1LL << 60;
    const int N = 200 + 3;
    static lli g[N][N];
    fill(&g[0][0], &g[N - 1][N - 1] + 1, inf);

    vector<int> v(r);
    cin >> v;
    each (i, v) --i;

    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      g[a][b] = g[b][a] = c;
    }
    for (int k = 0; k < N; ++k) {
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          setmin(g[i][j], g[i][k] + g[k][j]);
        }
      }
    }

    lli mn = inf;
    sort(v.begin(), v.end());
    do {
      lli sum = 0;
      for (int i = 0; i + 1 < v.size(); ++i) {
        sum += g[v[i]][v[i + 1]];
      }
      setmin(mn, sum);
    } while (next_permutation(v.begin(), v.end()));
    cout << mn << endl;
  }

  return 0;
}
