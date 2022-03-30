#include "Direction.hpp"

//using namespace std;
#include "doctest.h"
#include "sources/Notebook.hpp"
using namespace ariel;

TEST_CASE("Good input") {
    ariel::Notebook notebook;
            CHECK_NOTHROW(notebook.write(1, 2, 0, Direction::Horizontal, "stav"));
            CHECK_NOTHROW(notebook.read(2,3,4,Direction::Horizontal,3));
            CHECK_NOTHROW(notebook.read(3, 3, 3, Direction::Vertical, 5));
            CHECK_NOTHROW(notebook.read(2, 1, 0, Direction::Horizontal, 4));
            CHECK_NOTHROW(notebook.erase(4, 4, 4, Direction::Vertical, 4));
            CHECK_NOTHROW(notebook.erase(1, 0, 1, Direction::Vertical, 3));
            CHECK(notebook.read(3, 12, 5, Direction::Horizontal, 4) == "stav");
            CHECK(notebook.read(6, 85, 2, Direction::Vertical, 6) == "zilber");


    for (int i = 0; i < 20; ++i) {
                CHECK_NOTHROW(notebook.write(i, 2*i, i*3, Direction::Horizontal, "stav"));
    }

}

TEST_CASE("Bad input") {
    ariel::Notebook notebook;
            CHECK_THROWS(notebook.write(3, -2, 0, Direction::Horizontal, "stav"));
            CHECK_THROWS(notebook.write(-3, 5, 0, Direction::Horizontal, "stav"));
            CHECK_THROWS(notebook.write(6, 6, -4, Direction::Horizontal, "stav"));
            CHECK_THROWS(notebook.read(-3, 1, 0, Direction::Horizontal, 1));
            CHECK_THROWS(notebook.read(5, -2, 1, Direction::Vertical, 4));
            CHECK_THROWS(notebook.read(6, 4, -7, Direction::Horizontal, 3));
            CHECK_THROWS(notebook.read(6, 4, -7, Direction::Horizontal, 103));
            CHECK_THROWS(notebook.read(3, 3, 3, Direction::Vertical, -9));
            CHECK_THROWS(notebook.read(0, 1, 0, Direction::Vertical, 0));
            CHECK_THROWS(notebook.erase(2, 4, 1, Direction::Vertical, -2));
            CHECK_THROWS(notebook.erase(-7, 1, 0, Direction::Horizontal, 2));
            CHECK_THROWS(notebook.erase(3, -10, 8, Direction::Vertical, 2));
            CHECK_THROWS(notebook.erase(1, 1, -5, Direction::Horizontal, 2));
            CHECK_THROWS(notebook.erase(4, 4, 4, Direction::Vertical, 0));
            CHECK_THROWS(notebook.erase(4, 4, 4, Direction::Vertical, 102));
            CHECK_FALSE(notebook.read(2, 99, 43, Direction::Vertical, 4) == "llll");



}