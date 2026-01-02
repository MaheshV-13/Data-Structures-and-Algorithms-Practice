#include <iostream>
using namespace std;

void printBoard(char board[3][3]) {
    cout << "\nTic-Tac-Toe Board:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWin(char board[3][3], char player) {

    for (int i = 0; i < 3; i++)
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;

    for (int j = 0; j < 3; j++)
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return true;

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

int main() {
    char board[3][3];
    int position = 1;

    for (int i = 0; i < 3; i++) {
    	for (int j = 0; j < 3; j++) {
    		board[i][j] = '0' + position++;
		}    
	}
        
    char player = 'X';

    for (int turn = 0; turn < 9; turn++) {
        printBoard(board);

        int move;
        cout << "Player " << player << ", enter your move (1-9): ";
        cin >> move;

        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        board[row][col] = player;

        if (checkWin(board, player)) {
            printBoard(board);
            cout << "Player " << player << " wins!\n";
            return 0;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    printBoard(board);
    cout << "It's a draw!\n";
    return 0;
}

