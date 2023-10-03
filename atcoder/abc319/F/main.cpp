// github.com/Johniel/contests
// atcoder/abc319/F/main.cpp

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

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    vec<int> parent(n);
    vec<int> type(n);
    vec<lli> strength(n);
    vec<lli> gain(n);
    type[0] = -1;
    strength[0] = gain[0] = 0;
    for (int i = 1; i < n; ++i) {
      cin >> parent[i] >> type[i] >> strength[i] >> gain[i];
      --parent[i];
    }
    const lli mxs = *max_element(strength.begin(), strength.end()) + 1LL;
    vec<int> g[n];
    for (int i = 1; i < n; ++i) {
      g[parent[i]].push_back(i);
    }
    const int ENEMY = 1;
    const int POTION = 2;
    vec<int> pidx;
    for (int i = 0; i < n; ++i) {
      if (type[i] == POTION) pidx.push_back(i);
    }
    const int P = 10 + 1;
    const int BIT = (1 << P);
    set<int> vis[BIT];
    vec<lli> atk(BIT, -(1LL << 60));
    if (int bit = 0; true) {
      atk[bit] = 1;
      priority_queue<pair<lli, int>> q;
      for (q.push(make_pair(0, 0)); q.size(); ) {
        auto [s, curr] = q.top();
        q.pop();
        s = abs(s);
        if (atk[bit] < s) break;
        setmin(atk[bit] += gain[curr], mxs);
        setmin(atk[bit], mxs);
        vis[bit].insert(curr);
        each (next, g[curr]) {
          if (type[next] == ENEMY) {
            q.push(make_pair(-strength[next], next));
          }
        }
      }
    }

    for (int bit = 0; bit < (1 << pidx.size()); ++bit) {
      for (int i = 0; i < pidx.size(); ++i) {
        if (bit & (1 << i)) continue;
        assert(!vis[bit].contains(pidx.at(i)));
        bool connected = vis[bit].contains(parent[pidx[i]]);
        unless (connected) continue;
        set<int> v = vis[bit];
        v.insert(pidx[i]);
        lli a = min(atk[bit] * gain[pidx[i]], mxs);
        priority_queue<pair<lli, int>> q;
        each (x, v) {
          each (y, g[x]) {
            if (!v.contains(y) && type[y] == ENEMY) {
              q.push(make_pair(-strength[y], y));
            }
          }
        }
        while (q.size()) {
          auto [s, curr] = q.top();
          q.pop();
          s = abs(s);
          if (a < s) break;
          setmin(a += gain[curr], mxs);
          v.insert(curr);
          each (next, g[curr]) {
            if (type[next] == ENEMY) {
              q.push(make_pair(-strength[next], next));
            }
          }
        }
        const int nb = (bit | (1 << i));
        if (atk[nb] < a) {
          atk[nb] = a;
          vis[nb] = v;
        }
      }
    }

    cout << (vis[(1 << pidx.size()) - 1].size() < n ? "No" : "Yes") << endl;


    // WAのまま維持されなかったものは１件のみ。
    // つまり、YesをNoにしているケースに注意すべき。
    // bool f = (vis[(1 << pidx.size()) - 1].size() < n); assert(f); cout << (f ? "No" : "Yes") << endl;
    // break;
  }
  return 0;
}
