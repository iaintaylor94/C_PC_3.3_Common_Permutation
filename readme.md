# Programming Challenges
## Problem 3.3: Common Permutation[^1]
### Problem description
This program finds the longest string such that a permutation of this string is a subsequence of two comparison strings - the comparison strings need not share a common subsequence. The longest string is printed in alphabetical order.

The input for each case is two lines containing the two comparison strings. Each case is separated by nothing. The program input is terminated when there are no more lines in the input file.


### Example 
>**Input**
>pretty
>women
>walking
>down
>the
>street                                                                

>**Output**                                             
>e                                                      
>nw                          
>et                                                   

### Problem solution
Two arrays, both containing the number of each character ('a' - 'z') contained within the two input strings are created. A third array (also 'a' - 'z') is populated with the minimum number of each letter in the first two arrays. The non-zero elements of this array are the common permutation of the two input strings.

### Bug Checklist
- [ ] NA

[^1]: Programming Challenges By S.Skienna and M.Revilla, page 69