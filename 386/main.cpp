#include <fstream>

using namespace std;

int main() {
    ifstream input("INPUT.txt");
    ofstream output("OUTPUT.txt");

    if (input.is_open() && output.is_open()) {
        int n;
        input >> n;

        int x = 0;
        int y = -5000;

        output << "YES" << endl;
        if (n % 2 == 1) {
            output << x << ' ' << y << endl;
            n--;
        }

        for (int i = 1; i <= n / 2; i++) {
            x = x + 1;
            y = y + i;
            output << x << ' ' << y << endl;
            output << -x << ' ' << y << endl;
        }
    }

    input.close();
    output.close();

    return 0;
}