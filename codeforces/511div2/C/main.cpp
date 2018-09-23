#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template <typename P, typename Q>
ostream& operator<<(ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

template <typename T>
ostream& operator<<(ostream& os, vector<T> v)
{
  os << "(";
  each (i, v)
    os << i << ",";
  os << ")";
  return os;
}

lli gcd(lli a, lli b)
{
  unless(a > b) swap(a, b);
  return b ? gcd(b, a % b) : a;
}

int main(int argc, char* argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  const lli N = 15 * 1e6 + 1;
  static bool prime[N];
  fill(prime, prime + N, true);
  prime[0] = prime[1] = false;
  for (lli i = 2; i * i < N; ++i) {
    for (lli j = i * i; j < N; j += i) {
      prime[j] = false;
    }
  }

  vector<lli> p;
  for (int i = 0; i < N; ++i) {
    if (prime[i]) p.push_back(i);
  }

  int n;
  while (cin >> n) {
    vector<int> v(n);
    each (i, v)
      cin >> i;

    lli d = v[0];
    each (i, v) {
      d = gcd(d, i);
    }

    each (i, v) {
      i /= d;
    }

    static int cnt[N];
    fill(cnt, cnt + N, 0);
    each (i, v)
      ++cnt[i];
    if (cnt[1] == n) {
      cout << -1 << endl;
      continue;
    }

    int mx = 0;
    each (i, p) {
      int x = 0;
      for (int j = i; j < N; j += i) {
        x += cnt[j];
      }
      mx = max(mx, x);
    }

    cout << n - mx << endl;
  }
  return 0;
}
