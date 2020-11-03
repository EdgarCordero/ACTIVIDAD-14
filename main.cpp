#include <iostream>

#include "array.h"
#include "computer.h"

using namespace std;

int main()
{
    Array<Computer> a;

    Computer c01  ("Mi computadora", "Windows 8", "COREi8", 32);
    Computer c02  ("Mi computadora", "Windows 7", "COREi8", 32);
    Computer c03  ("Mi computadora", "Windows 10", "COREi8", 32);
    Computer c04  ("Tu computadora", "Windows XP", "COREi3", 16);
    Computer c05  ("Nueva computadora", "Lynux", "COREi9", 64);

    a << c01 << c02 << c03 << c04 << c05;

    Computer c06  ("Nuestra", "Lynux", "COREi9", 64);

    Computer *ptr = a.buscar(c06);

    if(ptr != nullptr){
        cout << *ptr << endl;
    }else{
        cout << "NO EXISTE\n" << endl;
    }

    Computer c07 ("Nueva computadora", "Lynux", "COREi9", 64);

    Computer *ptr2 = a.buscar(c07);

    if(ptr2 != nullptr){
        cout << "ENCONTRADO:\n" << *ptr2 << endl;
    }else{
        cout << "NO EXISTE\n" << c06 << endl;
    }

    Computer c08  ("Mi computadora", "Windows 8", "COREi8", 32);

    Array<Computer*> ptrs= a.buscar_todos(c08);

    if(ptrs.sizeofArray() > 0){
        cout << "Coincidencias encontradas:" << endl;
        for(size_t i = 0; i < ptrs.sizeofArray(); i++){
            Computer *c = ptrs[i];
            cout << *c << endl;
        }
    }else{
        cout << "No hay coincidencias" << endl;
    }


}
