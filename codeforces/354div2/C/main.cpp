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

int f(string s, char c, int k)
{
  if (k == 0) {
    int cnt = 1;
    int mx = 0;
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == s[i - 1]) ++cnt;
      else {
        mx = max(mx, cnt);
        cnt = 1;
      }
    }
    return max(cnt, mx);
  }
  
  map<char, map<int, int>> acc;
  for (int i = 0; i < s.size(); ++i) {
    acc['a'][i + 1] = acc['a'][i] + (s[i] == 'a');
    acc['b'][i + 1] = acc['b'][i] + (s[i] == 'b');
  }

  const int n = s.size();
  const char d = (c == 'a' ? 'b' : 'a');

  auto g = [&] (size_t i, size_t j) {
    return i < s.size() && j <= s.size() && acc[d][j] - acc[d][i] <= k;
  };

  int i = 0;
  int j = 0;
  int mx = 0;
  
  while (i <= j) {
    while (g(i, j + 1)) ++j;
    if (g(i, j)) mx = max(mx, j - i);
    ++i;
  }
  return mx;
}

int main(int argc, char *argv[])
{
  int n, k;
  string s;
  while (cin >> n >> k >> s) {
    cout << max(f(s, 'a', k), f(s, 'b', k)) << endl;
  }
  return 0;
}
