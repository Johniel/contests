// github.com/Johniel/contests
// atcoder/abc390/E/main.cpp

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
  lli x;
  while (cin >> n >> x) {
    lli v[n];
    lli a[n];
    lli c[n];
    for (int i = 0; i < n; ++i) {
      cin >> v[i] >> a[i] >> c[i];
    }

    vec<pair<lli, lli>> u[3];
    for (int i = 0; i < n; ++i) {
      u[v[i] - 1].push_back(make_pair(a[i], c[i]));
    }

    const lli inf = (1LL << 60);
    const int X = 5000 + 3;
    vec<pair<lli, lli>> w[3]; // {ビタミンの総和、カロリー}
    for (int idx = 0; idx < 3; ++idx) {
      const int N = u[idx].size() + 1;
      // dp[どこまで見た][カロリー]:=ビタミンの総和;
      lli dp[N][X];
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < X; ++j) {
          dp[i][j] = -inf;
        }
      }
      dp[0][0] = 0;
      for (int i = 0; i < u[idx].size(); ++i) {
        for (int j = 0; j <= x; ++j) {
          setmax(dp[i + 1][j], dp[i][j]);
          auto [a, c] = u[idx][i];
          if (j + c <= x) setmax(dp[i + 1][j + c], dp[i][j] + a);
        }
      }
      w[idx].push_back(make_pair(0, 0));
      for (int j = 0; j <= x; ++j) {
        auto a = dp[u[idx].size()][j];
        if (0 < a) w[idx].push_back(make_pair(a, j));
      }
      sort(w[idx].begin(), w[idx].end());
      for (int i = (int)(w[idx].size()) - 2; 0 <= i; --i) {
        setmin(w[idx][i].second, w[idx][i + 1].second);
      }
      sort(w[idx].begin(), w[idx].end());
    }

    auto fn = [&] (lli req) {
      lli sum = 0;
      for (int idx = 0; idx < 3; ++idx) {
        auto itr = lower_bound(w[idx].begin(), w[idx].end(), make_pair(req, 0LL));
        if (itr == w[idx].end()) return false;
        sum += itr->second;
      }
      return sum <= x;
    };

    lli small = 0;
    lli large = inf;
    while (small + 1 < large) {
      lli mid = (small + large) / 2;
      if (fn(mid)) small = mid;
      else large = mid;
    }
    if (fn(large)) cout << large << endl;
    else if (fn(small)) cout << small << endl;
    else cout << 0 << endl;
  }
  return 0;
}
