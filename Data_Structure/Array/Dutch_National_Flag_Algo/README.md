## Intuition

Dutch National flag algorithm contains 3 pointers i.e. **low, mid, and high**, and 3 main rules.

### The rules are the following:

**arr[0….low-1]** contains 0. **[Extreme left part]**  
**arr[low….mid-1]** contains 1.  
**arr[high+1….n-1]** contains 2. **[Extreme right part]**, n = size of the array

The middle part i.e. **arr[mid….high]** is the unsorted segment.

So, hypothetically the array with different markers will look like the following:

![DNF](/Data_Structure/Array/Dutch_National_Flag_Algo/DNF.png)

**Approach:**

We will work based on the value of the **mid pointer**.

The steps will be the following:

1. First, we will run a loop that will continue until mid <= high.
2. There can be three different values of mid pointer i.e. arr[mid]
   - If **arr[mid] == 0**, we will swap arr[low] and arr[mid] and will increment both low and mid. Now the subarray from index 0 to (low-1) only contains 0.
   - If **arr[mid] == 1**, we will just increment the mid pointer and then the index (mid-1) will point to 1 as it should according to the rules.
   - If **arr[mid] == 2**, we will swap arr[mid] and arr[high] and will decrement high. Now the subarray from index high+1 to (n-1) only contains 2.
     In this step, we will do nothing to the mid-pointer as even after swapping, the subarray from mid to high(after decrementing high) might be unsorted. So, we will check the value of mid again in the next iteration.
3. Finally, our array should be sorted.

**_Note:_** Dutch National Flag Algorithm used on sorting a list of **three** different types of values. In this case, we consider **0, 1, and 2** as three different values.
