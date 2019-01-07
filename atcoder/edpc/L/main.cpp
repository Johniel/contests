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

const int N = 3000 + 5;
vector<lli> a;

lli memo[N][N];
lli rec(int begin, int end, int turn)
{
  unless (begin <= end) return 0;
  lli& ret = memo[begin][end];
  if (ret != -1) return ret;

  const lli inf = 1LL << 60;
  lli best;
  if (turn) {
    best = -inf;
    setmax(best, rec(begin, end - 1, turn ^ 1) + a[end]);
    setmax(best, rec(begin + 1, end, turn ^ 1) + a[begin]);
  } else {
    best = inf;
    setmin(best, rec(begin, end - 1, turn ^ 1) - a[end]);
    setmin(best, rec(begin + 1, end, turn ^ 1) - a[begin]);
  }
  
  return ret = best;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    a.resize(n);
    cin >> a;
    fill(&memo[0][0], &memo[N - 1][N - 1] + 1, -1);
    cout << rec(0, n - 1, 1) << endl;
  }
  
  return 0;
}
