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
    vector<lli> a(n * 3);
    cin >> a;

    const lli inf = 1LL << 60;
    vector<lli> v(n * 3, -inf);
    vector<lli> u(n * 3, inf);

    {
      priority_queue<lli, vector<lli>, greater<lli>> q;
      lli sum = 0;
      for (int i = 0; i < a.size(); ++i) {
        sum += a[i];
        q.push(a[i]);
        if (n < q.size()) {
          sum -= q.top();
          q.pop();
        }
        if (q.size() == n) {
          v[i] =  sum;
        }
      }
    }

    {
      priority_queue<lli, vector<lli>, less<lli>> q;
      lli sum = 0;
      for (int i = a.size() -1; 0 <= i; --i) {
        sum += a[i];
        q.push(a[i]);
        if (n < q.size()) {
          sum -= q.top();
          q.pop();
        }
        if (q.size() == n) {
          u[i] =  sum;
        }
      }
    }

    // cout << v << endl;
    // cout << u << endl;

    lli mx = -inf;
    for (int i = n - 1; i < 2 * n; ++i) {
      setmax(mx, v[i] - u[i + 1]);
    }
    cout << mx << endl;
  }

  return 0;
}
