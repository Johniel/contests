// codeforces/568div2/B/main.cpp
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

bool fn(string s, string t)
{
  vector<pair<char, int>> v;
  vector<pair<char, int>> u;

  each (c, s) {
    if (v.empty() || v.back().first != c) {
      v.push_back({c, 0});
    }
    ++v.back().second;
  }

  each (c, t) {
    if (u.empty() || u.back().first != c) {
      u.push_back({c, 0});
    }
    ++u.back().second;
  }

  if (v.size() != u.size()) return false;
  for (int i = 0; i < v.size(); ++i) {
    if (v[i].first != u[i].first) return false;
    unless (v[i].second <= u[i].second) return false;
  }
  return true;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    for (int i = 0; i < n; ++i) {
      string s, t;
      cin >> s >> t;
      cout << (fn(s, t) ? "YES" : "NO") << endl;
    }
  }


  return 0;
}
