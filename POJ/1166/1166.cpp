#include <iostream>
using namespace std;
const int move[9][9] = {
{1, 1, 0, 1, 1, 0, 0, 0, 0},// 1th move
{1, 1, 1, 0, 0, 0, 0, 0, 0},// 2th move
{0, 1, 1, 0, 1, 1, 0, 0, 0},// 3th move
{1, 0, 0, 1, 0, 0, 1, 0, 0},// 4th move
{0, 1, 0, 1, 1, 1, 0, 1, 0},// 5th move
{0, 0, 1, 0, 0, 1, 0, 0, 1},// 6th move
{0, 0, 0, 1, 1, 0, 1, 1, 0},// 7th move
{0, 0, 0, 0, 0, 0, 1, 1, 1},// 8th move
{0, 0, 0, 0, 1, 1, 0, 1, 1} // 9th move
};
int solution[9];
int clocks[9];

bool isOk() {
	for(int i=0; i<9; i++) {
		int temp = clocks[i];
		for(int j=0; j<9; j++) {
			temp = clocks[i] + solution[j]*move[j][i];
			temp = temp%4;
		}
		if(temp!=0)
			return false;
	}
	return true;
}

bool dfs(int depth) {
	if(depth==9)
		return false;
	if(isOk()) 
		return true;
	for(int i=0; i<4; i++) {
		solution[depth] = i;
		if(dfs(depth+1)) {
			return true;
			break;
		}
	}
	solution[depth] = 0;
	return false;
}

int main () {
	for(int i=0; i<9; i++)
		cin >> clocks[i];
	dfs(0);
	for(int i=0; i<9; i++) {
		for(int j=0; j<solution[i]; j++) 
			cout << i+1 << " ";
		
	}
}
