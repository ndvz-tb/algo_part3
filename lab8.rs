// Лабораторна робота №8 (Rust №2). Варіант 4
// Завдання: Масив має 45 дійсних елементів. Знайти суму квадратів
// тих його елементів, які знаходяться до найбільшого від'ємного елемента.

use std::time::{SystemTime, UNIX_EPOCH};

const SIZE: usize = 45;

// Заповнення масиву з 45 елементів випадковими дійсними числами в діапазоні [-15.0; 15.0]
fn fill_array(arr: &mut [f64; SIZE]) {
    let mut seed: u64 = SystemTime::now()
        .duration_since(UNIX_EPOCH)
        .map(|d| d.as_nanos() as u64)
        .unwrap_or(123456789);

    for i in 0..arr.len() {
        // Лінійний конгруентний генератор (без сторонніх бібліотек)
        seed = seed.wrapping_mul(6364136223846793005).wrapping_add(1442695040888963407);
        let raw = ((seed >> 32) % 301) as i64 - 150; // від -150 до +150
        arr[i] = (raw as f64) / 10.0;                // від -15.0 до +15.0
    }
}

// Виведення елементів масиву на екран (по 9 чисел у рядку)
fn print_array(arr: &[f64]) {
    for (i, item) in arr.iter().enumerate() {
        print!("{:6.1}", item);
        if (i + 1) % 9 == 0 {
            println!();
        }
    }
}

// Пошук найбільшого від'ємного елемента (від'ємне число, найближче до 0)
fn find_max_negative(arr: &[f64]) -> Option<(usize, f64)> {
    let mut max_neg_idx: Option<usize> = None;

    for i in 0..arr.len() {
        if arr[i] < 0.0 {
            match max_neg_idx {
                None => max_neg_idx = Some(i),
                Some(best_i) => {
                    if arr[i] > arr[best_i] {
                        max_neg_idx = Some(i);
                    }
                }
            }
        }
    }

    max_neg_idx.map(|idx| (idx, arr[idx]))
}

// Обчислення суми квадратів елементів, розташованих до індексу limit_idx (0..limit_idx)
fn sum_squares_before(arr: &[f64], limit_idx: usize) -> f64 {
    let mut sum: f64 = 0.0;
    for i in 0..limit_idx {
        sum += arr[i] * arr[i];
    }
    sum
}

fn main() {
    let mut arr: [f64; SIZE] = [0.0; SIZE];

    // Передавання масиву за змінним посиланням (&mut arr)
    fill_array(&mut arr);

    println!("Array of {} real elements:", SIZE);
    print_array(&arr);

    match find_max_negative(&arr) {
        Some((idx, val)) => {
            let sum_sq = sum_squares_before(&arr, idx);
            println!("\nMax negative element: arr[{}] = {:.1}", idx, val);
            println!("Elements count before it: {}", idx);
            println!("Sum of squares before max negative: {:.2}", sum_sq);
        }
        None => {
            println!("\nNo negative elements found in array.");
        }
    }
}
