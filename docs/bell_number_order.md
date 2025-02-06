``` c++
// https://atcoder.jp/contests/abc390/editorial/12045
vec<lli> a;
vec<lli> b;
unordered_set<lli> s;

void rec(int i, lli x)
{
  if (i == a.size()) {
    s.insert(x);
    return ;
  }
  for (int j = 0; j < b.size(); ++j) {
    x ^= b[j];
    b[j] += a[i];
    x ^= b[j];
    rec(i + 1, x);
    x ^= b[j];
    b[j] -= a[i];
    x ^= b[j];
  }
  b.push_back(a[i]);
  rec(i + 1, x ^ a[i]);
  b.pop_back();
  return ;
}

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    a.resize(n);
    cin >> a;
    b.clear();
    s.clear();
    rec(0, 0);
    cout << s.size() << endl;
  }
  return 0;
}
```
