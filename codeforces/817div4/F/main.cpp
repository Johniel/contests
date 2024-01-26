// github.com/Johniel/contests
// codeforces/817div4/F/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
#define unless(cond) if (!(cond))
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

int main(int argc, char *argv[])
{
  { int _; cin >> _; }
  int h, w;
  while (cin >> h >> w) {
    h += 2;
    w += 2;
    char g[h][w];
    fill(&g[0][0], &g[h - 1][w - 1] + 1, '.');
    for (int i = 1; i < h - 1; ++i) {
      for (int j = 1; j < w - 1; ++j) {
        cin >> g[i][j];
      }
    }
    const vec<vec<str>> L(
      {
        vec<str>({
            "...?",
            ".*..",
            ".**.",
            "....",
          }),
        vec<str>({
            "....",
            ".**.",
            "..*.",
            "?...",
          }),
        vec<str>({
            "?...",
            "..*.",
            ".**.",
            "....",
          }),
        vec<str>({
            "....",
            ".**.",
            ".*..",
            "...?",
          })});
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        for (int k = 0; k < L.size(); ++k) {
          bool f = true;
          int x = 0;
          for (int a = 0; a < L[k].size() && i + a < h; ++a) {
            for (int b = 0; b < L[k][a].size() && j + b < w; ++b) {
              f = f && (g[i + a][j + b] == L[k][a][b] || L[k][a][b] == '?');
              ++x;
            }
          }
          if (f && x == 16) {
            for (int a = 0; a < L[k].size(); ++a) {
              for (int b = 0; b < L[k][a].size(); ++b) {
                if (L[k][a][b] == '?') continue;
                g[i + a][j + b] = '.';
              }
            }
            break;
          }
        }
      }
    }
    cout << (count(&g[0][0], &g[h - 1][w - 1] + 1, '*') == 0 ? "YES" : "NO") << endl;
  }
  return 0;
}
