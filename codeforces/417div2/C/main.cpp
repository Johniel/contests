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

lli f(vector<lli> a, lli k, lli S)
{
  if (a.size() < k) return 0;
  vector<lli> b;
  for (int i = 0; i < a.size(); ++i) {
    b.push_back(a[i] + (i + 1) * k);
  }

  sort(b.begin(), b.end());
  lli sum = accumulate(b.begin(), b.begin() + k, 0LL);
  
  if (S < sum) return 0;
  return sum;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n, S;
  while (cin >> n >> S) {
    vector<lli> a(n);
    each (i, a) cin >> i;

    lli small = 0;
    lli large = 1 << 28;
    while (small + 1 < large) {
      lli mid = (small + large) / 2;
      if (f(a, mid, S)) small = mid;
      else large = mid;
    }

    if (0) {
    } else if (f(a, large, S)) {
      cout << large << ' ' << f(a, large, S) << endl;
    } else if (f(a, small, S)) {
      cout << small << ' ' << f(a, small, S) << endl;
    } else {
      cout << 0 << ' ' << 0 << endl;
    }
    
  }
  
  return 0;
}
