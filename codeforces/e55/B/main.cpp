#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { each (i, v) is >> i; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

int fn(string s)
{
  s = "S" + s + "S";
  
  vector<int> v;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'S') v.push_back(i);
  }

  int mx = 0;
  for (int i = 0; i + 2 < v.size(); ++i) {
    int j = i + 2;
    int x = (v[j] - 1) - (v[i] + 1) + 1;
    setmax(mx, x);
  }
  return mx;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  string s;
  while (cin >> n >> s) {
    if (count(s.begin(), s.end(), 'G') == s.size()) {
      cout << s.size() << endl;
      continue;
    }
    if (count(s.begin(), s.end(), 'S') == s.size()) {
      cout << 0 << endl;
      continue;
    }

    string t = s;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == 'G') {
        s[i] = 'S';
        break;
      }
    }
    for (int i = t.size() - 1; 0 <= i; --i) {
      if (t[i] == 'G') {
        t[i] = 'S';
        break;
      }
    }

    cout << max(fn(s), fn(t)) << endl;
  }

  return 0;
}
