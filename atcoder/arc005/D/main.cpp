// github.com/Johniel/contests
// atcoder/arc005/D/main.cpp

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
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

const int N = 20;
const int M = 11;
const int C = 100;
int memo[N][M][M][C];
array<int, 4> path[N][M][M][C];
vec<int> v;
vec<int> u;
const int inf = (1 << 28);
int rec(int nth, int k, int fixed, int carry)
{
  if (nth == u.size()) {
    if (carry == 0) return 0;
    else return inf;
  }

  if (C <= carry) return inf;
  if (M <= k) return inf;
  if (k < fixed) return inf;

  int& ret = memo[nth][k][fixed][carry];
  if (ret != -1) return ret;

  int mn = inf;

  if (fixed < k) {
    each (x, v) {
      if (x <= carry) {
        const int y = rec(nth, k, fixed + 1, carry - x) + 1; // num
        if (y < mn) {
          path[nth][k][fixed][carry] = array<int, 4>({nth, k, fixed + 1, carry - x});
          mn = y;
        }
      }
    }
  }
  if (fixed == k) {
    {
      int y = rec(nth, k + 1, fixed, carry) + 1; // '+' or '='
      if (y < mn) {
        path[nth][k][fixed][carry] = array<int, 4>({nth, k + 1, fixed, carry});
        mn = y;
      }
    }
    {
      const int nc = (carry * 10) + (nth + 1 < u.size() ? u[nth + 1] : 0);
      int y = rec(nth + 1, k, 0, nc);
      if (y < mn) {
        path[nth][k][fixed][carry] = array<int, 4>({nth + 1, k, 0, nc});
        mn = y;
      }
    }
  }

  return ret = mn;
}

int main(int argc, char *argv[])
{
  str s;
  str t;
  while (cin >> s >> t) {
    v.clear();
    u.clear();
    each (c, s) v.push_back(c - '0');
    each (c, t) u.push_back(c - '0');
    fill(&memo[0][0][0][0], &memo[N - 1][M - 1][M - 1][C - 1] + 1, -1);
    fill(&path[0][0][0][0], &path[N - 1][M - 1][M - 1][C - 1] + 1, array<int, 4>({-1, -1, -1, -1}));
    int cost = rec(0, 0, 0, u.front());

    int nth = 0;
    int k = 0;
    int fixed = 0;
    int carry = u.front();
    str u[M];
    // cout << cost << endl;
    while (path[nth][k][fixed][carry].front() != -1) {
      // cout << nth << ' ' << k << ' ' << fixed << ' ' << carry << endl;
      const auto& p = path[nth][k][fixed][carry];
      if (nth == p[0] && fixed < p[2]) {
        u[fixed] += '0' + abs(p[3] - carry);
      }
      nth = p[0];
      k = p[1];
      fixed = p[2];
      carry = p[3];
    }
    str r;
    for (int i = 0; i < M; ++i) {
      if (u[i].empty()) {
        r += '=';
        break;
      }
      if (r.size()) r += '+';
      r += u[i];
    }
    if (!count(r.begin(), r.end(), '+')) r.pop_back();
    cout << r << endl;
    // cout << endl;
  }
  return 0;
}
