// atcoder/abc005/D/main.cpp
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

  int n;
  while (cin >> n) {
    vector<vector<lli>> g(n, vector<lli>(n, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> g[i][j];
      }
    }
    Acc2D acc(g);

    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int a = i + 1; a <= n; ++a) {
          for (int b = j + 1; b <= n; ++b) {
            int x = acc.query(i, j, a, b);
            int y = (a - i) * (b - j);
            v.push_back(make_pair(y, x));
          }
        }
      }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i + 1 < v.size(); ++i) {
      setmax(v[i + 1].second, v[i].second);
    }

    int q, p;
    cin >> q;
    while (q--) {
      cin >> p;
      auto itr = lower_bound(v.begin(), v.end(), make_pair(p + 1, -1));
      --itr;
      cout << itr->second << endl;
    }
  }

  return 0;
}
