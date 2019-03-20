// codeforces/547div3/G/main.cpp
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

  int n, k;
  while (cin >> n >> k) {
    vector<pair<int, int>> v(n - 1);
    cin >> v;
    each (i, v) {
      --i.first;
      --i.second;
    }

    map<pair<int, int>, int> m;
    each (i, v) {
      m[i] = m.size() + 1;
    }

    const int N = 200000 + 5;
    vector<int> g[N];
    each (i, v) {
      g[i.first].push_back(i.second);
      g[i.second].push_back(i.first);
    }

    map<int, vector<int>> deg;
    for (int i = 0; i < n; ++i) {
      deg[g[i].size()].push_back(i);
    }
    int color = n - 1;
    int sum = 0;
    for (int i = n; 0 < i; --i) {
      sum += deg[i].size();
      if (k < sum) break;
      color = i - 1;
    }

    map<pair<int, int>, int> c;
    function<void(int, int)> rec = [&] (int curr, int prev) {
      int cnt = c[{prev, curr}];
      each (next, g[curr]) {
        if (next == prev) continue;
        c[{curr, next}] = c[{next, curr}] = (++cnt %= color);
        rec(next, curr);
      }
      return ;
    };
    rec(0, -1);

    cout << color << endl;
    each (i, v) {
      cout << c[i] + 1 << ' ';
    }
    cout << endl;
  }

  return 0;
}
