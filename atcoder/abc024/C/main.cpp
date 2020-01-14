// atcoder/abc024/C/main.cpp
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

  int n, d, k;
  while (cin >> n >> d >> k) {
    vector<pair<int, int>> v(d);
    cin >> v;
    while (k--) {
      int s, t;
      cin >> s >> t;
      bool ord = (s < t);
      for (int i = 0; i < v.size(); ++i) {
        if (v[i].first <= s && s <= v[i].second) {
          if (ord) s = v[i].second;
          else s = v[i].first;
        }
        if (ord && t <= s) {
          cout << i + 1 << endl;
          break;
        }
        if (!ord && s <= t) {
          cout << i + 1 << endl;
          break;
        }
      }
    }
  }

  return 0;
}
