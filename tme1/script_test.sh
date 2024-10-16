#!/bin/bash
cmake CMakeLists.txt
make all 
./ctme1 2> trace_locale 

echo "appel a valgrind :" 
valgrind ./ctme1

echo "appel a diff : "
diff trace_locale trace_cours.txt 
