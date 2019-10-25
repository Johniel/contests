// atcoder/abc131/F/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { each (i, v) is >> i; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<pair<int, int>> v(n);
    cin >> v;


    const int N = 1e5 + 5;
    const int M = N * 2;
    static vector<int> g[M];
    fill(g, g + M, vector<int>());
    each (i, v) {
      int a = i.first;
      int b = i.second + N;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    set<int> vis;
    vector<int> u;
    function<void(int, int)> rec = [&] (int curr, int prev) {
      vis.insert(curr);
      u.push_back(curr);
      each (next, g[curr]) {
        if (next == prev || vis.count(next)) continue;
        rec(next, curr);
      }
      return ;
    };

    lli sum = 0;
    for (int i = 0; i < M; ++i) {
      if (vis.count(i) == 0) {
        u.clear();
        rec(i, -1);
        lli a = 0;
        lli b = 0;
        each (j, u) {
          if (j < N) {
            a += g[j].size();
          } else {
            ++b;
          }
        }
        sum += (u.size() - b) * b - a;
      }
    }
    cout << sum << endl;
  }

  return 0;
}
