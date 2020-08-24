#include <fstream>

using namespace std;

int main() {
    ifstream input("INPUT.txt");
    ofstream output("OUTPUT.txt");

    if (input.is_open() && output.is_open()) {
        int N;
        input >> N;

        if (N > 0) {
            output << (1 + N) * N / 2;
        } else {
            output << (1 - N) * N / 2  + 1;
        }
    }

    input.close();
    output.close();

    return 0;
}
