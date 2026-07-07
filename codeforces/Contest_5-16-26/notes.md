# Codeforces Round 1098 Div. 2

## Problem A
Link: https://codeforces.com/contest/2228/problem/A

---

## Initial idea
- Thought about finding subarrays whose sum is divisible by 3
- First instinct was to simulate removal of valid segments
- Started with a counter-based approach over the array

---

## Key misunderstanding (main issue)
- Confused subarray vs subsequence early on
- This led to overthinking “removal” and structure of the array
- Problem was actually reducible to counting + grouping, not simulation

---

## Correct approach (what I converged to)
- Count frequencies of values (0, 1, 2)
- Build valid operations using:
  - single 0s
  - pairing 1s and 2s
  - leftover grouping by 3

---

## Implementation notes
- Used `count()` for frequency extraction
- Handled pairing between 1s and 2s greedily
- Converted remaining values into groups of 3 where possible

Bug fixes during contest:
- Replaced incorrect `%=` logic with subtraction (`-=`)
- Fixed logic in conditional branches where leftovers were mishandled

---

## Reflection
This was my first clearly bad contest, but it’s a useful baseline.

Main reasons it went poorly:
- weak early classification of problem type (subarray vs subsequence)
- not fully testing edge cases before coding
- small implementation mistakes (operator confusion, branching errors)

---

## Takeaway
Mistakes here were not about inability, but about:
- rushing into simulation
- failing to simplify structure early

Core lesson:
If a problem involves constraints like “divisible by k” with small values,
it is almost always frequency + grouping, not simulation.