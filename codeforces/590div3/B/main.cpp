// codeforces/590div3/B/main.cpp
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
    queue<int> q;
    set<int> vis;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      unless (vis.count(a)) {
        q.push(a);
        vis.insert(a);
        if (k < q.size()) {
          int b = q.front();
          q.pop();
          vis.erase(b);
        }
      }
    }
    cout << q.size() << endl;
    vector<int> v;
    while (q.size()) {
      v.push_back(q.front());
      q.pop();
    }
    reverse(v.begin(), v.end());
    each (i, v) cout << i << ' ';
    cout << endl;
  }

  return 0;
}
