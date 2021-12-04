// I feel like this could be better implemented, has to be revisited.


fn main() {

    let mut list = [104, 244, -246, 240, 120, -255, -55, -200, 9, -117, 150, -216, -205, -54, 201, -136, -148, 231];
    let length = list.len();
    println!("{:?}", list);
    quicksort(&mut list, &0, &(length-1));
    println!("{:?}", list);
}

fn quicksort(list: &mut [i32], low: &usize, high: &usize) {
    
    if low < high {
        let mut pivot = partition(list, &low, &high);
        if pivot == 0 {pivot+=1};
        quicksort(list, &low, &(&pivot-1));
        quicksort(list, &(&pivot+1), &high);
    }
}


fn partition(list: &mut [i32], low: &usize, high: &usize) -> usize {
    let pivot = list[*high];
    let mut i = (*low as i32) -1;

    for j in *low..*high {
        if list[j] <= pivot {
            i += 1;
            list.swap(i as usize, j);
        }
    }


    list.swap((i + 1) as usize, *high);

    (i + 1) as usize
}
