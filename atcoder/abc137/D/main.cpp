// atcoder/abc137/D/main.cpp
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

  int n, m;
  while (cin >> n >> m) {
    vector<pair<int, int>> v(n);
    cin >> v;

    map<int, vector<int>> b;
    each (i, v) {
      b[m - i.first].push_back(i.second);
    }

    lli sum = 0;
    priority_queue<lli> q;
    for (int day = m - 1; 0 <= day; --day) {
      if (b[day].size()) {
        each (i, b[day]) q.push(i);
      }
      if (q.size()) {
        sum += q.top();
        q.pop();
      }
    }
    cout << sum << endl;
  }

  return 0;
}
