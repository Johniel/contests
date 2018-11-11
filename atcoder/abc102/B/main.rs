use std::io::Read;

fn main() {
    let mut buff = String::new();
    std::io::stdin().read_to_string(&mut buff).unwrap();
    let mut iter = buff.split_whitespace();

    let n: usize = iter.next().unwrap().parse().unwrap();
    let mut a = Vec::new();

    for _i in 0..n {
        let x: i32 = iter.next().unwrap().parse().unwrap();
        a.push(x);
    }

    a.sort();
    println!("{}", a.last().unwrap() - a.first().unwrap());

    ()
}
