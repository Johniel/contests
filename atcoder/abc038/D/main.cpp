// atcoder/abc038/D/main.cpp
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

int LIS(const int num[], const int size)
{
  static const int INF = INT_MAX;
#define REP(i, n) for(int i=0; i<(int)n; i++)
  int t[size];
  int ind[size];
  int len = INT_MIN;
  fill(t, t + size, INF);
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
  int tmp = len;
  int result[len+1];
  REP(i, size)if(ind[size-1-i] == len)result[len--] = num[size-1-i];
  // REP(i, tmp+1)printf("%d\n", result[i]);
  return tmp+1;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<pair<int, int>> v(n);
    cin >> v;
    sort(v.begin(), v.end(), [] (auto a, auto b) {
      if (a.first != b.first) return a.first < b.first;
      return a.second > b.second;
    });

    const int N = 1e5 + 5;
    static int a[N];
    for (int i = 0; i < v.size(); ++i) {
      a[i] = v[i].second;
    }
    cout << LIS(a, (int)v.size()) << endl;
  }

  return 0;
}
