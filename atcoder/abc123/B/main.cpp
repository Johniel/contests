// atcoder/abc123/B/main.cpp
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

  int a, b, c, d, e;
  while (cin >> a >> b >> c >> d >> e) {
    vector<int> v({a, b, c, d, e});
    int mn = 1 << 29;
    sort(v.begin(), v.end());
    do {
      int mx = 0;
      int t = 0;
      each (i, v) {
        t += i;
        setmax(mx, t);
        if (t % 10) t = t + 10 - (t % 10);
      }
      setmin(mn, mx);
    } while (next_permutation(v.begin(), v.end()));
    cout << mn << endl;
  }

  return 0;
}
