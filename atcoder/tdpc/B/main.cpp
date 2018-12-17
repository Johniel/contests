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

vector<int> a;
vector<int> b;

const int N = 1000 + 5;
pair<int, int> memo[N][N];

pair<int, int> rec(int i, int j)
{
  pair<int, int>& ret = memo[i][j];
  if (ret.first != -1) return ret;

  pair<int, int> best = make_pair(0, 0);

  if (i < a.size()) {
    pair<int, int> p = rec(i + 1, j);
    auto q = make_pair(p.second + a[i], p.first);
    setmax(best, q);
  }

  if (j < b.size()) {
    auto p = rec(i, j + 1);
    auto q = make_pair(p.second + b[j], p.first);
    setmax(best, q);
  }

  return ret = best;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    a.resize(n);
    b.resize(m);
    cin >> a >> b;
    fill(&memo[0][0], &memo[N - 1][N - 1] + 1, make_pair(-1, -1));
    auto p = rec(0, 0);
    cout << p.first << endl;
  }

  return 0;
}
