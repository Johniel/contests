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
    vector<pair<int, lli>> v(n);
    cin >> v;
    each (i, v) --i.first;

    priority_queue<lli> q[m];
    each (i, v) {
      q[i.first].push(i.second);
    }

    map<int, lli> total;
    each (i, v) total[i.first] += i.second;

    vector<int> curr;
    for (int i = 0; i < m; ++i) {
      if (!q[i].empty()) curr.push_back(i);
    }

    lli mx = 0;
    map<int, lli> sum;
    while (curr.size()) {
      each (i, curr) {
        sum[i] += q[i].top();
        q[i].pop();
      }

      lli x = 0;
      each (i, curr) {
        x += max(0LL, sum[i]);
      }
      setmax(mx, x);

      vector<int> next;
      each (i, curr) {
        unless (q[i].empty()) next.push_back(i);
      }
      curr = next;
    }
    cout << mx << endl;
  }

  return 0;
}
