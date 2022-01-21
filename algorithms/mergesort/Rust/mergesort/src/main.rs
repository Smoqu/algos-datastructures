fn merge(left: &[i32], right: &[i32]) -> Vec<i32> {
    let mut l: usize = 0;
    let mut r: usize = 0;

    let mut result: Vec<i32> = vec![];

    while l < left.len() && r < right.len() {
        if left[l] < right[r] {
            result.push(left[l]);
            l += 1;
        } else {
            result.push(right[r]);
            r += 1;
        }
    }

    for i in l..left.len() {
        result.push(left[i]);
        l += 1;
    }

    for i in r..right.len() {
        result.push(right[i]);
        r += 1;
    }

    return result;
}

fn mergesort(array: &[i32]) -> Vec<i32> {
    let length = array.len();
    let middle = (length / 2) as usize;

    if length == 1 {
        return Vec::from(array);
    };

    let left = mergesort(&array[..middle]);
    let right = mergesort(&array[middle..]);

    return merge(&left, &right);
}

fn main() {
    let array = [-9, 5, 8, -1, 2, 7, 9];
    let sorted = mergesort(&array);

    println!("{:?}", sorted);
}
