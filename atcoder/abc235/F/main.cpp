// atcoder/abc235/F/main.cpp
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
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);


  str s;
  int m;
  while (cin >> s >> m) {
    vec<int> v(m);
    cin >> v;

    int used[20];
    fill(used, used + 20, 100);
    for (int i = 0; i < v.size(); ++i) {
      used[v[i]] = i;
    }

    vec<lli> w;
    w.push_back(1);
    for (int i = 0; i + 1 < s.size(); ++i) {
      w.push_back(w.back() * 10LL % mod);
    }
    reverse(w.begin(), w.end());

    const int N = 1e4 + 10;
    const int B = 1 << 10;
    static lli dp[N][B][2][2];
    fill(&dp[0][0][0][0], &dp[N - 1][B - 1][2 - 1][2 - 1] + 1, 0);
    static lli vis[N][B][2][2];
    fill(&vis[0][0][0][0], &vis[N - 1][B - 1][2 - 1][2 - 1] + 1, 0);
    vis[0][0][false][false] = 1;

    for (int i = 0; i < s.size(); ++i) {
      for (int bit = 0; bit < (1 << v.size()); ++bit) {
        for (int started = 0; started < 2; ++started) {
          for (int less = 0; less < 2; ++less) {
            const lli q = vis[i][bit][started][less];
            unless (q) continue;
            for (int k = 0; k <= (less ? 9 : (s[i] - '0')); ++k) {
              if (!started && k == 0) {
                vis[i + 1][0][false][true] = q;
              } else {
                int b = bit;
                if (used[k] < 50) b = (b | (1 << used[k]));
                lli a = (((w[i] * k) % mod) * q) % mod;
                lli p = (dp[i][bit][started][less] + a) % mod;
                (dp[i + 1][b][true][less || ((s[i] - '0') > k)] += p) %= mod;
                (vis[i + 1][b][true][less || ((s[i] - '0') > k)] += q) %= mod;
              }
            }
          }
        }
      }
    }
    lli z = 0;
    const int V = (1 << v.size()) - 1;
    if (vis[s.size()][V][true][true]) z += dp[s.size()][V][true][true];
    if (vis[s.size()][V][true][false]) z += dp[s.size()][V][true][false];
    cout << z % mod << endl;
  }

  return 0;
}
