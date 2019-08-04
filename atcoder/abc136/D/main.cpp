// atcoder/abc136/D/main.cpp
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
    const int N = 1e5;
    int cnt[N];
    fill(cnt, cnt + N, 0);

    s += 'R';

    int j = 0;
    int r = 0;
    int l = 0;
    for (int i = 0; i + 1 < s.size(); ++i) {
      r += (s[i] == 'R');
      l += (s[i] == 'L');
      if (s[i] == 'R' && s[i + 1] == 'L') j = i;
      if (s[i] == 'L' && s[i + 1] == 'R') {
        cnt[j] = ((r + 1) / 2) + (l / 2);
        cnt[j+1] = (r / 2) + ((l + 1) / 2);
        r = l = 0;
      }
    }

    for (int i = 0; i + 1 < s.size(); ++i) {
      if (i) cout << ' ';
      cout << cnt[i];
    }
    cout << endl;
  }

  return 0;
}
