mkdir -p build
FILE="$1"
echo "
#include \"../src/contest/template.cpp\"
#include \"../$FILE\"
" >build/temp.cpp
g++ -Wall -Wextra -Wfatal-errors -Wconversion -std=c++17 build/temp.cpp && rm a.out build/temp.cpp
