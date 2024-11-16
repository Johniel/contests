// github.com/Johniel/contests
// atcoder/abc380/F/main.cpp

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

vec<int> a;
vec<int> v;
map<lli, int> memo[2];

int rec(lli st, int turn)
{
  if (memo[turn].count(st)) return memo[turn][st];

  const int win = 1;
  const int lose = 0;

  int mx = lose;
  {
    lli w = 1;
    for (int i = 0; i < a.size(); ++i) {
      if (v[i] == turn) {
        v[i] = 2;
        setmax(mx, rec(st - (w * turn) + (w * 2), turn ^ 1) ^ 1);
        v[i] = turn;
      }
      w *= 3;
    }
  }
  {
    lli w1 = 1;
    for (int i = 0; i < a.size(); ++i) {
      if (v[i] == turn) {
        lli w2 = 1;
        for (int j = 0; j < a.size(); ++j) {
          if (v[j] == 2 && a[j] < a[i]) {
            v[i] = 2;
            v[j] = turn;
            setmax(mx, rec(st - (w1 * turn) + (w1 * 2) - (w2 * 2) + (w2 * turn), turn ^ 1) ^ 1);
            v[i] = turn;
            v[j] = 2;
          }
          w2 *= 3;
        }
      }
      w1 *= 3;
    }
  }

  return memo[turn][st] = mx;
}

int main(int argc, char *argv[])
{
  int n, m, l;
  while (cin >> n >> m >> l) {
    a.clear();
    v.clear();
    lli s = 0;
    lli w = 1;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      // --x;
      a.push_back(x);
      v.push_back(0);

      s = s * w + v.back();
      w *= 3;
    }
    for (int i = 0; i < m; ++i) {
      int x;
      cin >> x;
      // --x;
      a.push_back(x);
      v.push_back(1);

      s = s * w + v.back();
      w *= 3;
    }
    for (int i = 0; i < l; ++i) {
      int x;
      cin >> x;
      // --x;
      a.push_back(x);
      v.push_back(2);

      s = s * w + v.back();
      w *= 3;
    }
    assert(v.size() == a.size());
    memo[0].clear();
    memo[1].clear();
    int x = rec(s, 0);
    cout << (x ? "Takahashi" : "Aoki") << endl;
  }
  return 0;
}
