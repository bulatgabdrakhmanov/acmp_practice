#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main()
{
    ifstream input("INPUT.txt");
    ofstream output("OUTPUT.txt");
 
    if (input.is_open() && output.is_open()) {
        int N, S, res = 0;
        input >> N >> S;
        vector <int> cars (N, 0);
 
        for (int i = 0; i < N; i++) {
            input >> cars[i];
        }
 
        sort(cars.begin(), cars.end());
 
        for (int car: cars) {
            if (S - car >= 0) {
                S -= car;
                res++;
            }
            else break;
        }
 
        output << res;
    }
 
    output.close();
    input.close();
 
    return 0;
}