# Puzzle Solution


## What can I do with it?

* Follow the steps inside the program, you'll solve it.
* Whatever how disordered the puzzle is, you can still solve it.
* Even if the puzzle has no exact solution, it will help you find out.
* Almost **every sizes are avialable**. (For human-solving puzzles)

<br>

## How to use it?

* Run the **Puzzle-Solution.cpp** first.
* You have to **Input Your Puzzle's Size**. (for example: 4 )

```
What it your puzzle's size (N x N)? Input N. (1<N<100)
4
```

* Then **Input Your Puzzle's Numbers**, if it is the blank, Input the last number of your puzzle. (Like the example is 16)

```
Input the puzzle, from left to right, from up to down.
If it is the blank, input 16.
1   2   7   4 
6   16  3  14 
10  5   8  13 
11  12  9  15 
Your puzzle:
  1   2   7   4 
  6       3  14 
 10   5   8  13 
 11  12   9  15 
```

* The program will take you step by step, follow it until the puzzle is finished.

```
Move the blank:
down   right  
    1   7   4   
6   2   3   14  
10  5   8   13  
11  12  9   15 

Move 1:
left   
1       7   4   
6   2   3   14  
10  5   8   13  
11  12  9   15 
```

* If there are no problems of the puzzle.

```
Move 11 and the blank:
left   up     
1   2   3   4   
5   6   7   8   
9   10  11  12  
13  14  15      

Done!
```

* If it does have problems, it will look like this.

```
Move 11 and the blank:
left   up     
1   2   3   4   
5   6   7   8   
9   10  11  15  
13  14  12      

The puzzle has error. Please fix it.
```

## What is the method of this program?

* For any sizes of an puzzle, we can know every number of any positions by using variables. 





<img width="653" alt="2018-06-23 6 25 40" src="https://user-images.githubusercontent.com/40336920/41808621-e1b3d4e0-7712-11e8-8447-07e5c4f532b7.png">
