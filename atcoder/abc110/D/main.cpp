#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template <typename P, typename Q>
ostream& operator<<(ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

template <typename T>
ostream& operator<<(ostream& os, vector<T> v)
{
  os << "(";
  each (i, v)
    os << i << ",";
  os << ")";
  return os;
}

int main(int argc, char* argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  const lli mod = 1e9 + 7;
  const int N = 1e5 + 40;
  const int K = 32;

  static int nck[N][K];
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

  int n, m;
  while (cin >> n >> m) {
    map<int, int> cnt;
    for (int i = 2; i * i <= m; ++i) {
      while (m % i == 0) {
        ++cnt[i];
        m /= i;
      }
    }
    if (m != 1) ++cnt[m];

    lli x = 1;
    each (i, cnt) {
      x *= nck[n + i.second - 1][i.second];
      x %= mod;
    }
    cout << x << endl;
  }

  return 0;
}
