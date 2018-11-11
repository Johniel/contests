use std::cmp;
use std::io::Read;

fn main() {
    let mut buff = String::new();
    std::io::stdin().read_to_string(&mut buff).unwrap();
    let mut iter = buff.split_whitespace();

    let _n: i32 = iter.next().unwrap().parse().unwrap();
    let s: String = iter.next().unwrap().parse().unwrap();

    let mut mx: i32 = 0;
    for i in 1..s.len() {
        let t = &s[0..i];
        let u = &s[i..s.len()];
        let mut cnt: i32 = 0;
        for c in ('a' as u8)..('z' as u8 + 1) {
            if t.contains(c as char) && u.contains(c as char) {
                cnt = cnt + 1;
            }
            mx = cmp::max(mx, cnt);
        }
    }
    println!("{}", mx);

    ()
}
