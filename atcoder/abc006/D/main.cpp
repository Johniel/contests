// atcoder/abc006/D/main.cpp
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

constexpr int N = 3 * 1e4 + 5;
int num[N];

vector<int> LIS(const int size)
{
#define REP(i, n) for(int i=0; i<(int)n; i++)
  int t[size];
  int ind[size];
  int len = INT_MIN;
  fill(t, t + size, (1 << 29));
  REP(i, size){
    ind[i] = distance(t, lower_bound(t, t + size, num[i]));
    t[ ind[i] ] = num[i];
  }
  len = *max_element(ind, ind + size);
  /*
  REP(i, size)cout << num[i] << ' ';cout << endl;
  REP(i, size)cout << t[i] << ' '; cout << endl;
  REP(i, size)cout << ind[i] << ' ';cout << endl;
  cout << len << endl;
  */
  vector<int> v;
  int tmp = len;
  int result[len+1];
  REP(i, size)if(ind[size-1-i] == len)result[len--] = num[size-1-i];
  REP(i, tmp+1) {
    // printf("%d\n", result[i]);
    v.push_back(result[i]);
  }
  return v;
}


int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    for (int i = 0; i < n; ++i) {
      cin >> num[i];
    }
    cout << n - LIS(n).size() << endl;
  }

  return 0;
}
