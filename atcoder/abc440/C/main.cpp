// github.com/Johniel/contests
// atcoder/abc440/C/main.cpp

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
template<typename T> ostream& operator << (ostream& os, deque<T> q) {
  os << "deque{"; for (int i = 0; i < q.size(); ++i) os << q[i] << ","; os << "}"; return os; }
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


// https://ei1333.github.io/luzhiled/snippets/dp/slide-min.html

// template< typename T >
// vector< T > slide_min(const vector< T > &v, int k)
// {
//   deque< int > deq;
//   vector< T > ret;
//   for(int i = 0; i < v.size(); i++) {
//     while(!deq.empty() && v[deq.back()] >= v[i]) {
//       deq.pop_back();
//     }
//     deq.push_back(i);
//     if(i - k + 1 >= 0) {
//       ret.emplace_back(v[deq.front()]);
//       if(deq.front() == i - k + 1) deq.pop_front();
//     }
//   }
//   return ret;
// }

int main(int argc, char *argv[])
{
  { int _; cin >> _; }
  int n, w;
  while (cin >> n >> w) {
    vec<lli> c(n);
    cin >> c;

    // deque<lli> a;

    // for (int i = 0; i < n; ++i) c.push_back(c[i]);

    vec<lli> a(2 * w, 0);
    for (int i = 0; i < c.size(); ++i) {
      a[i % (2 * w)] += c[i];
    }
    // cout << a << endl;

    lli x = 0;
    for (int i = 0; i < w; ++i) {
      x += a[i];
    }

    int s = 0;
    int t = w;
    lli mn = (1LL << 60);
    for (int i = 0; i < 2 * w; ++i) {
      // cout << s << ' ' << x << endl;
      x -= a[s];
      x += a[t];
      ++s;
      ++t;
      s %= 2 * w;
      t %= 2 * w;
      setmin(mn, x);
    }
    cout << mn << endl;

    // lli x = 0;
    // int m = 0;
    // deque<int> q[n * 2];
    // for (int i = 0; i < c.size(); ++i) {
    //   q[i / w].push_back(i);
    //   m = i / w + 1;
    //   if ((i / w) % 2 == 0) x += c[i];
    // }

    // const lli S = accumulate(c.begin(), c.end(), 0LL);

    // if (m == 1) {
    //   cout << S - x << endl;
    //   continue;
    // }

    // lli mn = x;
    // const int fin = q[0].front();
    // for (int _ = 0; _ < m * 2; ++_) {
    //   for (int i = 0; i < m; ++i) {
    //     int j = (i - 1 + m) % m;
    //     q[j].push_back(q[i].front());
    //     q[i].pop_front();
    //   }
    //   for (int i = 0; i < m; ++i) {
    //     if (i % 2 == 0) {
    //       x += c[q[i].back()];
    //     } else {
    //       x -= c[q[i].back()];
    //     }
    //   }
    //   if (m % 2) x -= c[q[m - 1].back()];
    //   setmin(mn, x);
    //   setmin(mn, S - x);
    //   if (q[0].front() == fin) break;
    // }
    // cout << mn << endl;
  }
  return 0;
}
