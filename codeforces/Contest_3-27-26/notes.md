# Codeforces Round 1087 Div. 2

## Problem A
Link: https://codeforces.com/contest/2209/problem/A

Initial thoughts:
- looked simulation-heavy at first
- needed to maximize combat growth efficiently
- instinct was to process monsters greedily

Key realization:
- sorting the monsters smallest-to-largest simplifies everything
- if a monster cannot be defeated after sorting, no future monster can either

Strategy:
1. Sort monsters ascending
2. Fight weakest first
3. Use flip flops greedily to maximize equal-level fights
4. Snowball combat power

Implementation notes:
- moved combat logic into separate function to reduce main() complexity
- careful handling needed for flip flop allocation

Reflection:
- decent greedy recognition here
- started overcomplicating resource allocation slightly
- sorting insight was the major turning point

Pattern reminder:
When progression is monotonic ("if I can't beat this, I can't beat stronger"),
sorting often collapses the state space dramatically.