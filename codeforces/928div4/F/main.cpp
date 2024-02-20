// github.com/Johniel/contests
// codeforces/928div4/F/main.cpp

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
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
   int _; cin >> _;
  while (_--) {
    const int n = 7;
    static char g[n][n];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> g[i][j];
      }
    }
    bool f = false;
    auto fn = [&] (int k) {
      for (int i = 1; i + 1 < n; ++i) {
        for (int j = 1; j + 1 < n; ++j) {
          if ((i + j) % 2 == k) {
            if (g[i + 0][j + 0] == 'B' &&
                g[i - 1][j - 1] == 'B' &&
                g[i + 1][j + 1] == 'B' &&
                g[i + 1][j - 1] == 'B' &&
                g[i - 1][j + 1] == 'B') return false;
          }
        }
      }
      return true;
    };

    vec<pair<int, int>> v[2];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (g[i][j] == 'B') v[(i + j) % 2].push_back(make_pair(i, j));
      }
    }

    int z[2];
    z[0] = z[1] = (1 << 29);

    for (int k = 0; k < 2; ++k) {
      if (fn(k)) z[k] = 0;
      for (int a = 0; a < v[k].size(); ++a) {
        g[v[k][a].first][v[k][a].second] = 'W';
        if (fn(k)) setmin(z[k], 1);
        for (int b = a+1; b < v[k].size() && 2 < z[k]; ++b) {
          g[v[k][b].first][v[k][b].second] = 'W';
          if (fn(k)) setmin(z[k], 2);
          for (int c = b+1; c < v[k].size() && 3 < z[k]; ++c) {
            g[v[k][c].first][v[k][c].second] = 'W';
            if (fn(k)) setmin(z[k], 3);
            for (int d = c+1; d < v[k].size() && 4 < z[k]; ++d) {
              g[v[k][d].first][v[k][d].second] = 'W';
              if (fn(k)) setmin(z[k], 4);
              for (int e = d+1; e < v[k].size() && 5 < z[k]; ++e) {
                g[v[k][e].first][v[k][e].second] = 'W';
                if (fn(k)) setmin(z[k], 5);
                for (int f = e+1; f < v[k].size() && 6 < z[k]; ++f) {
                  g[v[k][f].first][v[k][f].second] = 'W';
                  if (fn(k)) setmin(z[k], 6);
                  for (int p = f+1; p < v[k].size() && 7 < z[k]; ++p) {
                    g[v[k][p].first][v[k][p].second] = 'W';
                    if (fn(k)) setmin(z[k], 7);
                    g[v[k][p].first][v[k][p].second] = 'B';
                  }
                  g[v[k][f].first][v[k][f].second] = 'B';
                }
                g[v[k][e].first][v[k][e].second] = 'B';
              }
              g[v[k][d].first][v[k][d].second] = 'B';
            }
            g[v[k][c].first][v[k][c].second] = 'B';
          }
          g[v[k][b].first][v[k][b].second] = 'B';
        }
        g[v[k][a].first][v[k][a].second] = 'B';
      }
    }
    cout << z[0] + z[1] << endl;
  }

  return 0;
}
