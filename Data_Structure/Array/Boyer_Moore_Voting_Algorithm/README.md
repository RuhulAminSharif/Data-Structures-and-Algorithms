<details>
  <summary> Boyer Moore Voting Algorithm </summary>  

**What is majority element?**  
A **majority element** is one that appears **more than half of the time** in the input elements.

The algorithm seeks out a **majority element** if one exists. However, if there is **no majority**, the algorithm will **not recognize** this and will continue to output one of the items.  

The algorithm is divided into **two parts**.
- A first pass identifies an element as a majority
- A second pass confirms that the element identified in the first pass is indeed a majority element.  

The method **will not identify** the majority element if it **does not exist**, and will thus return an arbitrary element. We need to **handle** this situation.  

### The proceeding of the algorithm:

- First, choose a candidate from the given set of elements if it is the same as the candidate element, increase the votes. Otherwise, decrease the votes. 
- If votes become 0, select another new element as the new candidate.

### Intuition Behind Working : (from gfg)
When the elements are the same as the candidate element, votes are incremented whereas when some other element is found (not equal to the candidate element), we decreased the count.  
This actually means that we are decreasing the priority of winning ability of the selected candidate, since we know that if the candidate is in majority it occurs more than N/2 times and the remaining elements are less than N/2.  
We keep decreasing the votes since we found some different element(s) than the candidate element.  
When votes become 0, this actually means that there are the equal  number of votes for different elements, which should not be the case for the element to be the majority element.  
So the candidate element cannot be the majority and hence we choose the present element as the candidate and continue the same till all the elements get finished.  
The final candidate would be our majority element.  

We check using the 2nd traversal to see whether its count is greater than N/2. If it is true, we consider it as the majority element.
### Dry run (from gfg)
Input :{1,1,1,1,2,3,5}  
Output : 1  

![BMVA](/Data_Structure/Array/Boyer_Moore_Voting_Algorithm/BMVA.png)  


</details>