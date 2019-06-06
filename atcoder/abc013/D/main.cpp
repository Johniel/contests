// atcoder/abc013/D/main.cpp
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

  int n, m, d;
  while (cin >> n >> m >> d) {
    vector<int> a(m);
    cin >> a;
    each (i, a) --i;

    vector<int> v;
    for (int i = 0; i < n; ++i) {
      v.push_back(i);
    }

    each (i, a) swap(v[i], v[i + 1]);

    const int LOG_D = 31;
    const int N = 2 * 1e5 + 5;
    static int p[LOG_D][N];
    fill(&p[0][0], &p[LOG_D - 1][N - 1] + 1, -1);
    for (int i = 0; i < n; ++i) {
      p[0][i] = v[i];
    }
    for (int i = 1; i < LOG_D; ++i) {
      for (int j = 0; j < n; ++j) {
        p[i][j] = p[i - 1][p[i - 1][j]];
      }
    }

    map<int, int> g;
    for (int i = 0; i < v.size(); ++i) {
      int j = i;
      for (int k = LOG_D - 1; 0 <= k; --k) {
        if (d & (1 << k)) {
          j = p[k][j];
        }
      }
      g[j] = i;
    }
    for (int i = 0; i < v.size(); ++i) {
      cout << g[i]+1 << endl;
    }
  }

  return 0;
}
