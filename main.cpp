#include<iostream>
#include<string>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include"gotoxy.h"
#include"Hide.h"
using namespace std;

//TODO:Add Scoreboard using fstream

struct coord {
	int x;
	int y;
} CurTet;
const int width = 10;
const int height = 20;
int score;
int ticknum = 0;
bool SwapReady = true;
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
				color(7);
			}
		}
	}
}
void tick(){
	Sleep(50);
	ticknum++;
	if(ticknum >= 3000){
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
bool collide(){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(CurrentTetrimino[i][j] != '.' && (grid[CurTet.y - 6 + i][((CurTet.x -1) / 2) + j] != '.' || ((CurTet.x -1) / 2) + j < 0 || ((CurTet.x -1) / 2) + j > 9)){
				return true;
			}
		}
	}
	return false;
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
		if(collide()){
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
		if(collide()){
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
	if(SwapReady){
		DeleteTetrimino();
		CurTet = {7, 6};
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
		SwapReady = false;
	}
}
bool DetectClear(int i){
	for(int j = 0; j < width; j++){
		if(grid[i][j] == '.'){
			return false;
		}
	}
	return true;
}
void ClearLine(){
	int counter = 0;
	for(int i = 0; i < height; i++){
		if(DetectClear(i)){
			counter++;
			for(int j = 0; j < width; j++){
				grid[i][j] = '.';
			}
			for(int j = i; j >= 0; j--){
				for(int k = 0; k < width; k++){
					if(j == 0){
						grid[j][k] = '.';
					}
					else{
						grid[j][k] = grid[j - 1][k];
					}
				}
			}
		}
	}
	switch(counter) {
		case 0:
			score += 0;
			break;
		case 1:
			score += 100;
			break;
		case 2:
			score += 400;
			break;
		case 3:
			score += 800;
			break;
		case 4:
			score += 1600;
			break;
	}
	FillBoard();
	PrintScoreNum();
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
	ClearLine();
	PrintTetrimino();
	SwapReady = true;
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
			if(CurrentTetrimino[i][j] != '.' && (grid[CurTet.y - 6 + i][((CurTet.x -1) / 2) + j + 1] != '.' ||((CurTet.x -1) / 2) + j + 1 >= 10 )){
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
void InstaDrop(){
	DeleteTetrimino();
	while(1){
		if(DownCond()){
			CurTet.y++;
		}
		else{
			PrintTetrimino();
			solidify();
			break;
		}
	}
}
bool Loss(){
	for(int i = 0; i < 3;i++){
		if(grid[i][4] != '.' || grid[i][5] != '.'){
			return true;
		}
	}
	return false;
}
bool cont(){
	char ch;
	do{
		cout << "Do you wish to play again? y/n" << endl;
		ch = getch();
	}while(ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N');
	if(ch == 'y' || ch == 'Y') return true;
	else return false;
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
			InstaDrop();
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
		else if (ch == 27){
			gotoxy(0, 26);
			ShowConsoleCursor(true);
			exit(0);
		}
	}
}
int main(){
	while(1){
		system("cls");
		ShowConsoleCursor(false);
		srand(time(NULL));
		int speed = 20;
		CurTet = {7, 6};
		score = 0;
		
		RandPiece();
		PrintGrid();
		PrintTetrimino();
		PrintScoreNum();
		while(1){
			if(ticknum % speed == 0){
				MoveDown();
				if(Loss()) break;
			}
			kbin();
			tick();
			if(ticknum % 10000 == 0){
				speed--;
				if(speed < 0) speed = 0;
			}
		}
		gotoxy(0, 27);
		ShowConsoleCursor(true);
		cout << "You lost!\nYour Score Was " << score << endl;
		if(!cont()) break;
		for(int i = 0; i < height; i++){
			for(int j = 0; j < width; j++){
				grid[i][j] = '.';
			}
		}
	}
	return 0;
}
