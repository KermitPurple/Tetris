#include<iostream>
#include<string>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include"gotoxy.h"
using namespace std;

const int width = 10;
const int height = 20;

int ticknum = 0;

struct coord {
	int x;
	int y;
};

string CurrentTetrimino[4];

////////////Peices////////////
const string Tetrimino[][4] = {
	{
		".I..",
		".I..",
		".I..",
		".I..",
	},
	{
		"....",
		".S..",
		".SS.",
		"..S.",
	},
	{
		"....",
		"..Z.",
		".ZZ.",
		".Z..",
	},
	{
		"....",
		"..T.",
		".TT.",
		"..T.",
	},
	{
		"....",
		".OO.",
		".OO.",
		"....",
	},
	{
		"....",
		".l..",
		".l..",
		".ll.",
	},
	{
		"....",
		"..J.",
		"..J.",
		".JJ.",
	},
};

////////////Grid///////////
int grid[height][width] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
};

void tick(){
	Sleep(50);
	ticknum++;
	if(ticknum >= 100000){
		ticknum = 0;
	}
	
}


void PrintGrid(){
	int g[14][12] = {
		{ 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187},
		{ 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
		{ 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185},
		{ 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
		{ 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
		{ 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
		{ 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
		{ 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
		{ 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
		{ 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
		{ 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
		{ 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
		{ 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
		{ 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188},
	};
	for(int i = 0; i < 14; i++) {
		for(int j = 0; j < 12; j++) {
			if( j == 0 || j == 11)
				cout << char(g[i][j]);
			else cout << char(g[i][j]) << char(g[i][j]);
		}
		cout << endl;
	}
}

void rotate(char c){
	string temp[4];
	if(c == 'r'){
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4;j++){
				temp[i][j] = CurrentTetrimino[3 - j][i];
			}
		}
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				CurrentTetrimino[i][j] = temp[i][j];
			}
		}
	}
	else if(c == 'l'){
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4;j++){
				temp[i][j] = CurrentTetrimino[j][3 - i];
			}
		}
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				CurrentTetrimino[i][j] = temp[i][j];
			}
		}
	}
}

void swap(){
}

void RandPiece(){
	int random = rand() % 7;
	for(int i = 0; i < 4; i++){
		CurrentTetrimino[i] = Tetrimino[random][i];
	}
}

void kbin(){
	if(kbhit()){
		char ch;
		ch = getch();
		if(ch == 'q'){
			rotate('r');
		}
		else if(ch == 'e'){
			rotate('l');
		}
		else if(ch == 'w'){
		}
		else if(ch == 'a'){
		}
		else if(ch == 's'){
		}
		else if(ch == 'd'){
		}
		else if(ch == ' '){
			swap();
		}
	}
}

int main(){
	srand(time(NULL));

	return 0;
}
