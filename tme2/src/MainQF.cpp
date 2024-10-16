//Laila Lahkim Bennani 21102544 Ivan Mulot-Radojcic 21102722
#include "QuestionFacultative.hpp"

using namespace tme2qf; 
using namespace std;

Box testFunction(Box ab){
        std::cerr << " + testFunction() called." << std::endl;
        Box area ("area", 0, 0, 15, 30);
        if(area.intersect(ab)){
            std::cerr << " | Intersection between:" << std::endl;
            std::cerr << " |  " << area << std::endl;
            std::cerr << " |  " << ab << std::endl;
            std::cerr << " | Gives" << std::endl;
            std::cerr << " |  " << area.getIntersection(ab) << std::endl;
        } else 
            std::cout << " No Intersection" << std::endl;
        return ab;
}

Box testFunction2(Box ab){
        std::cerr << " + testFunction() called." << std::endl;
        Box area ("area", 0, 0, 15, 30);
        if(area.intersect(ab)){
            std::cerr << " | Intersection between:" << std::endl;
            std::cerr << " |  " << area << std::endl;
            std::cerr << " |  " << ab << std::endl;
            std::cerr << " | Gives" << std::endl;

            //on peut changer ce code car on a redéfini l'opérateur && pour la classe box
            std::cerr << " |  " << (area && ab) ; //<< std::endl;
        } else 
            std::cout << " No Intersection" << std::endl;
        return ab;
}

int main(int argc, char* argv[]){
            {
                Box b0;

                Box b1 ("b1", 15, 10, 30, 20);
                std::cerr << "Allocated boxes: " << Box::getAllocateds() << std::endl;  

                std::cerr << "\nTest 1: " << std::endl << b1 ; std::cerr << std::endl;


                testFunction(b1);
                  
                b1.inflate (5,5,5,5);
                std::cerr << "\nTest 2 :" << std::endl; b1.print(std::cerr); std::cerr << std::endl;
                testFunction2(b1);

                std::cerr << "\nTest 3 : " << std::endl;
                std::cerr << "+ Box \"" << b1.getName() << "\" empty: " << boolalpha << b1.isEmpty() << std::endl;
                std::cerr << "| Box \"" << b1.getName() << "\" width: " << boolalpha << b1.getWidth() << std::endl;
                std::cerr << "| Box \"" << b1.getName() << "\" height: " << boolalpha << b1.getHeight() << std::endl;
                b1.inflate( -11 );
                std::cerr << "+ Box \"" << b1.getName() << "\" empty: " << boolalpha << b1.isEmpty() << " (inflated -11) " << std::endl;
                std::cerr << "| Box \"" << b1.getName() << "\" width: " << boolalpha << b1.getWidth() << std::endl;
                std::cerr << "| Box \"" << b1.getName() << "\" height: " << boolalpha << b1.getHeight() << std::endl;
            }
            std::cerr << "Allocated boxes: " << Box::getAllocateds() << std::endl;
            return 0;
}