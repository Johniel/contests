// github.com/Johniel/contests
// atcoder/abc467/D/main.cpp

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

// 線分PQの垂直二等分線 ax+by+c=0
tuple<long long int,
      long long int,
      long long int> get_canonical(
        long long int px, long long int py,
        long long int qx, long long int qy)
{
  // https://atcoder.jp/contests/abc467/editorial/23431
  long long int a = 2 * (qx - px);
  long long int b = 2 * (qy - py);
  long long int c = px * px + py * py - qx * qx - qy * qy;
  long long int g = gcd(a, gcd(b, c));
  a /= g, b /= g, c /= g;
  if (a < 0) a = -a, b = -b, c = -c;
  if (a == 0 and b < 0) b = -b, c = -c;
  return {a, b, c};
}

bool intersected_ll(tuple<long long int, long long int, long long int> l1,
                    tuple<long long int, long long int, long long int> l2)
{
  // https://atcoder.jp/contests/abc467/editorial/23431
  auto [a1, b1, c1] = l1;
  auto [a2, b2, c2] = l2;
  if (a1 * b2 - a2 * b1 == 0) {
    if (a1 == a2 and b1 == b2 and c1 == c2) {
      return true;
    } else {
      return false;
    }
  } else {
    return true;
  }
  assert(false);
}

int main(int argc, char *argv[])
{
  { int _; cin >> _; }
  vec<long long int> v(8);
  while (cin >> v) {
    auto x = get_canonical(v[0], v[1], v[2], v[3]);
    auto y = get_canonical(v[4], v[5], v[6], v[7]);
    cout << (intersected_ll(x, y) ? "Yes" : "No") << endl;
  }
  return 0;
}
