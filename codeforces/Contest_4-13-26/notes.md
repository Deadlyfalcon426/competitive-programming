# Codeforces Round 1093 Div. 2

## Problem A
Link: https://codeforces.com/contest/2220/problem/A

Initial idea:
- goal felt like arranging array so prefix sums never match later elements
- sorting descending immediately looked promising

Key insight:
- sorting descending works well in most cases
- duplicates introduce edge cases where sums can collide with elements

Implementation:
- used a set to enforce uniqueness handling
- minor inefficiencies from mixing push_back + resize
- spent time debugging helper function logic

Reflection:
- correct greedy direction was found quickly (~20–30 min solve)
- biggest issue was implementation detail bugs, not algorithm design
- need cleaner vector construction habits and less fragile helper functions

Pattern reminder:
When greedy structure is obvious after sorting, most difficulty comes from edge-case handling, not core logic.