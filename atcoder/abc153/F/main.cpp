// atcoder/abc153/F/main.cpp
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

template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "("; each (i, s) os << i << ","; os << ")"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "("; each (i, m) os << i << ","; os << ")"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }
template<typename P, typename Q> inline pair<Q, P> swap(pair<P, Q> p) { return make_pair(p.second, p.first); }

constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  lli d, a;
  while (cin >> n >> d >> a) {
    vector<pair<lli, lli>> v(n);
    cin >> v;

    const int D = 0;
    const int E = 1;
    priority_queue<vector<lli>> q; // (position, type, paramater)
    each (i, v) {
      q.push(vector<lli>({-i.first, E, i.second}));
    }

    lli cnt = 0;
    lli sum = 0;
    while (q.size()) {
      vector<lli> u = q.top();
      q.pop();
      if (u[1] == E) {
        if (sum < u[2]) {
          lli req = u[2] - sum;
          lli x = (req / a) + bool(req % a);
          cnt += x;
          sum += a * x;
          q.push(vector<lli>({u[0] - d * 2, D, -(x * a)}));
        }
      }
      if (u[1] == D) {
        sum += u[2];
      }
    }
    cout << cnt << endl;
  }

  return 0;
}
