#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "windows.h"
#include <string>

using namespace std;

#define SIDE 3
string player1 = "";
string player2 = "";
int player1Score = 0;
int player2Score = 0;



void dashboard();



void header() {
	system("CLS");
	cout << "---------------------------------------------" << endl;
	cout << "              TIK TOK TOE                    " << endl;
	cout << "---------------------------------------------" << endl;
}


void tie() {
	header();
	player1Score -= 5;
	player2Score -= 5;
	cout << "---------------------------------------------" << endl;
	cout << "             TIE - BOTH LOSE 5 POINTS       " << endl;
	cout << "---------------------------------------------" << endl;
	getch();
	dashboard();
}

void winner(char value) {
	header();

	cout << "---------------------------------------------" << endl;
	if (value == 'O') {
		cout << "           Player 1    BooYEAH!!!!       " << endl;
		player1Score += 5;
		player2Score -= 5;
	} else {
		player1Score -= 5;
		player2Score += 5;
		cout << "           Player 2    BooYEAH!!!!        " << endl;
	}
	cout << "---------------------------------------------" << endl;
	getch();
	dashboard();
}

void playerName() {
	cout << "Player Names" << endl;
	cout << "-----" << endl;

	cout << "Player 1: "; cin >> player1;
	cout << "Player 2: "; cin >> player2;
	system("CLS");
}


void end() {
	system("CLS");
	cout << "\n\n\n\nENDING";
	for (int i = 0; i < 100; ++i)
	{
		Sleep(1);
		cout << "_";
	}
	cout << "BYE :)";
	Sleep(2);
	exit(0);
}



void check(char value, char arr[][SIDE] ) {

	if ((arr[0][0] == value) && (arr[0][1] == value) && arr[0][2] == value) {
		winner(value);
	} else if ((arr[1][0] == value) && (arr[1][1] == value) && arr[1][2] == value) {
		winner(value);
	} else if ((arr[2][0] == value) && (arr[2][1] == value) && arr[2][2] == value) {
		winner(value);
	} else if ((arr[0][0] == value) && (arr[1][0] == value) && arr[2][0] == value) {
		winner(value);
	} else if ((arr[0][1] == value) && (arr[1][1] == value) && arr[2][1] == value) {
		winner(value);
	} else if ((arr[0][2] == value) && (arr[1][2] == value) && arr[2][2] == value) {
		winner(value);
	} else if ((arr[0][0] == value) && (arr[1][1] == value) && arr[2][2] == value) {
		winner(value);
	} else if ((arr[0][2] == value) && (arr[1][1] == value) && arr[2][0] == value) {
		winner(value);
	} else {

		int count = 0;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (arr[i][j] != 'X' && arr[i][j] != 'O') {
					return;
				} else {
					count++;
				}

			}
		}

		if (count == 9)
			tie();

	}



}



bool setInput(char value, int num, char arr[][SIDE]) {

	if (num < 1 && num > 9)
		return false;

	int count = 1;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (num == count) {
				if (arr[i][j] != 'X' && arr[i][j] != 'O') {
					arr[i][j] = value;
					check(value, arr);
					return true;
				} else {
					return false;
				}
			}



			count += 1;

		}
	}

	return false;
}


void print(char arr[3][3]) {
	int row = 3, col = 3;
	bool flag = true;
	int count = 0;
	while (flag) {
		header();
		for (int i = 0; i < row; ++i)
		{
			cout << "\t\t";
			for (int j = 0; j < col; ++j)
			{

				cout << arr[i][j] << ((j == 0 || j == 1) ? " | " : " ");

			}
			if (i < 2) {
				cout << endl << "\t\t---------" << endl;
			}

		}

		cout << "\n---------------------------------------------" << endl;
		int num;
		char value;
		if (count % 2 == 0) {
			cout << "Player 1 (" << player1 << ") : ";
			value = 'O';

		} else {
			cout << "Player 2 (" << player2 << ") : ";
			value = 'X';
		}
		cin >> num;

		if (setInput(value, num, arr)) {
			count += 1;
		}




	}
}



void play() {
	char arr[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};


	bool flag = true;
	while (flag) {
		print(arr);
	}

}

void dashboard() {

	bool flag = true;
	while (flag) {


		header();
		cout << "---------------------------------------------" << endl;
		cout << "                 WELCOME                   " << endl;
		cout << "---------------------------------------------" << endl;
		cout << "Player 1(" << player1 << ") Score: " << player1Score << endl;
		cout << "Player 2(" << player2 << ") Score: " << player2Score << endl;
		cout << "\nMenu" << endl;
		cout << "------" << endl;
		cout << "Press 1 For Start" << endl;
		cout << "Press 2 For Exit" << endl;
		cout << "\n_____________________________";


		cout << "\nEnter Your Choice: ";
		int choice; cin >> choice;
		switch (choice) {
		case 1: play();
			break;
		case 2: end();
			break;
		default:
			cout << "Please Enter Valid Choice" << endl;

		}

	}

}


int main() {
	header();
	playerName();
	dashboard();
	return 0;
}
