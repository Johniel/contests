#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

typedef long long int lli;

using namespace std;

lli f(lli n)
{
  if (n % 2) return n * 3 + 1;
  else return n / 2;
}

map<lli, lli> memo;
lli rec(lli n)
{

  if (memo.count(n)) return memo[n];
  memo[n] = 0;
  return memo[n] = rec(f(n)) + 1;
}

int main(int argc, char *argv[])
{
  const lli N = 1000000;
  memo[0] = 0;
  memo[1] = 1;
  lli n, m = 0;
  for (lli i = 0; i <= N; ++i) {
    if (m < rec(i)) {
      m = rec(i);
      n = i;
    }
  }
  cout << n << ' ' << m << endl;
  return 0;
}
