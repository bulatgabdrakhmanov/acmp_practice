#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
 
using namespace std;
 
int main()
{
    ifstream input("INPUT.txt");
    ofstream output("OUTPUT.txt");
 
    if (input.is_open() && output.is_open()) {
        unsigned long int n;
        input >> n;
         
 
        vector <int> res;
 
        while (n>=1) {
            res.insert(res.begin(), n % 3);
            n /= 3;
        }
 
        for (int i = 0; i < res.size(); i++) {
            if (i != res.size() - 1 && res.at(i+1) == 0) {
                res[i] -= 1;
                res[i+1] = 3;
 
                if (i > 0 && res[i] == 0) {
                    i = -1;
                }
            }
        }
 
        for (int i = 0; i < res.size(); i++) {
            if (res[i] != 0) output << res[i];
        }
    }
 
    input.close();
    output.close();
 
    return 0;
}
