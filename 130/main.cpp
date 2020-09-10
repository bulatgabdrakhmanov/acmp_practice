#include <fstream>
#include <vector>
#include <map>

using namespace std;

int distance(string element1, string element2, vector<string> array) {
    int distance = 0;

    for (int i = 0; i < array.size(); i++) {
        if (array[i] == element1) distance -= i;
        if (array[i] == element2) distance += i;
    }

    return abs(distance);
}

int main() {
    ifstream input("INPUT.txt");
    ofstream output("OUTPUT.txt");

    if (input.is_open() && output.is_open()) {
        vector<string> letters = {"a", "b", "c", "d", "e", "f", "g", "h"};
        vector<string> numbers = {"1", "2", "3", "4", "5", "6", "7", "8"};
        map<string, vector<string>> moves;

        for (int i = 0; i < (int) letters.size(); i++) {
            for (int j = 0; j < (int) numbers.size(); j++) {
                string currCoordinate = letters[i] + numbers[j];
                vector<string> possibleMoves;

                if (i < letters.size() - 1 && j < numbers.size() - 2) {
                    possibleMoves.push_back(letters[i + 1] + numbers[j + 2]);
                }
                if (i < letters.size() - 2 && j < numbers.size() - 1) {
                    possibleMoves.push_back(letters[i + 2] + numbers[j + 1]);
                }
                if (i < letters.size() - 2 && j > 1) {
                    possibleMoves.push_back(letters[i + 2] + numbers[j - 1]);
                }
                if (i < letters.size() - 1 && j > 2) {
                    possibleMoves.push_back(letters[i + 1] + numbers[j - 2]);
                }
                if (i > 1 && j > 2) {
                    possibleMoves.push_back(letters[i - 1] + numbers[j - 2]);
                }
                if (i > 2 && j > 1) {
                    possibleMoves.push_back(letters[i - 2] + numbers[j - 1]);
                }
                if (i > 2 && j < numbers.size() - 1) {
                    possibleMoves.push_back(letters[i - 2] + numbers[j + 1]);
                }
                if (i > 1 && j < numbers.size() - 2) {
                    possibleMoves.push_back(letters[i - 1] + numbers[j + 2]);
                }

                moves[currCoordinate] = possibleMoves;
            }
        }

        string firstHorseCoor, secondHorseCoor;
        input >> firstHorseCoor >> secondHorseCoor;

        int counter = 0;
        while (firstHorseCoor != secondHorseCoor) {
            counter++;
            vector<string> firstHorseMoves = moves[firstHorseCoor];
            vector<string> secondHorseMoves = moves[secondHorseCoor];

            int numberDistance = 7, letterDistance = 7;
            string newFHC, newSHC;

            for (string firstHorseMove: firstHorseMoves) {
                for (string secondHorseMove: secondHorseMoves) {
                    string firstHorseMoveLetter(1, firstHorseMove[0]);
                    string firstHorseMoveNumber(1, firstHorseMove[1]);
                    string secondHorseMoveLetter(1, secondHorseMove[0]);
                    string secondHorseMoveNumber(1, secondHorseMove[1]);

                    int nD = distance(firstHorseMoveNumber, secondHorseMoveNumber, numbers);
                    int lD = distance(firstHorseMoveLetter, secondHorseMoveLetter, letters);

                    if ((nD + lD) < (numberDistance + letterDistance)) {
                        numberDistance = nD;
                        letterDistance = lD;
                        newFHC = firstHorseMove;
                        newSHC = secondHorseMove;
                    }

                }
            }

            if ((numberDistance == 0 && letterDistance == 1) || (numberDistance == 1 && letterDistance == 0)) {
                counter = -1;
                break;
            } else if (numberDistance == 0 && letterDistance == 0) {
                break;
            } else {
                firstHorseCoor = newFHC;
                secondHorseCoor = newSHC;
            }
        }

        output << counter;
    }

    input.close();
    output.close();

    return 0;
}