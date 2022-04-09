// codeforces/e124/D/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    vec<pair<int, int>> v(n);
    cin >> v;

    map<pair<int, int>, int> no;
    map<int, pair<int, int>> rev;
    each (i, v) {
      int tmp = no.size();
      no[i] = tmp;
      rev[tmp] = i;
    }

    vec<pair<int, int>> u;
    each (i, v) {
      for (int d = 0; d < 4; ++d) {
        int ni = i.first + di[d];
        int nj = i.second + dj[d];
        auto p = make_pair(ni, nj);
        int tmp = no.size();
        if (!no.count(p)) {
          no[p] = tmp;
          rev[tmp] = p;
          u.push_back(p);
        }
      }
    }

    const int N = (2 * 1e5) * 5 + 3;
    static vec<int> g[N];
    fill(g, g + N, vec<int>());
    each (i, v) {
      for (int d = 0; d < 4; ++d) {
        int ni = i.first + di[d];
        int nj = i.second + dj[d];
        auto j = make_pair(ni, nj);
        assert(no.count(i));
        assert(no.count(j));
        int a = no[i];
        int b = no[j];
        g[a].push_back(b);
        g[b].push_back(a);
      }
    }


    const int src = no.size();
    each (i, u) {
      g[src].push_back(no[i]);
    }

    static int path[N];
    fill(path, path + N, -1);
    path[src] = src;

    queue<int> q;
    for (q.push(src); q.size(); q.pop()) {
      auto curr = q.front();
      each (next, g[curr]) {
        if (path[next] == -1) {
          path[next] = curr;
          q.push(next);
        }
      }
    }
    each (i, v) {
      int x = no[i];
      int y = -1;
      while (path[x] != x) {
        assert(x != -1);
        y = x;
        x = path[x];
      }
      cout << rev[y].first << ' ' << rev[y].second << endl;
    }
  }

  return 0;
}
