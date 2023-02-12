# Time: Best case-> O(nlog(n))
#       Worst case-> O(nlog(n))
#       Average case-> O(nlog(n))
# Space: O(n)
# Stable: YES

def mergeSort(arr, s, e):
    if s == e:
        return arr

    # The middle index of the array
    m = (s + e) // 2

    # Sort the left half
    mergeSort(arr, s, m)

    # Sort the right half
    mergeSort(arr, m + 1, e)

    # Merge sorted halfs
    merge(arr, s, m, e)
    
    return arr

# Merge in-place
def merge(arr, s, m, e):
    # Copy the sorted left & right halfs to temp arrays
    left = arr[s: m + 1]
    right = arr[m + 1: e + 1]

    i = 0 # index for left
    j = 0 # index for right
    k = s # index for arr

    # Merge the two sorted halfs into the original array
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            arr[k] = left[i]
            i += 1
        else:
            arr[k] = right[j]
            j += 1
        k += 1

    # One of the halfs will have elements remaining
    while i < len(left):
        arr[k] = left[i]
        i += 1
        k += 1
    while j < len(right):
        arr[k] = right[j]
        j += 1
        k += 1