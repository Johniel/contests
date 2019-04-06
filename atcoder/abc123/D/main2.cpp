// atcoder/abc123/D/main2.cpp
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

  int x, y, z;
  lli k;
  while (cin >> x >> y >> z >> k) {
    vector<lli> a(x);
    vector<lli> b(y);
    vector<lli> c(z);
    cin >> a >> b >> c;

    vector<lli> d;
    each (i, a) each (j, b) d.push_back(i + j);
    sort(begin(d), end(d));
    reverse(begin(d), end(d));
    while (k < d.size()) d.pop_back();

    vector<lli> e;
    each (i, d) each (j, c) e.push_back(i + j);
    sort(begin(e), end(e));
    reverse(begin(e), end(e));
    while (k < e.size()) e.pop_back();

    each (i, e) cout << i << endl;
  }

  return 0;
}
