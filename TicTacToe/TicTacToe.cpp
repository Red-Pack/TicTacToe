#include <iostream>
using namespace std;

class TicTacToe {
private:
    static const int SIZE = 3;
    static const char EMPTY_CELL = '.';
    static const char PLAYER_X = 'x';
    static const char PLAYER_O = '0';

    char currentPlayer;
    char Table[SIZE][SIZE];
    char defaultPlayer;
    bool gameWon = false;

    void resetTable() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                Table[i][j] = EMPTY_CELL;
            }
        }
    }

    bool isMoveValid(int row, int col) {
        return row >= 0 && row < SIZE && col >= 0 && col < SIZE && Table[row][col] == EMPTY_CELL;
    }

    bool checkWinCondition() {
        for (int i = 0; i < SIZE; i++) {
            if ((Table[i][0] == currentPlayer && Table[i][1] == currentPlayer && Table[i][2] == currentPlayer) ||
                (Table[0][i] == currentPlayer && Table[1][i] == currentPlayer && Table[2][i] == currentPlayer)) {
                return true;
            }
        }
        return (Table[0][0] == currentPlayer && Table[1][1] == currentPlayer && Table[2][2] == currentPlayer) ||
            (Table[0][2] == currentPlayer && Table[1][1] == currentPlayer && Table[2][0] == currentPlayer);
    }

public:
    TicTacToe(char startPlayer = PLAYER_X) {
        if (startPlayer == PLAYER_O) {
            currentPlayer = startPlayer;
            defaultPlayer = startPlayer;
        }
        else {
            currentPlayer = PLAYER_X;
            defaultPlayer = PLAYER_X;
        }
        resetTable();
    }

    bool isWin() {
        return checkWinCondition();
    }

    bool isDraw() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (Table[i][j] == EMPTY_CELL) {
                    return false;
                }
            }
        }
        return true;
    }

    void makeMove(int row, int col) {
        int actualRow = row - 1;
        int actualCol = col - 1;

        if (!isMoveValid(actualRow, actualCol) || gameWon) {
            cout << "Ход не может быть выполнен" << endl;
            return;
        }

        Table[actualRow][actualCol] = currentPlayer;

        if (isWin()) {
            cout << "Победитель - " << (char)toupper(currentPlayer) << endl;
            gameWon = true;
            return;
        }

        if (isDraw()) {
            cout << "Ничья" << endl;
            gameWon = true;
            return;
        }

        currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    void showTable() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                cout << Table[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }

    void restart() {
        resetTable();
        gameWon = false;
        currentPlayer = defaultPlayer;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    TicTacToe game;
    game.showTable();
    game.makeMove(1, 1);
    game.showTable();
    game.makeMove(1, 2);
    game.showTable();
    game.makeMove(2, 2);
    game.showTable();
    game.makeMove(1, 3);
    game.showTable();
    game.makeMove(3, 3);
    game.showTable();
    return 0;
}