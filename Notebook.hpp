#include <iostream>
#include <map>
#include "Direction.hpp"
#include <vector>
#include <string>


using namespace std;
namespace ariel
{
    const int line = 100;
    class Notebook{
        private:



        public:
            void write(int page, int line , int colum, Direction dir , string msg);
            std::string read(int page, int line, int colum, Direction dir, int num);
            void erase(int page, int line, int colum, Direction dir, int len );
            void show(int page);
            
            
    };
}
