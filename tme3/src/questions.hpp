#ifndef questions_h 
#define questions_h 

#include <vector>
#include <string>

namespace vector_bench {
    // Question 1 : 
    void backInsert();
    // Question 2 : 
    void frontInsert();
    // Question 3 : 
    void sortEachInsert();
}

// Question 4 : 
namespace list_bench {
    void backInsert();
    void frontInsert();
    void sortEachInsert();
}

// Question 5 : 
namespace map_bench {

    void word_count();

    // Question 6 : 
    class CompareString{
        public : 
            int operator() (const std::string s1, const std::string s2) const;
    };

}



#endif
