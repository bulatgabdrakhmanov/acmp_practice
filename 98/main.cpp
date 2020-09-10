#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream input("INPUT.txt");
    ofstream output("OUTPUT.txt");

    if (input.is_open() && output.is_open()) {
        int player1 = 0;
        int player2 = 0;
        bool flag = true;

        int N;
        input >> N;

        vector <int> array = {};

        for (int i = 0; i < N; i++) {
            int num;
            input >> num;
            array.push_back(num);
        }

        while (!array.empty()) {
            int firstElem = array.at(0);
            int lastElem = array.at(array.size() - 1);
            int result;
            if (firstElem >= lastElem) {
                result = firstElem;
                array.erase(array.begin());
            } else {
                result = lastElem;
                array.erase(array.begin() + array.size() - 1);
            }

            if (flag) {
                player1 += result;
                flag = false;
            } else {
                player2 += result;
                flag = true;
            }
        }

        output << player1 << ':' << player2;
    }

    input.close();
    output.close();

    return 0;
}
