#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>


template <class T>
class Array
{
    private:
        T *arreglo;
        size_t tam;
        size_t cont;
        const static size_t MAX =5;
    public:
        Array();
        ~Array();

        void insertAtEnd(T e);
        void insertAtStart(T e);
        void insertar(const T& e, size_t p);

        T operator[](size_t p){
            return arreglo[p];
        }

        size_t sizeofArray();

        void eliminar_final();
        void eliminar_inicio();
        void eliminar(size_t p);


        void expandir();

        T* buscar(const T& e);

        Array<T*> buscar_todos(const T& e);

        friend Array<T>& operator<<(Array<T> &a, const T& b){

        a.insertAtEnd(b);

        return a;

        }


};

using namespace std;
template<class T>
Array<T>::Array()
{
    arreglo = new T[MAX];
    cont = 0;
    tam = MAX;
}

template<class T>
Array<T>::~Array()
{
    delete[] arreglo;
}

template<class T>
void Array<T>::expandir(){
    T *nuevo = new T[tam+MAX];

    for (size_t i = 0; i < cont; i++){
        nuevo[i] = arreglo[i];
    }
    delete[] arreglo;
    arreglo = nuevo;

    tam = tam + MAX;
}

template<class T>
void Array<T>::insertAtEnd(T e){

    if(cont == tam){
        expandir();
    }
    arreglo[cont] = e;
    cont++;

}

template<class T>
void Array<T>::insertAtStart(T e){

    if(cont == tam){
        expandir();
    }

    for (size_t i = cont; i > 0; i--){
        arreglo[i] = arreglo[i - 1];
    }
    arreglo[0] = e;
    cont++;
}

template<class T>
void Array<T>::insertar(const T& e, size_t p){

    if(p >= cont){
        cout << "POSICION NO VALIDA" << endl;
        return;
    }
    if(cont == tam){
        expandir();
    }
    for(size_t i = cont; i > p; i--){
        arreglo[i] = arreglo[i-1];
    }
    arreglo[p] = e;
    cont++;
}

template<class T>
size_t Array<T>::sizeofArray(){
    return cont;
}

template<class T>
void Array<T>::eliminar_final(){
    if (cont == 0){
        cout << "ARREGLO VACIO" << endl;
        return;
    }
    cont --;
}

template<class T>
void Array<T>::eliminar_inicio(){

    if (cont == 0){
        cout << "ARREGLO VACIO" << endl;
        return;
    }

    for (size_t i = 0; i< cont-1; i++){
        arreglo[i] = arreglo[i+1];
    }
    cont--;
}
template<class T>
void Array<T>::eliminar(size_t p){
    if (cont == 0){
        cout << "ARREGLO VACIO" << endl;
        return;
    }
    for(size_t i = p; i < cont - 1; i++){
        arreglo[i] = arreglo[i+1];
    }
    cont--;
}

template<class T>
T* Array<T>::buscar(const T& e){

    for(size_t i = 0; i < cont; i++){
        if(e == arreglo[i]){
            return &arreglo[i];
        }
    }
    return nullptr;

}

template<class T>
Array<T*> Array<T>::buscar_todos(const T& e){
    Array<T*> ptrs;

    for(size_t i = 0; i < cont; i++){
        if(e == arreglo[i]){
            ptrs.insertAtEnd(&arreglo[i]);
        }
    }
    return ptrs;
}

#endif // ARRAY_H
