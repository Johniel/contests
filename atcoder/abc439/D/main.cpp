// github.com/Johniel/contests
// atcoder/abc439/D/main.cpp

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

lli fn(vec<lli> a)
{
  map<lli, vec<int>> m;
  for (int i = 0; i < a.size(); ++i) {
    m[a[i]].push_back(i);
  }

  // map<lli, vec<int>> m2;
  // each (k, m) m2[k.first].push_back(0);

  // for (int i = 0; i < a.size(); ++i) {
  //   if ((a[i] * 7) % 5 == 0) {
  //     lli x = (a[i] * 7) / 5;
  //     auto itr = lower_bound(m[x].begin(), m[x].end(), i + 1);
  //     m2[a[i]].push_back(m[x].end() - itr);
  //   } else {
  //     m2[a[i]].push_back(0);
  //   }
  // }

  // cout << m << endl;
  // cout << m2 << endl;

  // each (k, m2) {
  //   for (int i = 0; i + 1 < k.second.size(); ++i) {
  //     k.second[i + 1] += k.second[i];
  //   }
  // }

  // lli z = 0;
  // for (int i = 0; i < a.size(); ++i) {
  //   if ((a[i] * 7) % 5 == 0) {
  //     lli x = (a[i] * 7) / 5;
  //     auto itr = lower_bound(m[x].begin(), m[x].end(), i + 1);
  //     z += m2[x].at(itr - m[x].begin());
  //   }
  // }

  lli z = 0;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] % 5) continue;
    lli a7 = a[i] / 5 * 7;
    lli a3 = a[i] / 5 * 3;

    auto itr7 = lower_bound(m[a7].begin(), m[a7].end(), i + 1);
    auto itr3 = lower_bound(m[a3].begin(), m[a3].end(), i + 1);
    lli x7 = m[a7].end() - itr7;
    lli x3 = m[a3].end() - itr3;
    z += x7 * x3;
  }

  return z;
}

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    vec<lli> a(n);
    cin >> a;
    lli z = 0;
    z += fn(a);
    reverse(a.begin(), a.end());
    z += fn(a);
    cout << z << endl;
  }
  return 0;
}
