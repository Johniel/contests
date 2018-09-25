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

template<typename T>
struct Acc2D {
  vector<vector<T>> sum;
  Acc2D(vector<vector<T>> v) {
    const int N = v.size() + 1;
    sum.resize(N);
    fill(sum.begin(), sum.end(), vector<T>(N, 0));
    for (int i = 0; i < v.size(); ++i) {
      for (int j = 0; j < v.size(); ++j) {
        sum[i + 1][j + 1] = v[i][j] - sum[i][j] + sum[i][j + 1] + sum[i + 1][j];
      }
    }
  }
  T query(int ai, int aj, int bi, int bj) {
    return sum[bi][bj] + sum[ai][aj] - sum[ai][bj] - sum[bi][aj];
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  while (cin >> n >> k) {
    vector<pair<int, int>> b;
    vector<pair<int, int>> w;
    for (int i = 0; i < n; ++i) {
      int p, q;
      char c;
      cin >> p >> q >> c;
      if (c == 'B') b.push_back(make_pair(p, q));
      if (c == 'W') w.push_back(make_pair(p, q));
    }

    each (i, b) {
      i.first %= 2 * k;
      i.second %= 2 * k;
    }
    each (i, w) {
      i.first += k;
      i.first %= 2 * k;
      i.second %= 2 * k;
    }

    vector<vector<int>> g(2 * k, vector<int>(2 * k, 0));

    each (i, b) ++g[i.first][i.second];
    each (i, w) ++g[i.first][i.second];

    Acc2D<int> acc(g);

    int mx = 0;
    for (int i = 0; i < k; ++i) {
      for (int j = 0; j < k; ++j) {
        int sum = 0;

        sum += acc.query(0, 0, i, j);
        sum += acc.query(i, j, i+k, j+k);
        sum += acc.query(i+k, j+k, k+k, k+k);

        sum += acc.query(0, j+k, i, k+k);
        sum += acc.query(i+k, 0, k+k, j);

        mx = max({mx, sum, n - sum});
      }
    }
    cout << mx << endl;
  }

  return 0;
}
