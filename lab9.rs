// Лабораторна робота №9 (Rust №3). Варіант 17
// Обчислення виразу: (3*P*C - 4*B) * (1.5*y + 2*u)
// Усі операції виконано вручну вкладеними циклами без зовнішніх бібліотек.

// Множення двох матриць A * B
fn multiply_matrices(a: &Vec<Vec<f64>>, b: &Vec<Vec<f64>>) -> Vec<Vec<f64>> {
    let rows_a = a.len();
    let cols_a = a[0].len();
    let rows_b = b.len();
    let cols_b = b[0].len();

    if cols_a != rows_b {
        panic!("Cannot multiply matrices: columns of A must equal rows of B");
    }

    let mut result = vec![vec![0.0; cols_b]; rows_a];
    for i in 0..rows_a {
        for j in 0..cols_b {
            for k in 0..cols_a {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    result
}

// Лінійна комбінація матриць: alpha * A + beta * B
fn linear_comb_matrices(
    alpha: f64,
    a: &Vec<Vec<f64>>,
    beta: f64,
    b: &Vec<Vec<f64>>,
) -> Vec<Vec<f64>> {
    let rows = a.len();
    let cols = a[0].len();

    if rows != b.len() || cols != b[0].len() {
        panic!("Matrix dimensions must match");
    }

    let mut result = vec![vec![0.0; cols]; rows];
    for i in 0..rows {
        for j in 0..cols {
            result[i][j] = alpha * a[i][j] + beta * b[i][j];
        }
    }
    result
}

// Лінійна комбінація векторів: alpha * v1 + beta * v2
fn linear_comb_vectors(
    alpha: f64,
    v1: &Vec<f64>,
    beta: f64,
    v2: &Vec<f64>,
) -> Vec<f64> {
    let n = v1.len();
    if n != v2.len() {
        panic!("Vector dimensions must match");
    }

    let mut result = vec![0.0; n];
    for i in 0..n {
        result[i] = alpha * v1[i] + beta * v2[i];
    }
    result
}

// Множення матриці на вектор
fn multiply_matrix_vector(matrix: &Vec<Vec<f64>>, vector: &Vec<f64>) -> Vec<f64> {
    let m = matrix.len();
    let n = vector.len();

    if m == 0 || n == 0 || matrix[0].len() != n {
        panic!("Matrix and vector dimensions are not compatible for multiplication.");
    }

    let mut result = vec![0.0; m];
    for i in 0..m {
        for j in 0..n {
            result[i] += matrix[i][j] * vector[j];
        }
    }
    result
}

// Виведення матриці
fn print_matrix(name: &str, m: &Vec<Vec<f64>>) {
    println!("{}", name);
    for row in m {
        for val in row {
            print!("{:8.2}", val);
        }
        println!();
    }
}

fn main() {
    // Вихідні матриці P, C, B згідно з таблицею даних методички (стор. 5)
    let p: Vec<Vec<f64>> = vec![
        vec![ 3.0,  1.0,  2.0, -1.0],
        vec![ 2.0,  1.0,  1.0,  0.0],
        vec![-1.0,  0.0,  0.0,  2.0],
        vec![ 1.0, -2.0,  3.0,  1.0],
    ];

    let c: Vec<Vec<f64>> = vec![
        vec![3.0,  0.0, -1.0, -1.0],
        vec![2.0, -1.0,  1.0, -3.0],
        vec![1.0,  1.0, -2.0,  3.0],
        vec![1.0,  2.0, -2.0,  1.0],
    ];

    let b: Vec<Vec<f64>> = vec![
        vec![ 1.0,  0.0, -1.0, -1.0],
        vec![ 2.0, -1.0,  1.0, -3.0],
        vec![ 1.0,  0.0,  3.0, -2.0],
        vec![-1.0,  2.0, -2.0,  1.0],
    ];

    // Вихідні вектори y, u
    let y: Vec<f64> = vec![2.0, 5.0, -1.0, -2.0];
    let u: Vec<f64> = vec![2.0, 5.0,  1.0,  2.0];

    // 1. Добуток матриць P * C
    let pc = multiply_matrices(&p, &c);

    // 2. Перша дужка (матриця): dm = 3*P*C - 4*B
    let dm = linear_comb_matrices(3.0, &pc, -4.0, &b);

    // 3. Друга дужка (вектор): dv = 1.5*y + 2*u
    let dv = linear_comb_vectors(1.5, &y, 2.0, &u);

    // 4. Кінцевий результат: rv = dm * dv
    let rv = multiply_matrix_vector(&dm, &dv);

    print_matrix("Matrix P * C:", &pc);
    println!();
    print_matrix("Matrix dm = 3*P*C - 4*B:", &dm);
    println!("\nVector dv = 1.5*y + 2*u:\n{:?}", dv);
    println!("\nResult vector rv = (3*P*C - 4*B)*(1.5*y + 2*u):\n{:?}", rv);
}
