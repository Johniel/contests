// main.cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<pair<double, double>> v(n);
    cin >> v;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
      a.push_back(i);
    }
    vector<double> w;
    do {
      double sum = 0;
      for (int i = 0; i + 1 < n; ++i) {
        double x = v[a[i]].first - v[a[i + 1]].first;
        double y = v[a[i]].second - v[a[i + 1]].second;
        sum += sqrt(x * x + y * y);
      }
      w.push_back(sum);
    } while (next_permutation(a.begin(), a.end()));
    double sum = accumulate(w.begin(), w.end(), 0.0);
    printf("%.10lf\n", sum / w.size());
  }

  return 0;
}
