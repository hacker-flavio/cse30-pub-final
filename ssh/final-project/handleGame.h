#ifndef HANDLEGAME_H
#define HANDLEGAME_H

#include "ArrayList.h"
#include "Queue.h"

#include <iostream>
#include <ostream>
#include <stdexcept>

#include "GameState.h"
#include "Graph.h"
#include "Vertex.h"
#include <cmath>
using namespace std;

Vec validMove(GameState game) {
    for (int i = 0; i < game.size; i++) {
        for (int j = 0; j < game.size; j++) {
            if (game.grid[i][j] == -1) {
                return Vec(i, j);
            }
        }
    }
    return Vec(0, 0);
}

int getReward(Vertex<GameState> *start, int player, int gridSizeOption) {
    if (start->neighbors.size() == 0) {
        int currPlayer = start->data.currentTurn;
        GameState::Result result = start->data.hasWon(player, gridSizeOption);
        GameState::Result result2 = start->data.hasWon(!player, gridSizeOption);
        if (result.success) {
            return 100;
        } 
        else if (result2.success) {
            return -100;
        } 
        else {
            return 50;
        }
    } 
    else {
        int totalReward = 0;
        int reward = getReward(start->neighbors[0]->location, player, gridSizeOption);
        totalReward += reward;
        for (int i = 1; i < start->neighbors.size(); i++) {
            int curr = getReward(start->neighbors[i]->location, player, gridSizeOption);
            if (start->data.currentTurn == player) {
                if (curr > reward) {
                    reward = curr;
                }
            } 
            else {
                if (curr < reward) {
                    reward = curr;
                }
            }
            totalReward += reward;
        }
        return totalReward / start->neighbors.size();
    }
}

template <class T>
struct StartObject {
    Vertex<T> *pointer;
    int depthLevel;
    StartObject() {
        pointer = nullptr;
        depthLevel = 0;
    }
    StartObject(Vertex<T> *start, int level) {
        pointer = start;
        depthLevel = level;
    }
};

struct Position {
    int value;
    Position() { value = -100; }
    Position(int value) { this->value = value; }
};

Vec findBestMove(GameState game, int gridSizeOption, int maxLevels) {
    Graph<GameState> stateSpace;
    Vertex<GameState> *start = new Vertex<GameState>(game);

    stateSpace.addVertex(start);

    Queue<StartObject<GameState> > frontier;
    StartObject<GameState> startObject(start, 0);
    frontier.enqueue(startObject);

    int addToMaxLevel = 0;
    for (int i = 0; i < game.size; i++) {
        for (int j = 0; j < game.size; j++) {
            if (game.grid[i][j] == 1 || game.grid[i][j] == 0) {
                addToMaxLevel++;
            }
        }
    }

    // maxLevels = maxLevels + addToMaxLevel/2;
    maxLevels = maxLevels + addToMaxLevel / (2 * log(maxLevels + 1));
    if (maxLevels >= 6){
     maxLevels = 5;   
    }

    cout << maxLevels << endl;

    while (!frontier.isEmpty()) {
        StartObject<GameState> curr = frontier.dequeue();

        if (!curr.pointer->data.done && curr.depthLevel < maxLevels) {
            for (int i = 0; i < game.size; i++) {
                for (int j = 0; j < game.size; j++) {
                    if (curr.pointer->data.grid[i][j] == -1) {
                        GameState next = curr.pointer->data;
                        next.play(i, j, gridSizeOption, next);
                        Vertex<GameState> *successor = new Vertex<GameState>(next);
                        stateSpace.addVertex(successor);
                        stateSpace.addDirectedEdge(curr.pointer, successor);
                        StartObject<GameState> successorObject(successor, curr.depthLevel + 1);

                        if (!successor->data.done) {
                            frontier.enqueue(successorObject);
                        }
                    }
                }
            }
        }
    }

    int reward = getReward(start->neighbors[0]->location, game.currentTurn, gridSizeOption);
    int rewardPosition = 0;
    for (int i = 1; i < start->neighbors.size(); i++) {
        int curr = getReward(start->neighbors[i]->location, game.currentTurn, gridSizeOption);
        if (curr > reward) {
            reward = curr;
            rewardPosition = i;
        } else if (curr == reward) {
            GameState::Result result = start->neighbors[i]->location->data.hasWon(game.currentTurn, gridSizeOption);
            if (result.success) {
                reward = curr;
                rewardPosition = i;
            }
        }
    }
    return start->neighbors[rewardPosition]->location->data.lastMove;
}

