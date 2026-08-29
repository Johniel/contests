// github.com/Johniel/contests
// atcoder/ahc070/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename... Ts> ostream& operator << (ostream& os, const tuple<Ts...>& t) { os << "("; if constexpr (sizeof...(Ts) > 0) { apply([&](const Ts&... args) { ((os << args << ','), ...); }, t); } os << ")"; return os; }
template<typename... Ts> istream& operator >> (istream& is, tuple<Ts...>& t) { apply([&](Ts&... args) { ((is >> args), ...); }, t); return is; }
template<typename T> ostream& operator << (ostream& os, const vector<T>& v) { os << "("; for (const auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, const set<T>& s) { os << "set{"; for (const auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, const map<K, V>& m) { os << "map{"; for (const auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (const auto& i: a) os << i << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, stack<T> s) { os << "stack{"; while (s.size()) { os << s.top() << ","; s.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, queue<T> q) { os << "queue{"; while (q.size()) { os << q.front() << ","; q.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, const deque<T>& q) { os << "deque{"; for (int i = 0; i < q.size(); ++i) os << q[i] << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, priority_queue<T> q) { os << "heap{"; while (q.size()) { os << q.top() << ","; q.pop(); } os << "}"; return os; }
template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void _____(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr lli mod = 998244353; // 1e9 + 7;

inline int manhattan(const pair<int, int>& a, const pair<int, int>& b)
{
  return abs(a.first - b.first) + abs(a.second - b.second);
}

inline uint32_t xorshift(void)
{
  // https://shindannin.hatenadiary.com/entry/2021/03/06/115415
  static uint32_t x = 123456789;
  static uint32_t y = 362436069;
  static uint32_t z = 521288629;
  static uint32_t w = 88675123;
  uint32_t t;

  t = x ^ (x << 11);
  x = y; y = z; z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

constexpr int N = 100;
constexpr int M = 3;
constexpr int inf = (1 << 28);

// https://kopricky.github.io/code/DataStructure_Advanced/bit_2d.html
// https://usaco.guide/plat/2DRQ?lang=cpp
// https://codeforces.com/blog/entry/56590
template<typename T>
struct BIT2D {
  vector<vector<T> > bit;
  BIT2D() { bit.resize(N + 1, vector<T>(N + 1, -inf)); }
  void update(int i, int j, T val) {
    for(int i_ = i + 1; i_ < N + 1; i_ += i_ & -i_) {
      for(int j_ = j + 1; j_ < N + 1; j_ += j_ & -j_) {
        setmax(bit[i_][j_], val);
      }
    }
    return ;
  }
  T query(int i, int j) {
    T mx = -inf;
    for(int i_ = i; i_ > 0; i_ -= i_ & -i_) {
      for(int j_ = j; j_ > 0; j_ -= j_ & -j_) {
        setmax(mx, bit[i_][j_]);
      }
    }
    return mx;
  }
};

// |xi - xj| + |yi - yj|

BIT2D<int> LR;
BIT2D<int> LL;
BIT2D<int> UR;
BIT2D<int> UL;

void put_talisman(int i, int j)
{
  UL.update(i, j, i + j);
  UR.update(i, N - j - 1, i - j);
  LR.update(N - i - 1, N - j - 1, - i - j);
  LL.update(N - i - 1, j, - i + j);
  return ;
}

void remove_talisman(int i, int j)
{
  UL.update(i, j, -inf);
  UR.update(i, N - j - 1, -inf);
  LR.update(N - i - 1, N - j - 1, -inf);
  LL.update(N - i - 1, j, -inf);
  return ;
}

int query(int i, int j)
{
  int mn = inf;
  setmin(mn, (i + j) - UL.query(i + 1, j + 1));
  setmin(mn, (i - j) - UR.query(i + 1, N - j));
  setmin(mn, (- i - j) - LR.query(N - i, N - j));
  setmin(mn, (- i + j) - LL.query(N - i, j + 1));
  return mn;
}

int main(int argc, char *argv[])
{
  const auto time_start = chrono::steady_clock::now();

  { int _; scanf("%d%d", &_, &_); }
  vec<pair<int, int>> hauntings(N * N);
  for (int i = 0; i < N * N; ++i) {
    scanf("%d%d", &hauntings[i].first, &hauntings[i].second);
  }

  double sq[N * N + 10];
  for (int i = 0; i < N * N + 10; ++i) {
    sq[i] = sqrt(i);
  }

  constexpr array<pair<int, int>, M> relationships = {
    make_pair(7, 0),
    make_pair(11, 0),
    make_pair(23, 23)};

  int best_level = inf;

  auto eval = [&] (const vec<int>& v) {
    for (int i = 0; i < N + 1; ++i) {
      for (int j = 0; j < N + 1; ++j) {
        LR.bit[i][j] = LL.bit[i][j] = UR.bit[i][j] = UL.bit[i][j] = -inf;
      }
    }

    int i = 0;
    int j = 0;
    int level = 0;
    for (int t = 0; t < v.size(); ++t) {
      const auto [di, dj] = relationships[v[t]];
      i = (i + di) % N;
      j = (j + dj) % N;
      put_talisman(i, j);
      int dt = query(hauntings[t].first, hauntings[t].second);
      level += floor(dt * sq[t + 1]);
      if (best_level < level) break;
    }
    return level;
  };
  vec<int> v(hauntings.size());
  for (int i = 0; i < v.size(); ++i) {
    v[i] = xorshift() % M;
  }
  best_level = eval(v);

  int updated = 0;
  int loop = 0;
  vec<int> u(hauntings.size());
  while (true) {
    double elapsed = chrono::duration<double>(chrono::steady_clock::now() - time_start).count();
    if (1.95 < elapsed) break;

    for (int i = 0; i < u.size(); ++i) {
      u[i] = xorshift() % M;
    }
    int curr_level = eval(u);

    if (best_level > curr_level) {
      v = u;
      best_level = curr_level;
      ++updated;
    }
    ++loop;
  }
  // cerr << "level: " << best_level << ' ' << "score: " << round(1e6 * N * N * N / (best_level + 1)) << ", " << updated << ", " << loop << endl;

  for (int i = 0; i < relationships.size(); ++i) {
    printf("%d %d\n", relationships[i].first, relationships[i].second);
  }
  for (int i = 0; i < v.size(); ++i) {
    printf("%d\n", v[i]);
  }
  // each (i, relationships) cout << i.first << ' ' << i.second << endl;
  // each (i, v) cout << i << endl;

  return 0;
}
