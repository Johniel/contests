use std::cmp::max;
use std::cmp::min;
use std::collections::HashMap;
use std::io::Read;

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_to_string(&mut buf).unwrap();

    let mut itr = buf.split_whitespace();

    let _ = itr.next();
    let s: String = itr.next().unwrap().parse().unwrap();

    let mut cnt = HashMap::new();
    for c in s.chars() {
        *cnt.entry(c).or_insert(0) += 1;
    }

    let mut mx = 0;
    let mut mn = 0;
    if cnt.keys().len() == 4 {
        mn = 1000;
    }
    for (_, num) in cnt {
        mx = max(mx, num);
        mn = min(mn, num);
    }
    println!("{} {}", mx, mn)
}
