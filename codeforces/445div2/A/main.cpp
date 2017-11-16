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

  while (true) {
    vector<int> v;
    for (int i = 0; i < 6; ++i) {
      int x;
      if (cin >> x) {
        v.push_back(x);
      }
    }

    if (v.size() != 6) break;

    bool f = false;
    sort(v.begin(), v.end());
    do {
      int a = 0;
      int b = 0;
      a += v[0];
      a += v[1];
      a += v[2]; 
      b += v[3];
      b += v[4];
      b += v[5];
      f = f || (a == b);
    } while (next_permutation(v.begin(), v.end()));
    cout << (f ? "YES" : "NO") << endl;

  }
  
  return 0;
}
