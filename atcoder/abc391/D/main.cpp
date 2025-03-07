// github.com/Johniel/contests
// atcoder/abc391/D/main.cpp

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

// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  int n, w;
  while (cin >> n >> w) {
    vec<pair<lli, int>> v[w];
    for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      v[x].push_back(make_pair(y, i));
    }
    const lli inf = (1LL << 60);
    for (int i = 0; i < w; ++i) {
      sort(v[i].begin(), v[i].end());
      reverse(v[i].begin(), v[i].end());
    }

    vec<lli> u(n, inf);
    lli T = 0;
    while (true) {
      lli mx = -inf;
      bool f = true;
      for (int i = 0; i < w; ++i) {
        if (v[i].empty()) {
          f = false;
          break;
        }
        setmax(mx, v[i].back().first - T);
      }
      unless (f) break;

      // for (int i = 0; i < w; ++i) cout << v[i] << endl;
      // cout << mx << endl;

      if (abs(mx) == inf) break;
      setmax(mx, 0LL);
      T += mx;
      for (int i = 0; i < w; ++i) {
        u[v[i].back().second] = (T + 1) * 2;
        // cout << "remove: " << v[i].back().second + 1  << endl;
        v[i].pop_back();
      }
    }
    // cout << u << endl;
    int q;
    cin >> q;
    while (q--) {
      lli t;
      int i;
      cin >> t >> i;
      --i;
      cout << (!(u[i] <= t * 2) ? "Yes" : "No") << endl;
    }
  }
  return 0;
}
