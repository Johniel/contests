# atcoder/abc111/B

## Codes
main.rs
{% raw %}
```rs
use std::io::Read;

fn main() {
    let mut buff = String::new();
    std::io::stdin().read_to_string(&mut buff).unwrap();

    let mut iter = buff.split_whitespace();
    let n: i32 = iter.next().unwrap().parse().unwrap();

    for i in 1..10 {
        if n <= 111 * i {
            println!("{}", 111 * i);
            break;
        }
    }

    ()
}
```
{% endraw %}
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/atcoder)
+ [repository](https://github.com/Johniel/contests/tree/master/atcoder/abc111/B)
