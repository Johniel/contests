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
    using Block = struct {
      lli w, s, v;
    };
    vector<Block> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i].w >> v[i].s >> v[i].v;
    }
    sort(v.begin(), v.end(), [] (auto a, auto b) { return a.w + a.s < b.w + b.s; });

    const int N = 1000 + 5;
    const int M = 20000 + 5;
    static lli dp[N][M];
    fill(&dp[0][0], &dp[N - 1][M - 1], 0);

    for (int i = 0; i < v.size(); ++i) {
      for (int j = 0; j < M; ++j) {
        setmax(dp[i + 1][j], dp[i][j]);
      }
      for (int j = 0; j <= v[i].s; ++j) {
        setmax(dp[i + 1][j + v[i].w], dp[i][j] + v[i].v);
      }
    }
    cout << *max_element(&dp[0][0], &dp[N - 1][M - 1] + 1) << endl;
  }

  return 0;
}
