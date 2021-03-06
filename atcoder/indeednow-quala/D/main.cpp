// atcoder/indeednow-quala/D/main.cpp
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

  int h, w;
  while (cin >> h >> w) {
    using G = vec<vec<int>>;
    G v(h, vec<int>(w));
    cin >> v;

    vec<pair<int, int>> dst(h * w);
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        dst[v[i][j]] = make_pair(i, j);
      }
    }

    auto fn = [&] (G v) {
      int sum = 0;
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          if (v[i][j] == 0) continue;
          sum += abs(i - dst[v[i][j]].first);
          sum += abs(j - dst[v[i][j]].second);
        }
      }
      return sum;
    };

    G src(h, vec<int>(w));
    for (int i = 0, k = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        src[i][j] = ++k;
      }
    }
    src[h - 1][w - 1] = 0;

    priority_queue<pair<int, G>> q;
    map<G, int> m;
    m[src] = fn(src);
    q.push({-m[src], src});
    while (q.size()) {
      auto p = q.top();
      q.pop();
      if (p.second == v) break;
      if (m[p.second] != -p.first) continue;
      int i, j;
      i = j = 1 << 29;
      for (int a = 0; a < h; ++a) {
        for (int b = 0; b < w; ++b) {
          if (p.second[a][b] == 0) {
            i = a;
            j = b;
            a = b = 1 << 29;
          }
        }
      }
      for (int d = 0; d < 4; ++d) {
        int ni = i + di[d];
        int nj = j + dj[d];
        unless (0 <= ni && ni < h) continue;
        unless (0 <= nj && nj < w) continue;
        G u = p.second;
        swap(u[i][j], u[ni][nj]);
        int c = m[p.second] - fn(p.second) + 1 + fn(u);
        if (!m.count(u) || m[u] > c) {
          m[u] = c;
          q.push({-m[u], u});
        }
      }
    }
    assert(m.count(v));
    cout << m[v] << endl;
  }

  return 0;
}
