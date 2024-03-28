// github.com/Johniel/contests
// codeforces/937div4/G/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define makepair(a, b) make_pair(a, b)
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

__attribute__((constructor)) static void _____(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

lli rhash(str s) {
  lli h = 0;
  each (c, s) {
    lli x = c - 'a' + 1;
    h = h * mod + x;
  }
  return h;
}

int main(int argc, char *argv[])
{
  { int _; cin >> _; }
  int n;
  while (cin >> n) {
    vec<pair<lli, lli>> v;
    for (int i = 0; i < n; ++i) {
      str a, b;
      cin >> a >> b;
      v.push_back(make_pair(rhash(a), rhash(b)));
    }
    const int N = 16;
    const int B = (1 << N) + 3;
    static int dp[B][N];
    for (int i = 0; i < (1 << n); ++i) {
      for (int j = 0; j < n; ++j) {
        dp[i][j] = (1 << 29);
      }
    }
    for (int i = 0; i < n; ++i) {
      dp[1 << i][i] = 0;
    }
    for (int bit = 0; bit < (1 << n); ++bit) {
      vec<int> already, still;
      for (int i = 0; i < n; ++i) {
        if (bit & (1 << i)) already.push_back(i);
        else still.push_back(i);
      }
      each (i, already) {
        each (j, still) {
          if (v[i].first == v[j].first || v[i].second == v[j].second) {
            setmin(dp[bit | (1 << j)][j], dp[bit][i]);
          } else {
            setmin(dp[bit | (1 << j)][i], dp[bit][i] + 1);
          }
        }
      }
    }
    int mn = 1 << 29;
    for (int i = 0; i < n; ++i) {
      setmin(mn, dp[(1 << n) - 1][i]);
    }
    cout << mn << endl;
  }
  return 0;
}
