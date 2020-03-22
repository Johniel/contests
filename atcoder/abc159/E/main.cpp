// atcoder/abc159/E/main.cpp
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

const int H = 10 + 3;
const int W = 1000 + 5;

int g[H][W];

int main(int argc, char *argv[])
{
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.setf(std::ios_base::fixed);
  std::cout.precision(15);

  int h, w, K;
  while (cin >> h >> w >> K) {
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        char c;
        cin >> c;
        g[i][j] = c - '0';
      }
    }

    int mn = 1LL << 29;
    for (int bit = 0; bit < (1 << h); ++bit) {
      vec<pair<int, int>> v;
      int prev = 0;
      for (int i = 0; i < h; ++i) {
        if (bit & (1 << i)) {
          v.push_back(make_pair(prev, i + 1));
          prev = i + 1;
        }
      }
      // cout << v << ", " << h << endl;
      if (v.empty()) {
        v.push_back(make_pair(0, h));
      } else if (v.back().second != h) {
        v.push_back(make_pair(v.back().second, h));
      }

      int cnt = max(0, (int)v.size() - 1);
      map<int, int> m;
      for (int j = 0; j < w; ++j) {
        map<int, int> n = m;
        int mx = 0;
        for (int k = 0; k < v.size(); ++k) {
          for (int i = v[k].first; i < v[k].second; ++i) {
            setmax(mx, n[k] += g[i][j]);
          }
        }
        if (K < mx) {
          ++cnt;
          m.clear();
        }
        mx = 0;
        for (int k = 0; k < v.size(); ++k) {
          for (int i = v[k].first; i < v[k].second; ++i) {
            m[k] += g[i][j];
            setmax(mx, m[k]);
          }
        }
        if (K < mx) {
          cnt = (1 << 29);
          break;
        }
      }

      setmin(mn, cnt);
    }
    cout << mn << endl;
    // cout << endl;
  }

  return 0;
}
