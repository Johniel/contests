// github.com/Johniel/contests
// atcoder/ahc055/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename... Ts> ostream& operator << (ostream& os, const tuple<Ts...>& t) { os << "("; if constexpr (sizeof...(Ts) > 0) { apply([&](const Ts&... args) { ((os << args << ','), ...); }, t); } os << ")"; return os; }
template<typename... Ts> istream& operator >> (istream& is, tuple<Ts...>& t) { apply([&](Ts&... args) { ((is >> args), ...); }, t); return is; }
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

constexpr lli mod = 998244353; // 1e9 + 7;

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

int N = 200;
vec<vec<int>> A(N, vec<int>(N));
const int bare = -1;

struct State {
  vec<int> H;
  vec<int> C;
  vec<int> done;
  vec<pair<int, int>> v;
  State() { done.resize(N, 0); }

  double remave(const int target)
  {
    if (done[target] != 0) return -1;
    double tmp_sz = v.size();
    double tmp_hp = accumulate(H.begin(), H.end(), 0);

    priority_queue<pair<int, int>> q;
    q.push(make_pair(-H[target], target));

    while (q.size()) {
      auto [hp, target] = q.top();
      q.pop();
      hp = abs(hp);
      if (H[target] != hp) continue;
      done[target] = 1;
      for (int _ = 0; _ < hp; ++_) {
        v.push_back(make_pair(bare, target));
        --H[target];
      }
      vec<int> u(N);
      iota(u.begin(), u.end(), 0);
      sort(u.begin(), u.end(), [&] (auto x, auto y) { return A[target][x] > A[target][y]; });
      each (j, u) {
        if (C[target] <= 0) break;
        if (done[j]) continue;
        if (0 < H[j]) {
          if (H[j] == 1) {
            while (H[j]) {
              v.push_back(make_pair(bare, j));
              --H[j];
            }
          } else {
            int mn = min(H[j] / A[target][j], C[target]);
            for (int _ = 0; _ < mn; ++_) {
              v.push_back(make_pair(target, j));
              H[j] -= A[target][j];
              --C[target];
            }
          }
        }
        if (H[j] == 0) q.push(make_pair(-H[j], j));
      }
      if (0 < C[target]) {
        each (j, u) {
          if (C[target] <= 0) break;
          if (done[j]) continue;
          if (0 < H[j]) {
            if (H[j] == 1) {
              while (H[j]) {
                v.push_back(make_pair(bare, j));
                --H[j];
              }
            } else {
              v.push_back(make_pair(target, j));
              H[j] -= A[target][j];
              if (H[j] < 0) H[j] = 0;
              --C[target];
            }
          }
          if (H[j] == 0) q.push(make_pair(-H[j], j));
        }
      }
    }

    double sz = v.size();
    double hp = accumulate(H.begin(), H.end(), 0);
    return abs(hp - tmp_hp) / abs(sz - tmp_sz);
  }
};

vec<int> H(N);
vec<int> C(N);

int main(int argc, char *argv[])
{
  cin >> N;
  cin >> H >> C >> A;

  State s;
  s.H = H;
  s.C = C;

  while (true) {
    pair<double, int> p = make_pair(-1, -1);
    for (int i = 0; i < N; ++i) {
      State t = s;
      setmax(p, make_pair(t.remave(i), i));
    }
    if (p.first < 0) break;
    cerr << s.remave(p.second) << endl;
  }

  each (k, s.v) cout << k.first << ' ' << k.second << endl;
  cerr << s.v.size() << endl;

  return 0;
}
