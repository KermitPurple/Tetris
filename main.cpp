#include<iostream>
#include<string>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include"gotoxy.h"
using namespace std;

//TODO: add collision on walls and floor.
//TODO: Clear full lines
//TODO: Tetris music

struct coord {
	int x;
	int y;
} CurTet;
const int width = 10;
const int height = 20;
int score = 0;
int ticknum = 0;
string CurrentTetrimino[4] = {
	"xxxx",
	"xxxx",
	"xxxx",
	"xxxx",
};
string hold[4] = {
	"....",
	"....",
	"....",
	"....",
};
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
		".L..",
		".L..",
		".LL.",
	},
	{
		"....",
		"..J.",
		"..J.",
		".JJ.",
	},
};
char grid[height][width] = {
	{'.','.','.','.','.','.','.','.','.','.'},
	{'.','.','.','.','.','.','.','.','.','.'},
	{'.','.','.','.','.','.','.','.','.','.'},
	{'.','.','.','.','.','.','.','.','.','.'},
	{'.','.','.','.','.','.','.','.','.','.'},
	{'.','.','.','.','.','.','.','.','.','.'},
	{'.','.','.','.','.','.','.','.','.','.'},
	{'.','.','.','.','.','.','.','.','.','.'},
	{'.','.','.','.','.','.','.','.','.','.'},
	{'.','.','.','.','.','.','.','.','.','.'},
	{'.','.','.','.','.','.','.','.','.','.'},
	{'.','.','.','.','.','.','.','.','.','.'},
	{'.','.','.','.','.','.','.','.','.','.'},
	{'.','.','.','.','.','.','.','.','.','.'},
	{'.','.','.','.','.','.','.','.','.','.'},
	{'.','.','.','.','.','.','.','.','.','.'},
	{'.','.','.','.','.','.','.','.','.','.'},
	{'.','.','.','.','.','.','.','.','.','.'},
	{'.','.','.','.','.','.','.','.','.','.'},
	{'.','.','.','.','.','.','.','.','.','.'},
};
void color(int c){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void ColorSel(char ch){
	switch (ch) {
		case 'I':
			color(3);
			break;
		case 'S':
			color(4);
			break;
		case 'Z':
			color(2);
			break;
		case 'T':
			color(13);
			break;
		case 'O':
			color(14);
			break;
		case 'L':
			color(6);
			break;
		case 'J':
			color(12);
			break;
		default: 
			color(7);
			break;
	}
}
void FillBoard(){

	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			gotoxy(1 + 2 * j, 6 + i);
			if(grid[i][j] == '.'){
				cout << "  ";
			}
			else{
				ColorSel(grid[i][j]);
				cout << char(219) << char(219);
			}
		}
	}
}
void tick(){
	Sleep(50);
	ticknum++;
	if(ticknum >= 100000){
		ticknum = 0;
	}
}
void PrintScore(){
	gotoxy(1, 1);
	cout << "Score:";
}
void PrintGrid(){
	int g[27][13] = {
		{ 201, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 187},
		{ 186, 32, 32, 32, 32, 32, 32, 186, 32, 32, 32, 32, 186},
		{ 186, 32, 32, 32, 32, 32, 32, 186, 32, 32, 32, 32, 186},
		{ 186, 32, 32, 32, 32, 32, 32, 186, 32, 32, 32, 32, 186},
		{ 186, 32, 32, 32, 32, 32, 32, 186, 32, 32, 32, 32, 186},
		{ 204, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 185},
		{ 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
		{ 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
		{ 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
		{ 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
		{ 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
		{ 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
		{ 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
		{ 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
		{ 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
		{ 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
		{ 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
		{ 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
		{ 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
		{ 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
		{ 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
		{ 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
		{ 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
		{ 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
		{ 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
		{ 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
		{ 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188},
	};
	for(int i = 0; i < 27; i++) {
		for(int j = 0; j < 13; j++) {
			if( j == 0 || j == 12 || j == 6 || j == 7)
				cout << char(g[i][j]);
			else cout << char(g[i][j]) << char(g[i][j]);
		}
		cout << endl;
	}
	PrintScore();
}
void PrintHold(){
	coord h = {13, 1};
	for(int i = 0; i < 4; i++){
		for(int  j = 0; j < 4; j++){
			gotoxy(h.x + 2*j, h.y +  i);
			if(hold[i][j] == '.'){
				cout << "  ";
			}
			else {
				ColorSel(hold[i][j]);
				cout << char(219) << char(219);
				color(7);
			}
		}
	}
}
void PrintScoreNum(){
	gotoxy(1, 2);
	cout << score;
}
void PrintTetrimino(){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			gotoxy(CurTet.x + 2 * j, CurTet.y + i);
			if(CurrentTetrimino[i][j] != '.'){
				ColorSel(CurrentTetrimino[i][j]);
				cout << char(219) << char(219);
				color(7);
			}
		}
	}
}
void DeleteTetrimino(){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			gotoxy(CurTet.x + 2 * j, CurTet.y + i);
			if(CurrentTetrimino[i][j] != '.'){
				cout << "  ";
			}
		}
	}
}
void rotate(char c){
	string temp[4];
	DeleteTetrimino();
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
	PrintTetrimino();
}
void RandPiece(){
	int random = rand() % 7;
	for(int i = 0; i < 4; i++){
		CurrentTetrimino[i] = Tetrimino[random][i];
	}
}
void swap(){
	DeleteTetrimino();
	bool empty = true;
	string temp[4];
	for(int i = 0; i < 4; i++){
		temp[i] = hold[i];
		hold[i] = CurrentTetrimino[i];
		CurrentTetrimino[i] = temp[i];
		if(CurrentTetrimino[i] != "...."){
			empty = false;
		}
	}
	if (empty){
		RandPiece();
	}
	PrintHold();
	PrintTetrimino();
}
void solidify(){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(CurrentTetrimino[i][j] != '.'){ 
				grid[CurTet.y - 7 + i + 1][((CurTet.x -1) / 2) + j] = CurrentTetrimino[i][j];
			}
		}
	}
	CurTet = { 7, 6};
	RandPiece();
}
bool LeftCond(){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(CurrentTetrimino[i][j] != '.' && (grid[CurTet.y - 6 + i][((CurTet.x -1) / 2) + j - 1] != '.' || ((CurTet.x -1) / 2) + j - 1 < 0 )){
				return false;
			}
		}
	}
	return true;	
}
bool RightCond(){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(CurrentTetrimino[i][j] != '.' && grid[CurTet.y - 6 + i][((CurTet.x -1) / 2) + j + 1] != '.'){
				return false;
			}
		}
	}
	return true;
}
bool DownCond(){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(CurrentTetrimino[i][j] != '.' && grid[CurTet.y - 6 + i + 1][((CurTet.x -1) / 2) + j] != '.'){
				return false;
			}
		}
	}
	return true;
}
void MoveLeft(){
	if(LeftCond()){
		DeleteTetrimino();
		CurTet.x -= 2;
		PrintTetrimino();
	}
}
void MoveRight(){
	if(RightCond()){
		DeleteTetrimino();
		CurTet.x += 2;
		PrintTetrimino();
	}
}
void MoveDown(){
	if(DownCond()){
		DeleteTetrimino();
		CurTet.y++;
		PrintTetrimino();
	}
	else solidify();
}
void kbin(){
	if(kbhit()){
		char ch;
		ch = getch();
		if(ch == 'q'){
			rotate('l');
		}
		else if(ch == 'e'){
			rotate('r');
		}
		else if(ch == 'w'){
			solidify();
		}
		else if(ch == 'a'){
			MoveLeft();
		}
		else if(ch == 's'){
			MoveDown();
		}
		else if(ch == 'd'){
			MoveRight();
		}
		else if(ch == ' '){
			swap();
		}
		else if(ch == 'r'){
			FillBoard();
		}
	}
}
int main(){
	system("cls");
	srand(time(NULL));
	int speed = 20;
	CurTet = {7, 6};
	
	RandPiece();
	PrintGrid();
      	PrintTetrimino();
	PrintScoreNum();
	while(1){
		if(ticknum % speed == 0){
			MoveDown();
		}
		kbin();
		tick();
	}
	gotoxy(0, 26);

	return 0;
}
