// atcoder/arc006/B/main.cpp
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

  int w, h;
  while (cin >> w >> h) {
    const int W = w * 2 - 1;
    const int H = h + 1;
    string g[H];
    int si, sj;
    getline(cin, g[0]);
    for (int i = 0; i < H; ++i) {
      getline(cin, g[i]);
      while (g[i].size() < W) g[i] += ' ';
      for (int j = 0; j < W; ++j) {
        if (g[i][j] == 'o') {
          si = i;
          sj = j;
        }
      }
    }


    while (si) {
      --si;
      assert(g[si][sj] == '|');
      if (0 <= sj - 1           && g[si][sj - 1] == '-') sj -= 2;
      else if (sj + 1 < g[si].size() && g[si][sj + 1] == '-') sj += 2;
    }
    cout << sj / 2 + 1 << endl;
  }

  return 0;
}
