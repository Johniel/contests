// atcoder/abc128/D/main.cpp
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

  int n, x;
  while (cin >> n >> x) {
    vector<int> v(n);
    cin >> v;

    lli mx = -(1LL << 60);
    for (int i = 0; i < v.size(); ++i) {
      for (int j = i; j <= v.size(); ++j) {
        lli sum = 0;
        priority_queue<int> q;
        for (int k = 0; k < v.size(); ++k) {
          if (i <= k && k < j) {
          } else {
            sum += v[k];
            q.push(-1 * v[k]);
          }
        }
        if (x < q.size()) {
          continue;
        }
        setmax(mx, sum);
        int y = x - q.size();
        while (y-- && q.size()) {
          sum -= -1 * q.top();
          q.pop();
          setmax(mx, sum);
        }
        setmax(mx, sum);
      }
    }

    cout << mx << endl;
  }

  return 0;
}
