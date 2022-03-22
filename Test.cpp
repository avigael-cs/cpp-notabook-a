// avigael abitbol

#include "doctest.h"
#include "Notebook.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace ariel;




TEST_CASE("notebook - good tetst") {
    Notebook notebook;
    CHECK_THROWS(notebook.write(/*page=*/1, /*row=*/0, /*column=*/0,Direction::Horizontal,"horizontal"));
    CHECK_THROWS(notebook.write(/*page=*/1, /*row=*/10, /*column=*/10, Direction::Vertical,"vertical"));
    CHECK(notebook.read(1,0,0,Direction::Horizontal,10) == "horizontal");
    CHECK(notebook.read(1,10,10,Direction::Vertical,8) == "horizontal");


    CHECK_THROWS(notebook.write(/*page=*/1, /*row=*/0, /*column=*/0,Direction::Horizontal,"horizontal"));
    CHECK_THROWS(notebook.write(/*page=*/1, /*row=*/10, /*column=*/10, Direction::Vertical,"vertical"));
    CHECK(notebook.read(1,0,0,Direction::Horizontal,10) == "horizontal");
    CHECK(notebook.read(1,10,10,Direction::Vertical,8) == "horizontal");

    CHECK_THROWS(notebook.write(1,3,3,Direction::Horizontal,"u"));
    CHECK(notebook.read(1,3,3,Direction::Horizontal,7) == "uvigael");
    CHECK(notebook.read(1,3,3,Direction::Vertical,7) == "uvigael");
    CHECK_THROWS(notebook.write(1,3,3,Direction::Horizontal,"uvigael"));
    CHECK(notebook.read(1,3,3,Direction::Horizontal,7) == "uvigael");
    CHECK(notebook.read(1,3,3,Direction::Vertical,7) == "uvigael");
    CHECK_THROWS(notebook.write(1,3,3,Direction::Horizontal,"pasta"));
    CHECK_THROWS(notebook.write(1,3,3,Direction::Vertical,"pasta"));
    CHECK(notebook.read(1,3,3,Direction::Horizontal,8) == "pasta");
    CHECK(notebook.read(1,3,3,Direction::Vertical,8) == "pasta");
}

TEST_CASE("Exceptions Error") {
    Notebook notebook;
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