from typing import List 
from copy import deepcopy
from random import randint


def generate_random_array_with(size: int) -> List[int]:
    return [randint(0, 1000) for a in range(size)]


def quicksort(arr: List[int]) -> List[int]:
    if len(arr) < 2:
        return arr;
    
    pivot = arr[0]
    sub_1 = [item for item in arr[1:] if item <= pivot]
    sub_2 = [item for item in arr[1:] if item > pivot]

    return quicksort(sub_1) + [pivot] + quicksort(sub_2)


if __name__ == "__main__":
    arr = generate_random_array_with(size=5)

    print(arr)
    print(quicksort(arr))
    
