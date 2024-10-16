#include "questions.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <map>

#include "GPL_2_text.h"

using namespace std;

namespace vector_bench{

    //Question 1 :
    void backInsert(){
        vector<string> vec_back ; 
        const char ** s = GPL_2_text;
        while(*s++)
            if(*s)
                vec_back.push_back(*s);

        cout << "vec number of elements : " << vec_back.size() << endl;

        sort(vec_back.begin(), vec_back.end()); 

        for(string s : vec_back)
            cout << s ;
        cout << endl; 
    }

    //Question 2 : 
    void frontInsert(){
        vector<string> vec_front;
        const char ** s = GPL_2_text;
        while(*s++)
            if(*s)
                vec_front.insert(vec_front.begin(), *s);

        cout << "vec number of elements : " << vec_front.size() << endl;

        sort(vec_front.begin(), vec_front.end()); 

        for(string s : vec_front)
            cout << s ;
        cout << endl;  
    }

    //Question 3 : 
    void sortEachInsert(){
        vector<string> vec_sort ; 
        const char ** s = GPL_2_text;
        while(*s++)
            if(*s){
                vec_sort.push_back(*s);
                sort(vec_sort.begin(), vec_sort.end()); 
            }

        cout << "vec number of elements : " << vec_sort.size() << endl;

        for(string s : vec_sort)
            cout << s ;
        cout << endl; 
    }

}

namespace list_bench{

    //Question 4 :

    void backInsert(){
        list<string> list_back; 
        const char ** s = GPL_2_text;
        while(*s++)
            if(*s)
                list_back.push_back(*s);
        
        cout << "Nombre d'éléments de la liste : " << list_back.size() << endl;
        list_back.sort();

        for (string s : list_back)
            cout << s;
        cout << endl;
            
    }

    void frontInsert(){
        list<string> list_front;
        const char ** s = GPL_2_text;
        while (*s++)
            if(*s)
                list_front.push_front(*s);

        cout << "Nombre d'éléments de la liste : " << list_front.size() << endl;
        list_front.sort();

        for (string s : list_front)
            cout << s;
        cout << endl;
    }

    void sortEachInsert(){
        list<string> list_sort;
        const char ** s = GPL_2_text;
        while(*s++)
            if(*s){
                list_sort.push_back(*s);
                list_sort.sort();
            }

        cout << "Nombre d'éléments de la liste : " << list_sort.size() << endl;

        for (string s : list_sort)
            cout << s;
        cout << endl;

    }
}

namespace map_bench{

    //Question 5:
    void word_count(){
       // map<string, int> map_count;
        // Question 6 : 
        map<string, int, CompareString> map_count;
       
        const char ** s = GPL_2_text;
        while(*s++)
            if(*s){ 
                auto value =  map_count.find(*s);
                if(value != map_count.end() ){
                    map_count[*s] += 1;
                }else{
                    map_count[*s] = 1 ;
                }
            }
        cout << "Taille de la map : " << map_count.size() << endl;

        unsigned long nb_words = 0 ; 
        for(auto entry : map_count){
            cout << entry.first << ":" << entry.second ; 
            nb_words += entry.second ; 
        }
        cout << endl << "il y a " << nb_words << " mots au total" << endl ; 
    }

    // Question 6 :
    int CompareString::operator() (const std::string s1, const std::string s2) const{
        for(unsigned i = 0 ; i < s1.size() ; i++){
            if(i > s2.size()){
                return 0 ;
            }else if(s1[i] < s2[i]){
                return 1 ;
            }else if(s1[i] > s2[i]){
                return 0 ;
            }
        }
        return 0;
    }

}