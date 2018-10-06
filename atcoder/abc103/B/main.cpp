#include <bits/stdc++.h>
 
#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
 
using namespace std;
 
typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;
 
template <typename P, typename Q>
ostream& operator<<(ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
 
template <typename T>
ostream& operator<<(ostream& os, vector<T> v)
{
  os << "(";
  each (i, v)
    os << i << ",";
  os << ")";
  return os;
}
 
int main(int argc, char* argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  string s, t;
  while (cin >> s >> t) {
    bool g = false;
    for (int i = 0; i < s.size(); ++i) {
      bool f = true;
      for (int j = 0; j < s.size(); ++j) {
        int k = (i + j) % s.size();
        f = f && (s[k] == t[j]);
      }
      g = g || f;
    }
    cout << (g ? "Yes" : "No") << endl;
  }
 
  return 0;
}
