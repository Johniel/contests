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
  PrefixSum2D() {}
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

const int H = 7;
const int W = 7;
const int K = 40;
using P = pair<pair<lli, lli>, pair<lli, lli>>;
PrefixSum2D<lli> sum;
lli memo[H][W][H][W][K];
lli at_least;
const lli inf = 1LL << 62;

lli rec(int bi, int bj, int ei, int ej, int k)
{
  if (sum(bi, bj, ei, ej) < at_least) return inf;
  if (k == 0) return sum(bi, bj, ei, ej);
  lli& ret = memo[bi][bj][ei][ej][k];
  if (ret != -1) return ret;

  lli mn = inf;

  for (int i = bi + 1; i < ei; ++i) {
    for (int c = 0; c < k; ++c) {
      lli a = rec(bi, bj, i, ej, c);
      lli b = rec(i, bj, ei, ej, (k - 1) - c);
      setmin(mn, max(a, b));
    }
  }
  for (int j = bj + 1; j < ej; ++j) {
    for (int c = 0; c < k; ++c) {
      lli a = rec(bi, bj, ei, j, c);
      lli b = rec(bi, j, ei, ej, (k - 1) - c);
      setmin(mn, max(a, b));
    }
  }

  return ret = mn;
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
    sum = PrefixSum2D<lli>(v);
    vec<lli> u;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        for (int a = i + 1; a <= h; ++a) {
          for (int b = j + 1; b <= w; ++b) {
            u.push_back(sum(i, j, a, b));
          }
        }
      }
    }
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());
    lli z = inf;
    each (i, u) {
      at_least = i;
      fill(&memo[0][0][0][0][0], &memo[H - 1][W - 1][H - 1][W - 1][K - 1], -1);
      lli mx = rec(0, 0, h, w, t);
      setmin(z, mx - at_least);
    }
    cout << z << endl;
  }
  return 0;
}
