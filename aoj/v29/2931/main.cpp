// aoj/zprocon1/B/main.cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<int> v(n);
    cin >> v;
    each (i, v) --i;
    string s(2 * n, '_');
    int j = 0;
    int k = 0;
    each (i, v) {
      while (j <= i) {
        s[k++] = '(';
        ++j;
      }
      s[k++] = ')';
    }
    if (count(s.begin(), s.end(), '_')) {
      cout << ":(" << endl;
      continue;
    }

    vector<pair<int, int>> w;
    vector<int> u;
    j = 0;
    k = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        u.push_back(j++);
      } else {
        w.push_back(make_pair(u.back(), k));
        u.pop_back();
        ++k;
      }
    }

    bool f = true;
    each (i, w) {
      f = f && (v[i.second] == i.first);
    }
    cout << (f ? s : ":(") << endl;
  }
  
  return 0;
}
