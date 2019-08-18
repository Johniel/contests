// atcoder/abc138/E/main.cpp
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

  string s, t;
  while (cin >> s >> t) {
    {
      set<char> vis(s.begin(), s.end());
      bool f = true;
      each (c, t) f = f && vis.count(c);
      unless (f) {
        cout << -1 << endl;
        continue;
      }
    }

    const int N = 1e5 + 5;
    static map<char, lli> next[N];
    static map<char, lli> prev[N];
    for (int i = 0; i < N; ++i) {
      prev[i].clear();
      next[i].clear();
    }
    map<char, lli> last;

    last.clear();
    for (int i = s.size() - 1; 0 <= i; --i) {
      next[i] = last;
      last[s[i]] = i;
    }

    last.clear();
    for (int i = 0; i < s.size(); ++i) {
      prev[i] = last;
      if (last.count(s[i]) == 0) {
        last[s[i]] = i;
      }
    }

    lli x = 0, y = 0, z = 0;
    if (s[0] != t[0]) {
      char c = t[0];
      if (next[x].count(c)) {
        x = next[x][c];
      } else if (prev[x].count(c)) {
        x = prev[x][c];
      } else {
        x = x;
      }
      y = x;
    }

    for (int i = 1; i < t.size(); ++i) {
      char c = t[i];
      if (next[x].count(c)) {
        y = next[x][c];
      } else if (prev[x].count(c)) {
        y = prev[x][c];
        ++z;
      } else {
        y = x;
        ++z;
      }
      x = y;
    }
    cout << y + z * s.size() + 1 << endl;
  }

  return 0;
}
