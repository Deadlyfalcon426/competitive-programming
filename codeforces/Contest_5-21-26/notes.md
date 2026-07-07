# Codeforces Round 1099 Div. 2

## Problem A
Link: https://codeforces.com/contest/2231/problem/A

---

## Initial idea
- Needs to be consecutive numbers' sums all distinct
- so counting numbers, \[1,2,3,4,5\]
- doesnt work, looks like sums and numbers in same array must all be distinct
- odd numbers to 2*n, \[1,3,5,7\], is distinct from sums \[4,8,12\] because odd+odd always equals even
- job well done, not any trouble in coding it, probably the easiest code ive ever written in a contest.

---

## Problem B
Link: https://codeforces.com/contest/2231/problem/B

---

## Initial Idea
- Need to choose a subsequence to add + integer k to all numbers in order to make OG array always nondescending (ascending or equal at every step)
- got too stuck in the planning phase, just kept thinking about different ideas such as
- find all the gaps and store in an array, look for biggest and add it to the rest
- beginning always doesnt need k and end never suffers from having k
- had several ideas but this was the best one

## Upsolve
- got kind of depressed during the contest and couldn't like solve it in time even though I had an hour
- plan to be more productive with my planning time in future, especially because I already foudn the solution
- Upsolving using the 'find biggest first method'
- took less than 45 minutes to re-solve and write code using this approach.
- TOOK 4 SUBMISSIONS FOR NO GOOD REASON
- first was forgot to remove a cout for debugging
- second was it didn't like having yesnoyesno and wanted YES\nNO\nYES\nNO?????
- third again was on me i wrote YES for no and NO for yes
- Fourth worked. like 2 was on me BUT THEY SAID NOT CASE SENSITIVE AND LITERALLY EVERY PROBLEM EVER DOESNT NEED NEWLINE BETWEEN
- i think from now on i will include newline just to spare me the pain
- and screw their 'not case-sensitve' im doing whatever the example shows
- For each test case, print "Yes" if it is possible to sort the array by performing the operation at most once. Otherwise, print "No". You may print the answer in any case. For example, "YeS", "YES", "NO", "nO" will also be accepted.
- above line is just lies bruv

## Reflection
- I feel like again I just need to get it together during contests and then I will succeed. 
- I'd like to practice more advanced greedy problems, subsequence, and constructive algorithm problems. this second problem took much longer than necessary
- top solutions seem to utilize bits library but i have yet to learn that, have to start soon.
- of course the newline and exact output copy will be standard from now on