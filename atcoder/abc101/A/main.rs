use std::io::Read;

fn main() {
    let mut buff = String::new();
    std::io::stdin().read_to_string(&mut buff).unwrap();
    let mut iter = buff.split_whitespace();

    let s: String = iter.next().unwrap().parse().unwrap();

    let x: i32 = s.matches('+').count() as i32;
    let y: i32 = s.matches('-').count() as i32;

    println!("{}", x - y);

    ()
}
