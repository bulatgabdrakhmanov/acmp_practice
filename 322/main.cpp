#include <iostream>
#include <fstream>
#include <string>
#include <vector>
 
using namespace std;
 
 
string fibText(string text)
{
    string fibText = "";
    fibText += text.at(0);
 
    vector <int> fib (text.size() + 2, 1);
 
    for (int i = 2; i <= text.size(); i++) {
        fib[i] = fib[i-1] + fib[i-2];
        if (fib[i]-1 < text.size()) {
            fibText += text.at(fib[i]-1);
        }
        else break;
    }
 
    return fibText;
}
 
int main()
{
    ifstream input("INPUT.txt");
    ofstream output("OUTPUT.txt");
 
    if (input.is_open() && output.is_open()) {
        string text;
        getline(input, text);
 
        output << fibText(text);
    }
 
    input.close();
    output.close();
 
    return 0;
}