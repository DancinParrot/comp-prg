# My Thought Process

This messy document entails my raw thoughts and ideas when attempting problems. This was inspired from one of Colin Galen's videos as I figured it'd be useful to jot down the process for future reference. Also to know stuff like, how close am I to actually reaching the solution or simply just to see how much improvement have been made. It's always good to keep a history of things.

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
00:40

After distributing evenly:
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
