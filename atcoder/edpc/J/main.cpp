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

const int N = 300 + 5;
double memo[N][N][N];
int n;
double rec(int _1, int _2, int _3)
{
  if (max({_1, _2, _3}) == 0) return 0;
  double& ret = memo[_1][_2][_3];
  if (ret != -1) return ret;

  double m = _1 + _2 + _3;
  double sum = n / m;

  if (_1) {
    double p = double(_1) / m;
    sum += p * rec(_1 - 1, _2, _3);
  }

  if (_2) {
    double p = double(_2) / m;
    sum += p * rec(_1 + 1, _2 - 1, _3);
  }

  if (_3) {
    double p = double(_3) / m;
    sum += p * rec(_1, _2 + 1, _3 - 1);
  }

  return ret = sum;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> n) {
    vector<int> a(n);
    cin >> a;

    fill(&memo[0][0][0], &memo[N - 1][N - 1][N - 1] + 1, -1);
    int _1 = count(a.begin(), a.end(), 1);
    int _2 = count(a.begin(), a.end(), 2);
    int _3 = count(a.begin(), a.end(), 3);
    printf("%.10lf\n", rec(_1, _2, _3));
  }

  return 0;
}
