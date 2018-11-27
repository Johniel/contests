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
    vector<int> a(n);
    cin >> a;

    map<int, int> cnt;
    each (i, a) ++cnt[i];


    priority_queue<pair<int, int>> q;
    each (i, cnt) {
      q.push(make_pair(i.second, i.first));
    }

    while (2 <= q.size() && 1 < q.top().first) {
      auto x = q.top();
      q.pop();
      auto y = q.top();
      q.pop();
      
      x.first -= 1;
      y.first -= 1;
      if (x.first) q.push(x);
      if (y.first) q.push(y);
    }

    cout << q.size() << endl;
  }
  
  return 0;
}
