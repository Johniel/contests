// atcoder/tdpc/I/main.cpp
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

string s;
const int N = 300 + 5;
int memo[N][N];
int memo2[N][N];

int rec(int i, int j)
{
  const int inf = 1 << 27;
  int& ret = memo[i][j];
  if (ret != -1) return ret;

  if (i == j) return 0;

  int mx = -inf;
  for (int k = i + 1; k < j; ++k) {
    int a = rec(i, k);
    int b = rec(k, j);
    setmax(mx, a + b);
  }
  if (s[i] == 'i' && s[j - 1] == 'i') {
    for (int k = i + 1; k < j; ++k) {
      if (s[k] == 'w') {
        int a = rec(i + 1, k);
        int b = rec(k + 1, j - 1);
        setmax(mx, a + b + 1);
      }
    }
  }
  return ret = mx;
}

int rec2(int i, int j)
{
  int& ret = memo2[i][j];
  if (ret != -1) return ret;

  int mx = max(0, rec(i, j));
  for (int k = i + 1; k < j; ++k) {
    setmax(mx, rec2(i, k) + rec2(k, j));
  }
  return ret = mx;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> s) {
    fill(&memo[0][0], &memo[N - 1][N - 1] + 1, -1);
    fill(&memo2[0][0], &memo2[N - 1][N - 1] + 1, -1);
    cout << rec2(0, s.size()) << endl;
  }
  return 0;
}
