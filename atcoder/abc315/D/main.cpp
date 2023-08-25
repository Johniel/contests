// github.com/Johniel/contests
// atcoder/abc315/D/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }
template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

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
  int h, w;
  while (cin >> h >> w) {
    char g[h][w];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }

    // map<pair<char, int>, set<int>> a, b;
    const int H = 2000 + 3;
    const int W = 2000 + 3;
    static int a[30][H];
    static int b[30][W];
    fill(&a[0][0], &a[30 - 1][H - 1] + 1, 0);
    fill(&b[0][0], &b[30 - 1][W - 1] + 1, 0);
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (g[i][j] == '.') continue;
        ++a[g[i][j] - 'a'][i];
        ++b[g[i][j] - 'a'][j];
      }
    }

    static bool fixedr[H];
    static bool fixedc[W];
    fill(fixedr, fixedr + h, false);
    fill(fixedc, fixedc + h, false);
    int rh = h;
    int rw = w;
    for (int _ = 0; _ < h + w; ++_) {
      vec<pair<char, int>> row;
      for (int i = 0; i < h; ++i) {
        if (fixedr[i]) continue;
        map<char, int> m;
        for (char c = 'a'; c <= 'z' && m.size() < 2; ++c) {
          if (a[c - 'a'][i]) m[c] += a[c - 'a'][i];
        }
        if (m.empty()) fixedr[i] = true;
        if (m.size() == 1 && m.begin()->second == 1) fixedr[i] = true;
        if (m.size() == 1 && m.begin()->second == rw && 2 <= rw) {
          row.push_back(make_pair(m.begin()->first, i));
        }
      }
      vec<pair<char, int>> col;
      for (int j = 0; j < w; ++j) {
        if (fixedc[j]) continue;
        map<char, int> m;
        for (char c = 'a'; c <= 'z' && m.size() < 2; ++c) {
          if (b[c - 'a'][j]) m[c] += b[c - 'a'][j];
        }
        if (m.empty()) fixedc[j] = true;
        if (m.size() == 1 && m.begin()->second == 1) fixedc[j] = true;
        if (m.size() == 1 && m.begin()->second == rh && 2 <= rh) {
          col.push_back(make_pair(m.begin()->first, j));
        }
      }
      if (row.empty() && col.empty()) break;
      // each (k, col) cout << k << ' '; cout << endl;
      // each (k, row) cout << k << ' '; cout << endl;
      each (k, row) {
        auto [c, i] = k;
        for (int j = 0; j < w; ++j) {
          --b[c - 'a'][j];
        }
        --rh;
        fixedr[i] = true;
      }
      each (k, col) {
        auto [c, j] = k;
        for (int i = 0; i < h; ++i) {
          --a[c - 'a'][i];
        }
        --rw;
        fixedc[j] = true;
      }
    }
    // cout << make_pair(rh, rw) << endl;
    cout << rh * rw << endl;
  }
  return 0;
}
