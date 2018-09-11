#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q>
ostream& operator << (ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

template<typename T>
ostream& operator << (ostream& os, vector<T> v)
{
  os << "(";
  each (i, v) os << i << ",";
  os << ")";
  return os;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<lli> a(n);
    each (i, a) cin >> i;
    vector<lli> b(n);
    each (i, b) cin >> i;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    lli A = 0;
    lli B = 0;

    for (int i = 0; i < n; ++i) {
      // A
      if (a.size() && b.size()) {
        if (a.back() > b.back()) {
          A += a.back();
          a.pop_back();
        } else {
          b.pop_back();
        }
      } else {
        if (a.size()) {
          A += a.back();
          a.pop_back();
        } else if (b.size()) {
          b.pop_back();
        }
      }

      // B
      if (a.size() && b.size()) {
        if (b.back() > a.back()) {
          B += b.back();
          b.pop_back();
        } else {
          a.pop_back();
        }
      } else {
        if (a.size()) {
          a.pop_back();
        } else if (b.size()) {
          B += b.back();
          b.pop_back();
        }
      }
    }

    cout << A - B << endl;
  }
  
  return 0;
}
