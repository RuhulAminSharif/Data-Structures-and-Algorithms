## Bubble Sort

<p>
Bubble Sort works by repeatedly swapping the adjacent elements if they are in the wrong order. This algorithm is not suitable for large data sets as its average and worst-case time complexity is quite high.
</p>

## Step-by-step process

An array of numbers "5 1 4 2 8"

### First Pass

- ( 5 1 4 2 8 ) → ( 1 5 4 2 8 ), Here, algorithm compares the first two elements, and swaps since 5 > 1.
- ( 1 5 4 2 8 ) → ( 1 4 5 2 8 ), Swap since 5 > 4
- ( 1 4 5 2 8 ) → ( 1 4 2 5 8 ), Swap since 5 > 2
- ( 1 4 2 5 8 ) → ( 1 4 2 5 8 ), Now, since these elements are already in order (8 > 5), algorithm does not swap them.

### Second Pass

- ( 1 4 2 5 8 ) → ( 1 4 2 5 8 )
- ( 1 4 2 5 8 ) → ( 1 2 4 5 8 ), Swap since 4 > 2
- ( 1 2 4 5 8 ) → ( 1 2 4 5 8 )
- ( 1 2 4 5 8 ) → ( 1 2 4 5 8 )

Now, the array is already sorted, but the algorithm does not know if it is completed. The algorithm needs one additional whole pass without any swap to know it is sorted.

### Third Pass

- ( 1 2 4 5 8 ) → ( 1 2 4 5 8 )
- ( 1 2 4 5 8 ) → ( 1 2 4 5 8 )
- ( 1 2 4 5 8 ) → ( 1 2 4 5 8 )
- ( 1 2 4 5 8 ) → ( 1 2 4 5 8 )

### Complexity Analysis:

- Time Complexity: O(N^2)
- Auxiliary Space: O(1)

### Advantages of Bubble Sort:

- Bubble sort is easy to understand and implement.
- It does not require any additional memory space.
- It is a stable sorting algorithm, meaning that elements with the same key value maintain their relative order in the sorted output.

### Disadvantages of Bubble Sort:

- Has a time complexity of O(N2) which makes it very slow for large data sets.
- It can limit the efficiency of the algorithm in certain cases since this algorithms requires a comparison operator to determine the order of element cause it is a comparison-based algorithm.

### Where is the Bubble sort algorithm used?

- read: [Bubble Sort](https://en.wikipedia.org/wiki/Bubble_sort#In_practice)
