// github.com/Johniel/contests
// atcoder/arc165/C/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
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
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

const int N = 2 * 1e5 + 3;
vec<pair<int, lli>> g[N];

int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    fill(g, g + n, vec<pair<int, lli>>());
    for (int i = 0; i < m; ++i) {
      int a, b;
      lli w;
      cin >> a >> b >> w;
      --a;
      --b;
      g[a].push_back(make_pair(b, w));
      g[b].push_back(make_pair(a, w));
    }

    auto fn = [&] (const lli x) {
      map<int, int> color;
      for (int src = 0; src < n; ++src) {
        if (color.count(src)) continue;
        queue<int> q;
        color[src] = 0;
        for (q.push(src); q.size(); q.pop()) {
          int curr = q.front();
          each (e, g[curr]) {
            auto [next, w] = e;
            if (x <= w) continue;
            // 同じ色で塗られた相異なる 2 頂点を結ぶどの単純パスについても、単純パスの重みは X 以上である。
            if (!color.count(next)) {
              color[next] = color[curr] ^ 1;
              q.push(next);
            }
            if (color[next] == color[curr]) return false;
          }
        }
      }

      for (int i = 0; i < n; ++i) {
        vec<lli> v;
        each (e, g[i]) {
          auto [_, w] = e;
          if (x <= w) continue;
          v.push_back(w);
        }
        if (2 <= v.size()){
          sort(v.begin(), v.end());
          if (v[v.size() - 1] + v[v.size() - 2] < x) return false;
        }
      }

      return true;
    };

    lli small = 0;
    lli large = 1LL << 40;
    while (small + 1 < large) {
      lli mid = (small + large) / 2;
      if (fn(mid)) small = mid;
      else large = mid;
    }
    if (0) ;
    else if (fn(large)) cout << large << endl;
    else if (fn(small)) cout << small << endl;
    else assert(0);
  }
  return 0;
}
