#include <iostream>
#include <fstream>
using namespace std;
 
int main()
{
    ifstream input("INPUT.txt");
    ofstream output("OUTPUT.txt");
 
    if (input.is_open() && output.is_open()) {
        int N, sum = 0, tower = 0;
        input >> N;
 
        while (sum+tower < N) {
            tower++;
            sum += tower;
        }
         
        output << tower;
    }
 
    output.close();
    input.close();
 
    return 0;
}