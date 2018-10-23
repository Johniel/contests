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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli _a, _b;
  while (cin >> _a >> _b) {

    vector<int> v, u;
    auto fn = [&] (lli x) {
                lli a = _a;
                lli b = _b;
                v.clear();
                u.clear();
                while (0 <= a && 0 <= b && 0 < x) {
                  if (x <= a) {
                    a -= x;
                    v.push_back(x);
                  } else {
                    b -= x;
                    u.push_back(x);
                  }
                  --x;
                }

                return x == 0 && 0 <= a && 0 <= b;
              };

    lli small = 0;
    lli large = 1e9 * 2 + 10;
    while (small + 1 < large) {
      int mid = (small + large) / 2;
      if (fn(mid)) small = mid;
      else large = mid;
    }

    if (!fn(large)) fn(small);

    sort(v.begin(), v.end());
    cout << v.size() << endl;
    each (i, v) cout << i << ' '; cout << endl;

    sort(u.begin(), u.end());
    cout << u.size() << endl;
    each (i, u) cout << i << ' '; cout << endl;
  }

  return 0;
}
