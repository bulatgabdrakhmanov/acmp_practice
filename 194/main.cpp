#include <iostream>
#include <fstream>
 
using namespace std;
 
int photo(int N)
{
    if (N == 0) return 0;
    if (N == 1 || N == 2) return 1;
 
    int Ph[60] = {};
    Ph[0] = 0;
    Ph[1] = 1;
    Ph[2] = 1;
 
    for (int i = 3; i <= N; i++) {
        Ph[i] = Ph[i-1] + Ph[i-3] + 1;
    }
 
    return Ph[N];
} 
 
int main()
{
    ifstream input("INPUT.txt");
    ofstream output("OUTPUT.txt");
 
    if (input.is_open() && output.is_open()) {
        int N, result = 0;
        input >> N;
 
        result = photo(N);
 
        output << result;
    }
 
    input.close();
    output.close();
 
    return 0;
}