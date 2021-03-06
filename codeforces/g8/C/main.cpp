// codeforces/g8/C/main.cpp
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

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  lli n;
  while (cin >> n) {
    int di[] = {1, 1, 0, 1};
    int dj[] = {0, 1, 1, 1};
    set<pair<int, int>> vis;
    vis.insert({0, 0});
    vis.insert({1, 0});
    vis.insert({0, 1});
    for (int i = 0; i < n; ++i) {
      lli x = i + 1;
      lli y = i + 1;
      for (int d = 0; d < 4; ++d) {
        lli nx = x + di[d];
        lli ny = y + dj[d];
        vis.insert({nx, ny});
      }
      vis.insert({x, y});
    }
    cout << vis.size() << endl;
    each (i, vis) cout << i.first << ' ' << i.second << endl;
  }

  return 0;
}
