use std::io::Read;

fn main() {
    let mut buff = String::new();
    std::io::stdin().read_to_string(&mut buff).unwrap();
    let mut iter = buff.split_whitespace();

    let n: i32 = iter.next().unwrap().parse().unwrap();

    if n % 2 == 0 {
        println!("{}", n);
    } else {
        println!("{}", n * 2);
    }

    ()
}
