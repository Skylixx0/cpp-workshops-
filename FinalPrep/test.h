#ifndef ALIK_TEST_H
#define ALIK_TEST_H
#include <iostream>
namespace alik{
    class Test{
        char* name;
        public:
        std::ostream& display(std::ostream& out = std::cout) const;
        
    };
}

#endif