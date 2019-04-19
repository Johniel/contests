// codeforces/552div3/G/main.cpp
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
    const lli N = 1e7 + 5;
    static int idx[N];
    fill(idx, idx + N, -1);
    pair<int, int> p = {0, 1};
    lli mn = (a[0] * a[1]) / __gcd(a[0], a[1]);
    for (int i = 0; i < a.size(); ++i) {
      if (idx[a[i]] != -1 && a[i] < mn) {
        p = {idx[a[i]], i};
        mn = a[i];
      }
      idx[a[i]] = i;
    }
    const lli mx = *max_element(begin(a), end(a));
    for (lli gcd = 1; gcd <= mx; ++gcd) {
      vector<lli> v;
      for (lli i = 1; i * gcd <= mx; ++i) {
        lli j = i * gcd;
        if (idx[j] != -1) {
          v.push_back(j);
          if (v.size() == 2) break;
        }
      }
      if (2 == v.size() && (v[0] * v[1] / gcd) < mn) {
        p = {idx[v[0]], idx[v[1]]};
        mn = (v[0] * v[1] / gcd);
      }
    }
    unless (p.first < p.second) swap(p.first, p.second);
    cout << p.first + 1 << ' ' << p.second + 1 << endl;
  }
  
  return 0;
}
