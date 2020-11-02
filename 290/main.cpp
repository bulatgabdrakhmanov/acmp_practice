#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream input("INPUT.txt");
    ofstream output("OUTPUT.txt");

    if (input.is_open() && output.is_open()) {
        int Nb, Mb, Nd, Md, result = 0;
        input >> Nb >> Mb;

        vector<vector<char>> base_plan(Nb, vector<char>(Mb, '#'));

        for (int i = 0; i < Nb; i++) {
            string row;
            input >> row;
            for (int j = 0; j < Mb; j++) {
                base_plan.at(i).at(j) = row.at(j);
            }
        }

        input >> Nd >> Md;
        vector<vector<char>> desert_area(Nd, vector<char>(Md, '.'));

        for (int i = 0; i < Nd; i++) {
            string row;
            input >> row;
            for (int j = 0; j < Md; j++) {
                desert_area.at(i).at(j) = row.at(j);
            }
        }

        for (int i = 0; i < Nd - Nb + 1; i++) {
            for (int j = 0; j < Md - Mb + 1; j++) {
                bool is_possible = true;

                for (int k = 0; k < Nb; k++) {
                    for (int l = 0; l < Mb; l++) {
                        char base_ch = base_plan.at(k).at(l);
                        char desert_ch = desert_area.at(i + k).at(j + l);

                        if (desert_ch == '.' && desert_ch != base_ch) {
                            is_possible = false;
                            break;
                        }
                    }
                }

                if (is_possible) {
                    result++;
                }
            }
        }

        output << result;
    }

    input.close();
    output.close();

    return 0;
}