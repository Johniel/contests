// github.com/Johniel/contests
// atcoder/abc305/E/main.cpp

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
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

const int N = 2 * 1e5 + 3;
vec<pair<int, lli>> g[N];
vec<pair<int, int>> v;

lli dist[N];
lli potential[N];
void sssp(const int src)
{
  const lli inf = 1LL << 60;
  fill(potential, potential + N, 0);
  fill(dist, dist + N, inf);
  dist[src] = 0;
  priority_queue<pair<lli, int>, vector<pair<lli, int>>, greater<pair<lli, int>>> q;
  for (q.push({0, src}); q.size();) {
    const pair<lli, int> p = q.top();
    const int curr = p.second;
    q.pop();
    if (dist[curr] != p.first) continue;
    for (int i = 0; i < g[curr].size(); ++i) {
      const pair<int, lli> e = g[curr][i];
      const int next = e.first;
      // if (e.residue() <= 0) continue;
      const lli rcost = e.second + (potential[curr] - potential[next]);
      if (dist[next] > rcost + dist[curr]) {
        dist[next] = rcost + dist[curr];
        q.push({dist[next], next});
      }
    }
  }
  return ;
}

int main(int argc, char *argv[])
{
  int n, m, k;
  while (cin >> n >> m >> k) {
    fill(g, g + N, vec<pair<int, lli>>());
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(make_pair(b, 1));
      g[b].push_back(make_pair(a, 1));
    }
    v.resize(k);
    cin >> v;
    each (i, v) --i.first;

    ++n;
    const int src = n - 1;
    for (int i = 0; i < v.size(); ++i) {
      g[src].push_back(make_pair(v[i].first, -v[i].second));
    }
    sssp(src);
    // for (int i = 0; i < n-1; ++i) cout << dist[i] << ' '; cout << endl;
    vec<int> u;
    for (int i = 0; i < n-1; ++i) if (dist[i] <= 0) u.push_back(i);
    cout << u.size() << endl;
    each (i, u) cout << i + 1 << ' '; cout << endl;
  }
  return 0;
}
