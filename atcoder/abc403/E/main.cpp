// github.com/Johniel/contests
// atcoder/abc403/E/main.cpp

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
  int q;
  while (cin >> q) {
    auto count = [&] (const str& s, const ordered_set<pair<str, int>>& vis) {
      auto mn = vis.lower_bound(make_pair(s, -1));
      auto mx = vis.lower_bound(make_pair(s + "~", -1));
      int z = 0;
      z -= vis.order_of_key(*mn);
      z += vis.order_of_key(*mx);
      vec<pair<str, int>>v;
      each (i, vis) v.push_back(i);
      cout << v << ' ' << s << ' ' << z << endl;
      return max(0, z);
    };
    // ordered_set<pair<str, int>> X, Y;
    int z = 0;
    const int P = 37;
    set<lli> X;
    map<lli, vec<int>> pend;
    set<int> R;
    for (int i = 0; i < q; ++i) {
      int op;
      str s;
      cin >> op >> s;
      if (op == 1) {
        lli h = 0;
        for (int i = 0; i < s.size(); ++i) {
          h = h * P + (s[i] - 'a' + 1);
        }
        // cout << s << ' ' << h << ' ' << pend << endl;
        X.insert(h);
        if (pend.count(h)) {
          each (j, pend[h]) {
            unless (R.count(j)) --z;
            R.insert(j);
          }
          pend.erase(h);
        }
      }
      if (op == 2) {
        vec<lli> u;
        lli h = 0;
        for (int i = 0; i < s.size(); ++i) {
          h = h * P + (s[i] - 'a' + 1);
          u.push_back(h);
        }
        bool found = false;
        each (i, u) {
          if (X.count(i)) {
            found = true;
            break;
          }
        }
        if (found) {
        } else {
          ++z;
          each (j, u) pend[j].push_back(i);
        }
      }
      cout << z << endl;
    }
  }
  return 0;
}
