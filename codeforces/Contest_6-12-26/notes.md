# Codeforces Round 1103 (Div. 3)
## Problem A
### Link: https://codeforces.com/contest/2236/problem/A
---
## Initial thoughts
- Lowk the easist thing ive ever done, fastest code ive ever written
- well looks like i messed it up
- BRO THIS ISNT MY FAULT IT WORKED WHEN ALL I ADDED WAS \N THIS IS MADNESS
- revenge arc, from now on I always use \n. this has happened too many times to let go
- screw those guys saying "any case will do!", cant even use Scanner/cin. its not that hard damn


## Problem B
### Link: https://codeforces.com/contest/2236/problem/B
---
## Initial Thoughts
 - Doing it during the contest cause i need to formulate thoughts
 - so one situation its impossible in, is if there are more than 2 '1's, since we have one swap
 - nvm we have infinite swaps
 - so then we need to find ig subsequences where they are split by correct amount
 - idea-> odd amount of ones, instant impossible
 - seems to hold up in my head.
 - this is backed by examples and that we must invert 2 at a time... i think its solid!
 - next check-> for every one, can we match it with another one exactly 'k' away?
 - lowk i think its good chat
 - alr made a save, if 0000, then obvious yes
 - ok theres another issue:
 - 10100101 has overlapping if k=5, but if its like k=2, then we lowk might have an issue 
 - because like the next 1 was already included
 - solution? flag the used up one? perhaps replace with zero? 
 - definitely replace with zero, that actually reflects the simluation well!
 - wrong answer on test 2 😢
 - probably a logic error since it got that far then
 - ok crazy idea: since we have inf turns, as long as there are even amount of ones, then it will be possible
 - wrong as well... test 2 again, some sort of edge case perhaps

## Final solution 
- This comes after much deliberation and modulo understanding
- Modulo is like trains that stop after the same amount of distances
- you can utlize them for patterns of things that are always like k away
- So what i ended up doing was taking position of all ones, taking % of all positions, then checking if the remainder is same as others
- then since a swap only does 2, we need even amount cause inverting yk and stuff
- so sort the remainders of the ones, then check if each pair are equal
- this generates even amounts, because 4 becomes 2 and 2
- in the first iteration i included this edge case, however i forgot in the second attempt, which led to a very embarassing WA. edge case of zero ones, 0000.

# Contest Reflection
- Dang that was rough. 
- selling this hard on Div 3 is lowk disgraceful
- plus i had momentum too from this first question
- BUT I FINALLY UNDERSTAND MODULUS TO AN EXTENT
- so something good came out of this
- even though rating lowk might tank :p


