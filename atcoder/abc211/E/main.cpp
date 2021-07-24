// atcoder/abc211/E/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, k;
  while (cin >> n >> k) {
    const int N = 8;
    const int BIT = (1 << N) + 3;

    char g[N][N];
    int nth[N][N];
    fill(&g[0][0], &g[N - 1][N - 1] + 1, '#');
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        nth[i][j] = cnt++;
        cin >> g[i][j];
      }
    }

    queue<vec<pair<int, int>>> q;
    set<vec<pair<int, int>>> vis;
    {
      ull ini = 0;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (g[i][j] == '.') {
            vec<pair<int, int>> v;
            v.push_back(make_pair(i, j));
            q.push(v);
            vis.insert(v);
          }
        }
      }
    }

    char h[N][N];
    lli z = 0;
    for (; q.size(); q.pop()) {
      auto curr = q.front();
      copy(&g[0][0], &g[N - 1][N - 1] + 1, &h[0][0]);
      each (i, curr) {
        h[i.first][i.second] = '@';
      }
      if (curr.size() == k) {
        ++z;
        continue;
      }

      each (p, curr) {
        int i = p.first;
        int j = p.second;
        for (int d = 0; d < 4; ++d) {
          int ni = i + di[d];
          int nj = j + dj[d];
          unless (0 <= ni && ni < n) continue;
          unless (0 <= nj && nj < n) continue;
          unless (h[ni][nj] == '.') continue;
          vec<pair<int, int>> next = curr;
          next.push_back(make_pair(ni, nj));
          sort(next.begin(), next.end());
          if (vis.count(next)) continue;
          q.push(next);
          vis.insert(next);
        }
      }
    }
    cout << z << endl;
  }

  return 0;
}
