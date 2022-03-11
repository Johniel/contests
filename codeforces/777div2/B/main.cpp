// codeforces/777div2/B/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

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

template<typename T>
struct PrefixSum2D {
  vector<vector<T>> sum;
  PrefixSum2D(vector<vector<T>> v) {
    const int H = v.size() + 1;
    const int W = v[0].size() + 1;
    sum.resize(H);
    fill(sum.begin(), sum.end(), vector<T>(W, 0));
    for (int i = 0; i < v.size(); ++i) {
      for (int j = 0; j < v[i].size(); ++j) {
        sum[i + 1][j + 1] = v[i][j];
      }
    }
    for (int i = 1; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        sum[i][j] += sum[i - 1][j];
      }
    }
    for (int i = 0; i < H; ++i) {
      for (int j = 1; j < W; ++j) {
        sum[i][j] += sum[i][j - 1];
      }
    }
  }
  T query(int ai, int aj, int bi, int bj) {
    assert(0 <= ai && ai < sum.size());
    assert(0 <= bi && bi < sum.size());
    assert(0 <= aj && aj < sum[0].size());
    assert(0 <= bj && bj < sum[0].size());
    assert(ai <= bi && aj <= bj);
    return sum[bi][bj] + sum[ai][aj] - sum[ai][bj] - sum[bi][aj];
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int _;
  cin >> _;

  int h, w;
  while (cin >> h >> w) {
    const int H = 100 + 1;
    const int W = 100 + 1;
    static char g[H][W];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }

    vec<vec<int>> v(h, vec<int>());
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        v[i].push_back(g[i][j] - '0');
      }
    }
    PrefixSum2D<int> sum(v);

    static bool vis[H][W];
    fill(&vis[0][0], &vis[H - 1][W - 1] + 1, false);

    int mni, mxi, mnj, mxj;
    function<void(int, int)> rec = [&] (int i, int j) {
      vis[i][j] = true;
      setmin(mni, i);
      setmin(mnj, j);
      setmax(mxi, i);
      setmax(mxj, j);
      for (int d = 0; d < 4; ++d) {
        int ni = i + di[d];
        int nj = j + dj[d];
        unless (0 <= ni && ni < h) continue;
        unless (0 <= nj && nj < w) continue;
        if (g[ni][nj] == '1' && !vis[ni][nj]) rec(ni, nj);
      }
      return ;
    };
    bool f = true;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (g[i][j] == '0') continue;
        mni = mnj = +(1 << 29);
        mxi = mxj = -(1 << 29);
        if (!vis[i][j]) {
          rec(i, j);
          if (sum.query(mni, mnj, mxi + 1, mxj + 1) != (mxi - mni + 1) * (mxj - mnj + 1)) {
            f = false;
          }
        }
      }
    }
    cout << (f ? "YES" : "NO") << endl;
  }

  return 0;
}
