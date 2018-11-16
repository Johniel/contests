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
    vector<int> g[n];
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    const int N = 1e5 + 5;
    const int D = 10 + 3;
    int dp[N][D];
    fill(&dp[0][0], &dp[N - 1][D - 1] + 1, -1);

    map<int, int> color;

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
      int v, d, c;
      cin >> v >> d >> c;
      color[i + 1] = c;
      --v;
      dp[v][d] = i + 1;
    }

    for (int i = D - 1; 0 <= i - 1; --i) {
      for (int curr = 0; curr < n; ++curr) {
        each (next, g[curr]) {
          setmax(dp[next][i - 1], dp[curr][i]);
        }
      }
    }

    map<int, int> mx;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < D; ++j) {
        setmax(mx[i], dp[i][j]);
      }
    }

    for (int i = 0; i < n; ++i) {
      cout << color[mx[i]] << endl;
    }
    cout << endl;
  }

  return 0;
}
