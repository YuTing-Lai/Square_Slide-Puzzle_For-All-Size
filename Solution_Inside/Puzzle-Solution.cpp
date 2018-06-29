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
#include <vector>
using namespace std;

int puzzle[101][101]={{0}};
queue<string> move_step;
vector< pair<int, int> > number_pos;
int rowB,colB; //the blank's row and column
int row,col,RD,CD;
int pos;
int size;
int number;
int total_numbers;

void printMoveSteps(int n){
	int nextLine = 1;
	if(n == size*size){
		printf("Move the blank:\n");
	}
	else if(n == size*size - size - 1){
		printf("Move %d and the blank:\n", n);
	}
	else{
		printf("Move %d:\n",n);
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
	int length = log10(total_numbers) + 2;
	for(int i=1; i<=size; i++){
		for(int j=1; j<=size; j++){
			if(puzzle[i][j] == total_numbers)
				cout << setw(length) << " " << " ";
			else
			cout << setw(length) << puzzle[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void swap_number(char mode){

	switch(mode)
	{
		case 'u':
			puzzle[rowB][colB] = puzzle[rowB-1][colB];
			puzzle[rowB-1][colB] = total_numbers;
			number_pos[puzzle[rowB][colB]].first++;
			rowB--;
			move_step.push("down");
			break;
		case 'd':
			puzzle[rowB][colB] = puzzle[rowB+1][colB];
			puzzle[rowB+1][colB] = total_numbers;
			number_pos[puzzle[rowB][colB]].first--;
			rowB++;
			move_step.push("up");
			break;
		case 'l':
			puzzle[rowB][colB] = puzzle[rowB][colB-1];
			puzzle[rowB][colB-1] = total_numbers;
			number_pos[puzzle[rowB][colB]].second++;
			colB--;
			move_step.push("right");
			break;
		case 'r':
			puzzle[rowB][colB] = puzzle[rowB][colB+1];
			puzzle[rowB][colB+1] = total_numbers;
			number_pos[puzzle[rowB][colB]].second--;
			colB++;
			move_step.push("left");
			break;
	}


}

void find_the_blank(){
	rowB = number_pos[total_numbers].first;
	colB = number_pos[total_numbers].second;

}

void find_the_number(int n){
	row = number_pos[n].first;
	col = number_pos[n].second;
}

void cw_down(){
	//clockwise ㄇ
	swap_number('l');
	swap_number('u');
	swap_number('r');
	swap_number('r');
	swap_number('d');
}

void ccw_down(){
	//counterclockwise ㄇ
	swap_number('r');
	swap_number('u');
	swap_number('l');
	swap_number('l');
	swap_number('d');
}

void cw_up(){
	//clockwise ㄩ
	swap_number('r');
	swap_number('d');
	swap_number('l');
	swap_number('l');
	swap_number('u');
}

void ccw_up(){
	//counterclockwise ㄩ
	swap_number('l');
	swap_number('d');
	swap_number('r');
	swap_number('r');
	swap_number('u');
}

void cw_left(){
	//clockwise ]
	swap_number('u');
	swap_number('r');
	swap_number('d');
	swap_number('d');
	swap_number('l');
}

void ccw_left(){
	//counterclockwise ]
	swap_number('d');
	swap_number('r');
	swap_number('u');
	swap_number('u');
	swap_number('l');
}

void cw_right(){
	//clockwise [
	swap_number('d');
	swap_number('l');
	swap_number('u');
	swap_number('u');
	swap_number('r');
}

void ccw_right(){
	//counterclockwise [
	swap_number('u');
	swap_number('l');
	swap_number('d');
	swap_number('d');
	swap_number('r');
}

void Dual(){
	number = size*size-size-1;

	//if the puzzle size is 2x2
	if(size == 2){

		//put the blank to the left-up-most of the small puzzle
		if(rowB == size)
			swap_number('u');
		if(colB == size)
			swap_number('l');
	}

	find_the_number(number);

	if( (col == size) && (row == size-1) ){
		swap_number('r');
		swap_number('d');
	}
	else if( (col == size-1) && (row == size) ){
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

	printMoveSteps(number);
	print_puzzle();

}




void segmentOne(int width){
	//The first number
	number = size*size - (width-1)*size -(width-1);

	while(number < (size*size - (width-1)*size)){

		//Find the number's position
		find_the_number(number);

		//Find the row's and col's difference between blank and number
		RD = row - rowB;
		CD = col - colB;

		if( (RD != 0) && (CD != 0) ){
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
					//do the counterclockwise ㄇ
					ccw_down();
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

				if(row == size){
					for(int i=0; i>CD+1; i--){
						//do the clockwise ㄇ
						cw_down();
					}
					swap_number('l');
					swap_number('u');
					swap_number('r');

				}
				else{
					for(int i=0; i>CD; i--){
						//do the counterclockwise ㄩ
						ccw_up();
					}
					swap_number('u');
					swap_number('l');
				}

			}
			//now the number is at colB, and the blank is on the upside of the number
			for(int i=0; i<RD-1; i++){
				// do the counterclockwise ]
				ccw_left();
			}
			swap_number('d');
			swap_number('r');
			swap_number('u');
		}
		else if(RD == 0){
			//move the blank to the left side of the number
			for(int i=0; i<CD-1; i++){
				swap_number('r');
			}
			for(int i=0; i<CD-1; i++){
				//do the clockwise ㄩ
				cw_up();
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
				//do the counterclockwise ]
				ccw_left();
			}
			swap_number('d');
			swap_number('r');
			swap_number('u');
		}

		printMoveSteps(number);
		print_puzzle();

		//keep right going
		number++;

	}

}


void segmentTwo(int width){
	//The right most number
	//put the blank to the down side first
	swap_number('d');
	//check if it is fit
	if(puzzle[size-width+1][size] == number){
		for(int i=0; i<width-1; i++){
			swap_number('l');
		}
	}
	//try to put the right most number to row(s-width+2) col(s-1)
	else{
		swap_number('l');
		rowB = size-width+2;
		colB = size-1;
		//find where the right most number is
		find_the_number(number);

		RD = row - rowB;
		CD = col - colB;

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
					//do the clockwise ㄇ
					cw_down();
				}
				swap_number('l');
				swap_number('u');
				swap_number('r');
			}

			//move the number to the target row
			for(int i=0; i<RD-1; i++){
				//do the clockwise [
				cw_right();
			}
			swap_number('d');
			swap_number('l');
			swap_number('u');
		}
		else if(RD == 0){
			if(CD>0){
				//do the clockwise ㄩ
				cw_up();
			}
			else{
				//move the blank to the right side of the number
				for(int i=0; i>CD+1; i--){
					swap_number('l');
				}
				//move the number and the blank to the target place
				for(int i=0; i>CD+1; i--){
					//do the counterclockwise ㄩ
					ccw_up();
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
				//do the clockwise [
				cw_right();
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


}


void segmentThree(int width){
	number = size*size - (width-2)*size - width+1;

	while(number < size*size-width+1){

		//Find the number's position
		find_the_number(number);


		//Find the row's and col's difference between blank and number
		RD = row - rowB;
		CD = col - colB;

		if( (RD != 0) && (CD != 0) ){
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
				if(col == size){
					for(int i=0; i>RD+1; i--){
						//do counterclockwise [
						ccw_right();
					}
					swap_number('u');
					swap_number('l');
					swap_number('d');
				}
				else{
					for(int i=0; i>RD; i--){
						//do clockwise ]
						cw_left();
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
					//do the clockwise [
					cw_right();
				}
				swap_number('d');
				swap_number('l');
				swap_number('u');
			}

			//now they at the same row
			//move the number inside
			for(int i=0; i<CD-1; i++){
				//do the clockwise ㄩ
				cw_up();
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
				//do the clockwise ㄩ
				cw_up();
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
				ccw_left();
			}
			swap_number('d');

		}

		printMoveSteps(number);
		print_puzzle();

		//go for the next number
		number+=size;

	}

}

void segmentFour(int width){
	swap_number('r');
	//check if it is fit
	if(puzzle[size][size-width+1] == (number) ){
		for(int i=0; i<width-2; i++){
			swap_number('u');
		}
	}
	//if the puzzle is 3*3
	else if(width == 3){
		//try to put the number to row(s) col(s) and the blank to row(s) col(s-1)
		if(puzzle[size-1][size] == number){
			swap_number('r');
			swap_number('u');
			swap_number('l');
			swap_number('d');
		}
		else if(puzzle[size-1][size-1] == number){
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


		//Find the number's position
		find_the_number(number);

		//Find the row's and col's difference between blank and number
		RD = row - rowB;
		CD = col - colB;

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
					//do the counterclockwise [
					ccw_right();
				}
				swap_number('u');
				swap_number('l');
				swap_number('d');
			}

			//now the number is at the target row, move it to the target col
			//and move the blank to row(s=2) col(s-width+2)
			for(int i=0; i<CD-1; i++){
				//do the clockwise ㄩ
				cw_up();
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
				//do the clockwise ㄩ
				cw_up();
			}
			swap_number('r');
			swap_number('u');
			swap_number('l');
		}
		//CD == 0
		else{
			if(RD>0){
				//do the counterclockwise ]
				ccw_left();
			}
			else{
				//move the blank to the down side of the number
				for(int i=0; i>RD+1; i--){
					swap_number('u');
				}

				//move the number and the blank to the target place
				for(int i=0; i>RD+1; i--){
					//do the clockwise ]
					cw_left();
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

}

void PuzzleStack(int width){



	if(width == size){

		row = rowB-1;
		col = colB-1;

		//move the blank to the left-up-most side of the puzzle
		for(int i=0; i<row; i++){
			swap_number('u');
		}
		for(int i=0; i<col; i++){
			swap_number('l');
		}

		printMoveSteps(total_numbers);
		print_puzzle();
	}


	segmentOne(width);

	segmentTwo(width);

	segmentThree(width);

	segmentFour(width);

	//go for the rest puzzle
	if(width == 3){
		Dual();
	}
	else{
		PuzzleStack(width-1);
	}

}


int main() {
	size=0;
	//Input puzzle's size
	while(size<2 || size>99){
		cout << "What it your puzzle's size (N x N)? Input N. (1<N<100)" << endl;
		scanf("%d", &size);
	}
	total_numbers = size*size;

	number_pos.resize(total_numbers+1);


	//Input puuzle's numbers
	cout << "Input the puzzle, from left to right, from up to down." << endl;
	cout << "If it is the blank, input " << size*size << "." << endl;
	int puzzle_number;
	pair<int,int> ppos;
	for(int i=0; i<size*size; i++){
		cin >> puzzle_number;
		puzzle[i/size +1][i%size +1] = puzzle_number;
		ppos.first = i/size +1;
		ppos.second = i%size +1;
		number_pos[puzzle_number] = ppos;
	}

	find_the_blank();


	printf("Your puzzle:\n");
	print_puzzle();

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
