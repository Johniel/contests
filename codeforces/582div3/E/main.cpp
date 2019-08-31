// codeforces/582div3/E/main.cpp
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
  while (cin >> n) {
    string s, t, u, x;
    cin >> s >> t;
    cout << "YES" << endl;
    const string C = "abc";
    if (s[0] != s[1] && t[0] != t[1]) {
      each (i0, C) each (i1, C) each (i2, C) {
        if (i0 == i1 || i1 == i2 || i2 == i0) continue;
        u = string("") + i0 + i0 + i1 + i1 + i2 + i2;
        if (u.find(s) != string::npos) continue;
        if (u.find(t) != string::npos) continue;
        x = u;
      }
      for (int i = 0; i < n; ++i) cout << x[0];
      for (int i = 0; i < n; ++i) cout << x[2];
      for (int i = 0; i < n; ++i) cout << x[4];
      cout << endl;
    } else {
      each (i0, C) each (i1, C) each (i2, C) {
        if (i0 == i1 || i1 == i2 || i2 == i0) continue;
        u = string("") + i0 + i1 + i2 + i0;
        if (u.find(s) != string::npos) continue;
        if (u.find(t) != string::npos) continue;
        x = u;
      }
      for (int i = 0; i < n; ++i) {
        cout << x[0] << x[1] << x[2];
      }
      cout << endl;
    }

  }

  return 0;
}
