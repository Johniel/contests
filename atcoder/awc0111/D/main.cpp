// github.com/Johniel/contests
// atcoder/awc0111/D/main.cpp

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

const int N = 10 + 1;

vec<str> rec(int curr, int prev, vec<int> g[N])
{
  vec<vec<str>> v;
  each (next, g[curr]) {
    if (next == prev) continue;
    v.push_back(rec(next, curr, g));
  }
  if (v.empty()) return {"ab"};
  vec<str> u;
  sort(v.begin(), v.end());
  do {
    vec<int> a(v.size(), 0);
    while (true) {
      for (int i = 0; i + 1 < a.size(); ++i) {
        a[i + 1] += (a[i] / v[i].size());
        a[i] %= v[i].size();
      }
      if (a.back() == v.back().size()) break;
      str s;
      for (int i = 0; i < v.size(); ++i) {
        s += v[i][a[i]];
      }
      u.push_back(str("a") + s + str("b"));
      ++a[0];
    }
  } while (next_permutation(v.begin(), v.end()));
  sort(u.begin(), u.end());
  u.erase(unique(u.begin(), u.end()), u.end());
  return u;
}

vec<int> g1[N];
vec<int> g2[N];

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    fill(g1, g1 + n, vec<int>());
    fill(g2, g2 + n, vec<int>());
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g1[a].push_back(b);
      g1[b].push_back(a);
    }
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g2[a].push_back(b);
      g2[b].push_back(a);
    }

    vec<str> x = rec(0, -1, g1);
    vec<str> y = rec(0, -1, g2);
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    sort(y.begin(), y.end());
    y.erase(unique(y.begin(), y.end()), y.end());
    vec<str> v;
    set_intersection(x.begin(), x.end(), y.begin(), y.end(), back_inserter(v));

    cout << v.size() << endl;
    each (k, v) cout << k << endl;
  }
  return 0;
}
