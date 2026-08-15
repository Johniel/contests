// github.com/Johniel/contests
// atcoder/abc471/F/main.cpp

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

// Sort strings so that their concatenation becomes lexicographically
// minimum/maximum.
//
// For two strings a and b:
//   a should come before b iff a + b < b + a.
//
// Typical use cases:
// - Arrange decimal strings to form the smallest/largest number.
// - Optimize the lexicographical order of a concatenation.
// - Any problem where only the relative order of concatenated strings matters.
template<bool Greater = false>
struct omega_order {
  bool operator()(const string& a, const string& b) const {
    const int n = a.size();
    const int m = b.size();

    for (int i = 0; i < n + m; ++i) {
      const char x = (i < n) ? a[i] : b[i - n];
      const char y = (i < m) ? b[i] : a[i - m];

      if (x != y) {
        return Greater ? x > y : x < y;
      }
    }
    return false;
  }
};

int main(int argc, char *argv[])
{
  int n, k;
  while (cin >> n >> k) {
    str A, B;

    vec<str> v(n);
    cin >> v;

    vec<pair<int, lli>> u;
    for (int i = 0; i < v.size(); ++i) {
      u.push_back(make_pair(v[i].size(), stoll(v[i])));
    }
    vec<int> idx(u.size());
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&] (auto i, auto j) { return u[i] < u[j]; });
    reverse(idx.begin(), idx.end());

    vec<str> a;
    for (int i = 0; i < k; ++i) {
      a.push_back(v[idx[i]]);
    }

    vec<str> b;
    for (int i = 0; i < k - 1; ++i) {
      b.push_back(v[idx[i]]);
    }
    int mx = k - 1;
    for (int i = k - 1; i < idx.size(); ++i) {
      if (u[idx[mx]].second < u[idx[i]].second) {
        mx = i;
      }
    }
    b.push_back(to_string(u[idx[mx]].second));

    sort(a.begin(), a.end(), omega_order<true>{});
    sort(b.begin(), b.end(), omega_order<true>{});
    str s = accumulate(a.begin(), a.end(), str(""));
    str t = accumulate(b.begin(), b.end(), str(""));

    reverse(t.begin(), t.end());
    while (t.size() && t.back() == '0') t.pop_back();
    reverse(t.begin(), t.end());
    if (t.empty()) t = "0";

    reverse(s.begin(), s.end());
    while (s.size() && s.back() == '0') s.pop_back();
    reverse(s.begin(), s.end());
    if (s.empty()) s = "0";

    if (s.size() == t.size()) cout << max(s, t) << endl;
    else {
      if (s.size() < t.size()) cout << t << endl;
      else cout << s << endl;
    }
  }
  return 0;
}
