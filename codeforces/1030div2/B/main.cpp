// github.com/Johniel/contests
// codeforces/1030div2/B/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

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

constexpr lli mod = 998244353; // 1e9 + 7;

int main(int argc, char *argv[])
{
  // {
  //   const int n = 5;
  //   int g[n][n];
  //   for (int i = 0; i < n; ++i) {
  //     for (int j = 0; j < n; ++j) {
  //       g[i][j] = j;
  //     }
  //   }
  //   for (int i = 0; i < n; ++i) {
  //     vec<int> v;
  //     for (int j = 0; j < n; ++j) {
  //       v.push_back(g[i][j]);
  //     }
  //     reverse(v.begin(), v.begin() + i);
  //     reverse(v.begin() + i, v.end());
  //     for (int j = 0; j < n; ++j) {
  //       g[i][j] = v[j];
  //     }
  //   }
  //   for (int i = 0; i < n; ++i) {
  //     for (int j = 0; j < n; ++j) {
  //       cout << g[i][j]+1 << ' ';
  //     }
  //     cout << endl;
  //   }
  // }
  { int _; cin >> _; }
  int n;
  while (cin >> n) {
    vec<vec<int>> v;
    for (int i = 1; i <= n; ++i) {
      v.push_back({i, 1, i});
      if (i < n) v.push_back({i, i + 1, n});
    }

    cout << v.size() << endl;
    each (u, v) {
      cout << u[0] << ' ' << u[1] << ' ' << u[2] << endl;
    }

    // int g[n][n];
    // for (int i = 0; i < n; ++i) {
    //   for (int j = 0; j < n; ++j) {
    //     g[i][j] = j + 1;
    //   }
    // }
    // each (u, v) {
    //   vec<int> w;
    //   for (int i = 0; i < n; ++i) {
    //     w.push_back(g[u[0] - 1][i]);
    //   }
    //   cout << u << ": " << w << " -> ";
    //   reverse(w.begin() + u[1] - 1, w.begin() + u[2]);
    //   cout << w << endl;
    //   for (int i = 0; i < w.size(); ++i) {
    //     g[u[0] - 1][i] = w[i];
    //   }
    // }
    // for (int i = 0; i < n; ++i) {
    //   cout << "> ";
    //   for (int j = 0; j < n; ++j) {
    //     cout << g[i][j] << ' ';
    //   }
    //   cout << endl;
    // }
  }
  return 0;
}
