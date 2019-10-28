// codeforces/579div3/B/main.cpp
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

  int q;
  while (cin >> q) {
    while (q--) {
      int n;
      cin >> n;
      vector<int> a(n * 4);
      cin >> a;
      sort(a.begin(), a.end());

      bool f = true;
      for (int i = 0; i < n * 2; i += 2) {
        int p = a[i];
        int q = a[i + 1];
        int s = a[a.size() - i - 1];
        int t = a[a.size() - i - 2];
        f = f && (p == q);
        f = f && (s == t);
        f = f && (p * s == a.front() * a.back());
        f = f && (q * t == a.front() * a.back());
      }
      cout << (f ? "YES" : "NO") << endl;
    }
  }

  return 0;
}
