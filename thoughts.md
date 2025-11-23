# My Thought Process

This messy document entails my raw thoughts and ideas when attempting problems. This was inspired from one of Colin Galen's videos as I figured it'd be useful to jot down the process for future reference. Also to know stuff like, how close am I to actually reaching the solution or simply just to see how much improvement have been made. It's always good to keep a history of things.

## 2164B: Even Modulo Pair

00:10 Prime numbers? If even % even will be even, if and only if they're not multiples. Like 6 is not a multiple of 8, so 8 % 6 = 2, but 4 is a multiple of 8 so 8 % 4 = 0.

00:15 I don't thin can do O(n^2), n can be as big as 10^5, so (10^5)^2 = 10^10, more than 10^8 ops per second

00:20 Recall theory behind modulo. 17 % 6 = 17 - 6 - 6 = 5. Hence, 7 % 5 = 7 - 5. even % even, if 0 also even. Hence, if even then js break and return, otherwise keeping checking if any odd pairs meet condition.

00:25 Notice diff between two adjacent primes in list of primes are always even? So check, if this exist. Hence, check if at least two evens or primes. What about 117 and 1117 though, they are not primes but still valid

00:30 Decided to just implement a bruteforce, O(n^2) solution. Got WA on test 2, cause of two problems: first, j = i + 1 so as to not check the same element as i; second, check either even or remainder is even. It got accepted but why though cause the complexity shouldn't fit within the time limit of 1 second given that n can be 2*10^5?

00:35 This type of problem requires bounding the naive solution. Similar to 2167D, only requires primes until 53, essentially bounding solution to O(53n) or O(n). How bounding works in this problem?

Since the given sequence is **strictly increasing**, which is different from non-decreasing as there will be no same elements, so a1 < a2 < a3 < a4 < ... < an. For `x < y`, if `x` and `y` even, then remainder confirm even. TBC...

## 1705B: Mark the Dust Sweeper

00:00 Goal is to move all dust to nth room. For example, 2 0 0, move 2 to last, so 0 0 2. 1-indexed used in test case, when i = 1 and j = 2:

2 0 0\
i j

Set ai = ai - 1, aj = aj + 1, become: 1 1 0

Afterwards, i = 1, j = 3 to become: 0 1 1

Finally, i = 2 and j = 3 to become: 0 0 2

00:10 Need to sort? sort(0 2 0 2 0) = [0, 0, 0, 2, 2]. Cannot sort as will change order which changes number of operations.

00:15 Loop through and pick subarray such that [i, j=i+1], 

0 2 0 2 0\
0 0 2 2 0 cost = 2 as set i--, then i-- again\
0 0 2 0 2 cost = 4\
0 0 0 2 2 cost = 6\
0 0 0 0 4 cost = 8\

00:20 Make every 0 at least 1? Then from first 1, move to last element

00:25 Fill 0s between last and some element to satisfy condition of i < j and ai, ai+1, ..., aj-1 > 0. The some element should be a nonzero digit from left. Loop from left, find a non-zero digit and set that as the starting point:

0 2 0 2 0\
  i\

As seen above, i = 2 for 1-indexed will be starting point

00:30 From starting point, make [i,j] such that nums[j] == 0, to fill 0s with >= 1. When there's no 0, then from starting point, choose [i, j] where j = last element, and slowly move all values to the last element.

For example: 2 0 3 0 4 6

1 1 2 1 4 6 - after filling in gaps, cost = 2 operations\
0 1 2 1 4 7 - cost = 1\
0 0 2 1 4 8 - cost = 1\
0 0 1 1 4 9 - cost = 1\
0 0 0 1 4 10 - cost = 1\
0 0 0 0 4 11 - cost = 1\
0 0 0 0 3 12 - cost = 1\
0 0 0 0 2 13 - cost = 1\
0 0 0 0 1 14 - cost = 1\
0 0 0 0 0 15 - cost = 1\
Total costs = 2 + 9 = 11

00:40 Again, int overflow cause 10^9+10^9 > int max of 10^9, I should just use ll all the time instead of int.

00:50 Got WA, expected 0 but got some random large number, turns out, another case where edge case not handled correct. Since every element, `a` in array has a range of 0 <= a <= 10^9, if all elements = 0, start = -1, so cause out of bounds.

## 1771A: Hossam and Combinatorics

00:00 sort(nums) and pick largest and smallest via last and first elements?

Consider this array with duplicate elements, then how?
nums = [2, 2, 3, 7, 8, 10]

|2-10| = 8
|10-2| = 8

Repeat another time as got two elements with same value of 2.
|2-10| = 8
|10-2| = 8

