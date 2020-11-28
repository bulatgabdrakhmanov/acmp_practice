#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
    ifstream input("INPUT.txt");
    ofstream output("OUTPUT.txt");

    if (input.is_open() && output.is_open()) {
        int n;
        input >> n;

        string text;
        for (int i = 1; text.size() < n; i++) {
            for (int j = 1; j <= i; j++) {
                text += to_string(j);
            }
        }

        output << text.at(n - 1);
    }

    input.close();
    output.close();

    return 0;
}
