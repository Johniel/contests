// github.com/Johniel/contests
// codeforces/839div3/F/main.cpp

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

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;
template<typename T> using heap = priority_queue<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

const int H = 30;
const int W = 30;
struct S {
  int g[H][W];
  S() {
    fill(&g[0][0], &g[H - 1][W - 1] + 1, 0);
  }
};

int main(int argc, char *argv[])
{
  int h, w, c;
  while (cin >> h >> w >> c) {
    vec<S> v;
    for (int k = 0; k < c + 1; ++k) {
      S s;
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          char d;
          cin >> d;
          s.g[i][j] = d - '0';
        }
      }
      v.push_back(s);
    }
    vec<pair<int, int>> u;
    for (int k = 0; k < v.size(); ++k) {
      int x = 0;
      for (int i = 1; i < h - 1; ++i) {
        for (int j = 1; j < w - 1; ++j) {
          int y = 0;
          y += (v[k].g[i][j] != v[k].g[i][j + 1]);
          y += (v[k].g[i][j] != v[k].g[i][j - 1]);
          y += (v[k].g[i][j] != v[k].g[i + 1][j]);
          y += (v[k].g[i][j] != v[k].g[i - 1][j]);
          x += (y == 4);
        }
      }
      u.push_back(make_pair(x, k));
    }
    sort(u.begin(), u.end());
    reverse(u.begin(), u.end());
    // cout << u << endl;

    vec<vec<int>> cmds;
    int ini = u.front().second;
    S curr = v[ini];
    each (p, u) {
      int k = p.second;
      if (k == ini) continue;
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          if (curr.g[i][j] != v[k].g[i][j]) {
            cmds.push_back(vec<int>({1, i, j}));
            curr.g[i][j] = v[k].g[i][j];
          }
        }
      }
      cmds.push_back(vec<int>({2, k}));
    }

    cout << ini + 1 << endl;
    cout << cmds.size() << endl;
    each (cmd, cmds) {
      if (cmd[0] == 1) {
        cout << cmd[0] << ' ' << cmd[1]+1 << ' ' << cmd[2]+1 << endl;
      }
      if (cmd[0] == 2) {
        cout << cmd[0] << ' ' << cmd[1]+1 << endl;
      }
    }
  }
  return 0;
}
