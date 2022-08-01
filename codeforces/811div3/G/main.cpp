// codeforces/811div3/G/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

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
template<typename T> ostream& operator << (ostream& os, multiset<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

const int N = 2 * 1e5 + 3;
vec<vec<lli>> g[N];
int z[N];
multiset<pair<lli, int>> vis;
void rec(int curr, lli A, lli B, int depth) {
  vis.insert({B, depth});
  auto itr = vis.lower_bound({A, 1 << 27});
  if (itr != vis.begin()) {
    --itr;
    z[curr] = itr->second;
  }
  each (e, g[curr]) {
    int next = e[0];
    lli a = e[1];
    lli b = e[2];
    rec(next, A + a, B + b, depth+1);
  }
  vis.erase(vis.find({B, depth}));
  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int _;
  cin >> _;

  int n;
  while (cin >> n) {
    vis.clear();
    fill(z, z + n, 0);
    fill(g, g + n, vec<vec<lli>>());
    for (int i = 1; i < n; ++i) {
      int p, a, b;
      cin >> p >> a >> b;
      --p;
      g[p].push_back({i, a, b});
    }
    rec(0, 0, 0, 0);
    for (int i = 1; i < n; ++i) {
      cout << z[i] << ' ' ;
    }
    cout << endl;
  }

  return 0;
}
