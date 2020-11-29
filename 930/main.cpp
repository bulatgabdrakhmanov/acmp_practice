#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int main() {
    ifstream input("INPUT.txt");
    ofstream output("OUTPUT.txt");

    if (input.is_open() && output.is_open()) {
        string fn, mn;
        map<char, vector<int>> fnChMap;
        map<char, vector<int>> mnChMap;

        int chIn = 0;
        for (char fnCh = input.get(); fnCh != '\n'; fnCh = input.get(), chIn++) {
            if (fnChMap.count(fnCh) > 0) {
                fnChMap.at(fnCh).push_back(chIn);
            } else {
                fnChMap[fnCh] = {chIn};
            }
        }

        chIn = 0;
        for (char mnCh = input.get(); mnCh != '\n' && !input.eof(); mnCh = input.get(), chIn++) {
            if (mnChMap.count(mnCh) > 0) {
                mnChMap.at(mnCh).push_back(chIn);
            } else {
                mnChMap[mnCh] = {chIn};
            }
        }

        int fnBorder = 0;
        int mnBorder = 0;

        for (char ch = 'z'; ch >= 'a'; ch = (char) (ch - 1)) {
            if (fnChMap.count(ch) > 0 && mnChMap.count(ch) > 0) {
                vector<int> fnChMapVector = fnChMap.at(ch);
                vector<int> mnChMapVector = mnChMap.at(ch);

                int fnChCount = 0;
                int mnChCount = 0;

                for (int i: fnChMapVector) {
                    if (i >= fnBorder) {
                        fnChCount++;
                    }
                }

                for (int i: mnChMapVector) {
                    if (i >= mnBorder) {
                        mnChCount++;
                    }
                }

                int commonChCount = min(fnChCount, mnChCount);
                if (commonChCount > 0) {
                    for (int i = 0; i < commonChCount; i++, output << ch);

                    int fnChCounter = 0;
                    int mnChCounter = 0;

                    for (int i: fnChMapVector) {
                        if (fnChCounter == commonChCount) {
                            break;
                        }
                        if (i >= fnBorder) {
                            fnBorder = i;
                            fnChCounter++;
                        }
                    }

                    for (int i: mnChMapVector) {
                        if (mnChCounter == commonChCount) {
                            break;
                        }
                        if (i >= mnBorder) {
                            mnBorder = i;
                            mnChCounter++;
                        }
                    }
                }
            }
        }
    }

    input.close();
    output.close();

    return 0;
}