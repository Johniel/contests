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

template<typename T>
ostream& operator << (ostream& os, vector<T> v)
{
  os << "(";
  each (i, v) os << i << ",";
  os << ")";
  return os;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a, b;
  while (cin >> a >> b) {
    swap(a, b);
    
    const int N = 100;
    int g[N][N];
    fill(&g[0][0], &g[N - 1][N - 1] + 1, '@');

    vector<pair<int, int>> v;
    vector<pair<int, int>> u;

    set<pair<int, int>> taboo;
    taboo.insert(make_pair(0, 0));
    taboo.insert(make_pair(N-1, N-1));
    taboo.insert(make_pair(0, N-1));
    taboo.insert(make_pair(N-1, 0));
    
    int di[] = {0, +1, 0, -1};
    int dj[] = {+1, 0, -1, 0};
    {
      int dir = 0;
      int len = N;
      int i = 0;
      int j = -1;
      while (len) {
        for (int k = 0; k < len; ++k) {
          i += di[dir];
          j += dj[dir];
          g[i][j] = '#';
          unless (taboo.count(make_pair(i, j))) v.push_back(make_pair(i, j));
        }
        dir = (dir + 1) % 4;
        --len;
      }
    }

    {
      int dir = 3;
      int len = N - 1;
      int i = N;
      int j = 0;
      while (len) {
        for (int k = 0; k < len; ++k) {
          i += di[dir];
          j += dj[dir];
          g[i][j] = '.';
          unless (taboo.count(make_pair(i, j))) u.push_back(make_pair(i, j));
        }
        dir = (dir + 1) % 4;
        --len;
      }
    }

    reverse(u.begin(), u.end());

    for (int i = 0; i < a - 1; ++i) {
      int j = 2 * i + 1;
      g[v[j].first][v[j].second] = '.';
    }
    for (int i = 0; i < b - 1; ++i) {
      int j = 2 * i + 1;
      g[u[j].first][u[j].second] = '#';
    }

    cout << N << ' ' << N << endl;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        cout << (char)g[i][j];
      }
      cout << endl;
    }
  }
  
  return 0;
}
