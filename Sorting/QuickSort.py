# Time: Best case-> O(nlog(n))
#       Worst case-> O(n^2)
#       Average case-> O(nlog(n))
# Space: O(1) in place
# Stable: NO

def quickSort(arr, s, e):
    if e - s + 1 <= 1:
        return
            
    pivot = arr[e]
    left = s # pointer for left side

    # Partition: elements smaller than pivot on left side
    for i in range(s, e):
        if arr[i] < pivot:
            temp = arr[i]
            arr[i] = arr[left]
            arr[left] = temp
            left += 1

    # Move pivot in-between left & right sides
    arr[e] = arr[left]
    arr[left] = pivot

    quickSort(arr, s, left-1) # Quick sort left side
    quickSort(arr, left+1, e) # Quick sort right side
