// github.com/Johniel/contests
// yukicoder/2071/main.cpp

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

  int n;
  while (cin >> n) {
    vec<lli> a(n);
    cin >> a;
    sort(a.begin(), a.end());

    if (16 <= a.size()) {
      cout << (1 << 16) - 1 << endl;
      continue;
    }

    const int N = 2 * 1e5;
    const int M = (1 << 16);
    static bool dp[2][M];
    fill(&dp[0][0], &dp[2 - 1][M - 1] + 1, false);
    dp[0][0] = true;
    for (int i = 0; i < a.size(); ++i) {
      int curr = i % 2;
      int next = (i + 1) % 2;
      for (int j = 0; j < M; ++j) dp[next][j] = false;
      for (int j = 0; j < M; ++j) {
        unless (dp[curr][j]) continue;
        int b = a[i];
        for (int k = 0; k <= 20; ++k) {
          dp[next][j | b] = true;
          if (b % 2) b += (1 << 16);
          b /= 2;
        }
      }
    }
    int mx = 0;
    for (int i = 0; i < M; ++i) {
      if (dp[a.size() % 2][i]) mx = i;
    }
    cout << mx << endl;
  }

  return 0;
}
