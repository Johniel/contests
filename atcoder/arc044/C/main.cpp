// github.com/Johniel/contests
// atcoder/arc044/C/main.cpp

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

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using str = string;
template<typename T> using vec = vector<T>;



int main(int argc, char *argv[])
{
  // h,w<=1e5
  // q<=1e5
  int h, w, q;
  while (cin >> h >> w >> q) {
    // dp[q][i][j]:=q回目のビームを回避したいときにi,jにいるコスト
    // 縦横独立だったりしない？
    vec<pair<int, int>> a, b;
    for (int i = 0; i < q; ++i) {
      int t, d, x;
      cin >> t >> d >> x;
      if (d == 0) a.push_back(make_pair(t, x));
      else        b.push_back(make_pair(t, x));
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    auto fn = [] (vec<pair<int, int>> v, const int h) {
      const int N = 1e5 + 3;
      // dp[i][x]:=i番目を避けたいときにxにいるコスト
      // 直前にビームの飛んできた箇所だけ更新できる？
      const int inf = (1 << 29);
      static int dp[2][N];
      fill(&dp[0][0], &dp[2 - 1][N - 1] + 1, inf);
      for (int i = 1; i <= h; ++i) {
        dp[0][i] = dp[1][i] = 0;
      }
      map<int, vec<int>> m;
      each (i, v) m[i.first].push_back(i.second);
      each (k, m) sort(k.second.begin(), k.second.end());
      int curr = 0;
      int next = 1;
      each (k, m) {
        each (i, k.second) dp[next][i] = inf;
        each (i, k.second) {
          setmin(dp[next][i], dp[next][i - 1] + 1);
          setmin(dp[next][i], dp[next][i + 1] + 1);
        }
        each (i, k.second | views::reverse) {
          setmin(dp[next][i], dp[next][i - 1] + 1);
          setmin(dp[next][i], dp[next][i + 1] + 1);
        }
        each (i, k.second) dp[curr][i] = dp[next][i];
        swap(curr, next);
      }
      int z = inf;
      for (int i = 0; i < N; ++i) setmin(z, dp[curr][i]);
      if (z == inf) return -inf;
      return z;
    };
    cout << max(fn(a, h) + fn(b, w), -1) << endl;
  }
  return 0;
}
