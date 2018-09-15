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

const int N = 2 * 1e5 + 5;
const int M = 'z' + 5;
int g[N][M];

const int inf = 1 << 28;
int memo[N];
int path[N];
int rec(int curr)
{
  int& ret = memo[curr];
  if (ret != -1) return ret;

  int mn = inf;
  for (char c = 'a'; c <= 'z'; ++c) {
    if (!g[curr][c]) {
      path[curr] = -1 * int(c);
      return ret = 0;
    }
    int len = rec(g[curr][c]) + 1;
    if (len < mn) {
      mn = len;
      path[curr] = g[curr][c];
    }
  }
  return ret = mn;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  while (cin >> s) {
    s = "@" + s;

    fill(&g[0][0], &g[N - 1][M - 1] + 1, 0);
    for (int i = s.size() - 2; 0 <= i; --i) {
      for (char c = 'a'; c <= 'z'; ++c) {
        g[i][c] = g[i + 1][c];
      }
      g[i][s[i + 1]] = i + 1;
    }

    fill(memo, memo + N, -1);
    fill(path, path + N, -1);
    rec(0);
    string t;
    for (int i = 0; ; i = path[i]) {
      if (i < 0) {
        t += abs(i);
        break;
      }
      t += s[i];
    }
    cout << t.substr(1) << endl;
  }

  return 0;
}
