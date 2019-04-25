// codeforces/554div2/B/main.cpp
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

int fn(lli x)
{
  int j = -1;
  for (int i = 0; (1LL << i) <= x; ++i) {
    unless (x & (1LL << i)) j = i;
  }
  return j;
}

void test(lli x)
{
  string s;
  while (x) {
    s += '0' + (x % 2);
    x /= 2;
  }
  reverse(begin(s), end(s));
  cout << s << endl;
  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli x;
  while (cin >> x) {
    vector<lli> v;
    int y = 0;

    while (true) {
      // test(x);
      int a = fn(x);
      if (a == -1) break;
      ++a;
      x = x ^ ((1 << a) - 1);
      ++y;
      v.push_back(a);
      int b = fn(x);
      if (b == -1) break;
      ++x;
      ++y;
    }

    cout << y << endl;
    if (v.size()) {
      each (i, v) cout << i << ' ';
      cout << endl;
    }
  }

  return 0;
}
