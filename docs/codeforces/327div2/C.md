# codeforces/327div2/C

## Codes
```php
<?php
for ($a = 0; $a <= 1; ++$a) {
    for ($b = 0; $b <= 1; ++$b) {
        for ($c = 0; $c <= 1; ++$c) {
            echo 3 . "\n";
            echo $a . " " . $b . " " . $c . "\n";
        }
    }   
}```
```cpp
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

// int main(int argc, char *argv[])
void test(void)
{
  const int N = 10;
  int a[N];
  int b[N];
  
  srand(time(NULL));
  for (int i = 0; i < N; ++i) {
    a[i] = rand() % 2;
  }

  while (true) {
    for (int i = 0; i < N; ++i) {
      cout << a[i] << ' ';
    }
    cout << endl;
    b[0] = a[0];
    b[N - 1] = a[N - 1];
    for (int i = 1; i + 1 < N; ++i) {
      b[i] = ((a[i - 1] + a[i] + a[i + 1]) >= 2);
    }
    bool f = true;
    for (int i = 0; i < N; ++i) {
      f = f && (a[i] == b[i]);
    }
    if (f) break;
    copy(b, b + N, a);
  }
  return ;
}

void _00(int n, int a[])
{
  int b[n];
  copy(a, a + n, b);
  int mx = 0;
  for (int i = 0; i + 1 < n; ++i) {
    if (a[i] == 0 && a[i + 1] == 1 && a[i + 2] == 0) {
      int j = i;
      int len = 0;
      while (j < n && a[j] == 0 && a[j + 1] == 1 && a[j + 2] == 0) {
        ++len;
        j += 2;
      }
      mx = max(mx, len);
      i = j;
    }      
  }

  int x = 0;
  int y = 0;
  
  b[0] = a[0];
  for (int i = 1; i + 1 < n; ++i) {
    b[i] = (a[i - 1] && a[i]) || (a[i] && a[i + 1]);    
  }
  b[n - 1] = a[n - 1];
  
  if (b[0]) for (int i = 0; i < n; i += 2) {
    if (a[i] == 1 && a[i + 1] == 0) {
      b[i] = b[i + 1] = 1;
      ++x;
    } else break;
  }
  if (b[n - 1]) for (int i = n - 1; 0 < i; i -= 2) {
    if (a[i - 1] == 0 && a[i] == 1) {
      b[i - 1] = b[i] = 1;
      ++y;
    } else break;
  }

  mx = max({mx, x, y});
  
  printf("%d\n", mx);
  for (int i = 0; i < n; ++i) {
    if (i) printf(" ");
    printf("%d", b[i]);
  }
  puts("");
  return ;
}

pair<int, vector<int>> f(vector<int> v)
{
  // cout << ">> "; each (i, v)  cout << i << ' '; cout << endl;
  if (v.size() == 1) return make_pair(0, v);
  const int z = count(v.begin(), v.end(), 0);  
  const int o = count(v.begin(), v.end(), 1);
  
  if (v.front() == 0 && v.back() == 0) {
    replace(v.begin(), v.end(), 1, 0);
    return make_pair(o, v);
  }
  
  if (v.front() == 1 && v.back() == 1) {
    replace(v.begin(), v.end(), 0, 1);
    return make_pair(z, v);
  }
  
  if (v.front() == 0 && v.back() == 1) {
    vector<int> u;
    for (int i = 0; i < z; ++i) u.push_back(0);
    for (int i = 0; i < o; ++i) u.push_back(1);
    return make_pair(o - 1, u);
  }
  
  if (v.front() == 1 && v.back() == 0) {
    vector<int> u;
    for (int i = 0; i < o; ++i) u.push_back(1);
    for (int i = 0; i < z; ++i) u.push_back(0);
    return make_pair(o - 1, u);
  }
}

int main(int argc, char *argv[])
{
  int n;
  while (scanf("%d", &n) == 1) {
    vector<int> a, b, c;
    for (int i = 0; i < n; ++i) {
      int n;
      scanf("%d", &n);
      a.push_back(n);
    }

    int mx = 0;
    each (i, a) {      
      if (b.size() && b.back() == i) {
        pair<int, vector<int>> tmp = f(b);
        each (j, tmp.second) c.push_back(j);
        mx = max(mx, tmp.first);
        b.clear();        
      }
      b.push_back(i);
    }
    
    if (b.size()) {
      pair<int, vector<int>> tmp = f(b);
      each (j, tmp.second) c.push_back(j);
      mx = max(mx, tmp.first);      
    }
    printf("%d\n", mx);
    for (int i = 0; i < c.size(); ++i) {
      if (i) printf(" ");
      printf("%d", c[i]);
    }
    puts("");
  }
  return 0;
}
```
