#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <iostream>
#define GREEN_TEXT "\033[1;32m"
#define RESET_COLOR "\033[0m"

struct Vec {
    int x;
    int y;

    Vec() {
        x = 0;
        y = 0;
    }

    Vec(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void set(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

std::ostream &operator<<(std::ostream &os, const Vec &v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

struct GameState;
std::ostream &operator<<(std::ostream &os, const GameState &state);

struct GameState {
    int **grid;
    bool currentTurn;
    int size;
    int turnCount;

    bool done;
    Vec lastMove;

    GameState() {
        size = 3;
        currentTurn = 0;
        turnCount = 0;
        done = false;

        lastMove.set(-1, -1);

        grid = new int *[size];

        for (int i = 0; i < size; i++) {
            grid[i] = new int[size];
            for (int j = 0; j < size; j++) {
                grid[i][j] = -1;
            }
        }
    }

    GameState(int size) {
        this->size = size;
        currentTurn = 0;
        turnCount = 0;
        done = false;

        lastMove.set(-1, -1);

        grid = new int *[size];

        for (int i = 0; i < size; i++) {
            grid[i] = new int[size];
            for (int j = 0; j < size; j++) {
                grid[i][j] = -1;
            }
        }
    }
    GameState(const GameState &other) {
        size = other.size;
        currentTurn = other.currentTurn;
        turnCount = other.turnCount;
        done = other.done;
        lastMove = other.lastMove;

        grid = new int *[size];

        for (int i = 0; i < size; i++) {
            grid[i] = new int[size];
            for (int j = 0; j < size; j++) {
                grid[i][j] = other.grid[i][j];
            }
        }
    }

    bool operator==(const GameState &other) {
        bool sizeMatch = size == other.size;
        bool currentTurnMatch = currentTurn == other.currentTurn;
        bool turnCountMatch = turnCount == other.turnCount;
        bool doneMatch = done == other.done;
        bool lastMoveMatch = lastMove.x == other.lastMove.x && lastMove.y == other.lastMove.y;
        if (sizeMatch && currentTurnMatch && turnCountMatch && doneMatch &&
            lastMoveMatch) {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    if (grid[i][j] != other.grid[i][j]) {
                        return false;
                    }
                }
            }

            return true;
        } 
        else {
            return false;
        }
    }

    GameState &operator=(const GameState &other) {
        currentTurn = other.currentTurn;
        turnCount = other.turnCount;
        done = other.done;
        lastMove = other.lastMove;

        if (size == other.size) {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    grid[i][j] = other.grid[i][j];
                }
            }
        } 
        else {
            for (int i = 0; i < size; i++) {
                delete[] grid[i];
            }
            delete[] grid;

            size = other.size;

            grid = new int *[size];

            for (int i = 0; i < size; i++) {
                grid[i] = new int[size];
                for (int j = 0; j < size; j++) {
                    grid[i][j] = other.grid[i][j];
                }
            }
        }

        return *this;
    }

    struct Result {
        bool success;
        int value;
        GameState *temp;
        Result() {
            success = false;
            value = 0;
            temp = nullptr;
        }

        Result(bool success, int value, GameState *temp) {
            this->success = success;
            this->value = value;
            this->temp = temp;
        }
    };

