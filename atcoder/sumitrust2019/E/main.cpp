// atcoder/sumitrust2019/E/main.cpp
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

  const lli mod = 1000000007;

  int n;
  while (cin >> n) {
    vector<int> a(n);
    cin >> a;

    const int N = 100000 + 5;
    vector<int> idx[N];
    for (int i = 0; i < a.size(); ++i) {
      idx[a[i]].push_back(i);
    }
    bool f = true;
    for (int i = 0; i < n; ++i) {
      f = f && (idx[i + 1].size() <= idx[i].size());
      f = f && (idx[i].size() <= 3);
    }
    unless (f) {
      cout << 0 << endl;
      continue;
    }

    static lli dp[N];
    fill(dp, dp + N, 0);
    dp[0] = 1;

    const int m = *max_element(a.begin(), a.end());
    for (int i = 0; i < m; ++i) {
      const int j = i + 1;
      vector<int> x = idx[i];
      vector<int> y = idx[j];
      sort(y.begin(), y.end());
      sort(x.begin(), x.end());
      set<vector<int>> vis;
      do {
        vector<int> v;
        bool f = true;
        for (int k = 0; k < y.size(); ++k) {
          f = f && (x[k] <= y[k]);
          v.push_back(x[k]);
        }
        if (f && vis.count(v) == 0) {
          (dp[j] += dp[i]) %= mod;
          vis.insert(v);
        }
      } while (next_permutation(x.begin(), x.end()));
    }

    lli p;
    const int z = count(a.begin(), a.end(), 0);
    if (z == 1) p = 3;
    if (z == 2) p = 6;
    if (z == 3) p = 6;
    cout << (dp[m] * p) % mod << endl;
  }

  return 0;
}
