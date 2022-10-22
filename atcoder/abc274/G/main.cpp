// github.com/Johniel/contests
// atcoder/abc274/G/main.cpp

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

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

// template<int N>
// struct BiparticleMatching {
//   array<vector<int>, N> g;
//   array<int, N> match;
//   array<bool, N> vis;

//   void init(void) {
//     fill(g.begin(), g.end(), vector<int>());
//     return ;
//   }

//   void add_edge(int i, int j) {
//     g[i].push_back(j);
//     g[j].push_back(i);
//     return ;
//   }

//   bool rec(int curr) {
//     vis[curr] = true;
//     each (next, g[curr]) {
//       int w = match[next];
//       if (w < 0 || (!vis[w] && rec(w))) {
//         match[curr] = next;
//         match[next] = curr;
//         return true;
//       }
//     }
//     return false;
//   }

//   int run(void) {
//     int sum = 0;
//     fill(match.begin(), match.end(), -1);
//     for (int i = 0; i < N; ++i) {
//       if (match[i] == -1) {
//         fill(vis.begin(), vis.end(), false);
//         sum += rec(i);
//       }
//     }
//     return sum;
//   }
// };
//constexpr int N = 300 * 300 * 2 + 5;
// BiparticleMatching<N> matching;

#include <atcoder/maxflow>
using namespace atcoder;

int main(int argc, char *argv[])
{
  const int H = 300;
  const int W = 300;

  int h, w;
  while (cin >> h >> w) {
    // matching.init();

    static char g[H][W];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }
    const int K = 300 * 300;

    static int a[H][W];
    static int b[H][W];
    fill(&a[0][0], &a[H - 1][W - 1] + 1, -1);
    fill(&b[0][0], &b[H - 1][W - 1] + 1, -1);

    int cnt = 0;

    for (int i = 0; i < h; ++i) {
      bool prev = false;
      for (int j = 0; j < w; ++j) {
        if (g[i][j] == '.') {
          unless (prev) ++cnt;
          a[i][j] = cnt;
          prev = true;
        }
        if (g[i][j] == '#') {
          prev = false;
        }
      }
    }

    for (int j = 0; j < w; ++j) {
      bool prev = false;
      for (int i = 0; i < h; ++i) {
        if (g[i][j] == '.') {
          unless (prev) ++cnt;
          b[i][j] = cnt;
          prev = true;
        }
        if (g[i][j] == '#') {
          prev = false;
        }
      }
    }

    // assert(cnt < N);
    cnt += 2;
    const int src = cnt - 1;
    const int dst = cnt - 2;
    mf_graph<int> matching(cnt);


    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        --a[i][j];
        --b[i][j];
      }
    }

    // cout << cnt << endl;
    // for (int i = 0; i < h; ++i) {
    //   for (int j = 0; j < w; ++j) cout << a[i][j] << ' '; cout << endl;
    // }
    // for (int i = 0; i < h; ++i) {
    //   for (int j = 0; j < w; ++j) cout << b[i][j] << ' '; cout << endl;
    // }


    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (a[i][j] < 0 || b[i][j] < 0) continue;
        matching.add_edge(a[i][j], b[i][j], 1);
      }
    }

    set<int> vis;
    vis.insert(-1);
    vis.insert(-2);
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        unless (vis.count(a[i][j])) {
          vis.insert(a[i][j]);
          matching.add_edge(src, a[i][j], 1);
        }
        unless (vis.count(b[i][j])) {
          vis.insert(b[i][j]);
          matching.add_edge(b[i][j], dst, 1);
        }
      }
    }
    cout << matching.flow(src, dst) << endl;
    // cout << matching.run() << endl;
    // break;
  }
  return 0;
}
