#include <iostream>
using namespace std;

char ar[3][3] = { { '1','2','3' },{ '4','5','6' },{ '7','8','9' } };
char pl = 'X';//pl stands for player
int ro, col;// ro = row & col = column
bool draw = false;

void gameBoard() {
	system("cls");
	cout << "T I C  T A C  T O E  GAME" << endl;
	cout << "\tPlayer 1 [X]  ^_^" << endl;
	cout << "\tPlayer 2 [O]  ^_^" << endl << endl;
	cout << "\t\t     |     |     " << endl;
	cout << "\t\t  " << ar[0][0] << "  |  " << ar[0][1] << "  |  " << ar[0][2] << "  " << endl;
	cout << "\t\t_____|_____|_____" << endl;
	cout << "\t\t     |     |     " << endl;
	cout << "\t\t  " << ar[1][0] << "  |  " << ar[1][1] << "  |  " << ar[1][2] << "  " << endl;
	cout << "\t\t_____|_____|_____" << endl;
	cout << "\t\t     |     |     " << endl;
	cout << "\t\t  " << ar[2][0] << "  |  " << ar[2][1] << "  |  " << ar[2][2] << "  " << endl;
	cout << "\t\t     |     |     " << endl;


}

void playerTurn() {
	int in; //in stands for input ^_^;
	if (pl == 'X')
		cout << "\tPlayer 1 turn:";
	if (pl == 'O')
		cout << "\tPlayer 2 turn:";
	cin >> in;

	switch (in) {
	case 1: ro = 0; col = 0; break;
	case 2: ro = 0; col = 1; break;
	case 3: ro = 0; col = 2; break;
	case 4: ro = 1; col = 0; break;
	case 5: ro = 1; col = 1; break;
	case 6: ro = 1; col = 2; break;
	case 7: ro = 2; col = 0; break;
	case 8: ro = 2; col = 1; break;
	case 9: ro = 2; col = 2; break;
	default:
		cout << "You have entered an invalid number.Enter a known number, Please. ^_^" << endl;
		break;
	}

	if (pl == 'X' && ar[ro][col] != 'X' && ar[ro][col] != 'O')
	{
		ar[ro][col] = 'X';
		pl = 'O';
	}
	else if (pl == 'O' && ar[ro][col] != 'X' && ar[ro][col] != 'O')
	{
		ar[ro][col] = 'O';
		pl = 'X';
	}
	else{
		cout << "Already Filled." << endl;
	playerTurn();
}
	gameBoard();

}

bool gameEnd() {
	for (int i = 0;i < 3;i++)
	if (ar[i][0] == ar[i][1] && ar[i][0] == ar[i][2] || ar[0][i] == ar[1][i] && ar[0][i] == ar[2][i])
	return false;
	if (ar[0][0] == ar[1][1] && ar[0][0] == ar[2][2] || ar[0][2] == ar[1][1] && ar[0][0] == ar[2][0])
	return false;
	for (int i = 0;i < 3;i++)
	for (int j = 0;j < 3;j++)
	if (ar[i][j] != 'X' && ar[i][j] != 'O')
	return true;
	draw = true;
	return false;
	

}

main()
{

	while (gameEnd()) {

		gameBoard();
		playerTurn();
		gameEnd();
	}

	if(pl == 'X')
	cout << "Player 2 wins. Game Over." << endl;
	if(pl == 'O')
	cout << "Player 1 wins. Game Over." << endl;
	

}
