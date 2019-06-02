// atcoder/agc034/A/main.cpp
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

  int n, a, b, c, d;
  string s;
  while (cin >> n >> a >> b >> c >> d >> s) {
    s = "#" + s + "##";
    bool f = true;
    unless (a <= c && b <= d) {
      f = false;
    }

    if ((a < b && d < c) || (b < a && c < d)) {
      bool x = false;
      for (int i = max(a, b) - 1; i + 1 <= min(c, d); ++i) {
        x = x || (s[i] == '.' && s[i + 1] == '.' && s[i + 2] == '.');
      }
      f = f && x;
    } else {
      for (int i = a; i + 1 <= c; ++i) {
        f = f && !(s[i] == '#' && s[i + 1] == '#');
      }
      for (int i = b; i + 1 <= d; ++i) {
        f = f && !(s[i] == '#' && s[i + 1] == '#');
      }
    }
    cout << (f ? "Yes" : "No") << endl;
  }

  return 0;
}
