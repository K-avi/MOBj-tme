#include "questions.hpp"
#include "Timer.hpp"
using namespace list_bench;
using namespace map_bench;
int main ( int argc, char* argv[] ){
    
    //Question 1 : 
    Timer t1;
    t1.start();
    backInsert();
    t1.stop();

    std::cout << "Question 1, temps écoulé : " << t1 << std::endl;

    // Question 2 : 
    Timer t2;
    t2.start();
    frontInsert();
    t2.stop();

    std::cout << "Question 2, temps écoulé : " << t2 << std::endl;

    // Question 3 :
    Timer t3;
    t3.start();
    sortEachInsert();
    t3.stop();
    std::cout << "Question 3, temps écoulé : " << t3 << std::endl; 

    // Question 4 : 

    // test de back insert sur liste : 
    Timer t4;
    t4.start();
    list_bench::backInsert();
    t4.stop();

    std::cout << "Question 4 list_bench::backInsert(), temps écoulé : " << t4 << std::endl;

    // test de front insert sur liste 2 : 
    Timer t5;
    t5.start();
    list_bench::frontInsert();
    t5.stop();

    std::cout << "Question 4 list_bench::frontInsert(), temps écoulé : " << t5 << std::endl;

    // test de sort each insert sur liste :
    Timer t6;
    t6.start();
    list_bench::sortEachInsert();
    t6.stop();
    std::cout << "Question 4 list_bench::sortEachInsert(), temps écoulé : " << t6 << std::endl; 

    //Question 5 : 
    Timer t7;
    t7.start();    
    word_count();
    t7.stop();
    std::cout << "Question 5, temps écoulé : " << t7 << std::endl; 
    
    return 0;
}
