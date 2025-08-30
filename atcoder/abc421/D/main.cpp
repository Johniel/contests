// github.com/Johniel/contests
// atcoder/abc421/D/main.cpp

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
  pair<lli, lli> x, y;
  lli n, s_, t_;
  while (cin >> x >> y>> n >> s_ >> t_) {
    vec<pair<char, lli>> s(s_);
    vec<pair<char, lli>> t(t_);
    cin >> s >> t;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());

    lli z = 0;

    // tから見た差
    pair<lli, lli> p = make_pair(x.first - y.first, x.second - y.second);
    while (s.size() && t.size()) {
      lli len_s = s.back().second;
      lli len_t = t.back().second;
      lli len_mn = min(len_s, len_t);

      pair<lli, lli> diff = make_pair(0, 0);

      if (s.back().first == 'U') diff.first -= 1;
      if (s.back().first == 'D') diff.first += 1;
      if (s.back().first == 'L') diff.second -= 1;
      if (s.back().first == 'R') diff.second += 1;

      if (t.back().first == 'U') diff.first += 1;
      if (t.back().first == 'D') diff.first -= 1;
      if (t.back().first == 'L') diff.second += 1;
      if (t.back().first == 'R') diff.second -= 1;


      pair<lli, lli> D;
      D.first = len_mn * diff.first;
      D.second = len_mn * diff.second;

      if (diff == make_pair(0LL, 0LL)) {
        if (p == make_pair(0LL, 0LL)) z += len_mn;
      } else if (diff.first == 0) {
        if (p.first == 0 && p.second % diff.second == 0) {
          lli y = -p.second / diff.second;
          z += (1 <= y && y <= len_mn);
        }
      } else if (diff.second == 0) {
        if (p.second == 0 && p.first % diff.first == 0) {
          lli x = -p.first / diff.first;
          z += (1 <= x && x <= len_mn);
        }
      } else {
        if (p.first % diff.first == 0 && p.second % diff.second == 0) {
          lli x = (-p.first) / diff.first;
          lli y = (-p.second) / diff.second;
          z += (x == y) && (1 <= x && y <= len_mn);
        }
      }

      p.first += D.first;
      p.second += D.second;

      s.back().second -= len_mn;
      t.back().second -= len_mn;
      if (s.back().second == 0) s.pop_back();
      if (t.back().second == 0) t.pop_back();
    }

    cout << z << endl;
  }
  return 0;
}
