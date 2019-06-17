// atcoder/abc130/E/main2.cpp
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

const int N = 2000 + 5;
const lli mod = 1e9 + 7;

vector<int> s;
vector<int> t;

lli memo[N][N];
lli rec(int i, int j)
{
  if (i == s.size()) return 0;
  if (j == t.size()) return 0;

  lli& ret = memo[i][j];
  if (ret != -1) return ret;

  lli sum = 0;

  sum += rec(i + 1, j);
  sum += rec(i, j + 1);
  sum -= rec(i + 1, j + 1);
  sum += mod;
  sum %= mod;

  if (s[i] == t[j]) {
    sum += rec(i + 1, j + 1) + 1;
    sum %= mod;
  }

  return ret = sum;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    s.resize(n);
    t.resize(m);
    cin >> s >> t;

    fill(&memo[0][0], &memo[N - 1][N - 1] + 1, -1);
    cout << rec(0, 0) + 1 << endl;
  }

  return 0;
}
