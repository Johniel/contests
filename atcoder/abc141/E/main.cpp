// atcoder/abc141/E/main.cpp
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

  int n;
  string s;
  while (cin >> n >> s) {

    auto fn = [&] (int len) {
      map<ull, int> m;
      for (int i = 0; i + len <= s.size(); ++i) {
        ull h = 0;
        for (int j = 0; j < len; ++j) {
          h = h * 71 + (s[i + j] - 'a' + 1);
        }
        m[h] = i;
      }
      for (int i = 0; i + len <= s.size(); ++i) {
        ull h = 0;
        for (int j = 0; j < len; ++j) {
          h = h * 71 + (s[i + j] - 'a' + 1);
        }
        if (i + len <= m[h]) {
          return true;
        }
      }
      return false;
    };

    int small = 1;
    int large = 5000 + 5;
    while (small + 1 < large) {
      int mid = (small + large) / 2;
      if (fn(mid)) small = mid;
      else large = mid;
    }
    cout << (fn(small) ? small : 0) << endl;
  }

  return 0;
}
