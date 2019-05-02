// codeforces/e64/B/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

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

string fn(string s)
{
  map<char, int> m;
  each (c, s) ++m[c];

  string t;
  char a = m.begin()->first;
  char b = m.rbegin()->first;

  t += string(m[a], a);
  if (a != b) t += string(m[b], b);
  m[a] = m[b] = 0;

  for (char c = 'a'; c <= 'z'; ++c) {
    if (m[c] == 0) continue;
    if (abs(t.back() - c) == 1) {
      reverse(t.begin(), t.end());
    }
    t += string(m[c], c);
    m[c] = 0;
  }

  bool f = true;
  for (int i = 0; i + 1 < t.size(); ++i) {
    f = f && (abs(t[i] - t[i + 1]) != 1);
  }

  return f ? t : "No answer";
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int tc;
  while (cin >> tc) {
    while (tc--) {
      string s;
      cin >> s;
      cout << fn(s) << endl;
    }
  }

  return 0;
}
