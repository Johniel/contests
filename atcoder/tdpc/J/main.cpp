// atcoder/tdpc/J/main.cpp
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

const int N = 16;
const int BIT = 1 << N;
double memo[BIT];
double rec(int bit)
{
  double& ret = memo[bit];
  unless (ret < 0) return ret;

  double mn = 1e128;
  for (int i = 1; i + 1 < N; ++i) {
    const int a = 1 << (i - 1);
    const int b = 1 << i;
    const int c = 1 << (i + 1);

    int x = bit & (a | b | c);
    unless (__builtin_popcount(x)) continue;

    double e = 0;
    if (x == a) e = rec(bit ^ a) + 3.0;
    if (x == b) e = rec(bit ^ b) + 3.0;
    if (x == c) e = rec(bit ^ c) + 3.0;

    if (x == a + b) e = (rec(bit ^ a) + rec(bit ^ b)) / 2.0 + 1.5;
    if (x == b + c) e = (rec(bit ^ b) + rec(bit ^ c)) / 2.0 + 1.5;
    if (x == a + c) e = (rec(bit ^ a) + rec(bit ^ c)) / 2.0 + 1.5;

    if (x == a + b + c) e = 1.0 + (rec(bit ^ a) + rec(bit ^ b)  + rec(bit ^ c)) / 3.0;

    setmin(mn, e);
  }

  return ret = mn;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<int> x(n);
    cin >> x;

    int bit = 0;
    each (i, x) bit = bit | (1 << i);

    fill(memo, memo + BIT, -1);
    memo[0] = 0;
    printf("%.10lf\n", rec(bit));
  }

  return 0;
}
