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

const lli mod = 1e9 + 7;

template<int N = 50>
struct M {
  lli x[N][N];
  M()
  {
    fill(&x[0][0], &x[N - 1][N - 1], 0);
  }
};



template<int N>
M<N> operator * (M<N> a, M<N> b)
{
  M<N> c;
  for (int k = 0; k < N; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        (c.x[i][j] += a.x[i][k] * b.x[k][j]) %= mod;
      }
    }
  }
  return c;
}

template<int N>
M<N> power(M<N> m, lli p)
{
  if (p == 1) return m;
  if (p == 0) {
    M<N> e;
    for (int i = 0; i < N; ++i) {
      e.x[i][i] = 1;
    }
    return e;
  }

  M<N> a = power(m, p / 2);
  if (p % 2) return a * a * m;
  else return a * a;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  lli k;
  while (cin >> n >> k) {
    M<50> m;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> m.x[i][j];
      }
    }
    m = power(m, k);
    lli sum = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        (sum += m.x[i][j]) %= mod;
      }
    }
    cout << sum << endl;
  }
  
  return 0;
}
