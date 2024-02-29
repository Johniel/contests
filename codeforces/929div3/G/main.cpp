// github.com/Johniel/contests
// codeforces/929div3/G/main.cpp

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
  if (0) {
    int h = 5;
    int w = 5;
    int cnt = 0;
    for (lli bit = 0; bit < (1LL << (h * w)); ++bit) {
      int g[h][w];
      lli b = bit;
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          g[i][j] = b % 2;
          b /= 2;
        }
      }
      bool f = true;
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          if (j + 2 < w && g[i][j] == g[i + 0][j + 1] && g[i][j] == g[i + 0][j + 2]) f = false;
          if (i + 2 < h && g[i][j] == g[i + 1][j + 0] && g[i][j] == g[i + 2][j + 0]) f = false;
          if (i + 2 < h && j + 2 < w && g[i][j] == g[i + 1][j + 1] && g[i][j] == g[i + 2][j + 2]) f = false;
          if (i + 2 < h && j + 2 < w && g[i + 1][j + 1] == g[i + 2][j + 0] && g[i + 1][j + 1] == g[i + 0][j + 2]) f = false;
        }
      }
      if (f) {
        ++cnt;
        for (int i = 0; i < h; ++i) {
          for (int j = 0; j < w; ++j) {
            cout << g[i][j];
          }
          cout << endl;
        }
        cout << endl;
      }
    }
    cout << cnt << endl;
  }

  { int _; cin >> _; }
  int n, m, q;
  while (cin >> n >> m >> q) {
    int i, j;
    str s;

    auto fn1 = [] (int i, int j, int k) {
      // 0011
      // 1100

      // ....
      // aaaa

      // bb..
      // bb..

      int a = (i % 2 == 1);
      int b = (j % 4 <= 1);

      if (a ^ b) {
        if (k == 0) return true;
      } else {
        if (k == 1) return true;
      }
      return false;
    };

    auto fn1a = [&] (int i, int j, int k) { return fn1(i + 1, j, k); };
    auto fn1b = [&] (int i, int j, int k) { return fn1(i, j + 1, k); };
    auto fn1c = [&] (int i, int j, int k) { return fn1(i + 1, j + 1, k); };

    auto fn2 = [&] (int i, int j, int k) { return fn1(j, i, k); };
    auto fn2a = [&] (int i, int j, int k) { return fn2(i + 1, j, k); };
    auto fn2b = [&] (int i, int j, int k) { return fn2(i, j + 1, k); };
    auto fn2c = [&] (int i, int j, int k) { return fn2(i + 1, j + 1, k); };

    vec<function<bool(int, int, int)>> v;
    v.push_back(fn1);
    v.push_back(fn1a);
    v.push_back(fn1b);
    v.push_back(fn1c);
    v.push_back(fn2);
    v.push_back(fn2a);
    v.push_back(fn2b);
    v.push_back(fn2c);

    vec<int> w(8, 1);
    cout << 8 << endl;
    while (q--) {
      cin >> i >> j >> s;
      --i;
      --j;
      int k = (s.front() == 'c');
      for (int s = 0; s < 8; ++s) {
        w[s] = (w[s] && (v[s](i, j, k)));
      }

      cout << accumulate(w.begin(), w.end(), 0) << endl;
    }
  }
  return 0;
}
