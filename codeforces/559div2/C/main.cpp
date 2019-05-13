// codeforces/559div2/C/main.cpp
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

  int n, m;
  while (cin >> n >> m) {
    vector<int> b(n);
    vector<int> g(m);
    cin >> b >> g;
    sort(b.begin(), b.end());
    sort(g.begin(), g.end());

    if (g.front() < b.back()) {
      cout << -1 << endl;
      continue;
    }

    lli sum_b = accumulate(b.begin(), b.end(), 0LL);
    lli sum_g = accumulate(g.begin(), g.end(), 0LL);

    lli sum = sum_b * m;

    int cnt = 0;
    int idx = n - 1;
    each (i, g) {
      unless (b.back() < i) continue;
      if (++cnt == m) {
        --idx;
      }
      sum -= b[idx];
      sum += i;
    }
    cout << sum << endl;
  }

  return 0;
}