    Result hasWon(int player, int gridSizeOption, const GameState *gameState = nullptr) {
        int num = 2;
        GameState *temp = new GameState(gridSizeOption);
        GameState *old = new GameState(gridSizeOption);
        if (gameState != nullptr) {
            *temp = *gameState;
            *old = *gameState;
        }
        for (int i = 0; i < size; i++) {
            int count = 0;
            for (int j = 0; j < size; j++) {
                if (grid[i][j] == player) {
                    count++;
                }
            }
            if (count == size) {
                for (int j = 0; j < size; j++) {
                    if (grid[i][j] == player) {
                        temp->grid[i][j] = player + 2;
                    }
                }
                Result myResult(true, num, temp);
                return myResult;
            }
        }

        for (int i = 0; i < size; i++) {
            int count = 0;
            for (int j = 0; j < size; j++) {
                if (grid[j][i] == player) {
                    count++;
                }
            }
            if (count == size) {
                for (int j = 0; j < size; j++) {
                    if (grid[j][i] == player) {
                        temp->grid[j][i] = player + 2;
                    }
                }
                Result myResult(true, num, temp);
                return myResult;
            }
        }

        int mainDiagCount = 0;
        for (int i = 0; i < size; i++) {
            if (grid[i][i] == player) {
                mainDiagCount++;
            }
        }
        if (mainDiagCount == size) {
            for (int i = 0; i < size; i++) {
                if (grid[i][i] == player) {
                    temp->grid[i][i] = player + 2;
                }
            }
            Result myResult(true, num, temp);
            return myResult;
        }

        int secondaryDiagCount = 0;
        for (int i = 0; i < size; i++) {
            if (grid[i][size - 1 - i] == player) {
                secondaryDiagCount++;
            }
        }
        if (secondaryDiagCount == size) {
            for (int i = 0; i < size; i++) {
                if (grid[i][size - 1 - i] == player) {
                    temp->grid[i][size - 1 - i] = player + 2;
                }
            }
            Result myResult(true, num, temp);
            return myResult;
        }

        Result myResult(false, num, old);
        return myResult;
    }

    bool play(int x, int y, int gridSizeOption, GameState &game) {
        if (grid[x][y] != -1) {
            return false;
        }
        grid[x][y] = currentTurn;
        currentTurn = !currentTurn;
        turnCount++;
        lastMove.set(x, y);
        Result result = hasWon(0, gridSizeOption, &game);
        Result result2 = hasWon(1, gridSizeOption, &game);
        if (turnCount == size * size) {
            done = true;
        } 
        else if (result.success || result2.success) {
            done = true;
        }

        return true;
    }

    ~GameState() {
        for (int i = 0; i < size; i++) {
            delete[] grid[i];
        }
        delete[] grid;
    }
};

