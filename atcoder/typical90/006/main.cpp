// atcoder/typical90/006/main.cpp
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

  int n, k;
  str s;
  while (cin >> n >> k >> s) {
    const int N = 1e5 + 3;
    const int C = 30;
    static int next[N][C];
    fill(&next[0][0], &next[N - 1][C - 1] + 1, -1);
    for (int i = 0; i < s.size(); ++i) {
      next[i][s[i] - 'a'] = i;
    }
    for (int i = s.size() - 1; 0 <= i; --i) {
      for (int c = 0; c <= 'z' - 'a'; ++c) {
        if (next[i][c] == -1) {
          next[i][c] = next[i + 1][c];
        }
      }
    }

    str t;
    int i = 0;
    while (t.size() < k) {
      for (int c = 0; c <= 'z' - 'a'; ++c) {
        if (next[i][c] == -1) continue;
        if (k <= t.size() + s.size() - next[i][c]) {
          i = next[i][c] + 1;
          t += 'a' + c;
          break;
        }
      }
    }
    cout << t << endl;
  }

  return 0;
}