So, 4 interesting pairs. 1 (largest) * 2 * 2 (smallest duplicates)

What if: nums = [2, 2, 3, 7, 8, 10, 10]

|2-10| = 8
|10-2| = 8

|2-10| = 8
|10-2| = 8

|10-2| = 8
|2-10| = 8

|10-2| = 8
|2-10| = 8

So, 8 interesting pairs. As got two 2s and two 10s. 2 (largest) * 2 * (2 smallest dups) = 8

00:10 Just sort(nums), then two points from front and back. If a(i+1) and a(j+1) == prev ai and aj

00:15 For each largest duplicate, there will be 2 * smallest duplicates

What if, nums = [1, 2, 3, 6, 8]

Going by the formula, 1 (largest) * 2 * 1 (smallest) = 2

00:50 Got int overflow, so change everything to ll, but ans still wrong. Used a python script to gen n = 10^5 with each a = 10^5, no int overflow but ans wrong as prod is same when a = 10^5 and a = 35565 which is impossible.

00:51 What if all elements have same value, then there's no sm and lg, but they still satisfy the condition of an interesting pair, it's just that diff = 0.

01:00 No clue, had to see editorial. I thought when all equals, should be n * 2 * n. Turns out, my ans is correct, just that the edge case was not handled properly when |ai - aj| = 0, for this case, ans = n(n-1). My ans missed out -1, why -1, cause exclude the last element from the rest as the rest will be the `sm`.

## 2093B: Expensive Number

00:00 13700 Start from right side, find a non-zero digit. Then, remove leading numbers to the left. Finally, remove trailing zeros to the right.

13700
  ^

Remove leading numbers:
00700

Remove trailing zeros:
007

Cost = 7 / (0 + 0 + 7) = 1

Since input is super huge, 10^100, use a string to store input. Then, just loop from right side.

## 1543B: Customising the Track

00:00 How you get 4 got 2nd test case when 1 + 1 = 2, turns out cause sum two times. Take note j = i + 1
1 2 3
i j

|1-2| = 1
|2-3| = 1
inconvenience = 2(1+1) = 4

n = 3
Move 1 car from 3rd track to 1st track:
2 2 2
i j

|2-2| = 0
2 2 2
  i j
|2-2| = 0
inconvenience = 0 + 0


00:10 Sum i and sum j so must multiply by 2

Example 2:
0 1 1 0
i j
|0-1| = 1
0 1 1 0
  i j 
|1-1| = 0
0 1 1 0
    i j 
|1-0| = 1
inconvenience = 2(1 + 1) = 4

00:20 Make everything equal or as equal as possible? Find `track with least traffic = l`, and distribute cars equally to each track such that == l.

00:30 Reveal hint. So previous guess sort of correct, make everything as even as possible as seen from first test case, 2 2 2. But what if cannot make even, or rather how? To make even, take sum(nums) / len(nums), what number for each track such that all tracks are equal.

00:35 For example, third test case, sum(nums) = 57/len(nums) = 5.7, so every track must have at least 5 to be even, but since odd num, one track will be more. In this case, if each track is 5, still got 7 left over, so distribute again, making seven elements with value of 6 and three elements with value of 5.

00:40 After distributing evenly:

6,6,6,6,6,6,6,5,5,5
            i j

|6-5| = 1

6,6,6,6,6,6,6,5,5,5
              i j
|5-5| = 0
|5-5| = 0
inconvenience = 2(1) = 2

00:50 Really no clue lol, so had to read editorial. Turns out sum(nums) % n to find out even or odd, if even meaning array can be split equally so

01:00 Understanding the editorial using first test case, so let consider this:

x = a certain element in the array that will be added with value from another element
p = the original value of x
y = the corresponding affected element which is used to add to x

After the change,
x = p + 1
y = (n - x)

Observe below to see this pattern:
For n = 3, move 1 car from 3rd track to 1st track:
x = 1 + 1 = 2
y = 3 - 1 = 2

2 2 2
i j

|2-2| = 0
2 2 2
  i j
|2-2| = 0
inconvenience = 0 + 0

01:10 Based on the previous observation, a formula can be formed, x = sum(nums) % n to get remainder, or the number of elements that'll be more than the rest, like below with seven numbers that is 1 more than the other three numbers:
6,6,6,6,6,6,6,5,5,5

p = sum(nums)/n

To get the other minority elements: (n - x) which corresponds to the three elements with value of 5 as shown above

Hence, the formula x * (n - x) will be the ans. If x is 0, means all elements can be split evenly, and hence, inconvenience = 0.
