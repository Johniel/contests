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

  while (true) {
    const int N = 5;
    bool g[N][N];
    fill(&g[0][0], &g[N - 1][N - 1] + 1, false);
    for (int i = 0; i < 3; ++i) {
      int src, dst;
      if (cin >> src >> dst) {
        --src;
        --dst;
        g[src][dst] = g[dst][src] = true;
      } else {
        return 0;
      }
    }
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    sort(v.begin(), v.end());
    bool f = false;
    do {
      f = f || (g[v[0]][v[1]] && g[v[1]][v[2]] && g[v[2]][v[3]]);
    } while (next_permutation(v.begin(), v.end()));
    cout << (f ? "YES" : "NO") << endl;
  }
  
  return 0;
}
