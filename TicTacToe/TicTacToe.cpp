#include <iostream>
using namespace std;
class TicTacToe {
private:
    char currentPlayer;
    char Table[3][3];
    char def;
    bool fwin = false;

    void resTable() {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                Table[i][j] = '.';
            }
        }
    }
public:
    TicTacToe(char _start = 'x')
    {
        if (_start == '0') {
            currentPlayer = _start;
            def = _start;
        }
        else {
            currentPlayer = 'x';
            def = 'x';
        }

        resTable();
    }

    bool isWin() {
        for (int i = 0; i < 3; i++) {
            if (Table[i][0] == currentPlayer && Table[i][1] == currentPlayer && Table[i][2] == currentPlayer) return true;
            if (Table[0][i] == currentPlayer && Table[1][i] == currentPlayer && Table[2][i] == currentPlayer) return true;
        }
        if (Table[0][0] == currentPlayer && Table[1][1] == currentPlayer && Table[2][2] == currentPlayer) return true;
        if (Table[0][2] == currentPlayer && Table[1][1] == currentPlayer && Table[2][0] == currentPlayer) return true;
        return false;
    }

    bool isDraw() {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (Table[i][j] == '.') return false;
            }
        }
        return true;
    }

    void make_to_move(int r, int c) {
        int col = c - 1;
        int row = r - 1;
        if (row < 0 || row > 2 || col < 0 || col > 2 || Table[row][col] != '.' || fwin) {
            cout << "Ход не может быть выполнен" << endl;
            return;
        }
        else {
            Table[row][col] = currentPlayer;
        }

        if (isWin()) {
            cout << "Победитель - " << (char)toupper(currentPlayer) << endl;
            fwin = true;
            return;
        }

        if (isDraw()) {
            cout << "Ничья" << endl;
            fwin = true;
            return;
        }

        currentPlayer = (currentPlayer == 'x') ? '0' : 'x';
    }
    void show_table() {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << Table[i][j];
            }
            cout << endl;
        }
    }
    void restart() {
        resTable();
        fwin = false;
        currentPlayer = def;
    }
};