// codeforces/552div3/B/main.cpp
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
    vector<lli> a(n);
    cin >> a;
    sort(begin(a), end(a));
    if (a.front() == a.back()) {
      cout << 0 << endl;
      continue;
    }

    
    lli x = -1;
    vector<lli> v;
    for (int x = -300; x <= 300; ++x) {
      set<lli> vis;
      each (i, a) {
        if (i != x) {
          vis.insert(abs(x - i));
        }
      }
      if (vis.size() == 1) {
        v.push_back(*vis.begin());
      }
    }
    if (v.empty()) {
      cout << -1 << endl;
    } else {
      sort(begin(v), end(v));
      cout << v.front() << endl;
    }
  }
  
  return 0;
}
