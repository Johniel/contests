// atcoder/diverta2019/C/main.cpp
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
    vector<string> v(n);
    cin >> v;

    lli cnt = 0;
    each (s, v) {
      for (int i = 0; i + 1 < s.size(); ++i) {
        cnt += (s[i] == 'A' && s[i + 1] == 'B');
      }
      s = string("") + s.front() + s.back();
    }

    int BA = 0;
    int _A = 0;
    int B_ = 0;
    each (s, v) {
      if (s == "BA") ++BA;
      else {
        B_ += (s[0] == 'B');
        _A += (s[1] == 'A');
      }
    }

    int x = min(BA, B_);
    cnt += x;
    BA -= x;

    int y = min(_A, BA);
    cnt += y;
    BA -= y;

    cnt += min(_A, B_);
    if (x || y) {
      cnt += BA;
    } else {
      cnt += max(0, BA - 1);
    }

    cout << cnt << endl;
  }

  return 0;
}
