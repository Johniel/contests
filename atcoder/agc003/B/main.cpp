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

lli g(vector<lli> v)
{
  lli cnt = 0;
  for (int i = 0; i + 1 < v.size(); ++i) {
    cnt += v[i] / 2;
    v[i] %= 2;
    int j = i + 1;
    int mn = min(v[i], v[j]);
    v[i] -= mn;
    v[j] -= mn;
    cnt += mn;
  }
  each (i, v) cnt += i / 2;
  return cnt;
}

lli f(vector<lli> v)
{
  vector<lli> u = v;
  reverse(u.begin(), u.end());
  return max(g(v), g(u));
}

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    lli sum = 0;
    vector<lli> v;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      if (a == 0 && v.size()) {
        sum += f(v);
        v.clear();
      } else {
        v.push_back(a);
      }
    }
    if (v.size()) sum += f(v);
    cout << sum << endl;
  }
  return 0;
}
