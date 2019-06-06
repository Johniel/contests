// codeforces/e66/B/main.cpp
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
    vector<pair<string, lli>> v(n, {"", -1});
    each (i, v) {
      cin >> i.first;
      if (i.first == "for") cin >> i.second;
    }

    const lli inf = 1LL << 32;
    lli sum = 0;
    stack<lli> s;
    s.push(1);
    each (i, v) {
      if (i.first == "add") {
        sum += s.top();
      }
      if (i.first == "for") {
        s.push(min(s.top() * i.second, inf));
      }
      if (i.first == "end") {
        s.pop();
      }
      if (inf <= sum) {
        sum = -1;
        break;
      }
    }
    if (sum == -1) cout << "OVERFLOW!!!" << endl;
    else cout << sum << endl;
  }

  return 0;
}
