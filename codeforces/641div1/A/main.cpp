// codeforces/641div1/A/main.cpp
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

    const int M = 2 * 1e5 + 5;
    static int mn[M][3];
    fill(&mn[0][0], &mn[M - 1][3 - 1] + 1, 1 << 30);
    static int cnt[M];
    fill(cnt, cnt + M, 0);
    each (i, a) {
      for (int j = 2; j * j <= i; ++j) {
        if (i % j == 0) {
          int x = 1;
          while (i % j == 0) {
            i /= j;
            x *= j;
          }
          ++cnt[j];
          mn[j][2] = x;
          unless (mn[j][0] < mn[j][1]) swap(mn[j][0], mn[j][1]);
          unless (mn[j][1] < mn[j][2]) swap(mn[j][1], mn[j][2]);
          unless (mn[j][0] < mn[j][1]) swap(mn[j][0], mn[j][1]);
          unless (mn[j][1] < mn[j][2]) swap(mn[j][1], mn[j][2]);
        }
      }
    }
    each (i, a) {
      if (i != 1) {
        ++cnt[i];
        mn[i][2] = i;
        unless (mn[i][0] < mn[i][1]) swap(mn[i][0], mn[i][1]);
        unless (mn[i][1] < mn[i][2]) swap(mn[i][1], mn[i][2]);
        unless (mn[i][0] < mn[i][1]) swap(mn[i][0], mn[i][1]);
        unless (mn[i][1] < mn[i][2]) swap(mn[i][1], mn[i][2]);
      }
    }

    lli x = 1;
    for (int i = 0; i < M; ++i) {
      if (n == cnt[i]) x *= mn[i][1];
      if (n == cnt[i] + 1) x *= mn[i][0];
    }
    cout << x << endl;
  }

  return 0;
}
