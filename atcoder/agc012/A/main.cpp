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

  int m;
  while (cin >> m) {
    int n = m * 3;
    int a[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a, a + n);
    deque<int> q;
    for (int i = 0; i < n; ++i) {
      q.push_back(a[i]);
    }
    lli sum = 0;
    while (q.size()) {
      q.pop_back();
      sum += q.back();
      q.pop_back();
      q.pop_front();
    }
    cout << sum << endl;
  }
  
  return 0;
}
