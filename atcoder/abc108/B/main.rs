use std::io::Read;

fn main() {
    let mut buff = String::new();
    std::io::stdin().read_to_string(&mut buff).unwrap();
    let mut iter = buff.split_whitespace();

    let x1: i32 = iter.next().unwrap().parse().unwrap();
    let y1: i32 = iter.next().unwrap().parse().unwrap();
    let x2: i32 = iter.next().unwrap().parse().unwrap();
    let y2: i32 = iter.next().unwrap().parse().unwrap();

    let diff_y = y2 - y1;
    let diff_x = x2 - x1;

    println!(
        "{} {} {} {}",
        x2 - diff_y,
        y2 + diff_x,
        x1 - diff_y,
        y1 + diff_x
    );

    ()
}
