// github.com/Johniel/contests
// atcoder/abc349/F/main.cpp

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

int main(int argc, char *argv[])
{
  vec<lli> p2(2 * 1e5 + 3);
  p2[0] = 1;
  for (int i = 1; i < p2.size(); ++i) {
    p2[i] = (p2[i - 1] * 2) % mod;
  }

  int n;
  lli m;
  while (cin >> n >> m) {
    vec<lli> a(n);
    cin >> a;

    if (m == 1) {
      int _1 = count(a.begin(), a.end(), 1);
      if (_1 == 0) cout << 0 << endl;
      else cout << p2[_1] - 1 << endl;
      continue;
    }

    vec<pair<lli, int>> v;
    {
      lli x = m;
      for (lli i = 2; i * i <= m; ++i) {
        if (x % i == 0) {
          int w = 0;
          while (x % i == 0) {
            x /= i;
            ++w;
          }
          v.push_back(make_pair(i, w));
        }
      }
      if (x != 1) v.push_back(make_pair(x, 1));
    }

    vec<int> mask;
    {
      each (j, a) {
        int bit = 0;
        lli x = j;
        for (int i = 0; i < v.size(); ++i) {
          if (x % v[i].first == 0) {
            int w = 0;
            while (x % v[i].first == 0) {
              x /= v[i].first;
              ++w;
            }
            if (v[i].second < w) { bit = -1; break; }
            if (v[i].second == w) bit += (1 << i);
          }
        }
        if (0 <= bit && x == 1) mask.push_back(bit);
      }
    }

    if (mask.empty()) {
      cout << 0 << endl;
      continue;
    }
    const int b = (1 << v.size());
    {
      int w = 0;
      each (i, mask) w |= i;
      unless (w == b - 1) {
        cout << 0 << endl;
        continue;
      }
    }

    map<int, int> freq;
    each (i, mask) ++freq[i];
    sort(mask.begin(), mask.end());
    mask.erase(unique(mask.begin(), mask.end()), mask.end());

    const int B = (1 << 18);
    static lli dp[2][B];
    for (int j = 0; j < B; ++j) {
      dp[0][j] = dp[1][j] = 0;
    }

    dp[0][0] = 1;
    for (int i = 0; i < mask.size(); ++i) {
      const int curr = (i + 0) % 2;
      const int next = (i + 1) % 2;
      for (int j = 0; j < b; ++j) dp[next][j] = 0;
      for (int j = 0; j < b; ++j) {
        (dp[next][j] += dp[curr][j]) %= mod;
        lli y = (p2[freq[mask[i]]] - 1 + mod) % mod;
        (dp[next][j | mask[i]] += dp[curr][j] * y % mod) %= mod;
      }
    }
    cout << dp[mask.size() % 2][b - 1] << endl;
  }
  return 0;
}
