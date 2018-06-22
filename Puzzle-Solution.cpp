//============================================================================
// Name        : Puzzle-Solution.cpp
// Author      : YuTing-Lai
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <time.h>
#include <iomanip>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

int puzzle[101][101]={{0}};
queue<string> move_step;
int size;

void printMoveSteps(int number){
	int nextLine = 1;
	if(number == size*size){
		printf("Move the blank:\n");
	}
	else if(number == size*size - size - 1){
		printf("Move %d and the blank:\n", number);
	}
	else{
		printf("Move %d:\n",number);
	}

	while(!move_step.empty()){
		cout << setiosflags(ios::left) << setw(6) << move_step.front() << " ";
		move_step.pop();
		if(nextLine == 10){
			nextLine = 0;
			printf("\n");
		}
		nextLine++;
	}
	printf("\n");
}


void print_puzzle(){
	int s = size;
	int length = log10(s*s) + 2;
	for(int i=1; i<=s; i++){
		for(int j=1; j<=s; j++){
			if(puzzle[i][j] == s*s)
				cout << setw(length) << " " << " ";
			else
			cout << setw(length) << puzzle[i][j] << " ";
		}
		cout << endl;
	}
}

void swap_number(char mode){
	int s = size;
	int N = s*s;
	int pos;
	for(pos=0; pos<N; pos++){
		if(puzzle[pos/s +1][pos%s +1] == N)
			break;
	}
	int row = pos/s + 1;
	int col = pos%s + 1;

	switch(mode)
	{
		case 'u':
			puzzle[row][col] = puzzle[row-1][col];
			puzzle[row-1][col] = N;
			move_step.push("down");
			break;
		case 'd':
			puzzle[row][col] = puzzle[row+1][col];
			puzzle[row+1][col] = N;
			move_step.push("up");
			break;
		case 'l':
			puzzle[row][col] = puzzle[row][col-1];
			puzzle[row][col-1] = N;
			move_step.push("right");
			break;
		case 'r':
			puzzle[row][col] = puzzle[row][col+1];
			puzzle[row][col+1] = N;
			move_step.push("left");
			break;
	}


}

void Dual(){
	int s = size;
	int pos=0;
	int number = s*s-s-1;
	int N = s*s;
	int row,col;

	//if the puzzle size is 2x2
	if(s == 2){
		//find the blank first
		for(; pos<N; pos++){
			if(puzzle[pos/s +1][pos%s +1] == N)
				break;
		}
		row = pos/s + 1;
		col = pos%s + 1;

		//put the blank to the left-up-most of the small puzzle
		if(row == s)
			swap_number('u');
		if(col == s)
			swap_number('l');
	}

	for(pos=0; pos<N; pos++){
		if(puzzle[pos/s +1][pos%s +1] == number)
			break;
	}
	row = pos/s + 1;
	col = pos%s + 1;

	if( (col == s) && (row == s-1) ){
		swap_number('r');
		swap_number('d');
	}
	else if( (col == s-1) && (row == s) ){
		swap_number('d');
		swap_number('r');
	}
	else{
		swap_number('r');
		swap_number('d');
		swap_number('l');
		swap_number('u');
		swap_number('r');
		swap_number('d');
	}

	printMoveSteps(N-s-1);
	print_puzzle();
	cout << endl;

}

