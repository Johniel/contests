// atcoder/tdpc/L/main.cpp
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

struct Acc {
  vector<lli> sum;
  Acc(vector<lli> v) {
    sum.push_back(0);
    each (i, v) {
      sum.push_back(sum.back() + i);
    }
  }
  lli query(lli begin, lli end) {
    return sum[end] - sum[begin];
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    const int N = 1000 + 5;
    vector<Acc> v;
    for (int i = 0; i < n; ++i) {
      vector<lli> u(n);
      cin >> u;
      v.push_back(Acc(u));
    }
    static lli dp[N][N];
    fill(&dp[0][0], &dp[N - 1][N - 1] + 1, -(1LL << 60));
    for (int i = 0; i < N; ++i) {
      dp[i][i] = 0;
    }

    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= i; ++j) {
        setmax(dp[i][j], dp[i - 1][j] + v[i - 1].query(j, i) * 2);
      }
      for (int j = 0; j + 1 <= i; ++j) {
        setmax(dp[i][j + 1], dp[i][j]);
      }
    }

    cout << *max_element(&dp[0][0], &dp[N - 1][N - 1] + 1) << endl;
  }

  return 0;
}
