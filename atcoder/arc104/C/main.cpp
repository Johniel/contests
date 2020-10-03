// atcoder/arc104/C/main.cpp
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

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    const int N = 205;

    int in[N];
    fill(in, in + N, -1);

    int out[N];
    fill(out, out + N, -1);

    vec<pair<int, int>> v(n);
    cin >> v;
    each (i, v) {
      if (i.first != -1) --i.first;
      if (i.second != -1) --i.second;
    }

    for (int i = 0; i < v.size(); ++i) {
      if (v[i].first != -1) in[v[i].first] = i;
      if (v[i].second != -1) out[v[i].second] = i;
    }

    static bool dp[N];
    fill(dp, dp + N, false);
    dp[0] = true;

    for (int i = 0; i < n + n; ++i) {
      for (int len = 1; len <= n && i + len * 2 <= n+n; ++len) {
        bool f = dp[i];
        for (int k = i; k < i + len; ++k) {
          if (out[k] != -1) f = false;
          if (in[k + len] != -1) f = false;
          if (in[k] == -1 && out[k + len] == -1) continue;
          if (in[k] == -1 && out[k + len] != -1 && v[out[k + len]].first == -1) continue;
          if (in[k] != -1 && v[in[k]].second == k + len) continue;
          if (in[k] != -1 && v[in[k]].second == -1 && out[k + len] == -1) continue;
          f = false;
        }
        if (f) dp[i + len + len] = true;
      }
    }

    bool f = dp[n + n] && in[n + n - 1] == -1;
    set<int> vis;
    each (i, v) {
      if (i.first != -1 && i.second != -1) {
        unless (i.first < i.second) f = false;
      }
      if (i.first != -1 && vis.count(i.first)) f = false;
      if (i.second != -1 && vis.count(i.second)) f = false;
      vis.insert(i.first);
      vis.insert(i.second);
    }
    cout << (f ? "Yes" : "No") << endl;
  }

  return 0;
}
