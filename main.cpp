
#include <Helper.h>
#include "Cat.h"


int main() { 
    //std::cout << "Hello, world!\n";

    cat myCat("Sofi", "Striped", "Gray", "Green", 3, 'M');
    myCat.create_pasaport(15, 10, 2024);

    myCat.print_details();

    Helper helper;
    helper.help();

    return 0;
}