void PuzzleStack(int width){


	int s = size;
	int pos=0;
	//five numbers: first, first+1, first+2, first+s, first+2s
	int number = s*s - (width-1)*s -(width-1);
	int N = s*s;
	int row,col;

	if(width == s){
		//find the blank first
		for(pos=0; pos<N; pos++){
			if(puzzle[pos/s +1][pos%s +1] == N)
				break;
		}
		int rowB = pos/s + 1;
		int colB = pos%s + 1;

		//move the blank to the left-up-most side of the puzzle
		for(int i=0; i<rowB-1; i++){
			swap_number('u');
		}
		for(int i=0; i<colB-1; i++){
			swap_number('l');
		}

		printMoveSteps(N);
		print_puzzle();
		cout << endl;
	}



	while(number < (s*s - (width-1)*s)){
		//Find the blank's position
		for(pos=0; pos<N; pos++){
			if(puzzle[pos/s +1][pos%s +1] == N)
				break;
		}
		int rowB = pos/s + 1;
		int colB = pos%s + 1;

		//Find the number's position
		for(pos=0; pos<N; pos++){
			if(puzzle[pos/s +1][pos%s +1] == number)
				break;
		}
		row = pos/s + 1;
		col = pos%s + 1;

		//Find the row's and col's difference between blank and number
		int RD = row - rowB;
		int CD = col - colB;

		if( (row != rowB) && (col != colB) ){
			//move the blank at the same row as the number
			for(int i=0; i<RD; i++){
				swap_number('d');
			}
			if(CD > 0){
				//move blank to the left side of the number
				for(int i=0; i<CD-1; i++){
					swap_number('r');
				}

				for(int i=0; i<CD-1; i++){
					//do counterclockwise ㄇ
					swap_number('r');
					swap_number('u');
					swap_number('l');
					swap_number('l');
					swap_number('d');
				}
				swap_number('r');
				swap_number('u');
				swap_number('l');
			}
			//if CD < 0, left side
			else{
				//move blank to the right side of the number
				for(int i=0; i>CD+1; i--){
					swap_number('l');
				}

				if(row == s){
					for(int i=0; i>CD+1; i--){
						//do the clockwise |--|
						swap_number('l');
						swap_number('u');
						swap_number('r');
						swap_number('r');
						swap_number('d');
					}
					swap_number('l');
					swap_number('u');
					swap_number('r');

				}
				else{
					for(int i=0; i>CD; i--){
						//do the counterclockwise |__|
						swap_number('l');
						swap_number('d');
						swap_number('r');
						swap_number('r');
						swap_number('u');
					}
					swap_number('u');
					swap_number('l');
				}

			}
			//now the number is at colB, and the blank is on the upside of the number
			for(int i=0; i<RD-1; i++){
				swap_number('d');
				swap_number('r');
				swap_number('u');
				swap_number('u');
				swap_number('l');
			}
			swap_number('d');
			swap_number('r');
			swap_number('u');
		}
		else if(row == rowB){
			//move the blank to the left side of the number
			for(int i=0; i<CD-1; i++){
				swap_number('r');
			}
			for(int i=0; i<CD-1; i++){
				//do the clockwise |__|
				swap_number('r');
				swap_number('d');
				swap_number('l');
				swap_number('l');
				swap_number('u');
			}
			swap_number('r');
		}
		//col == colB
		else{
			//move the blank to the upside of the number
			for(int i=0; i<RD-1; i++){
				swap_number('d');
			}
			for(int i=0; i<RD-1; i++){
				//do the ]
				swap_number('d');
				swap_number('r');
				swap_number('u');
				swap_number('u');
				swap_number('l');
			}
			swap_number('d');
			swap_number('r');
			swap_number('u');
		}

		printMoveSteps(number);
		print_puzzle();
		cout << endl;

		//keep right going
		number++;

	}


	//The right most number
	//put the blank to the down side first
	swap_number('d');
	//check if it is fit
	if(puzzle[s-width+1][s] == number){
		for(int i=0; i<width-1; i++){
			swap_number('l');
		}
	}
	//try to put the right most number to row(s-width+2) col(s-1)
	else{
		swap_number('l');
		int rowB = s-width+2;
		int colB = s-1;
		//find where the right most number is
		for(pos=0; pos<N; pos++){
			if(puzzle[pos/s +1][pos%s +1] == number)
				break;
		}
		row = pos/s + 1;
		col = pos%s + 1;

		int RD = row - rowB;
		int CD = col - colB;

		if( (RD != 0) && (CD != 0) ){
			//move the blank to the same row as the number
			for(int i=0; i<RD; i++){
				swap_number('d');
			}
			//move the number to the target col,
			//and move the blank to the upside of the number
			if(CD>0){
				swap_number('r');
				swap_number('u');
				swap_number('l');
			}
			//CD<0
			else{
				//move the blank to the right side of the number
				for(int i=0; i>CD+1; i--){
					swap_number('l');
				}
				//move the number to the target col,
				//and move the blank to the upside of the number
				for(int i=0; i>CD+1; i--){
					//do the clockwise |--|
					swap_number('l');
					swap_number('u');
					swap_number('r');
					swap_number('r');
					swap_number('d');
				}
				swap_number('l');
				swap_number('u');
				swap_number('r');
			}

			//move the number to the target row
			for(int i=0; i<RD-1; i++){
				//do the clockwise [
				swap_number('d');
				swap_number('l');
				swap_number('u');
				swap_number('u');
				swap_number('r');
			}
			swap_number('d');
			swap_number('l');
			swap_number('u');
		}
		else if(RD == 0){
			if(CD>0){
				swap_number('r');
				swap_number('d');
				swap_number('l');
				swap_number('l');
				swap_number('u');
			}
			else{
				//move the blank to the right side of the number
				for(int i=0; i>CD+1; i--){
					swap_number('l');
				}
				//move the number and the blank to the target place
				for(int i=0; i>CD+1; i--){
					swap_number('l');
					swap_number('d');
					swap_number('r');
					swap_number('r');
					swap_number('u');
				}
				swap_number('l');
			}
		}
		//CD == 0
		else{
			//move the blank to the upside of the number
			for(int i=0; i<RD-1; i++){
				swap_number('d');
			}
			//put the number and the blank to the target place
			for(int i=0; i<RD-1; i++){
				swap_number('d');
				swap_number('l');
				swap_number('u');
				swap_number('u');
				swap_number('r');
			}
			swap_number('d');
			swap_number('l');
			swap_number('u');
		}


		//now the right most number is at row(s-width+2) col(s-2)
		//and the blank is at the left side
		//put the right most number in
		swap_number('u');
		swap_number('r');
		swap_number('d');
		swap_number('r');
		swap_number('u');
		swap_number('l');
		swap_number('l');
		swap_number('d');

		//move the blank to the left most side
		for(int i=0; i<width-3; i++){
			swap_number('l');
		}
		//finished the upside


	}

	printMoveSteps(number);
	print_puzzle();
	cout << endl;


	/*
	 * now go for the left side
	 */
	number = s*s - (width-2)*s - width+1;

	while(number < s*s-width+1){
		//Find the blank's position
		for(pos=0; pos<N; pos++){
			if(puzzle[pos/s +1][pos%s +1] == N)
				break;
		}
		int rowB = pos/s + 1;
		int colB = pos%s + 1;

		//Find the number's position
		for(pos=0; pos<N; pos++){
			if(puzzle[pos/s +1][pos%s +1] == number)
				break;
		}
		row = pos/s + 1;
		col = pos%s + 1;

		//Find the row's and col's difference between blank and number
		int RD = row - rowB;
		int CD = col - colB;

		if( (row != rowB) && (col != colB) ){
			//move the blank to the same col as the number
			for(int i=0; i<CD; i++){
				swap_number('r');
			}
			//try to move the number to the same row
			if(RD<0){
				//move the blank to the down side of the number
				for(int i=0; i>RD+1; i--){
					swap_number('u');
				}
				//move the number to the same row and move the blank to the left side of the number
				if(col == s){
					for(int i=0; i>RD+1; i--){
						//do counterclockwise [
						swap_number('u');
						swap_number('l');
						swap_number('d');
						swap_number('d');
						swap_number('r');
					}
					swap_number('u');
					swap_number('l');
					swap_number('d');
				}
				else{
					for(int i=0; i>RD; i--){
						//do clockwise ]
						swap_number('u');
						swap_number('r');
						swap_number('d');
						swap_number('d');
						swap_number('l');
					}
					swap_number('l');
					swap_number('u');
				}

			}
			//RD>0
			else{
				//move the blank to the upside of the number
				for(int i=0; i<RD-1; i++){
					swap_number('d');
				}
				//move the number to the target row
				for(int i=0; i<RD-1; i++){
					swap_number('d');
					swap_number('l');
					swap_number('u');
					swap_number('u');
					swap_number('r');
				}
				swap_number('d');
				swap_number('l');
				swap_number('u');
			}

			//now they at the same row
			//move the number inside
			for(int i=0; i<CD-1; i++){
				//do the clockwise|__|
				swap_number('r');
				swap_number('d');
				swap_number('l');
				swap_number('l');
				swap_number('u');
			}
			swap_number('r');
			swap_number('d');
			swap_number('l');
		}
		else if(RD == 0){
			//move the blank to the left side of the number
			for(int i=0; i<CD-1; i++){
				swap_number('r');
			}

			for(int i=0; i<CD-1; i++){
				//do the clockwise |__|
				swap_number('r');
				swap_number('d');
				swap_number('l');
				swap_number('l');
				swap_number('u');
			}
			swap_number('r');
			swap_number('d');
			swap_number('l');
		}
		//CD == 0
		else{
			//move the blank to the upside of the number
			for(int i=0; i<RD-1; i++){
				swap_number('d');
			}

			for(int i=0; i<RD-1; i++){
				//do the counterclockwise ]
				swap_number('d');
				swap_number('r');
				swap_number('u');
				swap_number('u');
				swap_number('l');
			}
			swap_number('d');

		}

		printMoveSteps(number);
		print_puzzle();
		cout << endl;

		//go for the next number
		number+=s;

	}

	/*
	 * try to put the down-left-most number inside
	 */

	swap_number('r');
	//check if it is fit
	if(puzzle[s][s-width+1] == (s*s-width+1) ){
		for(int i=0; i<width-2; i++){
			swap_number('u');
		}


	}
	//if the puzzle is 3*3
	else if(width == 3){
		//try to put the number to row(s) col(s) and the blank to row(s) col(s-1)
		if(puzzle[s-1][s] == number){
			swap_number('r');
			swap_number('u');
			swap_number('l');
			swap_number('d');
		}
		else if(puzzle[s-1][s-1] == number){
			swap_number('u');
			swap_number('r');
			swap_number('d');
			swap_number('l');
		}

		//move the number inside and move the blank to row(s-1) col(s-1)
		swap_number('l');
		swap_number('u');
		swap_number('r');
		swap_number('d');
		swap_number('r');
		swap_number('u');
		swap_number('l');
		swap_number('l');
		swap_number('d');
		swap_number('r');
		swap_number('u');
	}
	//not fit, try to put the number to rol(s-1) col(s-width+2)
	else{
		//move the blank to rol(s-1) col(s-width+2)
		swap_number('u');

		int rowB = s-1;
		int colB = s-width+2;

		//Find the number's position
		for(pos=0; pos<N; pos++){
			if(puzzle[pos/s +1][pos%s +1] == number)
				break;
		}
		row = pos/s + 1;
		col = pos%s + 1;

		//Find the row's and col's difference between blank and number
		int RD = row - rowB;
		int CD = col - colB;

		if( (RD != 0) && (CD != 0) ){
			//move to the same col as the number
			for(int i=0; i<CD; i++){
				swap_number('r');
			}

			if(RD>0){
				swap_number('d');
				swap_number('l');
				swap_number('u');
			}
			else{
				//move blank to the down side of the number
				for(int i=0; i>RD+1; i--){
					swap_number('u');
				}

				//move the number to the target row
				for(int i=0; i>RD+1; i--){
					swap_number('u');
					swap_number('l');
					swap_number('d');
					swap_number('d');
					swap_number('r');
				}
				swap_number('u');
				swap_number('l');
				swap_number('d');
			}

			//now the number is at the target row, move it to the target col
			//and move the blank to row(s=2) col(s-width+2)
			for(int i=0; i<CD-1; i++){
				//do the clockwise |__|
				swap_number('r');
				swap_number('d');
				swap_number('l');
				swap_number('l');
				swap_number('u');
			}
			swap_number('r');
			swap_number('u');
			swap_number('l');
		}
		else if(RD==0){
			//move the blank to the left side of the number
			for(int i=0; i<CD-1; i++){
				swap_number('r');
			}
			//move the number and the blank to the target place
			for(int i=0; i<CD-1; i++){
				//do the clockwise|__|
				swap_number('r');
				swap_number('d');
				swap_number('l');
				swap_number('l');
				swap_number('u');
			}
			swap_number('r');
			swap_number('u');
			swap_number('l');
		}
		//CD == 0
		else{
			if(RD>0){
				swap_number('d');
				swap_number('r');
				swap_number('u');
				swap_number('u');
				swap_number('l');
			}
			else{
				//move the blank to the down side of the number
				for(int i=0; i>RD+1; i--){
					swap_number('u');
				}

				//move the number and the blank to the target place
				for(int i=0; i>RD+1; i--){
					swap_number('u');
					swap_number('r');
					swap_number('l');
					swap_number('l');
					swap_number('d');
				}
				swap_number('u');

			}
		}

		//now the number is at row(s-1) col(s-width+2),
		//and the blank is at the top of the number
		//move the number in, and move the blank to the row(s-width+2) col(s-width+2)
		swap_number('l');
		swap_number('d');
		swap_number('r');
		swap_number('d');
		swap_number('l');
		swap_number('u');
		swap_number('u');
		swap_number('r');

		for(int i=0; i<width-4; i++){
			swap_number('u');
		}


	}

	printMoveSteps(number);
	print_puzzle();
	cout << endl;

	//go for next 「
	if(width == 3){
		Dual();
	}
	else{
		PuzzleStack(width-1);
	}


}


int main() {
	//Input puzzle's size
	cout << "What it your puzzle's size (N x N)? Input N. (1<N<100)" << endl;
	scanf("%d", &size);

	//Input puuzle's numbers
	cout << "Input the puzzle, from left to right, from up to down." << endl;
	cout << "If it is the blank, input " << size*size << "." << endl;
	int puzzle_number;
	for(int i=0; i<size*size; i++){
		cin >> puzzle_number;
		puzzle[i/size +1][i%size +1] = puzzle_number;
	}

	printf("Your puzzle:\n");
	print_puzzle();
	cout << endl;

	//go for solving the puzzle
	if(size == 2)
		Dual();
	else{
		PuzzleStack(size);
	}

	//check if there are any errors in the puzzle.
	if(puzzle[size][size-1] != size*size-1){
		printf("The puzzle has error. Please fix it.\n");
	}
	else{
		printf("Done!\n");
	}



	return 0;
}

