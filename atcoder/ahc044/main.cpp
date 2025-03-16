// github.com/Johniel/contests
// atcoder/ahc044/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename P, typename Q, typename R> ostream& operator << (ostream& os, tuple<P, Q, R> t) { os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ")"; return os; }
template<typename P, typename Q, typename R> istream& operator >> (istream& is, tuple<P, Q, R>& t) { is >> get<0>(t) >> get<1>(t) >> get<2>(t); return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "set{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "map{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, stack<T> s) { os << "stack{"; while (s.size()) { os << s.top() << ","; s.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, queue<T> q) { os << "queue{"; while (q.size()) { os << q.front() << ","; q.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, deque<T> q) { os << "deque{"; for (int i = 0; i < q.size(); ++i) os << q[i] << ","; os << "}"; return os; }
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

uint32_t xorshift(void)
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

const int N = 100;
const int L = 5 * 1e5;
const lli inf = (1LL << 60);
vec<int> T(N);
using int128 = __int128_t;

struct S {
  vec<int> a;
  vec<int> b;
  vec<int> diff;
  lli ha, hb;
  int score;
  S() {
    a.resize(N, -1);
    b.resize(N, -1);
    diff.resize(N, 0LL);
    score = 0;
  }
  int eval(void) {
    fill(diff.begin(), diff.end(), 0);
    {
      int x = 0;
      for (int i = 0; i < L; ++i) {
        ++diff[x];
        if (diff[x] % 2) x = a[x];
        else             x = b[x];
      }
    }
    score = 0;
    ha = 0;
    hb = 0;
    for (int i = 0; i < N; ++i) {
      diff[i] -= T[i];
      score += abs(diff[i]);
      const lli P = 137;
      ha = ha * P + (a[i] + 1);
      hb = hb * P + (b[i] + 1);
    }
    // clog << a << ' ' << ha << endl;
    // clog << b << ' ' << hb << endl;
    return score;
  }
  pair<lli, lli> ID(void) const {
    return make_pair(ha, hb);
  }
};
bool operator < (const S& x, const S& y)
{
  return x.score > y.score;
}

S seed(void)
{
  S s;
  for (int i = 0; i < N; ++i) {
    s.a[i] = xorshift() % N;
    s.b[i] = xorshift() % N;
  }
  s.eval();
  return s;
}

S seed0(void)
{
  S s;
  for (int i = 0; i < N; ++i) {
    s.a[i] = (i + 1) % N;
    s.b[i] = (i + 1) % N;
  }
  s.eval();
  return s;
}

S seed0R1(void)
{
  S s;
  for (int i = 0; i < N; ++i) {
    s.a[i] = (i + 1) % N;
    s.b[i] = (i + 1) % N;
  }
  int x = xorshift() % N;
  int y = xorshift() % N;
  int xt = xorshift() % 2;
  int yt = xorshift() % 2;
  if (xt == 0 && yt == 0) swap(s.a[x], s.a[y]);
  if (xt == 0 && yt == 1) swap(s.a[x], s.b[y]);
  if (xt == 1 && yt == 0) swap(s.b[x], s.a[y]);
  if (xt == 1 && yt == 1) swap(s.b[x], s.b[y]);
  s.eval();
  return s;
}

S seed0Ra(void)
{
  S s;
  for (int i = 0; i < N; ++i) {
    s.a[i] = (i + 1) % N;
    s.b[i] = (i + 1) % N;
  }
  for (int i = 0; i < N; ++i) {
    int x = xorshift() % N;
    int y = xorshift() % N;
    swap(s.a[x], s.a[y]);
  }
  for (int i = 0; i < N; ++i) {
    int x = xorshift() % N;
    int y = xorshift() % N;
    swap(s.b[x], s.b[y]);
  }
  s.eval();
  return s;
}

int main(int argc, char *argv[])
{
  { int _; cin >> _ >> _; cin >> T; }

  set<pair<lli, lli>> vis;
  priority_queue<pair<int, S>> q;
  pair<int, S> best;
  {
    S ini = seed0();
    best = make_pair(ini.score, ini);
    q.push(make_pair(ini.score, ini));
    vis.insert(ini.ID());
  }
  for (int _ = 0; _ < 20; ++_) {
    S ini = seed0R1();
    setmin(best, make_pair(ini.score, ini));
    q.push(make_pair(ini.score, ini));
    vis.insert(ini.ID());
  }
  for (int _ = 0; _ < 20; ++_) {
    S ini = seed0Ra();
    setmin(best, make_pair(ini.score, ini));
    q.push(make_pair(ini.score, ini));
    vis.insert(ini.ID());
  }

  const int WIDTH = 2;
  priority_queue<pair<int, S>> stok;
  priority_queue<pair<int, S>> stok2;
  int phase = 0;
  for (int _ = 0; _ < 132; ++_) {
    priority_queue<pair<int, S>> staging;

    if (q.size() < WIDTH) {
      while (stok.size()) {
        q.push(stok.top());
        stok.pop();
      }
      if (q.size() < WIDTH) {
        while (stok2.size()) {
          q.push(stok2.top());
          stok2.pop();
        }
      }
      q.push(best);
      phase = (phase + 1) % 4;
    }

    while (q.size()) {
      S curr = q.top().second;
      setmin(best, q.top());
      q.pop();

      int mx_idx = 0;
      int mn_idx = 0;
      for (int i = 0; i < N; ++i) {
        if (phase == 0) {
          if (curr.diff[mx_idx] < curr.diff[i]) mx_idx = i;
          if (curr.diff[mn_idx] > curr.diff[i]) mn_idx = i;
        } else if (phase == 1) {
          if (curr.diff[mx_idx] <= curr.diff[i]) mx_idx = i;
          if (curr.diff[mn_idx] >  curr.diff[i]) mn_idx = i;
        } else if (phase == 2) {
          if (curr.diff[mx_idx] <  curr.diff[i]) mx_idx = i;
          if (curr.diff[mn_idx] >= curr.diff[i]) mn_idx = i;
        } else {
          if (curr.diff[mx_idx] <= curr.diff[i]) mx_idx = i;
          if (curr.diff[mn_idx] >= curr.diff[i]) mn_idx = i;
        }
      }

      for (int i = 0; i < N; ++i) {
        if (curr.a[i] == mx_idx) {
          S next = curr;
          next.a[i] = mn_idx;
          next.eval();
          if (!vis.count(next.ID())) {
            staging.push(make_pair(next.score, next));
            vis.insert(next.ID());
          }
        }
        if (curr.b[i] == mx_idx) {
          S next = curr;
          next.b[i] = mn_idx;
          next.eval();
          if (!vis.count(next.ID())) {
            staging.push(make_pair(next.score, next));
            vis.insert(next.ID());
          }
        }
      }
    }

    while (WIDTH * 2 < staging.size()) {
      staging.pop();
      stok2.push(staging.top());
    }
    while (WIDTH < staging.size()) {
      staging.pop();
      stok.push(staging.top());
    }
    while (WIDTH < stok.size()) {
      stok2.push(stok.top());
      stok.pop();
    }
    while (WIDTH * 2 < stok2.size()) {
      stok2.pop();
    }
    while (staging.size()) q.push(staging.top()), staging.pop();
  }

  while (q.size()) {
    setmin(best, q.top());
    q.pop();
  }

  for (int i = 0; i < N; ++i) {
    cout << best.second.a[i] << ' ' << best.second.b[i] << endl;
  }
  // clog << best.first << ", " << 1000000 - best.first << endl;

  return 0;
}
