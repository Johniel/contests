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

bool isleap(int y)
{
  if(y%4 == 0){
    if(y%100 == 0 && y%400 != 0)return false;
    return true;
  }
  return false;
}

int main(int argc, char *argv[])
{
  int n;
  char of[100];
  char type[100];
  const int D[12] = {31,
                     28 + isleap(2016),
                     31,
                     30, 
                     31, 
                     30, 
                     31, 
                     31, 
                     30, 
                     31, 
                     30, 
                     31};      
  int d[400];
  d[1] = 4;
  for (int i = 2; i < 400; ++i) {
    d[i] = (d[i - 1] + 1) % 7;
  }
  const int N = accumulate(D, D + 12, 0);
  while (scanf("%d%s%s", &n, of, type) == 3) {
    if (strcmp(type, "month") == 0) {
      int sum = 0;
      for (int i = 0; i < 12; ++i) {
        sum += (n <= D[i]);
      }
      printf("%d\n", sum);
    }
    if (strcmp(type, "week") == 0) {
      --n;
      int sum = 0;
      for (int i = 1; i <= N; ++i) {
        sum += (d[i] == n);
      }
      printf("%d\n", sum);
    }    
  }
  return 0;
}
