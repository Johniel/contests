# atcoder/abc111/A

## Codes
main.rs
{% raw %}
```rs
use std::io::Read;

fn main() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();

    s = s.replace("1", "@");
    s = s.replace("9", "1");
    s = s.replace("@", "9");

    println!("{}", s);
    ()
}
```
{% endraw %}
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/atcoder)
+ [repository](https://github.com/Johniel/contests/tree/master/atcoder/abc111/A)
