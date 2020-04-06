// atcoder/arc032/C/main.cpp
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
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.setf(std::ios_base::fixed);
  std::cout.precision(15);

  int n;
  while (cin >> n) {
    vec<pair<int, int>> v(n);
    cin >> v;

    map<int, vec<int>> m;
    for (int i = 0; i < v.size(); ++i) {
      m[v[i].first].push_back(i);
    }

    const int N = 1e6 + 5;
    static pair<int, int> dp[N]; // {max length, idx}
    fill(dp, dp + N, make_pair(0, 1 << 29));
    for (int i = 0; i < n; ++i) {
      dp[v[i].first] = make_pair(1, i);
    }

    for (int i = N - 2; 0 <= i; --i) {
      if (dp[i].first < dp[i + 1].first) {
        dp[i] = dp[i + 1];
      }
      if (dp[i].first == dp[i + 1].first && dp[i].second > dp[i + 1].second) {
        dp[i] = dp[i + 1];
      }
      each (j, m[i]) {
        const int k = v[j].second;
        if (dp[i].first < dp[k].first + 1) {
          dp[i].first = dp[k].first + 1;
          dp[i].second = j;
        }
        if (dp[i].first == dp[k].first + 1 && dp[i].second > j) {
          dp[i].first = dp[k].first + 1;
          dp[i].second = j;
        }
      }
    }

    // for (int i = 0; i < 11; ++i) {
    //   cout << i << ":" << dp[i] << " from: " << path[i] << endl;
    // }
    // cout << v << endl;

    int idx = 0;
    vec<int> w;
    while (dp[idx].first) {
      w.push_back(dp[idx].second);
      idx = v[dp[idx].second].second;
    }

    cout << w.size() << endl;
    for (int i = 0; i < w.size(); ++i) {
      if (i) cout << ' ';
      cout << w[i] + 1;
    }
    cout << endl;
  }

  return 0;
}
