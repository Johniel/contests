// codeforces/613div2/D/main.cpp
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

lli rec(vector<lli> v, int depth)
{
  if (v.empty()) return (1LL << 60);
  if (depth == -1) return 0;

  const lli bit = (1LL << depth);
  vector<lli> a, b;
  each (i, v) {
    if (i & bit) a.push_back(i ^ bit);
    else b.push_back(i);
  }

  lli x = rec(a, depth - 1);
  lli y = rec(b, depth - 1);
  if (a.empty() || b.empty()) {
    return min(x, y);
  }
  return min(x, y) | bit;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<lli> a(n);
    cin >> a;

    int mx = 0;
    for (int i = 0; i < 40; ++i) {
      each (j, a) {
        if (j & (1LL << i)) {
          mx = i;
        }
      }
    }
    cout << rec(a, mx) << endl;
  }

  return 0;
}
