// github.com/Johniel/contests
// atcoder/abc298/G/main.cpp

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
  T query(int ai, int aj, int bi, int bj) {
    assert(0 <= ai && ai < sum.size());
    assert(0 <= bi && bi < sum.size());
    assert(0 <= aj && aj < sum[0].size());
    assert(0 <= bj && bj < sum[0].size());
    assert(ai <= bi && aj <= bj);
    return sum[bi][bj] + sum[ai][aj] - sum[ai][bj] - sum[bi][aj];
  }
};

const int H = 7;
const int W = 7;
const int K = 40;
using P = pair<pair<lli, lli>, pair<lli, lli>>;
P memo[H][W][H][W][K];
const P nil = {{-1, -1}, {-1, -1}};

pair<lli, lli> merge(pair<lli, lli> a, pair<lli, lli> b)
{
  return make_pair(max(a.first, b.first), min(a.second, b.second));
}

P conquer(P best, pair<lli, lli> large, pair<lli, lli> small)
{
  lli cost = abs(best.first.second - best.first.first);
  lli cost_l = abs(large.second - large.first);
  lli cost_s = abs(small.second - small.first);
  if (0) {
  } else if (cost > cost_s && cost_l > cost_s) {
    best.first = small;
    best.second = small;
  } else if (cost > cost_l && cost_s > cost_l) {
    best.first = large;
    best.second = large;
  } else if (cost > cost_l && cost_s == cost_l) {
    best.first = large;
    best.second = small;
  }

  cost = abs(best.first.second - best.first.first);
  cost_l = abs(large.second - large.first);
  cost_s = abs(small.second - small.first);
  if (cost == cost_l && best.first.first < large.first) {
    best.first = large;
  }
  if (cost == cost_s && best.second.second > small.second) {
    best.first = small;
  }
  return best;
};

P rec(int bi, int bj, int ei, int ej, int k)
{
  P& ret = memo[bi][bj][ei][ej][k];
  if (ret != nil) return ret;
  const lli inf = 1LL << 60;

  const pair<lli, lli> none = make_pair(inf, 0);
  P best = {none, none};

  for (int i = bi + 1; i < ei; ++i) {
    for (int c = 0; c < k; ++c) {
      P a = rec(bi, bj, i, ej, c);
      P b = rec(i, bj, ei, ej, (k - 1) - c);

      if (0) {
        cout << make_pair(make_pair(bi, bj), make_pair(ei, ej)) << k << ' '
             << make_pair(make_pair(bi, bj), make_pair(i, ej)) << c << ' ' << a
             << make_pair(make_pair(i, bj), make_pair(ei, ej)) << k-c << ' ' << b << endl;
      }

      if (a.first == none || a.second == none) continue;
      if (b.first == none || b.second == none) continue;
      pair<lli, lli> large = merge(a.first, b.first);
      pair<lli, lli> small = merge(a.second, b.second);
      best = conquer(best, large, small);
    }
  }
  for (int j = bj + 1; j < ej; ++j) {
    for (int c = 0; c < k; ++c) {
      P a = rec(bi, bj, ei, j, c);
      P b = rec(bi, j, ei, ej, (k - 1) - c);
      if (a.first == none || a.second == none) continue;
      if (b.first == none || b.second == none) continue;
      pair<lli, lli> large = merge(a.first, b.first);
      pair<lli, lli> small = merge(a.second, b.second);
      best = conquer(best, large, small);
    }
  }

  // cout << make_pair(make_pair(bi, bj), make_pair(ei, ej)) << k << ' ' << best << endl;
  return ret = best;
}

int main(int argc, char *argv[])
{
  int h, w, t;
  while (cin >> h >> w >> t) {
    vec<vec<lli>> v(h, vec<lli>(w));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> v[i][j];
      }
    }
    fill(&memo[0][0][0][0][0], &memo[H - 1][W - 1][H - 1][W - 1][K - 1], nil);
    PrefixSum2D<lli> sum(v);
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        for (int a = i; a <= h; ++a) {
          for (int b = j; b <= w; ++b) {
            lli x = sum.query(i, j, a, b);
            memo[i][j][a][b][0] = {{x, x}, {x, x}};
          }
        }
      }
    }
    P p = rec(0, 0, h, w, t);
    cout << abs(p.first.second - p.first.first) << endl;
    // break;
  }
  return 0;
}
