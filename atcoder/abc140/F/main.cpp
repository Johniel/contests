// atcoder/abc140/F/main.cpp
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
    vector<int> a(1 << n);
    cin >> a;
    sort(a.begin(), a.end());

    bool f = true;
    vector<int> b;
    b.push_back(a.back());
    a.pop_back();
    while (f && a.size()) {
      const int n = b.size();
      for (int i = 0; i < n; ++i) {
        auto itr = lower_bound(a.begin(), a.end(), b[i]);
        if (itr == a.begin()) {
          f = false;
          break;
        }
        --itr;
        b.push_back(*itr);
        a.erase(itr);
      }
    }

    cout << (f ? "Yes" : "No") << endl;
  }

  return 0;
}
