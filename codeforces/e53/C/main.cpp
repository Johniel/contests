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

template<typename T>
struct Acc {
  vector<T> sum;
  Acc(vector<T> v) {
    sum.push_back(0);
    each (i, v) {
      sum.push_back(sum.back() + i);
    }
  }
  T query(int begin, int end) {
    return sum[end] - sum[begin];
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  string s;
  lli x, y;
  while (cin >> n >> s >> x >> y) {
    map<char, int> cnt;
    each (c, s) ++cnt[c];

    vector<int> v;

    v.clear();
    each (c, s) v.push_back(c == 'U');
    Acc<int> U(v);

    v.clear();
    each (c, s) v.push_back(c == 'D');
    Acc<int> D(v);

    v.clear();
    each (c, s) v.push_back(c == 'R');
    Acc<int> R(v);

    v.clear();
    each (c, s) v.push_back(c == 'L');
    Acc<int> L(v);

    auto fn = [&] (int begin, int end) {
      lli x0 = 0;
      lli y0 = 0;

      x0 += cnt['R'] - R.query(begin, end);
      x0 -= cnt['L'] - L.query(begin, end);

      y0 += cnt['U'] - U.query(begin, end);
      y0 -= cnt['D'] - D.query(begin, end);

      lli diff = abs(x0 - x) + abs(y0 - y);
      int len = end - begin;

      return diff <= len && (diff - len) % 2 == 0;
    };

    const int inf = 1 << 29;
    int mn = 1 << 29;

    for (int i = 0; i < n; ++i) {
      int small = i;
      int large = n;
      while (small + 1 < large) {
        int mid = (small + large) / 2;
        if (fn(i, mid)) large = mid;
        else small = mid;
      }
      if (fn(i, large)) setmin(mn, large - i);
      if (fn(i, small)) setmin(mn, small - i);
    }
    
    cout << (mn == inf ? -1 : mn) << endl;
  }

  return 0;
}
