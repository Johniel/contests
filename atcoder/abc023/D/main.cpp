// atcoder/abc023/D/main.cpp
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

constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<pair<lli, lli>> v(n);
    cin >> v;

    function<lli(lli)> fn = [&] (lli t) {
      vector<lli> u;
      each (i, v) {
        lli sec = (t - i.first) / i.second;
        // if ((t - i.first) % i.second) --sec;
        u.push_back(sec);
      }
      sort(u.begin(), u.end());
      for (int i = 0; i < u.size(); ++i) {
        unless (i <= u[i]) {
          return false;
        }
      }
      return true;
    };

    lli small = 0;
    each (i, v) {
      setmax(small, i.first);
    }

    lli large = 1LL << 50;
    while (small + 1 < large) {
      lli mid = (small + large) / 2;
      if (fn(mid)) large = mid;
      else small = mid;
    }
    if (fn(small)) cout << small << endl;
    else cout << large << endl;
  }

  return 0;
}
