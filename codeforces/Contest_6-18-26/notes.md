# Order Capital Round 2 (Codeforces Round 1104, Div. 1 + Div. 2)
## Problem A
### Link: https://codeforces.com/contest/2237/problem/A
---
## Reflection (Written much later)
- doesnt look like anything too crazy here
- probably getting better and faster at writing code for the first, simplest problem 
- I think it was also nice that this was done without large vectors needed

## Problem B
### Link: https://codeforces.com/contest/2237/problem/B
---
## Initial Thoughts
- Had to open my notes to formulate thinking because I wasn't sure how to approach it.
- First objective: determine whether the target array is even reachable since we can only add.
- My first idea was to sort the original array and verify that every value could be increased to the corresponding target value.
- Once that worked, the problem became minimizing adjacent swaps.
- I initially tried to decide where to assign the new values, keeping track of indices and using - flags for elements that were already in the correct position.
- I experimented with insertion-sort ideas and several greedy approaches for assigning values - before swapping.
- The solution seemed to work on many cases, especially impossible ones, but failed on duplicates (e.g. [1,2,2] -> [1,3,5]), revealing that my mapping between equal values wasn't unique.
- From there I kept changing the implementation (distance between positions, flags, different assignment orders) instead of finding the underlying invariant, and the approach unraveled.

## Reflection
- I need to research more about how to spot invariants. Practicing it isnt getting me anywhere I feel.
- I need to learn when to give up an algorithm and try something else.
- I'm really disappointed in this performance. 
- This problem is not finished and remains to be completed
