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

vector<int> f(lli pos, const vector<lli>& v)
{
  const int i = lower_bound(v.begin(), v.end(), pos) - v.begin();
  vector<int> u;
  for (int j = max(0, i - 2); j <= min<int>(i + 2, v.size()) - 1; ++j) {
    u.push_back(j);
  }
  return u;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a, b, q;
  while (cin >> a >> b >> q) {
    vector<lli> s(a), t(b);
    cin >> s >> t;
    
    while (q--) {
      lli x;
      cin >> x;
      lli mn = 1LL << 62;

      for (int _ = 0; _ < 2; ++_) {
        vector<int> p = f(x, s);
        vector<int> q;
        each (i, p) {
          vector<int> r = f(s[i], t);
          q.insert(q.end(), r.begin(), r.end());
        }
        each (i, p) {
          each (j, q) {
            setmin(mn, abs(x - s[i]) + abs(s[i] - t[j]));
          }
        }
        swap(s, t);
      }
      cout << mn << endl;
    }
  }
  
  return 0;
}


