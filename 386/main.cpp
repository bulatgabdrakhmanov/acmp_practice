#include <fstream>

using namespace std;

int main() {
    ifstream input("INPUT.txt");
    ofstream output("OUTPUT.txt");

    if (input.is_open() && output.is_open()) {
        int n;
        input >> n;

        output << "YES" << endl;
        for (int i = 0; i < n; i++) {
            output << rand() % 20001 - 10000 << ' ' << rand() % 20001 - 10000 << endl;
        }
    }

    input.close();
    output.close();

    return 0;
}