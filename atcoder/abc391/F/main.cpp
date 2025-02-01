// github.com/Johniel/contests
// atcoder/abc391/F/main.cpp

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
  int n;
  lli K;
  while (cin >> n >> K) {
    vec<lli> a(n);
    vec<lli> b(n);
    vec<lli> c(n);
    cin >> a >> b >> c;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    reverse(c.begin(), c.end());
    auto eval = [&] (int i, int j, int k) {
      assert(i < n);
      assert(j < n);
      assert(k < n);
      return a[i] * b[j] + b[j] * c[k] + c[k] * a[i];
    };
    auto eval_v = [&] (vec<int> v) {
      assert(v.size() == 3);
      return eval(v[0], v[1], v[2]);
    };

    priority_queue<pair<lli, vec<int>>> q;
    vec<int> ini({0, 0, 0});
    q.push(make_pair(eval_v(ini), ini));
    set<vec<int>> vis;
    vis.insert(ini);

    vec<lli> v;

    while (q.size()) {
      auto p = q.top();
      q.pop();
      auto [val, u] = p;
      v.push_back(abs(val));
      if (5 * 1e5 < v.size()) break;
      for (int i = 0; i < 3; ++i) {
        ++u[i];
        if (u[i] < n) {
          unless (vis.count(u)) {
            vis.insert(u);
            q.push(make_pair(eval_v(u), u));
          }
        }
        --u[i];
      }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    cout << v[K - 1] << endl;
  }
  return 0;
}