void playGame(int option, int gridSizeOption, int dificultyNumSizeOption) {
    GameState game(gridSizeOption);

    while (!game.done) {
        // system("clear");
        cout << game << endl;

        int x, y;

        int maxLevels;
        if (gridSizeOption == 3) {
            maxLevels = 9;
        } 
        else {
            maxLevels = 4;
        }

        if (option == 1 && dificultyNumSizeOption == 2) {
            string sx, sy;
            if (game.currentTurn) {
                Vec move = findBestMove(game, gridSizeOption, maxLevels);
                x = move.x;
                y = move.y;
            } 
            else {
                bool validInput = false;
                while (!validInput) {
                    cout << endl;
                    cout << "Enter move for (" << (!game.currentTurn ? "X" : "O") << "): ";
                    cin.clear();

                    cin >> sx >> sy;

                    try {
                        int sx2 = std::stoi(sx);
                        int sy2 = std::stoi(sy);
                        if ((sx2 >= 0 && sx2 < gridSizeOption) && (sy2 >= 0 && sy2 < gridSizeOption)) {
                            x = std::stoi(sx);
                            y = std::stoi(sy);
                            validInput = true;
                        }
                    } 
                    catch (const invalid_argument &e) {
                        cerr << endl;
                    } 
                    catch (const out_of_range &e) {
                        cerr << endl;
                    }
                }
            }
        } 
        else {
            if (option == 1) {
                string sx, sy;
                if (game.currentTurn) {
                    Vec move = validMove(game);
                    x = move.x;
                    y = move.y;
                } 
                else {
                    bool validInput = false;
                    while (!validInput) {
                        cout << "Enter move for (" << (!game.currentTurn ? "X" : "O") << "): ";
                        cin.clear();
                        cin >> sx >> sy;

                        try {
                            int sx2 = std::stoi(sx);
                            int sy2 = std::stoi(sy);
                            if ((sx2 >= 0 && sx2 < gridSizeOption) && (sy2 >= 0 && sy2 < gridSizeOption)) {
                                x = std::stoi(sx);
                                y = std::stoi(sy);
                                validInput = true;
                            }
                        } 
                        catch (const invalid_argument &e) {
                            cerr << endl;
                        } 
                        catch (const out_of_range &e) {
                            cerr << endl;
                        }
                    }
                }
            } 
            else {
                bool validInput = false;
                while (!validInput) {
                    string sx, sy;
                    cout << endl;
                    cout << "Enter move for (" << (!game.currentTurn ? "X" : "O") << "): ";
                    cin.clear();
                    cin >> sx >> sy;

                    try {
                        int sx2 = std::stoi(sx);
                        int sy2 = std::stoi(sy);
                        if ((sx2 >= 0 && sx2 < gridSizeOption) && (sy2 >= 0 && sy2 < gridSizeOption)) {
                            x = std::stoi(sx);
                            y = std::stoi(sy);
                            validInput = true;
                        }
                    } 
                    catch (const invalid_argument &e) {
                        cerr << endl;
                    } 
                    catch (const out_of_range &e) {
                        cerr << endl;
                    }
                }
            }
        }

        game.play(x, y, gridSizeOption, game);
    }

    struct Result {
        bool success;
        int value;
        GameState *temp;
    };

    GameState::Result result = game.hasWon(0, gridSizeOption, &game);
    GameState::Result result2 = game.hasWon(1, gridSizeOption, &game);

    // system("clear");
    if (result.success) {
        cout << *result.temp << endl;
        cout << "Player X has won" << endl;
    } 
    else if (result2.success) {
        cout << *result2.temp << endl;
        cout << "Player O has won" << endl;
    } 
    else {
        cout << game << endl;
        cout << "It's a tie" << endl;
    }

    std::cout << std::endl;
    std::cout << "Press [Enter] to return to the main menu ";
    std::string end;
    std::cin.ignore();
    std::getline(std::cin, end);
}

#endif
