from typing import List
from math import floor


def recursive_bs(arr: List[int], target: int) -> int:
    mid_pos = floor(len(arr)/2)
    mid = arr[mid_pos]
    if len(arr) < 2 and mid != target:
        return -1

    if mid == target:
        return mid_pos

    # offset is being summed even when element is not in array
    if target > mid:
        pos_found = recursive_bs(arr[mid_pos:], target)

        if pos_found == -1:
            return -1

        return len(arr[:mid_pos]) + pos_found
    else:
        return recursive_bs(arr[:mid_pos], target)

if __name__ == "__main__":
    print(recursive_bs([1, 2, 3, 4, 5, 6], 1))
    print(recursive_bs([1, 2, 3, 4, 5, 6], 6))
    print(recursive_bs([1, 2, 3, 4, 5, 6], 4))
    print(recursive_bs([1, 2, 3, 4, 5, 6], 12))

