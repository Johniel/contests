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

const int N = 100 + 5;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<int> a(n);
    cin >> a;

    int cnt[N];
    fill(cnt, cnt + N, 0);
    each (i, a) ++cnt[i];
    
    int sum = accumulate(a.begin(), a.end(), 0);
    int mn = 0;
    
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (cnt[i] && cnt[j]) {
          for (int k = 1; k <= max(i, j); ++k) {
            if (i % k == 0 && (i + j) > (i / k) + (j * k)) {
              setmin(mn, (i / k) + (j * k) - (i + j));
            }
          }
        }
      }
    }
    cout << sum + mn << endl;
  }

  return 0;
}
