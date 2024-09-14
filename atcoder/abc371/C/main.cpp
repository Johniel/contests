// github.com/Johniel/contests
// atcoder/abc371/C/main.cpp

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
  while (cin >> n) {
    vec<pair<int, int>> g;
    {
      int m;
      cin >> m;
      for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g.push_back(make_pair(a, b));
        g.push_back(make_pair(b, a));
      }
      assert(g.size() == m * 2);
      sort(g.begin(), g.end());
    }
    vec<pair<int, int>> h;
    {
      int m;
      cin >> m;
      for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        h.push_back(make_pair(a, b));
        h.push_back(make_pair(b, a));
      }
      assert(h.size() == m * 2);
      sort(h.begin(), h.end());
    }

    lli A[n][n];
    for (int i = 0; i < n; ++i) {
      A[i][i] = 0;
      for (int j = i + 1; j < n; ++j) {
        cin >> A[i][j];
        A[j][i] = A[i][j];
      }
    }

    vec<int> rename(n);
    iota(rename.begin(), rename.end(), 0);
    lli mn = 1LL << 60;
    do {
      vec<int> rev(n);
      for (int i = 0; i < rename.size(); ++i) {
        rev[rename[i]] = i;
      }
      for (int i = 0; i < n; ++i) assert(i == rev.at(rename.at(i)));
      vec<pair<int, int>> u;
      each (e, h) {
        u.push_back(make_pair(rename[e.first], rename[e.second]));
      }
      sort(u.begin(), u.end());
      lli z = 0;
      each (e, u) {
        if (!binary_search(g.begin(), g.end(), e)) {
          z += A[rev[e.first]][rev[e.second]];
        }
      }
      each (e, g) {
        if (!binary_search(u.begin(), u.end(), e)) {
          z += A[rev[e.first]][rev[e.second]];
        }
      }
      setmin(mn, z / 2);
      // if (z / 2 == 1) cout << rename << endl;
    } while (next_permutation(rename.begin(), rename.end()));
    cout << mn << endl;
  }
  return 0;
}
