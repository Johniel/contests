// github.com/Johniel/contests
// atcoder/abc025/D/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename P, typename Q, typename R> ostream& operator << (ostream& os, tuple<P, Q, R> t) { os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ")"; return os; }
template<typename P, typename Q, typename R> istream& operator >> (istream& is, tuple<P, Q, R>& t) { is >> get<0>(t) >> get<1>(t) >> get<2>(t); return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, stack<T> s) { os << "stack{"; while (s.size()) { os << s.top() << ","; s.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, queue<T> q) { os << "queue{"; while (q.size()) { os << q.front() << ","; q.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, deque<T> q) { os << "deque{"; for (int i = 0; i < q.size(); ++i) os << q[i] << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, priority_queue<T> q) { os << "heap{"; while (q.size()) { os << q.top() << ","; q.pop(); } os << "}"; return os; }

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

const int N = 5;
int g[N][N];
int h[N][N];
bool cons[N][N];

vec<pair<int, int>> pos;

const int M = 20;
const int BIT = (1 << M);
vec<lli> dp;
lli is_valid(const int bit, pair<int, int> p)
{
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      h[i][j] = cons[i][j];
    }
  }
  for (int k = 0; k < pos.size(); ++k) {
    if (bit & (1 << k)) {
      auto [i, j] = pos[k];
      h[i][j] = 1;
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j + 2 < N; ++j) {
      const int a = j + 0;
      const int b = j + 1;
      const int c = j + 2;
      if (p == make_pair(i, b) && h[i][a] + h[i][b] + h[i][c] == 1) return false;
    }
  }
  for (int j = 0; j < N; ++j) {
    for (int i = 0; i + 2 < N; ++i) {
      const int a = i + 0;
      const int b = i + 1;
      const int c = i + 2;
      if (p == make_pair(b, j) && h[a][j] + h[b][j] + h[c][j] == 1) return false;
    }
  }
  return true;
}

int main(int argc, char *argv[])
{
  while (true) {
    {
      bool f = true;
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          f = f && (cin >> g[i][j]);
        }
      }
      unless (f) break;
    }

    map<int, pair<int, int>> existing;
    pos.clear();
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (g[i][j]) existing[g[i][j]] = make_pair(i, j);
        else pos.push_back(make_pair(i, j));
      }
    }

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        cons[i][j] = false;
      }
    }

    dp.resize(BIT, 0);
    dp[0] = 1;
    for (int k = 1; k <= 25; ++k) {
      vec<lli> next(dp.size(), 0);
      for (int bit = 0; bit < (1 << pos.size()); ++bit) {
        unless (dp[bit]) continue;
        if (existing.count(k)) {
          if (is_valid(bit, existing[k])) {
            (next[bit] += dp[bit]) %= mod;
          }
        } else {
          for (int s = 0; s < pos.size(); ++s) {
            if (bit & (1 << s)) continue;
            if (is_valid(bit, pos[s])) {
              (next[bit | (1 << s)] += dp[bit]) %= mod;
            }
          }
        }
      }
      if (existing.count(k)) {
        auto [i, j] = existing[k];
        cons[i][j] = k;
      }
      dp = next;
    }
    cout << dp[(1 << pos.size()) - 1] << endl;
  }

  return 0;
}
