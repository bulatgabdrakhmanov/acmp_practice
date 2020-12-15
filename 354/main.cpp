#include <iostream>
#include <fstream>
using namespace std;
 
int main()
{
    ifstream input("INPUT.txt");
    ofstream output("OUTPUT.txt");
 
    if (input.is_open() && output.is_open()) {
        int64_t n, div = 2;
        input >> n;
 
        while (div*div <= n) {
            if (n % div == 0) {
                output << div;
                n /= div;
                if (n > 1) output << '*';
            }
            else div++;
        }
        if (n > 1) output << n;
    }
 
    output.close();
    input.close();
 
    return 0;
}