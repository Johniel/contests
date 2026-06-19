// github.com/Johniel/contests
// atcoder/awc0095/D/main.cpp

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

int main(int argc, char *argv[])
{
  int n, k;
  while (cin >> n >> k) {
    vec<tuple<int, int, int>> v(n);
    cin >> v;
    int mn = (1 << 29);
    for (int bit = 0; bit < (1 << v.size()); ++bit) {
      unless (__builtin_popcountll(bit) == k) continue;
      vec<pair<int, int>> u;
      vec<int> a;
      for (int i = 0; i < v.size(); ++i) {
        unless (bit & (1 << i)) {
          u.push_back(make_pair(get<0>(v[i]), get<1>(v[i])));
          a.push_back(get<2>(v[i]));
        }
      }
      // cout << u << ' ' << a << endl;
      int mx = 0;
      for (int bit2 = 0; bit2 < (1 << u.size()); ++bit2) {
        vec<pair<int, int>> w;
        vec<int> b;
        for (int k = 0; k < u.size(); ++k) {
          if (bit2 & (1 << k)) continue;
          w.push_back(u[k]);
          b.push_back(a[k]);
        }
        for (int i = 0; i < w.size(); ++i) {
          for (int j = i + 1; j < w.size(); ++j) {
            unless (w[i].second <= w[j].first || w[j].second <= w[i].first) {
              b[i] = b[j] = 0;
            }
          }
        }
        // cout << w << ' ' << b << ' ' << accumulate(b.begin(), b.end(), 0) << endl;
        setmax(mx, accumulate(b.begin(), b.end(), 0));
      }
      setmin(mn, mx);
    }
    cout << mn << endl;
    // break;
  }
  return 0;
}
