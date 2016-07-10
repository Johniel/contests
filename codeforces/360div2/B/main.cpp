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

int main(int argc, char *argv[])
{
  char buff[100000 + 10];
  while (scanf("%s", buff) == 1) {
    string s(buff);
    string t(buff);
    reverse(t.begin(), t.end());
    printf("%s%s\n", s.c_str(), t.c_str());
  }
  return 0;
}
