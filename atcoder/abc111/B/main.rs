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
