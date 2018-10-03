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
    map<char, char> m1;
    map<char, char> m2;
    bool f = true;
    for (int i = 0; i < s.size(); ++i) {
      unless (m1.count(s[i])) {
        m1[s[i]] = t[i];
      }
      f = f && (m1[s[i]] == t[i]);
      unless (m2.count(t[i])) {
        m2[t[i]] = s[i];
      }
      f = f && (m2[t[i]] == s[i]);
    }
    cout << (f ? "Yes" : "No") << endl;
  }

  return 0;
}
