use std::io::Read;

fn main() {
    let mut buff = String::new();
    std::io::stdin().read_to_string(&mut buff).unwrap();
    let mut itr = buff.split_whitespace();

    let n = itr.next().unwrap().parse::<usize>().unwrap();

    let mut x: Vec<f32> = Vec::new();
    x.resize(n, 0.0);
    let mut y: Vec<f32> = Vec::new();
    y.resize(n, 0.0);
    for i in 0..n {
        x[i] = itr.next().unwrap().parse::<f32>().unwrap();
        y[i] = itr.next().unwrap().parse::<f32>().unwrap();
    }

    let mut mx: f32 = -1.0;
    for i in 0..n {
        for j in (i + 1)..n {
            let a = x[i] - x[j];
            let b = y[i] - y[j];
            let d = (a * a + b * b).sqrt();
            mx = f32::max(mx, d)
        }
    }
    println!("{:.10}", mx)
}
