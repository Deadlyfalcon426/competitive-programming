# Educational Codeforces Round 190 (Rated for Div. 2)

## Problem A

### Link: https://codeforces.com/contest/2230/problem/A

### Initial Thoughts
- Going to spend some time and think through the solution before rushing to code this time
- Looks like a sort of minimize the money needing to be spent.
- Using an min(a(n-x)+bn) type of thing
- My plan is to write out problem on paper now
- Harder than I thought... ok this is essentially an optimization problem, lets try and compare unit rates!

### First Attempt
- I'm going to make it go by the best cases, first up is the 3 deal, if its worth it, then we apply it and then we test if the rest is good. Should get the job done
- Took some debugging, but the approach was correct
- Spent an hour on the problem, one recurring mistake is the intentional use of mod when division is needed. Stop being trigger happy on mod

### Reflection
- Heh they thought they could catch me with the large numbers I just made everyone long long

## Problem B

### Link: https://codeforces.com/contest/2230/problem/B

### Initial Thoughts
- A subsequence problem, I might refer to previous contest's code
- what defines a multiple of 4? no odd number in ones place, so maybe start from the back of the string!
- 1 = 0.25 \*4 , so no, then 10 = 2.5\*4, so no, but then from then on 25\*4 = 100! 
- so as long as first 2 places are divisible by 4 on their own, the rest is trivial.
- start from the back, look for 2 subsequent digits that, when put together, create something divisible by 4 
- because i despise strings i am putting it into a vector, hopefully it wont kill my time complexity

### Reflection
- Well I read the problem wrong and that cost me it
- I made some progress but like I still have to restart and since i have 10 mins left I called it quits and I just tried to finish the problem and understand it
- I learned to use math effectively, not to solve this problem but to help me in my own convoluted solution. 
- By that, I mean that I wrote out the multiples of 4 and realized that if ones are %4==0 then the tens must be even and if ones are (x+2)%4==0 then tens must be odd
- So like I did solve something hard but it wasnt the right thing and I only realized that after I had finished debugging the original solution
- Yeah probably if I had read the problem correctly the first time I would have been able to solve it in time because it was a lot of the same concepts I used in my colution.
### 2nd attempt, technically the upsolve
- We can start by removing all 4s
- then the leftover multiples all have to start with 2 (odd and through 1-4)
- so all we have to do is remove everything after the 2 
- this is because if there is odd after 2 then 12, 32, all multiples of 4
- now it is simply optimization as is it less to remove all odd past 2, or to remove all 2s?
- i think a count function will come in handy here, guess switching to vector was a good decision after all!
- didnt work, entirely wrong approach, will probably come back to this when I have more time (5/18/26 9:31pm)
