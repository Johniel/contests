// github.com/Johniel/contests
// atcoder/abc445/D/main.cpp

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

int main(int argc, char *argv[])
{
  int h, w, n;
  while (cin >> h >> w >> n) {
    vec<pair<int, int>> v(n);
    cin >> v;
    vec<int> a(v.size());
    vec<int> b(v.size());
    iota(a.begin(), a.end(), 0);
    iota(b.begin(), b.end(), 0);
    sort(a.begin(), a.end(), [&] (int i, int j) { return v[i].first < v[j].first; });
    sort(b.begin(), b.end(), [&] (int i, int j) { return v[i].second < v[j].second; });
    set<int> vis;
    vec<pair<int, int>> u(n ,make_pair(-2, -2));
    while (vis.size() < n) {
      while (a.size() && vis.count(a.back())) a.pop_back();
      while (b.size() && vis.count(b.back())) b.pop_back();

      if (a.size() && v[a.back()].first == h) {
        u[a.back()] = make_pair(0, w - v[a.back()].second);
        vis.insert(a.back());
        w -= v[a.back()].second;
        // cout << "2> " << a.back()+1 << endl;
        continue;
      }
      if (b.size() && v[b.back()].second == w) {
        u[b.back()] = make_pair(h - v[b.back()].first, 0);
        vis.insert(b.back());
        h -= v[b.back()].first;
        // cout << "1> " << b.back()+1 << endl;
        continue;
      }
      // cout << a << endl;
      // cout << b << endl;
      // cout << vis << endl;
      // cout << h << ' ' << w << endl;
      // cout << u << endl;
      assert(false);
    }
    each (i, u) cout << i.first + 1 << ' ' << i.second + 1 << endl;
    // cout << endl;
  }
  return 0;
}
