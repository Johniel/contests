// github.com/Johniel/contests
// atcoder/abc399/D/main.cpp

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
  { int _; cin >> _; }
  int n;
  while (cin >> n) {
    vec<int> a(n * 2);
    cin >> a;
    map<int, int> m;
    vec<pair<int, int>> v;
    each (i, a) {
      v.push_back(make_pair(i, m[i]++));
    }

    set<int> taboo;
    for (int i = 0; i + 1 < a.size(); ++i) {
      if (a[i] == a[i + 1]) taboo.insert(a[i]);
    }

    set<pair<pair<int, int>, pair<int, int>>> vis;
    lli z = 0;
    for (int i = 0; i < v.size(); ++i) {
      int j = i - 1;
      int k = i + 1;
      if (0 <= j) {
        vis.insert(make_pair(v[i], v[j]));
        vis.insert(make_pair(v[j], v[i]));
      }
      if (k < v.size()) {
        vis.insert(make_pair(v[i], v[k]));
        vis.insert(make_pair(v[k], v[i]));
      }
      if (!taboo.count(v[i].first) && !taboo.count(v[j].first)) {
        auto p = make_pair(v[i], v[j]);
        p.first.second ^= 1;
        p.second.second ^= 1;
        z += vis.count(p);
      }
      if (!taboo.count(v[i].first) && !taboo.count(v[k].first)) {
        auto p = make_pair(v[i], v[k]);
        p.first.second ^= 1;
        p.second.second ^= 1;
        z += vis.count(p);
      }
    }
    cout << z/2 << endl;
  }
  return 0;
}
