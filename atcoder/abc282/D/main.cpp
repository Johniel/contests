// github.com/Johniel/contests
// atcoder/abc282/D/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;
template<typename T> using heap = priority_queue<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

const int N = 2 * 1e5 + 3;
vec<int> g[N];

int color[N];
void rec(int curr, int a, int b)
{
  color[curr] = a;
  each (next, g[curr]) {
    if (color[next] == a) throw "";
    if (color[next]) continue;
    rec(next, b, a);
  }
  return ;
}

int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    fill(g, g + N, vec<int>());
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    for (int i = 0; i < N; ++i) {
      sort(g[i].begin(), g[i].end());
    }
    fill(color, color + N, 0);
    int a = 1;
    int b = 2;
    bool f = true;
    for (int i = 0; i < n; ++i) {
      if (color[i] == 0) {
        try {
          rec(i, a, b);
        } catch (const char* e) {
          f = false;
        }
        a += 2;
        b += 2;
      }
    }
    if (!f) {
      cout << 0 << endl;
      continue;
    }

    lli x = n;
    map<int, lli> y;
    for (int i = 0; i < n; ++i) ++y[color[i]];
    // cout << y << endl;
    lli z = 0;
    for (int i = 0; i < n; ++i) {
      z += x - y[color[i]];
    }
    z -= m * 2;
    cout << z / 2 << endl;
  }

  return 0;
}
