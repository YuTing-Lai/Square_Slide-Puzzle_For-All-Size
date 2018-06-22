
# 4x4-Slide-Puzzle

</p>
<p align="center">
	<img width="250" alt="2018-06-19 7 37 14" src="https://user-images.githubusercontent.com/40336920/41595130-4cf2171c-73f8-11e8-94df-788a68ac4861.png">
</p>
 
  
Game.cpp [^game]
======


## How to play?

1. Run the **Slide_Puzzle_Game.cpp** first.
2. You'll get a random puzzle.
3. You can **move the number by typing it**.
4. Solve it, Go and Try!

### Game Tutorial View
##### Move the number:
If you want to move the 10 to the right.

<img width="300" alt="2018-06-19 6 44 06" src="https://user-images.githubusercontent.com/40336920/41593202-e019b5e2-73f1-11e8-961a-df1064154e6a.png">

Type **10** and **Enter**.

```
 6   2   3   4
 5   1   7  14
10      11  12
13   8   5   9
Enter the number you want to move:
10
```
And you will get this.

```
 6   2   3   4
 5   1   7  14
    10  11  12
13   8   5   9
Enter the number you want to move:
 
```
#### < Note1 >

If you type the error number, you'll get this.

```
error!!
 6   2   3   4
 5   1   7  14
    10  11  12
13   8   5   9
Enter the number you want to move:
 
```

### < Note2 >

When you finish the puzzle, you'll get this.

```
  1   2   3   4 
  5   6   7   8 
  9  10  11  12 
 13  14  15     
Finished! Great Job!
```

***
***
***
***

## Solution.cpp [^solution]

If you had a **REAL PUZZLE** but couldn't figure it out, try this.

### How to use it?

1. Run **Slide_Puzzle_Solution.cpp** .
2. Input your puzzle's numbers.
3. Follow the guide step by step.

### Solution Tutorial View

If the puzzle look like this.

<img width="365" alt="2018-06-19 8 22 27" src="https://user-images.githubusercontent.com/40336920/41597029-d9e32912-73fe-11e8-80f5-49a8ea056eec.png">

Input all the numbers inside, and **input 16 when it is the blank**.

It look like this:

```
Input the puzzle, from left to right, from up to down.
If it is the blank, input 16.
6 2 3 4
5 1 7 14
10 16 11 15
13 8 12 9
```

And you'll get:

```
Move 1
The moves: 
down   down   right  left   up     up     right  down   down   left   
up     right  down   left   
1       3   4   
2   6   7   14  
5   10  11  15  
13  8   12  9   

Move 2
The moves: 
up     right  up     left   left   down   down   right  up     left   
down   
1   2       4   
5   3   6   14  
10  11  7   15  
13  8   12  9 

...
...
...

Move 11
The moves: 
up     left   
1   2   3   4   
5   6   7   8   
9   10  11  12  
13  14  15      

It takes 119 moves
```

Follow **"The moves:"** step by step, and you'll finish in the end.

[^game]: Game here.
[^solution]: Solution here.

