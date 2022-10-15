// github.com/Johniel/contests
// atcoder/abc273/F/main.cpp

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

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{

  int n;
  lli x;
  while (cin >> n >> x) {
    vec<int> a(n);
    vec<int> b(n);
    cin >> a >> b;

    a.push_back(x);
    b.push_back(x);
    a.push_back(0);
    b.push_back(0);

    vec<pair<int, int>> wall;
    for (int i = 0; i < a.size(); ++i) {
      wall.push_back({a[i], i});
    }
    sort(wall.begin(), wall.end());

    vec<pair<int, int>> ham;
    for (int i = 0; i < b.size(); ++i) {
      ham.push_back({b[i], i});
    }
    sort(ham.begin(), ham.end());


    const int N = 2 * 1500 + 3;
    static lli cost[N][N][2];
    const lli inf = 1LL << 60;
    fill(&cost[0][0][0], &cost[N - 1][N - 1][2 - 1] + 1, inf);

    vec<int> v;
    map<pair<char, int>, int> m;
    for (int i = 0; i < ham.size(); ++i) {
      m[make_pair('H', ham[i].first)] = ham[i].second;
      v.push_back(ham[i].first);
    }
    for (int i = 0; i < wall.size(); ++i) {
      m[make_pair('W', wall[i].first)] = wall[i].second;
      v.push_back(wall[i].first);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    pair<int, int> src;
    int dst;
    for (int i = 0; i < v.size(); ++i) {
      if (v[i] == 0) src = make_pair(i, i);
      if (v[i] == x) dst = i;
    }

    // cout << ham << endl;
    // cout << wall << endl;
    // cout << v << endl;

    priority_queue<pair<lli, vec<int>>> q;
    const int R = 0;
    const int L = 1;
    q.push(make_pair(0, vec<int>({src.first, src.second, R})));
    q.push(make_pair(0, vec<int>({src.first, src.second, L})));
    cost[src.first][src.second][R] = cost[src.first][src.second][L] = 0;
    while (q.size()) {
      lli w = abs(q.top().first);
      vec<int> u = q.top().second;
      q.pop();
      int l = u[0];
      int r = u[1];
      int side = u[2];

      if (w != cost[l][r][side]) continue;

      const int curr = (side == R ? v[r] : v[l]);

      // cout << u << ' ' << cost[l][r][side] << ", " << curr << endl;

      // R
      {
        const int SIDE = R;
        auto itr = lower_bound(v.begin(), v.end(), v[r] + 1);
        if (itr != v.end() && r + 1 < v.size()) {
          lli nw = w + abs(*itr - curr);
          int nr = r + 1;
          if (nr < v.size()) {
            if (m.count(make_pair('H', *itr))) {
              if (cost[l][nr][SIDE] > nw) {
                cost[l][nr][SIDE] = nw;
                q.push(make_pair(-nw, vec<int>({l, nr, SIDE})));
              }
            }
            if (m.count(make_pair('W', *itr))) {
              int idx = m[make_pair('W', *itr)];
              if (cost[l][nr][SIDE] > nw && v[l] <= b[idx] && b[idx] <= v[r]) {
                cost[l][nr][SIDE] = nw;
                q.push(make_pair(-nw, vec<int>({l, nr, SIDE})));
              }
            }
          }
        }
      }
      // L
      {
        const int SIDE = L;
        auto itr = lower_bound(v.begin(), v.end(), v[l]);
        if (itr != v.begin() && l) {
          --itr;
          lli nw = w + abs(*itr - curr);
          int nl = l - 1;
          if (nl == 2 && r == 5) {
            // cout << w << "+" << *itr << "-" << curr << endl;
          }
          if (m.count(make_pair('H', *itr))) {
            if (cost[nl][r][SIDE] > nw) {
              cost[nl][r][SIDE] = nw;
              q.push(make_pair(-nw, vec<int>({nl, r, SIDE})));
            }
          }
          if (m.count(make_pair('W', *itr))) {
            int idx = m[make_pair('W', *itr)];
            if (cost[nl][r][SIDE] > nw && v[l] <= b[idx] && b[idx] <= v[r]) {
              cost[nl][r][SIDE] = nw;
              q.push(make_pair(-nw, vec<int>({nl, r, SIDE})));
            }
          }
        }
      }
    }

    lli mn = +inf;
    for (int i = 0; i < v.size(); ++i) {
      setmin(mn, cost[i][dst][R]);
      setmin(mn, cost[dst][i][L]);
    }
    cout << (mn == inf ? -1 : mn) << endl;
    // break;
  }

  return 0;
}
