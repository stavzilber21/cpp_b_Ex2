#include "Notebook.hpp"
#include <string>
using namespace std;
#include "../Direction.hpp"
#include <stdexcept>
#include <iostream>
using ariel::Direction;
using ariel::Notebook;
#include <limits.h>


void ariel::Notebook::write(int page, int row, int col, Direction direction, string text) {
    const int len_max = 100;
    if (col < 0 || col > len_max-1|| row < 0 || page < 0 || text.length() < 0) {
        throw runtime_error("Do not insert a negative variables!");
    }
    const int min = 32;
    const int max = 125;
    int len_text = text.length();
    for (int i = 0; i < len_text; ++i) {
        if (text[(unsigned int)i] < min || text[(unsigned int)i] > max) {
            throw runtime_error("The character is invalid!");
        }
    }

    if (direction == Direction::Horizontal) {
        if ((len_text + col) > len_max) {
            throw runtime_error("The word goes out of line!");
        }
        for (int i = col; i < len_text + col; i++) {
            if (notebook[page][row][i] == '~') {
                throw runtime_error("We have already deleted this location!");}
            if(notebook[page][row][i] >= min && notebook[page][row][i] < max){
                if(notebook[page][row][i]=='_'){
                    notebook[page][row][i] = text[(unsigned int)(i-col)];
                }
                else
                {
                    throw runtime_error("We have already written this location!");
                }

            }
            else{
                notebook[page][row][i] = text[(unsigned int)(i-col)];
            }
        }
    }
    if (direction == Direction::Vertical) {
        for (int i = row; i < len_text + row; i++) {
            if (notebook[page][i][col] == '~') {
                throw runtime_error("We have already deleted this location!");
            }
            if(notebook[page][i][col] >= min && notebook[page][i][col] <= max ){
                if(notebook[page][i][col]=='_'){
                    notebook[page][i][col] = text[(unsigned int)(i-row)];
                }
                else
                {
                    throw runtime_error("We have already written this location!");
                }
            }
            else{
                notebook[page][i][col] = text[(unsigned int)(i-row)];
            }
        }
    }
}

string ariel::Notebook::read(int page, int row, int col, Direction direction, int numOfChars) {
    const int len_max = 100;
    if (col < 0 || col > len_max-1 || row < 0 || page < 0 || numOfChars < 0) {
        throw runtime_error("Do not insert a negative variables!");
    }
    const int min = 32;
    const int max = 125;
    string ans;
    if (direction == Direction::Horizontal) {
        if ((numOfChars + col) > len_max) {
            throw runtime_error("The word goes out of line!");
        }
        for (int i = col; i < numOfChars + col; i++) {
            if(notebook[page][row][i] >= min && notebook[page][row][i] <= max+1) {
                ans += notebook[page][row][i];
            } else {
                ans += '_';
            }
        }
    }
    if (direction == Direction::Vertical) {
        for (int i = row; i < numOfChars + row; i++) {
            if (notebook[page][i][col] >= min && notebook[page][i][col] <= max+1) {
                ans += notebook[page][i][col];
            } else {
                ans += '_';
            }
        }
    }

    return ans;
}

void ariel::Notebook::erase(int page, int row, int col, Direction direction, int numOfChars) {
    const int len_max = 100;
    if (col < 0 || col > len_max-1 || row < 0 || page < 0 || numOfChars < 0) {
        throw runtime_error("Do not insert a negative variables!");
    }
    if (direction == Direction::Horizontal) {
        if ((numOfChars + col) > len_max) {
            throw runtime_error("The word goes out of line!");
        }
        for (int i = col; i < numOfChars + col; i++) {
            notebook[page][row][i] = '~';
        }
    }

    if (direction == Direction::Vertical) {
        for (int i = row; i < numOfChars + row; i++) {
            notebook[page][i][col] = '~';
        }
    }

}

void Notebook::show(int page) {
    if (page < 0) {
        throw runtime_error("Do not insert a negative variables!");
    }

    int key_max = INT_MIN;
    int key_min = INT_MAX;
    for (auto const & i: notebook[page]) {
        if(i.first < key_min) {key_min = i.first;}
        if(i.first > key_max) {key_max = i.first;}
    }
    if(key_min == INT_MAX) {return;}
    while(key_min <= key_max) {
        if(notebook[page].count(key_min) != 0) {
            std :: cout << key_min << ':' << notebook[page][key_min][0] << endl;
        }
        key_min++;
    }
}

