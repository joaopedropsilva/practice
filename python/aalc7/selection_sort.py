from typing import List 
from copy import deepcopy
from random import randint

def generate_random_array_with(size: int) -> List[int]:
    return [randint(0, 1000) for a in range(size)]


def selection_sort(array: List[int]) -> tuple[List[int], int]:
    arr = deepcopy(array)
    num_iter = 0

    for i, item in enumerate(arr):
        smallest = item
        pos_of_new_smallest = i

        for j in range(i, len(arr)):
            num_iter += 1

            if smallest > arr[j]:
                smallest = arr[j]
                pos_of_new_smallest = j

        arr[i] = smallest
        arr[pos_of_new_smallest] = item

    return (arr, num_iter)


if __name__ == "__main__":
    arrays = []
    sizes = [50, 100, 200, 300, 500, 1000]
    for i in range(len(sizes)):
        arrays.append(generate_random_array_with(size=sizes[i]))

    print("size\titerations")
    for i in range(len(arrays)):
        print(f"{sizes[i]}\t{selection_sort(arrays[i])[1]}")

