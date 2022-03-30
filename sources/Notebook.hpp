#include <string>

using namespace std;

#include "../Direction.hpp"
#include <vector>
#include <array>
#include <unordered_map>

namespace ariel {


    class Notebook {
        unordered_map<int, unordered_map<int, char[100]>> notebook;
    public:
        Notebook() {}

        ~Notebook() {}

        void write(int page, int row, int col, Direction direction, string text);

        string read(int page, int row, int col, Direction direction, int numOfChars);

        void erase(int page, int row, int col, Direction direction, int numOfChars);

        void show(int page);


    };

}