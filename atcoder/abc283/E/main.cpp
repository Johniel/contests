// github.com/Johniel/contests
// atcoder/abc283/E/main.cpp

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

const int N = 1000 + 2;
int memo[N][2][2];
const int H = 1000 + 2;
const int W = 1000 + 2;
int g[H][W];
const int inf = 1 << 28;
int h, w;

int rec(int i, int f1, int f2)
{
  int& ret = memo[i][f1][f2];
  if (ret != -1) return ret;

  if (i == h - 1) {
    int mn = inf;

    for (int f3 = 0; f3 < 2; ++f3) {
      bool f = true;
      for (int j = 0; j < w; ++j) {
        if (j + 1 < w  && g[i - 1][j + 1] == g[i - 1][j]) continue;
        if (0 <= j - 1 && g[i - 1][j - 1] == g[i - 1][j]) continue;
        if ((g[i - 2][j] ^ f1) == (g[i - 1][j] ^ f2)) continue;
        if ((g[i][j]     ^ f3) == (g[i - 1][j] ^ f2)) continue;
        f = false;
      }

      for (int j = 0; j < w; ++j) {
        if (j + 1 < w  && g[i][j + 1] == g[i][j]) continue;
        if (0 <= j - 1 && g[i][j - 1] == g[i][j]) continue;
        if ((g[i][j] ^ f3) == (g[i - 1][j] ^ f2)) continue;
        f = false;
      }

      if (f) setmin(mn, f3);
    }

    return ret = mn;
  }

  int mn = inf;
  for (int f3 = 0; f3 < 2; ++f3) {
    bool f = true;
    for (int j = 0; j < w; ++j) {
      if (j + 1 < w  && g[i - 1][j + 1] == g[i - 1][j]) continue;
      if (0 <= j - 1 && g[i - 1][j - 1] == g[i - 1][j]) continue;
      if ((g[i - 2][j] ^ f1) == (g[i - 1][j] ^ f2)) continue;
      if ((g[i][j]     ^ f3) == (g[i - 1][j] ^ f2)) continue;
      f = false;
    }
    if (f) setmin(mn, rec(i + 1, f2, f3) + f3);
  }

  return ret = mn;
}

int tmp[H][W];
int fn(int a, int b)
{
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      tmp[i][j] = g[i][j];
    }
  }

  if (a) {
    for (int j = 0; j < W; ++j) {
      g[0][j] ^= 1;
    }
  }
  if (b) {
    for (int j = 0; j < W; ++j) {
      g[1][j] ^= 1;
    }
  }

  static bool vis[2][W];
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      vis[i][j] = false;
    }
  }

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      for (int d = 0; d < 4; ++d) {
        int ni = i + di[d];
        int nj = j + dj[d];
        unless (0 <= ni && ni < h) continue;
        unless (0 <= nj && nj < w) continue;
        if (g[i][j] == g[ni][nj]) vis[i][j] = true;
      }
    }
  }

  int z = 0;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      z += vis[i][j];
    }
  }
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      g[i][j] = tmp[i][j];
    }
  }
  if (z == h * w) return a + b;
  else return inf;
}

bool fn2(int a, int b)
{
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      tmp[i][j] = g[i][j];
    }
  }

  if (a) {
    for (int j = 0; j < W; ++j) {
      g[0][j] ^= 1;
    }
  }
  if (b) {
    for (int j = 0; j < W; ++j) {
      g[1][j] ^= 1;
    }
  }

  int z = 0;
  for (int i = 0; i < 1; ++i) {
    for (int j = 0; j < w; ++j) {
      bool f = false;
      for (int d = 0; d < 4; ++d) {
        int ni = i + di[d];
        int nj = j + dj[d];
        unless (0 <= ni && ni < h) continue;
        unless (0 <= nj && nj < w) continue;
        if (g[i][j] == g[ni][nj]) f = true;
      }
      z += f;
    }
  }

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      g[i][j] = tmp[i][j];
    }
  }
  return  z == w;
}

int main(int argc, char *argv[])
{
  while (cin >> h >> w) {
    fill(&memo[0][0][0], &memo[N - 1][2 - 1][2 - 1] + 1, -1);
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }

    if (h == 2) {
      int mn = min({fn(0, 0), fn(0, 1), fn(1, 0), fn(1, 1)});
      cout << (mn == inf ? -1 : mn) << endl;
      continue;
    }

    int mn = inf;
    for (int a = 0; a < 2; ++a) {
      for (int b = 0; b < 2; ++b) {

        unless (fn2(a, b)) continue;

        setmin(mn, rec(2, a, b) + a + b);
      }
    }
    cout << (mn == inf ? -1 : mn) << endl;
    // break;
  }
  return 0;
}
