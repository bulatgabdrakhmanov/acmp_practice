#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef int16_t i16;

int main() {
    ifstream input("INPUT.txt");
    ofstream output("OUTPUT.txt");

    if (input.is_open() && output.is_open()) {
        string s1, s2;
        input >> s1 >> s2;

        int n = s1.size();
        int m = s2.size();

        vector<vector<i16>> prefixLens(n + 1, vector<i16>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1.at(i - 1) == s2.at(j - 1)) {
                    prefixLens.at(i).at(j) = prefixLens.at(i - 1).at(j - 1) + 1;
                }
            }
        }

        vector<vector<i16>> postfixLens(n + 1, vector<i16>(m + 1, 0));
        for (int i = n; i >= 1; i--) {
            for (int j = m; j >= 1; j--) {
                if (s1.at(i - 1) == s2.at(j - 1)) {
                    postfixLens.at(i - 1).at(j - 1) = postfixLens.at(i).at(j) + 1;
                }
            }
        }

        vector<vector<i16>> maxLens(n + 1, vector<i16>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                maxLens.at(i).at(j) =
                        max({maxLens.at(i - 1).at(j), maxLens.at(i).at(j - 1), prefixLens.at(i).at(j)});
            }
        }


        int maxI = 0;
        int maxJ = 0;
        int maxPrefixLen = 0;
        int maxPostfixLen = 0;
        int maxSum = 0;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                int prefixLen = maxLens.at(i).at(j);
                int postfixLen = postfixLens.at(i).at(j);
                int sum = maxLens.at(i).at(j) + postfixLens.at(i).at(j);

                if (sum > maxSum) {
                    maxPrefixLen = prefixLen;
                    maxPostfixLen = postfixLen;
                    maxSum = sum;
                    maxI = i;
                    maxJ = j;
                }
            }
        }

        if (maxSum > 0) {
            string maxPrefix;
            string maxPostfix;
            for (int i = 0; i <= maxI; i++) {
                for (int j = 0; j <= maxJ; j++) {
                    if (prefixLens.at(i).at(j) == maxPrefixLen) {
                        maxPrefix = s1.substr(i - maxPrefixLen, maxPrefixLen);
                        i = n + 1;
                        j = m + 1;
                    }
                }
            }
            for (int i = maxI + 1; i <= n; i++) {
                for (int j = maxJ + 1; j <= m; j++) {
                    if (prefixLens.at(i).at(j) == maxPostfixLen) {
                        maxPostfix = s1.substr(i - maxPostfixLen, maxPostfixLen);
                        i = n + 1;
                        j = m + 1;
                    }
                }
            }

            if (maxPrefix.size() > 0) {
                output << maxPrefix << endl;
            }
            output << maxPostfix;
        }
    }

    input.close();
    output.close();

    return 0;
}