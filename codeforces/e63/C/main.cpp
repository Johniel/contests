// codeforces/e63/C/main.cpp
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

lli gcd(lli a, lli b)
{
  unless (a > b) swap(a, b);
  return b ? gcd(b, a % b) : a;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    vector<lli> x(n);
    vector<lli> p(m);
    cin >> x >> p;

    vector<lli> v;
    for (int i = 0; i + 1 < x.size(); ++i) {
      v.push_back(x[i + 1] - x[i]);
    }
    sort(begin(v), end(v));
    lli g = v.front();
    each (i, v) g = gcd(g, i);

    lli y = -1;
    for (int i = 0; i < p.size(); ++i) {
      if (g % p[i] == 0) {
        y = i;
        break;
      }
    }
    if (y == -1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      cout << x.front() << ' ' << y + 1 << endl;
    }
  }

  return 0;
}
