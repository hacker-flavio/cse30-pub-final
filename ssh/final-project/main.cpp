#include <iostream>
#include <system_error>

#include "GameState.h"
#include "handleGame.h"

using namespace std;

string option1 = "  [1] Play against the computer";
string option2 = "  [2] Play against a human opponent";
string option3 = "  [3] Settings";
string option4 = "  [4] Current Configuration";
string option5 = "  [5] Exit";

string options[5] = {
    option1, option2, option3, option4, option5,
};

int main() {
    bool complete = false;
    string difficultyOption = "1";
    string gridSizeOption = "3";

    while (!complete) {
        bool validInputChoice = false;
        while (!validInputChoice) {
            system("clear");
            cout << "Welcome To Tic-Tac-Toe" << endl;
            cout << endl;
            for (int i = 0; i < 5; i++) {
                cout << options[i] << endl;
            }

            cout << endl;
            cout << "Enter choice: ";
            cin.clear();
            string option;

            getline(cin, option);

            if (option == "") {
                option = "1";
            }

            int choice;
            try {
                choice = stoi(option);
            } 
            catch (const invalid_argument &e) {
                cerr << endl;
            } 
            catch (const out_of_range &e) {
                cerr << endl;
            }

            if (choice == 1 || choice == 2) {
                int gridNumSizeOption = stoi(gridSizeOption);
                int dificultyNumSizeOption = stoi(difficultyOption);
                playGame(choice, gridNumSizeOption, dificultyNumSizeOption);
            } 
            else if (choice == 3) {
                bool validInput1 = false;
                while (!validInput1) {
                    bool validDiffLevel = false;
                    while (!validDiffLevel) {
                        system("clear");
                        string dificulty1 = "  [1] Piss Poor AI (Easy)";
                        string dificulty2 = "  [2] God (Hard)";
                        string difficultyChoices[2] = {
                            dificulty1,
                            dificulty2,
                        };
                        cout << "Change Difficulty:" << endl;
                        for (int i = 0; i < 2; i++) {
                            cout << difficultyChoices[i] << endl;
                        }
                        cout << "Enter choice: ";
                        cin.clear();
                        getline(cin, difficultyOption);
                        if (difficultyOption == "") {
                            difficultyOption = "1";
                            validDiffLevel = true;
                        }
                        try {
                            int difficultyChoice = stoi(difficultyOption);
                            if (difficultyChoice == 1 || difficultyChoice == 2) {
                                difficultyOption = to_string(difficultyChoice);
                                validDiffLevel = true;
                            }
                        } 
                        catch (const invalid_argument &e) {
                            cerr << endl;
                        } 
                        catch (const out_of_range &e) {
                            cerr << endl;
                        }
                    }
                    validInput1 = true;
                }
                bool validInput = false;
                while (!validInput) {
                    system("clear");
                    cout << "Change grid size: " << endl;
                    cout << "  [3] 3 x 3" << endl;
                    cout << "  [4] 4 x 4" << endl;
                    cout << endl;
                    cout << "Enter choice: ";
                    getline(cin, gridSizeOption);
                    if (gridSizeOption == "") {
                        gridSizeOption = "3";
                    }
                    try {
                        int gridChoice = stoi(gridSizeOption);
                        if (gridChoice == 3 || gridChoice == 4) {
                            gridSizeOption = to_string(gridChoice);
                            validInput = true;
                        }
                    } catch (const invalid_argument &e) {
                        cerr << endl;
                    } catch (const out_of_range &e) {
                        cerr << endl;
                    }
                }
            } else if (choice == 4) {
                bool validReturnInput = false;

                while (!validReturnInput) {
                    system("clear");
                    cout << "Difficulty mode is set to: " << difficultyOption << endl;
                    cout << "Grid size is set to: " << gridSizeOption << endl;
                    cout << endl;
                    cout << "Press [enter] to return to the main menu: ";
                    string end;
                    getline(cin, option);
                    if (option == "") {
                        validReturnInput = true;
                    }
                }

            } else if (choice == 5) {
                system("clear");

                complete = true;
                validInputChoice = true;
            }
        }
    }

    return 0;
}