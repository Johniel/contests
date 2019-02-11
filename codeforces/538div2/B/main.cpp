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

  int n, m, k;
  while (cin >> n >> m >> k) {
    vector<int> a(n);
    cin >> a;

    auto b = a;
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    map<int, int> cnt;
    lli sum = 0;
    for (int i = 0; i < m * k; ++i) {
      ++cnt[b[i]];
      sum += b[i];
    }

    vector<int> idx;
    int x = m;
    for (int i = 0; i < a.size(); ++i) {
      if (cnt[a[i]]) {
        --x;
        --cnt[a[i]];
      }
      if (!x) {
        idx.push_back(i + 1);
        x = m;
      }
    }
    idx.pop_back();
    cout << sum << endl;
    each (i, idx) cout << i << ' ' ;
    cout << endl;
  }
  
  return 0;
}
