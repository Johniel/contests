// github.com/Johniel/contests
// atcoder/abc311/G/main.cpp

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
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

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
  T operator () (int ai, int aj, int bi, int bj) const { return this->query(ai, aj, bi, bj); }
  T query(int ai, int aj, int bi, int bj) const {
    assert(0 <= ai && ai < sum.size());
    assert(0 <= bi && bi < sum.size());
    assert(0 <= aj && aj < sum[0].size());
    assert(0 <= bj && bj < sum[0].size());
    assert(ai <= bi && aj <= bj);
    return sum[bi][bj] + sum[ai][aj] - sum[ai][bj] - sum[bi][aj];
  }
};

namespace max_rectangle {
  const int H = 300 + 2;
  const int W = 300 + 2;
  bool g[H][W];
  void init(bool ini)
  {
    fill(&g[0][0], &g[H - 1][W - 1] + 1, ini);
    return ;
  }

  vec<pair<int, int>> run(const vec<lli>& h)
  {
    // see:
    // + 蟻本P.300
    // + https://drken1215.hatenablog.com/entry/2023/07/23/190400
    vec<int> left(h.size(), 0), right(h.size(), h.size());
    {
      vec<pair<lli, int>> v;
      for (int i = 0; i < h.size(); ++i) {
        while (v.size() && h[i] <= v.back().first) v.pop_back();
        if (v.size()) left[i] = v.back().second + 1;
        v.push_back(make_pair(h[i], i));
      }
    }
    {
      vec<pair<lli, int>> v;
      for (int i = h.size() - 1; 0 <= i; --i) {
        while (v.size() && h[i] <= v.back().first) v.pop_back();
        if (v.size()) right[i] = v.back().second;
        v.push_back(make_pair(h[i], i));
      }
    }
    vec<pair<int, int>> v;
    for (int i = 0; i < h.size(); ++i) {
      v.push_back(make_pair(left[i], right[i]));
    }
    return v;
  }

  // g[i][j]を含む最大長方形の高さ、[左端、右端)
  tuple<int, int, int> rect[H][W];
  void run(const int h, const int w)
  {
    fill(&rect[0][0], &rect[H - 1][W - 1] + 1, make_tuple(-1, -1, -1));
    static int dp[H][W];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (dp[i][j] = !!g[i][j]) rect[i][j] = make_tuple(1, 1, 1);
      }
    }
    for (int i = 1; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (dp[i][j]) dp[i][j] = dp[i - 1][j] + 1;
      }
    }

    for (int i = 0; i < h; ++i) {
      vec<lli> v;
      for (int j = 0; j < w; ++j) {
        v.push_back(dp[i][j]);
      }
      vec<pair<int, int>> u = run(v);
      for (int j = 0; j < w; ++j) {
        rect[i][j] = make_tuple(v[j], u[j].first, u[j].second);
      }
    }
    return ;
  }
};

int main(int argc, char *argv[])
{
  int h, w;
  while (cin >> h >> w) {
    max_rectangle::init(false);

    vec<vec<lli>> g(h, vec<lli>(w));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
        max_rectangle::g[i][j] = true;
      }
    }
    PrefixSum2D<lli> sum(g);

    map<lli, vec<pair<int, int>>> m;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        m[g[i][j]].push_back(make_pair(i, j));
      }
    }

    lli mx = 0;
    each (k, m) {
      max_rectangle::run(h, w);
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          if (max_rectangle::g[i][j]) {
            auto [a, wbegin, wend] = max_rectangle::rect[i][j];
            lli z = sum(i - (a - 1), wbegin, i + 1, wend);
            setmax(mx, z * k.first);
          }
        }
      }
      each (j, k.second) max_rectangle::g[j.first][j.second] = false;
    }
    cout << mx << endl;
  }
  return 0;
}
