// github.com/Johniel/contests
// codeforces/e161/D/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
#define unless(cond) if (!(cond))
// #define endl "\n"

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

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  { int _; cin >> _; }

  int n;
  while (cin >> n) {
    vec<lli> a(n), d(n);
    cin >> a >> d;

    vec<int> right(n, -1);
    vec<int> left(n, -1);
    for (int i = 0; i < n; ++i) {
      if (i + 1 < n) right[i] = i + 1;
      if (0 <= i - 1) left[i] = i - 1;
    }

    vec<int> v;
    for (int i = 0; i < n; ++i) {
      lli x = 0;
      if (right[i] != -1) x += a[right[i]];
      if (left[i] != -1) x += a[left[i]];
      if (d[i] < x) v.push_back(i);
    }

    set<int> die;
    vec<int> r;
    for (int _ = 0; _ < n; ++_) {
      // cout << die << endl;
      // cout << right << endl;
      // cout << left << endl;
      r.push_back(v.size());
      set<int> u;
      each (i, v) {
        die.insert(i);
        if (left[i] != -1 && right[i] != -1) {
          right[left[i]] = right[i];
          left[right[i]] = left[i];
          u.insert(left[i]);
          u.insert(right[i]);
        } else if (left[i] != -1) {
          right[left[i]] = -1;
          u.insert(left[i]);
        } else if (right[i] != -1) {
          left[right[i]] = -1;
          u.insert(right[i]);
        }
      }
      vec<int> w;
      each (i, u) {
        unless (die.count(i)) {
          lli x = 0;
          if (right[i] != -1) x += a[right[i]];
          if (left[i] != -1) x += a[left[i]];
          if (d[i] < x) w.push_back(i);
        }
      }
      v.clear();
      each (i, w) v.push_back(i);
    }
    each (i, r) cout << i << ' '; cout << endl;
    // break;
  }

  return 0;
}
