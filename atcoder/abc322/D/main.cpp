// github.com/Johniel/contests
// atcoder/abc322/D/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
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
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  const int H = 4;
  const int W = 4;
  auto rot = [&] (char g[H][W]) {
    char tmp[H][W];
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        tmp[j][H - 1 - i] = g[i][j];
      }
    }
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        g[i][j] = tmp[i][j];
      }
    }
    return ;
  };
  char a[H][W];
  char b[H][W];
  char c[H][W];

  while (true) {
    {
      bool f = true;
      for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) f = f && (cin >> a[i][j]);
      }
      for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) f = f && (cin >> b[i][j]);
      }
      for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) f = f && (cin >> c[i][j]);
      }
      unless (f) break;
    }
    {
      int x = count(&a[0][0], &a[H - 1][W - 1] + 1, '#');
      int y = count(&b[0][0], &b[H - 1][W - 1] + 1, '#');
      int z = count(&c[0][0], &c[H - 1][W - 1] + 1, '#');
      if (x + y + z != H * W) {
        cout << "No" << endl;
        continue;
      }
    }
    bool f = false;

    for (int ai = -H; ai <= H; ++ai) {
      for (int aj = -W; aj <= W; ++aj) {

        for (int bi = -H; bi <= H; ++bi) {
          for (int bj = -W; bj <= W; ++bj) {

            for (int ci = -H; ci <= H; ++ci) {
              for (int cj = -W; cj <= W; ++cj) {

                for (int x = 0; x < 4; ++x) {
                  for (int y = 0; y < 4; ++y) {

                    char g[H][W];
                    fill(&g[0][0], &g[H - 1][W - 1] + 1, '.');
                    for (int i = 0; i < H; ++i) {
                      for (int j = 0; j < W; ++j) {
                        int ni = ai + i;
                        int nj = aj + j;
                        unless (0 <= ni && ni < H) continue;
                        unless (0 <= nj && nj < W) continue;
                        if (a[ni][nj] == '#') g[i][j] = a[ni][nj];
                      }
                    }

                    for (int i = 0; i < H; ++i) {
                      for (int j = 0; j < W; ++j) {
                        int ni = bi + i;
                        int nj = bj + j;
                        unless (0 <= ni && ni < H) continue;
                        unless (0 <= nj && nj < W) continue;
                        if (b[ni][nj] == '#') g[i][j] = b[ni][nj];
                      }
                    }

                    for (int i = 0; i < H; ++i) {
                      for (int j = 0; j < W; ++j) {
                        int ni = ci + i;
                        int nj = cj + j;
                        unless (0 <= ni && ni < H) continue;
                        unless (0 <= nj && nj < W) continue;
                        if (c[ni][nj] == '#') g[i][j] = c[ni][nj];
                      }
                    }

                    f = f || (count(&g[0][0], &g[H - 1][W - 1] + 1, '#') == H * W);

                    rot(b);
                  }
                  rot(c);
                }
              }
            }
          }
        }
      }
    }
    cout << (f ? "Yes" : "No") << endl;
  }

  if (0) {
    for (int k = 0; k < 4; ++k) {
      for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
          cout << a[i][j];
        }
        cout << endl;
      }
      rot(a);
      cout << endl;
    }
  }

  return 0;
}
