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

const int N = 5000 + 10;
char types[N];

const lli mod = 1e9 + 7;

lli memo[N][N];
lli rec(int nth, int indent)
{
  if (!types[nth]) return 1;
  lli& ret = memo[nth][indent];
  if (ret != -1) return ret;
  lli sum = 0;

  if (types[nth] == 'f') {
    sum += rec(nth + 1, indent + 1);
    sum %= mod;
  }
  if (types[nth] == 's') {
    sum += rec(nth + 1, indent);
    sum %= mod;
  }
  if (indent && nth && types[nth - 1] == 's') {
    sum += rec(nth, indent - 1);
    sum %= mod;
  }

  return ret = sum;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    for (int i = 0; i < n; ++i) {
      cin >> types[i];
    }
    types[n] = '\0';
    fill(&memo[0][0], &memo[N - 1][N - 1] + 1, -1);
    cout << rec(0, 0) << endl;
  }

  return 0;
}
