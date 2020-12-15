#include <iostream>
#include <fstream>
 
using namespace std;
 
int main()
{
    ifstream input("INPUT.txt");
    ofstream output("OUTPUT.txt");
 
    if (input.is_open() && output.is_open()) {
        int R, x, y;
        input >> R >> x >> y;
 
        x = (x >= 0) ? x : -x;
 
        output.setf(ios::fixed);
        output.precision(2);
 
        output << x - (double)(x * (R - y)) / (double)(2 * R - y);
    }
 
    input.close();
    output.close();
 
    return 0;
}