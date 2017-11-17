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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<lli> a(n);
    vector<lli> b(n);
    each (i, a) cin >> i;
    each (i, b) cin >> i;

    lli sum = accumulate(a.begin(), a.end(), 0LL);
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    cout << (b[0] + b[1] < sum ? "NO" : "YES") << endl;
  }
  
  return 0;
}
