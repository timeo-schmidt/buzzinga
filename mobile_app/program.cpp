#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    
    for (int i = 1; i < argc; ++i)
        cout << argv[i];
    
    cout << "; test finished \n";

    return 0;
}