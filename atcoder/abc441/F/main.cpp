// github.com/Johniel/contests
// atcoder/abc441/F/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename... Ts> ostream& operator << (ostream& os, const tuple<Ts...>& t) { os << "("; if constexpr (sizeof...(Ts) > 0) { apply([&](const Ts&... args) { ((os << args << ','), ...); }, t); } os << ")"; return os; }
template<typename... Ts> istream& operator >> (istream& is, tuple<Ts...>& t) { apply([&](Ts&... args) { ((is >> args), ...); }, t); return is; }
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

constexpr lli mod = 998244353; // 1e9 + 7;

int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    vec<pair<lli, lli>> v(n);
    cin >> v;

    const int N = 1000 + 3;
    const int M = 5 * 1e4 + 3;

    const lli inf = (1LL << 58);

    static lli dp1[N][M];
    fill(&dp1[0][0], &dp1[N - 1][M - 1] + 1, -inf);
    dp1[0][0] = 0;

    for (int i = 0; i < v.size(); ++i) {
      for (int j = 0; j + v[i].first <= m; ++j) {
        setmax(dp1[i + 1][j + v[i].first], dp1[i][j] + v[i].second);
      }
      for (int j = 0; j <= m; ++j) {
        setmax(dp1[i + 1][j], dp1[i][j]);
      }
    }

    lli mx = 0;
    for (int j = 0; j <= m; ++j) {
      setmax(mx, dp1[v.size()][j]);
    }

    static lli dp2[N][M];
    fill(&dp2[0][0], &dp2[N - 1][M - 1] + 1, -inf);
    dp2[v.size()][0] = 0;

    for (int i = v.size(); 0 < i; --i) {
      for (int j = 0; j + v[i - 1].first<= m; ++j) {
        setmax(dp2[i - 1][j + v[i - 1].first], dp2[i][j] + v[i - 1].second);
      }
      for (int j = 0; j <= m; ++j) {
        setmax(dp2[i - 1][j], dp2[i][j]);
      }
    }


    // cout << mx << endl;
    // for (int i = 0; i <= v.size(); ++i) {
    //   for (int j = 0; j <= m; ++j) {
    //     if (dp1[i][j] < 0) cout << "_ ";
    //     else cout << dp1[i][j] << ' ';
    //   }
    //   cout << endl;
    // }
    // cout << endl;
    // for (int i = 0; i <= v.size(); ++i) {
    //   for (int j = 0; j <= m; ++j) {
    //     if (dp2[i][j] < 0) cout << "_ ";
    //     else cout << dp2[i][j] << ' ';
    //   }
    //   cout << endl;
    // }
    // cout << endl;

    for (int i = 0; i <= v.size(); ++i) {
      for (int j = 0; j <= m; ++j) {
        setmax(dp2[i][j + 1], dp2[i][j]);
      }
    }

    // for (int i = 0; i <= v.size(); ++i) {
    //   for (int j = 0; j <= m; ++j) {
    //     if (dp2[i][j] < 0) cout << "_ ";
    //     else cout << dp2[i][j] << ' ';
    //   }
    //   cout << endl;
    // }
    // cout << endl;

    // {
    //   int i = v.size() - 1;
    //   bool A = false;
    //   bool B = false;
    //   for (int pref = 0; pref <= m; ++pref) {
    //     {
    //       int suff = m - (pref + v[i].first);

    //       if (0 <= suff && suff <= m) {
    //         cout << make_pair(i, pref) << make_pair(pref, suff) << dp1[i][pref] << "+" << dp2[i + 1][suff] << "=="<< mx << endl;
    //       }

    //       if (0 <= suff && suff <= m && dp1[i][pref] + dp2[i + 1][suff] + v[i].second == mx) A = true;
    //     }
    //     {
    //       int suff = m - pref;
    //       if (0 <= suff && suff <= m && dp1[i][pref] + dp2[i + 1][suff] == mx) B = true;
    //     }
    //   }
    // }

    str s;
    for (int i = 0; i < v.size(); ++i) {
      bool A = false;
      bool B = false;
      for (int pref = 0; pref <= m; ++pref) {
        {
          int suff = m - (pref + v[i].first);
          if (0 <= suff && suff <= m && dp1[i][pref] + dp2[i + 1][suff] + v[i].second == mx) A = true;
        }
        {
          int suff = m - pref;
          if (0 <= suff && suff <= m && dp1[i][pref] + dp2[i + 1][suff] == mx) B = true;
        }
      }
      if (0) ;
      else if ( A && !B) s += 'A';
      else if ( A &&  B) s += 'B';
      else if (!A && !B) s += 'C';
      else s += 'C';
    }

    cout << s << endl;
  }
  return 0;
}
