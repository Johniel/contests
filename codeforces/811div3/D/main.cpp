// codeforces/811div3/D/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int _;
  cin >> _;

  int n;
  str s;
  while (cin >> s >> n) {
    vec<str> v(n);
    cin >> v;

    const int N = s.size() + 12;
    vec<int> g[N];
    for (int i = 0; i < s.size(); ++i) {
      for (int j = 0; j < v.size(); ++j) {
        int x = 0;
        for (int k = 0; k < v[j].size() && i + k < s.size(); ++k) {
          x += (s[i + k] == v[j][k]);
        }
        if (x == v[j].size()) g[i].push_back(j);
      }
    }

    int dp[N];
    const int inf = (1 << 27);
    fill(dp, dp + N, inf);
    dp[0] = 0;
    pair<int, int> path[N];
    fill(path, path + N, make_pair(-1, -1));
    for (int i = 0; i < s.size(); ++i) {
      each (j, g[i]) {
        for (int k = i+1; k <= i + v[j].size(); ++k) {
          if (dp[k] > dp[i] + 1) {
            dp[k] = dp[i] + 1;
            path[k] = {i, j};
          }
        }
      }
    }
    if (path[s.size()] == make_pair(-1, -1)) {
      cout << -1 << endl;
      continue;
    }

    cout << dp[s.size()] << endl;
    vec<pair<int, int>> u;
    for (int i = s.size(); path[i] != make_pair(-1, -1); i = path[i].first) {
      u.push_back({path[i].first, path[i].second});
    }
    reverse(u.begin(), u.end());
    each (i, u) {
      cout << i.second+1 << ' ' << i.first+1 << endl;
    }
  }


  return 0;
}
