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

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a, b;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      if (i % 2 == 0) a.push_back(x);
      else b.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> v;
    for (int i = 0; i < n; ++i) {
      if (i < a.size()) v.push_back(a[i]);
      if (i < b.size()) v.push_back(b[i]);
    }

    int idx = -1;
    vector<int> u = v;
    sort(u.begin(), u.end());
    for (int i = 0; i < n; ++i) {
      if (v[i] != u[i]) {
        idx = i;
        break;
      }
    }
    
    static int cnt = 0;
    cout << "Case #" << ++cnt << ": " << flush;
    if (idx == -1) cout << "OK" << endl;
    else cout << idx << endl;
  }
  
  return 0;
}
