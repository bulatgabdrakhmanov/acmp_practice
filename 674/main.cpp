#include <iostream>
#include <fstream>
 
using namespace std;
 
int prib(int N)
{
    if (N < 3) return 0;
    if (N == 3) return 1;
    return (N % 2 == 0) ? 2 * prib(N/2) : prib(N/2) + prib(N/2 + 1);
}
 
int main()
{
    ifstream input("INPUT.txt");
    ofstream output("OUTPUT.txt");
 
    if (input.is_open() && output.is_open()) {
        int N;
        input >> N;
        output << prib(N);
    }
 
    input.close();
    output.close();
}