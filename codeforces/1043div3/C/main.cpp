// github.com/Johniel/contests
// codeforces/1043div3/C/main.cpp

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
  vec<lli> p3(10000);
  p3[0] = 1;
  for (int i = 1; i < p3.size(); ++i) {
    p3[i] = p3[i - 1] * 3;
  }

  vec<lli> v(10000);
  v[0] = 3;
  for (int x = 1; x + 1 < p3.size(); ++x) {
    v[x] = p3[x + 1] + x * p3[x - 1];
  }

  { int _; cin >> _; }

  lli n, k;
  while (cin >> n >> k) {
    int i = 0;
    vec<pair<lli, lli>> u;
    lli y = 0;
    while (n) {
      int m = n % 3;
      u.push_back(make_pair(v[i], m));
      y += m;
      n /= 3;
      ++i;
    }

    auto fn = [&] (lli i) {
      return y - i + i * 3 <= k;
    };

    reverse(u.begin(), u.end());
    for (int i = 0; i + 1 < u.size(); ++i) {
      lli small = 0;
      lli large = u[i].second + 1;
      while (small + 1 < large) {
        lli mid = (small + large) / 2;
        if (fn(mid)) small = mid;
        else large = mid;
      }
      if (fn(small)) {
        u[i].second -= small;
        u[i + 1].second += small * 3;
        y = y - small + small * 3;
      } else {
        break;
      }
    }
    lli z = 0;
    each (i, u) z += i.second * i.first;
    if (k < y) z = -1;
    cout << z << endl;
  }


  return 0;
}

// int main(int argc, char *argv[])
// {
//   vec<lli> p3(10000);
//   p3[0] = 1;
//   for (int i = 1; i < p3.size(); ++i) {
//     p3[i] = p3[i - 1] * 3;
//   }

//   vec<lli> v(10000);
//   v[0] = 3;
//   for (int x = 1; x + 1 < p3.size(); ++x) {
//     v[x] = p3[x + 1] + x * p3[x - 1];
//   }

//   { int _; cin >> _; }

//   lli n;
//   while (cin >> n) {
//     lli z = 0;
//     int i = 0;
//     while (n) {
//       int m = n % 3;
//       z += v[i] * m;
//       n /= 3;
//       ++i;
//     }
//     cout << z << endl;
//   }


//   return 0;
// }
