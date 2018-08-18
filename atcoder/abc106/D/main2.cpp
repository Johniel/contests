#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q>
ostream& operator << (ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

template<typename T>
ostream& operator << (ostream& os, vector<T> v)
{
  os << "(";
  each (i, v) os << i << ",";
  os << ")";
  return os;
}

struct Acc2D {
  vector<vector<lli>> sum;
  Acc2D(vector<vector<lli>> v) {
    const int N = v.size() + 1;
    sum.resize(N);
    fill(sum.begin(), sum.end(), vector<lli>(N, 0));
    for (int i = 0; i < v.size(); ++i) {
      for (int j = 0; j < v.size(); ++j) {
        sum[i + 1][j + 1] = v[i][j];
      }
    }
    for (int i = 1; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        sum[i][j] += sum[i - 1][j];
      }
    }
    for (int i = 0; i < N; ++i) {
      for (int j = 1; j < N; ++j) {
        sum[i][j] += sum[i][j - 1];
      }
    }
  }
  lli query(int ai, int aj, int bi, int bj) {
    return sum[bi][bj] + sum[ai][aj] - sum[ai][bj] - sum[bi][aj];
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

    int n, m, q;
  while (cin >> n >> m >> q) {
    vector<vector<lli>> g(n);
    fill(g.begin(), g.end(), vector<lli>(n, 0));

    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      ++g[a][b];
    }

    Acc2D acc(g);
    while (q--) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      cout << acc.query(a, a, b + 1, b + 1) << endl;
    }
  }
  
  return 0;
}
