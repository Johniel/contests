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

  map<lli, lli> m;
  for (lli i = 2; i < 1e4; ++i) {
    m[i * (i - 1) / 2] = i;
  }

  int n;
  while (cin >> n) {
    if (m.count(n) == 0) {
      cout << "No" << endl;
      continue;
    }

    const int N = m[n];
    vector<int> v[N];
    int cnt = 1;
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        v[i].push_back(cnt);
        v[j].push_back(cnt);
        ++cnt;
      }
    }

    cout << "Yes" << endl;
    cout << N << endl;
    for (int i = 0; i < N; ++i) {
      cout << v[i].size();
      each (j, v[i]) cout << ' ' << j;
      cout << endl;
    }
  }
  
  return 0;
}
