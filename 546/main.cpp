#include <fstream>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    ifstream input("INPUT.txt");
    ofstream output("OUTPUT.txt");

    if (input.is_open() && output.is_open()) {
        int pages_count = 0;
        input >> pages_count;

        if (pages_count > 0) {
            int sheets_count = (int)ceil((float)pages_count / 4);
            int max_pages_count = sheets_count * 4;

            for (int i = 1; i <= sheets_count * 2; i++) {
                output << (int)ceil((float)i / 2) << " ";

                if (i % 2) {
                    output << 1 << " ";
                    if (max_pages_count - i + 1 <= pages_count) {
                        output << max_pages_count - i + 1 << " ";
                    } else {
                        output << 0 << " ";
                    }
                    output << i << " ";
                } else {
                    output << 2 << " ";
                    if (i <= pages_count) {
                        output << i << " ";
                    } else {
                        output << 0 << " ";
                    }
                    if (max_pages_count - i + 1 <= pages_count) {
                        output << max_pages_count - i + 1 << " ";
                    } else {
                        output << 0 << " ";
                    }
                }
                output << endl;
            }
        }
    }

    input.close();
    output.close();

    return 0;
}
