#include <fstream>

using namespace std;

int main() {
    ifstream input("INPUT.txt");
    ofstream output("OUTPUT.txt");

    if (input.is_open() && output.is_open()) {
        const int LETTERS_COUNT = 26;
        char letters[LETTERS_COUNT] = {
                'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
                'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l',
                'z', 'x', 'c', 'v', 'b', 'n', 'm'};

        char letter;
        input >> letter;

        if (letter == 'm') {
            output << 'q';
        } else {
            for (int i = 0; i < LETTERS_COUNT; i++) {
                if (letters[i] == letter) {
                    output << letters[i + 1];
                    return 0;
                }
            }
        }
    }

    input.close();
    output.close();

    return 0;
}
