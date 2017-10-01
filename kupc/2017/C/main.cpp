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

  map<char, int> conv;
  map<int, char> rev;
  for (char c = 'a'; c <= 'z'; ++c) {
    conv[c] = c - 'a' + 1;
    rev[conv[c]] = c;
  }

  int a;
  string s;
  while (cin >> a >> s) {
    vector<int> v, u;
    each (c, s) v.push_back(conv[c]);
    while (true) {
      bool f = true;
      for (int i = 0; i + 1 < v.size(); ++i) {
        if (v[i] + a <= conv['z'] && v[i + 1]) {
          --v[i + 1];
          v[i] += a;
          f = false;
        }
      }
      if (f) break;
    }
    while (v.size() && v.back() == 0) v.pop_back();
    each (i, v) cout << rev[i] ; cout << endl;
  }
  
  return 0;
}
