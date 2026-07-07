# Practice Problems — Codeforces Upsolving

---

## The 67th OIES Problem
Link: https://codeforces.com/contest/2218/problem/D

### Initial thinking
- Tried to build a sequence satisfying adjacent GCD constraints
- First instinct was pattern construction using small integers
- Explored handcrafted sequences like:
  - 1, 2, 6, 12, 20, 30
  - multiplicative growth patterns (n * (n+1))
- Considered using primes to avoid bad GCD interactions

### Key realization
- Misread as a construction problem instead of a constraint problem
- The real difficulty is satisfying adjacency rules, not generating a pattern

### What went wrong
- Focused on numeric pattern guessing instead of structural reasoning
- Tried to “invent” sequences without proving validity

### Takeaway
If a problem involves adjacency constraints (like GCD),
the solution usually comes from invariants or structure, not pattern construction.

---

## Reverse a Permutation
(Custom upsolve problem)

### Initial idea
- Use suffix maximums to identify where ordering breaks
- Find first position where current element is not optimal
- Apply segment reversal to fix ordering

### Approach
- Precompute suffix maximum array
- Scan from left to find first violation point
- Identify correct segment boundaries
- Apply reconstruction via segment rewrite

### What worked
- Suffix maximum preprocessing was the key optimization idea
- Linear scan improved efficiency from brute force O(n²) thinking

### Issues
- Slight confusion between value vs index mapping when selecting segment endpoints
- Needed stronger correctness reasoning before coding

### Takeaway
Suffix-based preprocessing is powerful for greedy correction problems,
but only works when segment correctness is fully justified.

---

## ICPC Balloons
Link: https://codeforces.com/problemset/problem/1703/B

### Idea
- Count score based on whether characters are seen before

### Approach
- Iterate through string
- Track used characters with a container
- +2 for first occurrence, +1 for repeats

### Issues
- Used vector with linear search → inefficient membership checks
- Could be improved using boolean array or set

### Takeaway
Choice of data structure matters even in simple problems:
- vector → slow lookup
- set / boolean array → correct for membership tracking

---

## Watermelon

### Idea
- Direct logic based on parity conditions of W

### Final logic
- W == 2 → NO
- W even → YES
- W odd → NO

### Takeaway
Some problems are pure case analysis.
Fast classification is often the real skill being tested.

## B Absolute Cinema
Link: https://codeforces.com/contest/2229/problem/B
---
### Initial thoughts
- Okay it was actually a while ago when I did this but i didnt have time to commit it.
- I think i did this on a car ride and then just didnt commit it, especially cause it was just for practice
- It wasnt that bad just like I had to put all big numbers in one array and then add the max from the other leftover array

## Mickey Mouse Constructive
Link: 
---
### Initial Thoughts
- Yeah that's not done, I was practicing constructive algorithms so ill get back to that hopefully