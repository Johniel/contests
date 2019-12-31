// atcoder/abc032/D/main.cpp
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

lli fn1(int n, lli w, vector<pair<lli, lli>> v /* v,w */)
{
  n = v.size() / 2;
  const int m = v.size() - n;

  lli mx = 0 ;

  const int N = 16;
  const int BIT = (1 << N);
  static pair<lli, lli> dp[BIT]; // w,v
  for (int bit = 0; bit < (1 << n); ++bit) {
    for (int i = 0; i < n; ++i) {
      if (bit & (1 << i)) {
        dp[bit].first += v[i].second;
        dp[bit].second += v[i].first;
      }
    }
    if (dp[bit].first <= w) {
      setmax(mx, dp[bit].second);
    }
  }
  sort(dp, dp + BIT);
  for (int i = 0; i + 1 < BIT; ++i) {
    setmax(dp[i + 1].second, dp[i].second);
  }

  for (int bit = 0; bit < (1 << m); ++bit) {
    lli a = 0;
    lli b = 0;
    for (int i = 0; i < m; ++i) {
      if (bit & (1 << i)) {
        a += v[i + n].first;
        b += v[i + n].second;
      }
    }
    if (b <= w) setmax(mx, a);
    int i = lower_bound(dp, dp + BIT, make_pair(w - b + 1LL, -1LL)) - dp;
    if (i) {
      setmax(mx, a + dp[i - 1].second);
    }
  }

  return mx;
}

// wi <= 1000
lli fn2(int n, int w, const vector<pair<lli, lli>>& v)
{
  const int W = 200 * 1000 + 5;
  static lli dp[W];
  fill(dp, dp + W, 0);

  each (j, v) {
    for (int i = W - 1; 0 <= i; --i) {
      if (i + j.second <= min(W, w)) {
        setmax(dp[i + j.second], dp[i] + j.first);
      }
    }
  }

  return *max_element(dp, dp + W);
}

// vi <= 1000
lli fn3(int n, int w, const vector<pair<lli, lli>>& v)
{
  const int V = 200 * 1000 + 5;
  static lli dp[V];
  fill(dp, dp + V, 1LL << 60);
  dp[0] = 0;

  each (j, v) {
    for (int i = V - 1; 0 <= i; --i) {
      if (i + j.first < V) {
        setmin(dp[i + j.first], dp[i] + j.second);
      }
    }
  }

  lli mx = 0;
  for (int i = 0; i < V; ++i) {
    if (dp[i] <= w) mx = i;
  }
  return mx;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  lli w;
  while (cin >> n >> w) {
    vector<pair<lli, lli>> v(n);
    cin >> v;

    lli mx_v = 0;
    each (i, v) setmax(mx_v, i.first);
    lli mx_w = 0;
    each (i, v) setmax(mx_w, i.second);

    if (0) ;
    else if (mx_w <= 1000) cout << fn2(n, w, v) << endl;
    else if (mx_v <= 1000) cout << fn3(n, w, v) << endl;
    else cout << fn1(n, w, v) << endl;
  }

  return 0;
}
