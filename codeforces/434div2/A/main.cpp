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
  
  lli n;
  int k;
  while (cin >> n >> k) {
    lli x = n;
    
    int cnt2 = 0;
    while (x && cnt2 < k && x % 2 == 0) {
      ++cnt2;
      x /= 2;
    }
    int cnt5 = 0;
    while (x && cnt5 < k && x % 5 == 0) {
      ++cnt5;
      x /= 5;
    }

    cout << x << string(k, '0') << endl;
  }
  
  return 0;
}
