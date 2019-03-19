// codeforces/547div3/D/main.cpp
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
  string s, t;
  while (cin >> n >> s >> t) {
    map<char, vector<int>> a, b;
    for (int i = 0; i < s.size(); ++i) {
      a[s[i]].push_back(i);
    }
    for (int i = 0; i < t.size(); ++i) {
      b[t[i]].push_back(i);
    }

    vector<pair<int, int>> v;

    for (char c = 'a'; c <= 'z'; ++c) {
      while (a[c].size() && b[c].size()) {
        v.push_back({a[c].back(), b[c].back()});
        a[c].pop_back();
        b[c].pop_back();
      }
    }

    for (char c = 'a'; c <= 'z'; ++c) {
      while (a['?'].size() && b[c].size()) {
        v.push_back({a['?'].back(), b[c].back()});
        a['?'].pop_back();
        b[c].pop_back();
      }
    }

    for (char c = 'a'; c <= 'z'; ++c) {
      while (a[c].size() && b['?'].size()) {
        v.push_back({a[c].back(), b['?'].back()});
        a[c].pop_back();
        b['?'].pop_back();
      }
    }

    while (a['?'].size() && b['?'].size()) {
      v.push_back({a['?'].back(), b['?'].back()});
      a['?'].pop_back();
      b['?'].pop_back();
    }

    cout << v.size() << endl;
    each (i, v) cout << i.first + 1 << ' ' << i.second + 1 << endl;
    each (i, v) assert(s[i.first] == t[i.second] || s[i.first] == '?' || t[i.second] == '?');
  }

  return 0;
}
