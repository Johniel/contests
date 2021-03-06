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

vector<int> a;
const int K = 1e5 + 5;
int memo[K];

int rec(int curr)
{
  int& ret = memo[curr];
  if (ret != -1) return ret;
  if (curr < a[0]) return 0;
  
  int mx = 0;
  each (i, a) {
    if (0 <= curr - i) {
      setmax(mx, rec(curr - i) ^ 1);
    }
  }
  
  return ret = mx;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  while (cin >> n >> k) {
    a.resize(n);
    fill(memo, memo + K, -1);
    cin >> a;
    cout << (rec(k) ? "First" : "Second") << endl;    
  }
  
  return 0;
}
