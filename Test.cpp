// avigael abitbol

#include "doctest.h"
#include "Notebook.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace ariel;




TEST_CASE("notebook - test") {
    ariel::Notebook notebook;
    CHECK_NOTHROW(notebook.write(/*page=*/1, /*row=*/0, /*column=*/0,Direction::Horizontal,"horizontal"));
    notebook.write(/*page=*/1, /*row=*/10, /*column=*/10, Direction::Vertical,"vertical");
    CHECK(notebook.read(1,10,10,Direction::Vertical,8) == "vertical");
    CHECK_NOTHROW(notebook.write(/*page=*/2, /*row=*/0, /*column=*/0,Direction::Horizontal,"avi"));
    CHECK_NOTHROW(notebook.write(/*page=*/5, /*row=*/10, /*column=*/10, Direction::Vertical,"cpp"));
    CHECK_NOTHROW(notebook.write(/*page=*/9, /*row=*/0, /*column=*/0,Direction::Horizontal,"horizontal"));
    CHECK_NOTHROW(notebook.write(/*page=*/8, /*row=*/10, /*column=*/10, Direction::Vertical,"vertical"));
    CHECK(notebook.read(1,0,0,Direction::Horizontal,10) == "horizontal");
    CHECK_NOTHROW(notebook.write(1,3,3,Direction::Horizontal,"u"));
    CHECK(notebook.read(1,3,3,Direction::Horizontal,7) == "uvigael");
    CHECK(notebook.read(1,3,3,Direction::Vertical,7) == "uvigael");
    CHECK_NOTHROW(notebook.write(1,3,3,Direction::Horizontal,"uvigael"));
    CHECK(notebook.read(1,3,3,Direction::Horizontal,7) == "uvigael");
    CHECK(notebook.read(1,3,3,Direction::Vertical,7) == "uvigael");
    CHECK_NOTHROW(notebook.write(1,3,3,Direction::Horizontal,"pasta"));
    CHECK_NOTHROW(notebook.write(1,3,3,Direction::Vertical,"pasta"));
    CHECK(notebook.read(1,3,3,Direction::Horizontal,8) == "pasta");
    CHECK(notebook.read(1,3,3,Direction::Vertical,8) == "pasta");
}

TEST_CASE("Exceptions Error") {
    ariel::Notebook notebook;
    CHECK_THROWS(notebook.read(0,0,0,Direction::Horizontal,7));
    CHECK_THROWS(notebook.read(0,0,0,Direction::Vertical,8));
    CHECK_THROWS(notebook.write(0,0,0,Direction::Horizontal,"avi"));
    CHECK_THROWS(notebook.write(0,0,0,Direction::Vertical,"abi"));
    CHECK_THROWS(notebook.read(1,450,450,Direction::Horizontal,6));
    CHECK_THROWS(notebook.read(1,450,450,Direction::Vertical,17));
    CHECK_THROWS(notebook.write(1,450,450,Direction::Horizontal,"abiabi"));
    CHECK_THROWS(notebook.write(1,450,450,Direction::Vertical,"abiabi"));
    CHECK_THROWS(notebook.read(1,450,450,Direction::Horizontal,6));
    CHECK_THROWS(notebook.read(1,450,450,Direction::Vertical,6));
}

TEST_CASE("CHECK"){
    ariel::Notebook notebook;
    notebook.write(6, 0, 0, Direction::Horizontal, "libi");
	CHECK((notebook.read(0, 0, 0, Direction::Horizontal, 4)) == ("libi"));
	notebook.write(3, 0, 0, Direction::Horizontal, "rami");
	CHECK((notebook.read(3, 0, 0, Direction::Horizontal, 4)) == ("rami"));
}

TEST_CASE("erase"){
    ariel::Notebook notebook;
    CHECK_NOTHROW(notebook.erase(0, 0, 0, Direction::Vertical, 1));
    CHECK_NOTHROW(notebook.erase(0, 0, 0, Direction::Horizontal, 2));
	CHECK_NOTHROW(notebook.erase(0, 1, 1, Direction::Vertical, 3));
}