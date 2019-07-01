// atcoder/abc132/D/main.cpp
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

  const lli mod = 1e9 + 7;
  const int N = 4000 + 5;
  const int K = 4000 + 5;

  static lli nck[N][K];
  fill(&nck[0][0], &nck[N - 1][K - 1] + 1, 0);
  for (int i = 0; i < N; ++i) {
    nck[i][0] = 1;
  }
  for (int n = 1; n < N; ++n) {
    for (int k = 1; k < K; ++k) {
      nck[n][k] = nck[n - 1][k - 1] + nck[n - 1][k];
      nck[n][k] %= mod;
    }
  }

  int n, k;
  while (cin >> n >> k) {
    for (int i = 0; i < k; ++i) {
      lli x = nck[k - 1][i] * nck[(i + 1) + (n - k - i)][(i + 1)];
      x %= mod;
      cout << x << endl;
    }
  }

  return 0;
}
