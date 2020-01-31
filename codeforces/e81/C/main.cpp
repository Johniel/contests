// codeforces/e81/C/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }
template<typename T> inline pair<T, T> reverse(pair<T, T> p) { return make_pair(p.second, p.first); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;

constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int tc;
  cin >> tc;
  string s, t;
  while (cin >> s >> t) {
    map<char, vector<int>> idx;
    for (int i = 0; i < s.size(); ++i) {
      idx[s[i]].push_back(i);
    }
    string u;
    int curr = 0;
    int cnt = 1;
    each (c, t) {
      auto itr = lower_bound(idx[c].begin(), idx[c].end(), curr);
      if (itr == idx[c].end()) {
        ++cnt;
        curr = 0;
        itr = lower_bound(idx[c].begin(), idx[c].end(), curr);
        if (itr == idx[c].end()) {
          cnt = -1;
          break;
        }
      }
      u += s[*itr];
      curr = (*itr) + 1;
    }
    if (cnt != -1) assert(u == t);
    cout << cnt << endl;
  }


  return 0;
}
