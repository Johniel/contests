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

bool is_753(lli x)
{
  set<lli> s;
  while (x) {
    s.insert(x % 10);
    x /= 10;
  }
  return s.size() == 3 && s.count(7) && s.count(5) && s.count(3);
}

set<lli> vis;
void rec(lli x, lli n)
{
  if (x <= n) {
    if (is_753(x)) vis.insert(x);
    rec(x * 10 + 7, n);
    rec(x * 10 + 5, n);
    rec(x * 10 + 3, n);
  }
  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n;
  while (cin >> n) {
    vis.clear();
    rec(7, n);
    rec(5, n);
    rec(3, n);
    cout << vis.size() << endl;
  }
  
  return 0;
}
