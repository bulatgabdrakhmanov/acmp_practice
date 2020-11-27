#include <fstream>
#include <string>
#include <iostream>
#include <list>

using namespace std;

int main() {
    ifstream input("INPUT.txt");
    ofstream output("OUTPUT.txt");

    if (input.is_open() && output.is_open()) {
        int greater_line_len = 0;

        list<int> up; // содержит длины строк от текущей
        list<int> low = {0}; // содержит длины строк до текущей включительно

        string text;
        getline(input, text);

        for (char ch : text) {
            if (ch == '\\') { // перенос курсора на новую строку
                low.push_back(0);
            } else if (ch == '<') { // удаление предыдущего символа
                if (low.back() > 0) {
                    low.back() -= 1;
                } else if (low.cbegin() != --low.cend()) {
                    low.pop_back();
                }
            } else if (ch == '^') { // перемещение в конец предыдущей строки
                if (low.cbegin() != --low.cend()) {
                    up.push_front(low.back());
                    low.pop_back();
                }
            } else if (ch == '|') { // перемещение в конец следующей строки
                if (!up.empty()) {
                    low.push_back(up.front());
                    up.pop_front();
                }
            } else {
                low.back() += 1;
            }

            if (low.back() > greater_line_len) {
                greater_line_len = low.back();
            }
        }

        output << greater_line_len;
    }

    input.close();
    output.close();

    return 0;
}