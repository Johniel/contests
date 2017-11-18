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
    vector<int> a(n);
    each (i, a) cin >> i;

    vector<int> b = a;
    sort(b.begin(), b.end());
    map<int, int> next;
    for (int i = 0; i < b.size(); ++i) {
      next[b[i]] = b[(i + 1) % b.size()];
    }

    each (i, a) cout << next[i] << ' '; cout << endl; 
  }
  
  return 0;
}

// (setq c-electric-flag nil)
