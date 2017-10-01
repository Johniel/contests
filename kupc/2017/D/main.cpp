#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q>
ostream& operator << (ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

int f(const int N)
{
  int cnt = 0;
  int g[N][N];
  for (int bit = 0; bit < (1 << (N * N)); ++bit) {
    int x = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        g[i][j] = (bool)(bit & (1 << x));
        ++x;
      }
    }
    int di[] = {-1, 0, 1, 1};
    int dj[] = {1, 1, 1, 0};
    bool f = true;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        for (int d = 0; d < 4; ++d) {
          int ai = i + di[d];
          int aj = j + dj[d];
          int bi = i - di[d];
          int bj = j - dj[d];
          set<int> vis;
          unless (0 <= ai && ai < N) continue;
          unless (0 <= aj && aj < N) continue;
          unless (0 <= bi && bi < N) continue;
          unless (0 <= bj && bj < N) continue;
          vis.insert(g[ai][aj]);
          vis.insert(g[bi][bj]);
          vis.insert(g[i][j]);
          f = f && (2 <= vis.size());
        }
      }
    }
    if (f) {
      cout << ++cnt << endl;
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          cout << (bool)g[i][j] << ' ';
        }
        cout << endl;
      }
      cout << endl;
    }
  }
  return cnt;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  // f(3); return 0;
  
  int n;
  while (cin >> n) {
    if (n == 1) cout << 1 << ' ' << 1 << endl;
    else if (n == 2) cout << 1 << ' ' << 1 << endl;
    else if (n == 3) cout << 2 << ' ' << 32 << endl;
    else if (n == 4) cout << 2 << ' ' << 18 << endl;
    else cout << 2 << ' ' << 8 << endl;
  }
  
  return 0;
}
