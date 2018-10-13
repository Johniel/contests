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

lli gcd(lli a, lli b)
{
  unless (a > b) swap(a, b);
  return b ? gcd(b, a % b) : a;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n, m;
  string s, t;
  while (cin >> n >> m >> s >> t) {
    lli lcm = n * m / gcd(n, m);
    map<lli, char> x;
    for (int i = 0; i < s.size(); ++i) {
      x[i * lcm / n] = s[i];
    }
    bool f = true;
    for (int i = 0; i < t.size(); ++i) {
      if (x.count(i * lcm / m)) {
        f = f && (x[i * lcm / m] == t[i]);
      }
    }
    if (!f) cout << -1 << endl;
    else cout << n * m / gcd(n, m) << endl;
  }
  
  return 0;
}
