// atcoder/m-solutions2019/D/main.cpp
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
    vector<int> g[n];
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    vector<int> c(n);
    cin >> c;

    int deg[n];
    fill(deg, deg + n, 0);
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      v.push_back(i);
      deg[i] = g[i].size();
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (deg[i] == 1) q.push(i);
    }

    map<int, int> m;
    sort(c.begin(), c.end());
    reverse(c.begin(), c.end());
    lli sum = 0;
    for (int i = 1; i < n; ++i) {
      sum += c[i];
    }

    while (q.size()) {
      int curr = q.front();
      q.pop();
      m[curr] = c.back();
      c.pop_back();
      each (next, g[curr]) {
        --deg[next];
        if (deg[next] == 1) q.push(next);
      }
    }

    cout << sum << endl;
    for (int i = 0; i < n; ++i) {
      cout << m[i] << ' ' ;
    }
    cout << endl;
  }

  return 0;
}
