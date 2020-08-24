#include <fstream>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    ifstream input("INPUT.txt");
    ofstream output("OUTPUT.txt");

    if (input.is_open() && output.is_open()) {
        int n; // длина шифровки
        int k; // длина номера секретной базы
        string cipher; // шифр

        input >> n >> k >> cipher;

        map <string, bool> substrRepeats;

        for (int i = 0; i < n - k + 1; i++) {
            string substr = cipher.substr(i, k);
            if (substrRepeats[substr]) {
                output << "YES";
                return 0;
            } else {
                substrRepeats[substr] = true;
            }
        }

        output << "NO";
    }

    input.close();
    output.close();

    return 0;
}
