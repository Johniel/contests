// atcoder/abc200/D/main.cpp
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
    vec<int> a(n);
    cin >> a;
    each (i, a) i %= 200;

    const int N = 200 + 3;
    static pair<short, int> dp[N][4][N][N];
    fill(&dp[0][0][0][0], &dp[N - 1][4 - 1][N - 1][N - 1] + 1, make_pair(-1, -1));
    dp[0][0][0][0] = make_pair(0, 0);
    for (int i = 0; i < a.size(); ++i) {
      for (int bit = 0; bit < 4; ++bit) {
        for (int j = 0; j < N; ++j) {
          for (int k = 0; k < N; ++k) {
            if (dp[i][bit][j][k].first == -1) continue;
            dp[i + 1][bit | 1][(j + a[i]) % 200][k] = make_pair(1, bit);
            dp[i + 1][bit | 2][j][(k + a[i]) % 200] = make_pair(2, bit);
            dp[i + 1][bit][j][k] = make_pair(0, bit);
          }
        }
      }
    }

    int j, k;
    j = k = -1;
    int bit = 1 + 2;
    for (int i = 0; i < N; ++i) {
      if (0 <= dp[a.size()][bit][i][i].first) {
        j = k = i;
        break;
      }
    }

    if (j == -1) {
      cout << "NO" << endl;
      continue;
    }

    vec<int> b;
    vec<int> c;
    int i = a.size();
    while (i) {
      if (dp[i][bit][j][k].first == 1) {
        bit = dp[i][bit][j][k].second;
        j = (j - a[i - 1] + 200) % 200;
        b.push_back(i);
      }
      if (dp[i][bit][j][k].first == 2) {
        bit = dp[i][bit][j][k].second;
        k = (k - a[i - 1] + 200) % 200;
        c.push_back(i);
      }
      --i;
    }

    reverse(b.begin(), b.end());
    reverse(c.begin(), c.end());
    cout << "YES" << endl;
    cout << b.size(); each (i, b) cout << ' ' << i; cout << endl;
    cout << c.size(); each (i, c) cout << ' ' << i; cout << endl;
  }

  return 0;
}
