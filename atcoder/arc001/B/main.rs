use std::cmp::min;
use std::io::Read;

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_to_string(&mut buf).unwrap();

    let mut itr = buf.split_whitespace();

    let a: i32 = itr.next().unwrap().parse().unwrap();
    let b: i32 = itr.next().unwrap().parse().unwrap();

    let mut mn = 1 << 29;
    for i in -40..40 {
        for j in -40..40 {
            for k in -40..40 {
                if i * 10 + j * 5 + k + a == b {
                    mn = min(mn, i.abs() + j.abs() + k.abs())
                }
            }
        }
    }
    println!("{}", mn)
}
