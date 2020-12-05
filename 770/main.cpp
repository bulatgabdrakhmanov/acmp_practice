#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    if (num == 2) return true;
    if (num < 2 || num % 2 == 0) return false;

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2) {
        if (num % i == 0) return false;
    }

    return true;
}

int main() {
    ifstream input("INPUT.txt");
    ofstream output("OUTPUT.txt");

    if (input.is_open() && output.is_open()) {
        string encryptedText;
        string decryptedText;
        input >> encryptedText;

        int step = 1;
        int leftBorder = 0;
        int rightBorder = 0;
        int encryptedTextSize = encryptedText.size();
        stack<string> cipherParts;

        for (int i = 0; encryptedTextSize > 0; i++) {
            string cipherPart;
            step = min(step, encryptedTextSize);

            if (i % 2 == 0) {
                cipherPart = encryptedText.substr(encryptedText.size() - step - rightBorder, step);
                rightBorder += step;
            } else {
                cipherPart = encryptedText.substr(leftBorder, step);
                leftBorder += step;
            }

            cipherParts.emplace(cipherPart);
            encryptedTextSize -= step;
            step++;
        }

        for (int i = cipherParts.size() % 2; !cipherParts.empty(); i++) {
            if (i % 2 == 0) {
                decryptedText = decryptedText + cipherParts.top();
            } else {
                decryptedText = cipherParts.top() + decryptedText;
            }

            cipherParts.pop();
        }

        int counter = 0;
        string result;
        for (char ch: decryptedText) {
            if (isupper(ch)) counter++;

            if (isPrime(counter)) {
                result += ch;
            }
        }

        if (!result.empty()) {
            output << result;
        } else {
            output << "Impossible";
        }
    }

    input.close();
    output.close();

    return 0;
}
