// atcoder/abc228/F/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <vector>
#include <deque>
#include <array>
#include <cassert>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <complex>

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

// u[i]=cmp{v[i],v[i+1]...,v[i+k]}な列を返す。
// verified at: ABC228F
template<typename T, class Compare = std::less<T>>
vector<T> slide_min(const vector<T>& v, const size_t k, Compare cmp = std::less<T>())
{
  deque<size_t> q;
  vector<T> u;
  for (size_t i = 0; i < v.size(); ++i) {
    while (!q.empty() && cmp(v[i], v[q.back()])) q.pop_back();
    while (!q.empty() && q.front() + k <= i) q.pop_front();
    q.push_back(i);
    if (k <= i + 1) u.push_back(v[q.front()]);
  }
  return u;
}

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

  const int N = 1000 + 3;

  int h, w, h1, w1, h2, w2;
  while (cin >> h >> w >> h1 >> w1 >> h2 >> w2) {
    setmin(h1, h);
    setmin(w1, w);
    setmin(h2, h1);
    setmin(w2, w1);
    vec<vec<lli>> g(h, vec<lli>(w));
    cin >> g;
    PrefixSum2D<lli> sum(g);
    static lli mx[N][N];
    fill(&mx[0][0], &mx[N - 1][N - 1] + 1, -(1LL << 60));
    for (int i = 0; i + h2 <= h; ++i) {
      vec<lli> v;
      for (int j = 0; j + w2 <= w; ++j) {
        v.push_back(sum.query(i, j, i + h2, j + w2));
      }
      v = slide_min(v, w1 - w2 + 1, greater<lli>());
      for (int j = 0; j < v.size(); ++j) {
        mx[i][j] = v[j];
      }
    }
    for (int j = 0; j < w; ++j) {
      vec<lli> v;
      for (int i = 0; i < h; ++i) {
        v.push_back(mx[i][j]);
      }
      v = slide_min(v, h1 - h2 + 1, greater<lli>());
      for (int i = 0; i < v.size(); ++i) {
        mx[i][j] = v[i];
      }
    }
    lli z = 0;
    for (int i = 0; i + h1 <= h; ++i) {
      for (int j = 0; j + w1 <= w; ++j) {
        setmax(z, sum.query(i, j, i + h1, j + w1) - mx[i][j]);
      }
    }
    cout << z << endl;
  }

  return 0;
}
