# Educational Codeforces Round 192 (Rated for Div. 2)

## Problem A
### Link: https://codeforces.com/contest/2242/problem/A
---

## Initial Thoughts
- Started by asking what situations would guarantee two identical bigrams.
- After trying a few examples, noticed there were only two ways to force it:
  - A letter appears at least three times, creating two identical consecutive bigrams (e.g. `aaa`).
  - Two different letters each appear at least twice, allowing a construction like `aabab`.
- Realized I didn't actually need to construct the string.
- Instead, I only needed to detect whether one of those two conditions existed.
- Rather than storing every frequency, I only tracked:
  - whether any count exceeded 2,
  - and whether I had already seen one letter with frequency exactly 2.
- The implementation ended up being much simpler than the statement initially suggested.

## Reflection
- Nice confidence booster after previous contests.
- I'm getting noticeably faster at reducing a constructive problem into a few observations instead of trying to simulate it.
- Another reminder that many Problem A's hide a simple observation behind a long statement.

---

## Problem B
### Link: https://codeforces.com/contest/2242/problem/B
---

## Initial Thoughts
- The problem naturally split into three independent stages, so I decided to model it that way.
- My first idea was to greedily build:
  1. the left section,
  2. the middle section,
  3. and leave everything else for the final section.
- While scanning the array, I kept running counts of `1`, `2`, and `3`.
- For each stage I maintained the inequality required by the statement:
  - Left: `ones >= twos + threes`
  - Middle: `ones + twos >= threes`
- I believed that once a section became valid, it made sense to commit to it and begin constructing the next one.
- Although I hadn't proven the greedy strategy formally, it matched my intuition and I decided to implement it.

## Debugging
- The first Wrong Answer revealed an edge case where ending the first section immediately wasn't always optimal.
- I experimented with allowing the first section to absorb one additional `3`, using a flag to remember that adjustment.
- This increased the complexity of the implementation and introduced another Wrong Answer.
- I initially thought the entire greedy approach had failed.
- Instead of rewriting everything, I reviewed the state transitions one by one.
- The actual bug was much smaller: the extra-`3` flag was never reset correctly, allowing the middle section to incorrectly ignore leading `3`s.
- Once that state bug was fixed, the solution was accepted.

## Reflection
- Biggest lesson: don't abandon an algorithm just because debugging becomes difficult.
- In this case, the greedy idea was correct—the implementation simply wasn't preserving the intended state.
- This contest reinforced how useful it is to think of problems as maintaining invariants throughout different phases.
- Breaking the solution into explicit stages made the logic much easier to organize.
- Probably the hardest problem I've solved entirely on my own so far.
- Best contest performance yet (assuming the rating agrees).
- Alhamdulillah. I genuinely think the recent time spent reading *Competitive Programmer's Handbook* by Antti Laaksonen is starting to show in how I approach problems instead of just how I write code.