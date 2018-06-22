//============================================================================
// Name        : Puzzle_Game.cpp
// Author      : YuTing-Lai
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;

int puzzle[101][101]={{0}};
int size;
int rowB, colB;

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

void shuffle(int x){
	//The numbers decide where the blank go

	//up
	if(x==1){
		if(rowB!=1){
			puzzle[rowB][colB] = puzzle[rowB-1][colB];
			puzzle[rowB-1][colB] = size*size;
			rowB--;
		}
	}
	//down
	else if(x==2){
		if(rowB!=size){
			puzzle[rowB][colB] = puzzle[rowB+1][colB];
			puzzle[rowB+1][colB] = size*size;
			rowB++;
		}
	}
	//left
	else if(x==3){
		if(colB!=1){
			puzzle[rowB][colB] = puzzle[rowB][colB-1];
			puzzle[rowB][colB-1] = size*size;
			colB--;
		}
	}
	//right
	else{
		if(colB!=size){
			puzzle[rowB][colB] = puzzle[rowB][colB+1];
			puzzle[rowB][colB+1] = size*size;
			colB++;
		}
	}
}

int near(int a){
	int N = size*size;
	if( (a>N-1) || (a<1) )
		return 0;

	//up side
	if(puzzle[rowB-1][colB] == a)
		return 1;
	//down side
	else if(puzzle[rowB+1][colB] == a)
		return 2;
	//left side
	else if(puzzle[rowB][colB-1] == a)
		return 3;
	//right side
	else if(puzzle[rowB][colB+1] == a)
		return 4;

	//not near
	return 0;

}

void move(int a){
	//To move the blank's position

	//the blank goes up
	if(a == 1){
		puzzle[rowB][colB] = puzzle[rowB-1][colB];
		puzzle[rowB-1][colB] = size*size;
		rowB--;
	}
	//the blank goes down
	else if(a == 2){
		puzzle[rowB][colB] = puzzle[rowB+1][colB];
		puzzle[rowB+1][colB] = size*size;
		rowB++;
	}
	//the blank goes left
	else if(a == 3){
		puzzle[rowB][colB] = puzzle[rowB][colB-1];
		puzzle[rowB][colB-1] = size*size;
		colB--;
	}
	//the blank goes right
	else if(a == 4){
		puzzle[rowB][colB] = puzzle[rowB][colB+1];
		puzzle[rowB][colB+1] = size*size;
		colB++;
	}
}

bool correct(){
	for(int i=0; i<size*size; i++){
		if(puzzle[i/size +1][i%size +1] != i+1)
			return false;
	}
	return true;
}

int main() {

	srand( time(NULL) );


	size = 0;
	while( (size<2) || (size>99) ){
		cout << "Which size (NxN) do you want to play? Input N. (1<N<100)" << endl;
		scanf("%d",&size);
	}

	for(int i=0; i<size*size; i++){
		puzzle[i/size +1][i%size +1] = i+1;
	}
	rowB = size;
	colB = size;

	//To avoid the puzzle is correct at the first
	while(correct()){
		for(int i=0; i<size*size*1000; i++){
			int x = rand()%4 +1;
			shuffle(x);
		}
	}


	print_puzzle();
	cout << endl;


	int move_number;
	cout << "Enter the number you want to move:" << endl;
	while(scanf("%d",&move_number) != EOF){
		if(near(move_number)){
			move(near(move_number));
		}
		else{
			cout << "error!!" << endl;
		}




		if(puzzle[size][size]== size*size){
			if(correct()){
				print_puzzle();
				cout <<"Finished! Great Job!" << endl;
				break;
			}else{
				cout << "Enter the number you want to move:" << endl;
			}
		}
		else{
			cout << "Enter the number you want to move:" << endl;
		}
		print_puzzle();
	}


	return 0;
}
