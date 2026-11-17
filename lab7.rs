// Лабораторна робота №7 (Rust №1). Варіант 17 (за методичкою C++_Lab, стор. 27–34)
// Функція: y(x) = (e^x + e^(-x)) / 2,  0 <= x <= 1,  n = 5
// Розклад у ряд: S = 1 + x^2 / 2! + ... + x^(2n) / (2n)!

// Обчислення k-го члена ряду: a_k = x^(2k) / (2k)!
fn term(x: f64, k: usize) -> f64 {
    if k == 0 {
        return 1.0;
    }

    let mut fact = 1.0;
    for i in 1..=(2 * k) {
        fact *= i as f64;
    }
    x.powi((2 * k) as i32) / fact
}

// Обчислення суми ряду Sn для фіксованої кількості доданків n
fn sum_n(x: f64, n: usize) -> f64 {
    let mut sum = 0.0;
    for k in 0..=n {
        sum += term(x, k);
    }
    sum
}

// Ітераційне обчислення суми ряду Se із заданою точністю eps
fn sum_eps(x: f64, eps: f64) -> f64 {
    let mut sum: f64 = 0.0;
    let mut ak: f64 = 1.0;
    let mut k: usize = 0;

    while ak.abs() > eps {
        ak = term(x, k);
        sum += ak;
        k += 1;
    }
    sum
}

// Точне значення функції y(x) = (e^x + e^(-x)) / 2
fn exact_y(x: f64) -> f64 {
    (x.exp() + (-x).exp()) / 2.0
}

fn main() {
    let a: f64 = 0.0;          // Ліва межа інтервалу
    let b: f64 = 1.0;          // Права межа інтервалу
    let points: usize = 10;    // Кількість точок табулювання
    let n: usize = 5;          // Кількість членів ряду (Варіант 17)
    let eps: f64 = 0.0001;     // Задана точність обчислень

    // Крок табулювання: h = (b - a) / (points - 1) з явним приведенням типів (as f64)
    let h: f64 = (b - a) / ((points - 1) as f64);

    println!(" i     x          Sn           Se          y(x)");
    for i in 1..=points {
        let x: f64 = a + ((i - 1) as f64) * h;
        let sn = sum_n(x, n);
        let se = sum_eps(x, eps);
        let y = exact_y(x);

        println!("{:2}  {:.4}   {:.7}   {:.7}   {:.7}", i, x, sn, se, y);
    }
}
