// github.com/Johniel/contests
// atcoder/abc381/F/main.cpp

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

const int N = 2 * 1e5 + 3;

vec<int> g[N];
vec<int> same;
vec<int> a;

const int M = 20;
int memo[N];
int rec(int left)
{
  int &ret = memo[left];
  if (ret != -1) return ret;

  int mx = 1;
  int right = same[left];
  each (next, g[right]) {
    // if (bit & (1 << a[next])) continue;
    // setmax(mx, rec(next) + (a[next] != a[curr]));
  }

  // return mx;
  return ret = mx;
}

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    fill(g, g + N, vec<int>());
    same.resize(N, -1);
    fill(memo, memo + N, -1);

    a.resize(n);
    cin >> a;
    each (i, a) --i;

    {
      fill(same.begin(), same.end(), -1);
      map<int, vec<int>> m;
      for (int i = 0; i < a.size(); ++i) {
        m[a[i]].push_back(i);
      }
      each (k, m) {
        vec<int> v = k.second;
        while (2 <= v.size()) {
          int i = v.back();
          v.pop_back();
          same[v.back()] = i;
        }
      }
    }
    map<int, vec<int>> m;
    for (int i = 0; i < a.size(); ++i) {
      m[a[i]].push_back(i);
    }

    const int B = (1 << 20) + 3;
    static int dp[B]; // dp[状態]:=最後
    const int inf = 1 << 28;
    fill(dp, dp + B, inf);
    dp[0] = -1;
    for (int bit = 0; bit < B; ++bit) {
      if (dp[bit] == inf) continue;
      int prev = dp[bit];
      for (int j = 0; j < 20; ++j) {
        if (bit & (1 << j)) continue;
        auto itr = lower_bound(m[j].begin(), m[j].end(), prev + 1);
        if (itr == m[j].end()) continue;
        ++itr;
        if (itr == m[j].end()) continue;
        setmin(dp[bit | (1 << j)], *itr);
      }
    }

    int mx = 0;
    for (int i = 0; i < B; ++i) {
      if (dp[i] != inf) {
        setmax(mx, __builtin_popcount(i) * 2);
      }
    }
    cout << mx << endl;
    // cout << endl;
  }
  return 0;
}
