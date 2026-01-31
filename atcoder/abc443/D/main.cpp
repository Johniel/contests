// github.com/Johniel/contests
// atcoder/abc443/D/main.cpp

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
  { int _; cin >> _; }
  int n;
  while (cin >> n) {
    vec<int> a(n);
    cin >> a;
    const int mn = *min_element(a.begin(), a.end());

    // vec<int> v;
    // for (int i = 0; i < a.size(); ++i) {
    //   if (a[i] == mn) v.push_back(i);
    // }
    // vec<int> u(n, 1 << 29);
    // for (int i = 0; i < v.size(); ++i) {
    //   for (int j = 0; j < a.size(); ++j) {
    //     setmin(u[j], a[j]);
    //     setmin(u[j], abs(v[i] - j));
    //   }
    // }
    // cout << u << endl;


    vec<int> u = a;
    for (int _ = 0; _ < 4; ++_) {
      int x = a.front();
      bool f = false;
      for (int i = 0; i < a.size(); ++i) {
        // if (a[i] == mn) f = true;
        // unless (f) continue;
        // if (u[i] == mn) x = u[i];
        setmin(u[i], x);
        x = u[i] + 1;
      }
      reverse(a.begin(), a.end());
      reverse(u.begin(), u.end());
    }
    // cout << u << endl;
    lli z = 0;
    for (int i = 0; i < a.size(); ++i) {
      z += abs(u[i] - a[i]);
    }
    cout << z << endl;
    for (int i = 0; i < a.size(); ++i) assert(u[i] <= a[i]);
    for (int i = 0; i + 1 < a.size(); ++i) assert(abs(u[i] - u[i + 1]) <= 1);
  }
  return 0;
}
