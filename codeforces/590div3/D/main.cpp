// codeforces/590div3/D/main.cpp
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

  string s;
  while (cin >> s) {
    int q;
    cin >> q;

    map<char, set<int>> m;
    for (int i = 0; i < s.size(); ++i) {
      m[s[i]].insert(i);
    }

    for (int i = 0; i < q; ++i) {
      int op;
      cin >> op;
      if (op == 1) {
        int j;
        char d;
        cin >> j >> d;
        --j;
        assert(m[s[j]].count(j));
        m[s[j]].erase(j);
        m[d].insert(j);
        s[j] = d;
      }
      if (op == 2) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        int cnt = 0;
        for (char d = 'a'; d <= 'z'; ++d) {
          auto j = m[d].lower_bound(x);
          cnt += (j != m[d].end()) && (*j <= y);
        }
        cout << cnt << endl;
      }
    }
  }

  return 0;
}