std::ostream &operator<<(std::ostream &os, const GameState &state) {
    // std::system("clear");
    for (int k = 0; k < state.size + 2; k++) {
        if (k == 0) {
            os << "   "
               << "   ";
            for (int i = 0; i < state.size; i++) {
                os << " "
                   << " " << i << "   ";
            }
            os << std::endl;
            os << std::endl;
        } else if (k > 0 && k < state.size + 1) {
            os << " "
               << " "
               << "   "
               << " ";

            for (int i = 0; i < state.size; i++) {
                if (state.grid[k - 1][i] == 0 || state.grid[k - 1][i] == 2) {
                    if (i < state.size - 1) {
                        if (state.grid[k - 1][i] == 0) {
                            os << " "
                               << "╲︎ ╱︎"
                               << " "
                               << "|";
                        } else {
                            os << " "
                               << "\033[38;5;2m"
                               << "╲︎ ╱︎"
                               << "\033[0m"
                               << " "
                               << "|";
                        }

                    } else {
                        if (state.grid[k - 1][i] == 0) {
                            os << " "
                               << "╲︎ ╱︎"
                               << " "
                               << " ";
                        } else {
                            os << " "
                               << "\033[38;5;2m"
                               << "╲︎ ╱︎"
                               << "\033[0m"
                               << " "
                               << " ";
                        }
                    }
                } else if (state.grid[k - 1][i] == 1 ||
                           state.grid[k - 1][i] == 3) {
                    if (i < state.size - 1) {
                        if (state.grid[k - 1][i] == 1) {
                            os << " "
                               << "╭━╮︎"
                               << " "
                               << "|";
                        } else {
                            os << " "
                               << "\033[38;5;205m"
                               << "╭━╮︎"
                               << "\033[0m"
                               << " "
                               << "|";
                        }
                    } else {
                        if (state.grid[k - 1][i] == 1) {
                            os << " "
                               << "╭━╮︎"
                               << " "
                               << " ";
                        } else {
                            os << " "
                               << "\033[38;5;205m"
                               << "╭━╮︎"
                               << "\033[0m"
                               << " "
                               << " ";
                        }
                    }
                } else {
                    if (i < state.size - 1) {
                        os << " "
                           << "   "
                           << " "
                           << "|";
                    } else {
                        os << " "
                           << "   "
                           << " "
                           << " ";
                    }
                }
            }
            os << std::endl;

            os << " " << k - 1 << "   "
               << " ";
            for (int i = 0; i < state.size; i++) {
                if (state.grid[k - 1][i] == 0 || state.grid[k - 1][i] == 2) {
                    if (i < state.size - 1) {
                        if (state.grid[k - 1][i] == 0) {
                            os << " "
                               << " x "
                               << " "
                               << "|";
                        } else {
                            os << " "
                               << "\033[38;5;2m"
                               << " x "
                               << "\033[0m"
                               << " "
                               << "|";
                        }
                    } else {
                        if (state.grid[k - 1][i] == 0) {
                            os << " "
                               << " x "
                               << " "
                               << " ";
                        } else {
                            os << " "
                               << "\033[38;5;2m"
                               << " x "
                               << "\033[0m"
                               << " "
                               << " ";
                        }
                    }
                } else if (state.grid[k - 1][i] == 1 ||
                           state.grid[k - 1][i] == 3) {
                    if (i < state.size - 1) {
                        if (state.grid[k - 1][i] == 1) {
                            os << " "
                               << "┃︎╱┃︎"
                               << " "
                               << "|";
                        } else {
                            os << " "
                               << "\033[38;5;205m"
                               << "┃︎╱┃︎"
                               << "\033[0m"
                               << " "
                               << "|";
                        }

                    } else {
                        if (state.grid[k - 1][i] == 1) {
                            os << " "
                               << "┃︎╱┃︎"
                               << " "
                               << " ";
                        } else {
                            os << " "
                               << "\033[38;5;205m"
                               << "┃︎╱┃︎"
                               << "\033[0m"
                               << " "
                               << " ";
                        }
                    }
                } else {
                    if (i < state.size - 1) {
                        os << " "
                           << "   "
                           << " "
                           << "|";
                    } else {
                        os << " "
                           << "   "
                           << " "
                           << " ";
                    }
                }
            }
            os << std::endl;

            os << " "
               << " "
               << "   "
               << " ";

            for (int i = 0; i < state.size; i++) {
                if (state.grid[k - 1][i] == 0 || state.grid[k - 1][i] == 2) {
                    if (i < state.size - 1) {
                        if (state.grid[k - 1][i] == 0) {
                            os << " "
                               << "╱︎ ╲︎"
                               << " "
                               << "|";
                        } else {
                            os << " "
                               << "\033[38;5;2m"
                               << "╱︎ ╲︎"
                               << "\033[0m"
                               << " "
                               << "|";
                        }

                    } else {
                        if (state.grid[k - 1][i] == 0) {
                            os << " "
                               << "╱︎ ╲︎"
                               << " "
                               << " ";
                        } else {
                            os << " "
                               << "\033[38;5;2m"
                               << "╱︎ ╲︎"
                               << "\033[0m"
                               << " "
                               << " ";
                        }
                    }
                }

                else if (state.grid[k - 1][i] == 1 ||
                         state.grid[k - 1][i] == 3) {
                    if (i < state.size - 1) {
                        if (state.grid[k - 1][i] == 1) {
                            os << " "
                               << "╰━╯︎"
                               << " "
                               << "|";
                        } else {
                            os << " "
                               << "\033[38;5;205m"
                               << "╰━╯︎"
                               << "\033[0m"
                               << " "
                               << "|";
                        }

                    } else {
                        if (state.grid[k - 1][i] == 1) {
                            os << " "
                               << "╰━╯︎"
                               << " "
                               << " ";
                        } else {
                            os << " "
                               << "\033[38;5;205m"
                               << "╰━╯︎"
                               << "\033[0m"
                               << " "
                               << " ";
                        }
                    }
                } else {
                    if (i < state.size - 1) {
                        os << " "
                           << "   "
                           << " "
                           << "|";
                    } else {
                        os << " "
                           << "   "
                           << " "
                           << " ";
                    }
                }
            }
            os << std::endl;

            os << "   "
               << " "
               << " ";
            for (int m = 0; m < state.size * 2 + state.size; m++) {
                if (k != state.size) {
                    if (m % 3 == 0) {
                        if (m > 0) {
                            os << "+-";
                        } else {
                            os << " -";
                        }
                    } else {
                        os << "--";
                    }
                }
            }
            os << std::endl;
        }
    }
    return os;
}

#endif