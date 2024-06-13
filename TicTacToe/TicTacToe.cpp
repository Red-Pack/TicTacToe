#include <iostream>
using namespace std;

/**
 * @brief Класс TicTacToe реализует игру "Крестики-нолики".
 */
class TicTacToe {
private:
    static const int SIZE = 3; ///< Размер игрового поля (3x3).
    static const char EMPTY_CELL = '.'; ///< Символ, обозначающий пустую ячейку.
    static const char PLAYER_X = 'x'; ///< Символ игрока X.
    static const char PLAYER_O = '0'; ///< Символ игрока O.

    char currentPlayer; ///< Текущий игрок.
    char Table[SIZE][SIZE]; ///< Игровое поле.
    char defaultPlayer; ///< Игрок, который начинает игру.
    bool gameWon = false; ///< Флаг, показывающий, завершена ли игра.

    /**
     * @brief Сбрасывает игровое поле до начального состояния.
     */
    void resetTable() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                Table[i][j] = EMPTY_CELL;
            }
        }
    }

    /**
     * @brief Проверяет, является ли указанная строка выигрышной.
     * @param row Номер строки.
     * @return true, если строка выигрышная, иначе false.
     */
    bool isRowWin(int row) {
        return Table[row][0] == currentPlayer && Table[row][1] == currentPlayer && Table[row][2] == currentPlayer;
    }

    /**
     * @brief Проверяет, является ли указанный столбец выигрышным.
     * @param col Номер столбца.
     * @return true, если столбец выигрышный, иначе false.
     */
    bool isColWin(int col) {
        return Table[0][col] == currentPlayer && Table[1][col] == currentPlayer && Table[2][col] == currentPlayer;
    }

    /**
     * @brief Проверяет, является ли одна из диагоналей выигрышной.
     * @return true, если одна из диагоналей выигрышная, иначе false.
     */
    bool isDiagonalWin() {
        bool leftToRight = Table[0][0] == currentPlayer && Table[1][1] == currentPlayer && Table[2][2] == currentPlayer;
        bool rightToLeft = Table[0][2] == currentPlayer && Table[1][1] == currentPlayer && Table[2][0] == currentPlayer;
        return leftToRight || rightToLeft;
    }

    /**
     * @brief Проверяет условие победы.
     * @return true, если текущий игрок выиграл, иначе false.
     */
    bool checkWinCondition() {
        for (int i = 0; i < SIZE; i++) {
            if (isRowWin(i) || isColWin(i)) {
                return true;
            }
        }
        return isDiagonalWin();
    }

    /**
     * @brief Проверяет, является ли ход валидным.
     * @param row Номер строки.
     * @param col Номер столбца.
     * @return true, если ход валидный, иначе false.
     */
    bool isMoveValid(int row, int col) {
        return row >= 0 && row < SIZE && col >= 0 && col < SIZE && Table[row][col] == EMPTY_CELL;
    }

public:
    /**
     * @brief Конструктор класса TicTacToe.
     * @param startPlayer Игрок, который начинает игру. По умолчанию 'x'.
     */
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

    /**
     * @brief Проверяет, выиграл ли текущий игрок.
     * @return true, если текущий игрок выиграл, иначе false.
     */
    bool isWin() {
        return checkWinCondition();
    }

    /**
     * @brief Проверяет, завершилась ли игра вничью.
     * @return true, если игра завершилась вничью, иначе false.
     */
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

    /**
     * @brief Делает ход в указанную ячейку.
     * @param row Номер строки.
     * @param col Номер столбца.
     */
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

    /**
     * @brief Выводит текущее состояние игрового поля.
     */
    void showTable() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                cout << Table[i][j];
            }
            cout << endl;
        }
    }

    /**
     * @brief Перезапускает игру.
     */
    void restart() {
        resetTable();
        gameWon = false;
        currentPlayer = defaultPlayer;
    }
};

/**
 * @brief Точка входа в программу.
 * @return 0 в случае успешного выполнения.
 */
int main() {
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