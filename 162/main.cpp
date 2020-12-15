#include <iostream>
#include <fstream>
 
using namespace std;
 
int police(int N, int M) {
    if (N == 0 || M == 0) return 0;
    else if (N == 1 || M == 1) return N*M*4;
    else {
        int T = 2*(N+M);
        while (N > 0 && M > 0) {
            int squareCount = (N == 1 || M == 1) ? N*M / 2 : (N*M - (N-2)*(M-2)) / 2;
            T += squareCount * 4;
            N -= 2;
            M -= 2;
        }
        return T;
    }
}
 
int main()
{
    ifstream input("INPUT.txt");
    ofstream output("OUTPUT.txt");
 
 
    if (input.is_open() && output.is_open()) {
        int N, M;
        input >> N >> M;
 
        output << police(N, M);
    }
 
    input.close();
    output.close();
 
    return 0;
}