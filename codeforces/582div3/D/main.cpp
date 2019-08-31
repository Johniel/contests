// codeforces/582div3/D/main.cpp
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

  int n, k;
  while (cin >> n >> k) {
    vector<int> a(n);
    cin >> a;

    map<int, priority_queue<int>> m;
    each (i, a) {
      int x = i;
      for (int j = 0; j < 31; ++j) {
        m[x].push(j);
        if (k < m[x].size()) m[x].pop();
        unless (x) break;
        x /= 2;
      }
    }

    lli mn = 1LL << 60;
    each (i, m) {
      if (i.second.size() < k) continue;
      lli sum = 0;
      while (i.second.size()) {
        sum += i.second.top();
        i.second.pop();
      }
      setmin(mn, sum);
    }
    cout << mn << endl;
  }

  return 0;
}
