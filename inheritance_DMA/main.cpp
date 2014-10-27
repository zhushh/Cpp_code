#include <iostream>
#include "dma.h"
#include <map>
using std::cout;
using std::endl;
int main() {
    baseDMA shirt("Portabelly", 8);
    lacksDMA balloon("red", "Blimpo", 4);
    hasDMA map("Mercator", "Buffalo Keys", 5);
     
    cout << "Displaying baseDMA object:\n";
    cout << shirt << endl;
    cout << "Displaying lacksDMA object:\n";
    cout << balloon << endl;
    cout << "Displaying hasDMA object:\n";
    cout << map << endl;
     
    hasDMA map2;
    map2 = map;
    map2 = map2;
    cout << "Result of hasDMA assignment:\n";
    cout << map2 << endl;
    return 0;
}
 


