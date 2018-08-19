#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q>
ostream& operator << (ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

template<typename T>
ostream& operator << (ostream& os, vector<T> v)
{
  os << "(";
  each (i, v) os << i << ",";
  os << ")";
  return os;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  const int N = 1e5;
  bool prime[N];
  fill(prime, prime + N, true);
  prime[0] = prime[1] = false;
  for (int i = 2; i * i < N; ++i) {
    for (int j = 2; i * j < N; ++j) {
      prime[i * j] = false;
    }
  }
  vector<lli> p;
  for (int i = 0; i < N; ++i) {
    if (prime[i]) p.push_back(i);
  }

  auto fact = [&] (pair<lli, lli> x) {
      set<lli> s;
      s.insert(x.first);
      s.insert(x.second);
      each (i, p) {
        while (x.first % i == 0) {
          s.insert(i);
          s.insert(x.first / i);
          x.first /= i;
        }
        while (x.second % i == 0) {
          s.insert(i);
          s.insert(x.second / i);
          x.second /= i;
        }
      }
      s.insert(x.first);
      s.insert(x.second);
      s.erase(0LL);
      s.erase(1LL);
      return s;
  };

  int n;
  while (cin >> n) {
    vector<pair<lli, lli>> v(n);
    each (i, v) cin >> i.first >> i.second;
    set<lli> s = fact(v.front());
    each (i, v) {
      set<lli> t;
      each (j, s) {
        if(i.first  % j == 0) t.insert(j);
        if(i.second % j == 0) t.insert(j);
      }
      s = t;
    }
    if (s.empty()) s.insert(-1);
    cout << *s.begin() << endl;
  }

  return 0;
}
