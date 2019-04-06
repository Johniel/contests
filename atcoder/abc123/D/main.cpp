// atcoder/abc123/D/main.cpp
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

  int x, y, z;
  lli w;
  while (cin >> x >> y >> z >> w) {
    vector<lli> a(x);
    vector<lli> b(y);
    vector<lli> c(z);
    cin >> a >> b >> c;
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    sort(begin(c), end(c));
    reverse(begin(a), end(a));
    reverse(begin(b), end(b));
    reverse(begin(c), end(c));

    vector<lli> d;
    each (i, a) each (j, b) d.push_back(i + j);
    sort(begin(d), end(d));
    reverse(begin(d), end(d));

    priority_queue<lli, vector<lli>, greater<lli>> q;
    each (i, d) {
      each (j, c) {
        if (q.size() < w) q.push(i + j);
        else {
          if (i + j < q.top()) break;
          q.push(i + j);
        }
        if (w < q.size()) q.pop();
      }
    }

    vector<lli> v;
    while (q.size()) {
      v.push_back(q.top());
      q.pop();
    }
    sort(begin(v), end(v));
    reverse(begin(v), end(v));
    each (i, v) cout << i << endl;
  }

  return 0;
}
