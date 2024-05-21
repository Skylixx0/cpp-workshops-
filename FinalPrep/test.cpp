#include "test.h"
#include <iostream>
using namespace std;
namespace alik{
    std::ostream& Test::display(std::ostream& out){
        out << "your name is: " << this
    };
}