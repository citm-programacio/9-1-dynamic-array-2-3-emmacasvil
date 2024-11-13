// Dynamic_Arrays_2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std; 

int arrFunction(int*& arr, int num, int len) 
{
    int* auxArr = new int[len]; //Dynamic auxiliary array to put in order the values without losing information
    int auxSort; // Auxiliary int for the bubble sort
    arr[len - 1] = num; //We set the value entered to the last position

    for (int i = 0; i < len; i++) //Copy the original array into the auxiliary one
    {
        auxArr[i] = arr[i];
    }

    for (int i = 0; i < len - 1;  i++) //Bubble sort
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (auxArr[j] > auxArr[j + 1])
            {
                auxSort = auxArr[j]; 
                auxArr[j] = auxArr[j + 1]; 
                auxArr[j + 1] = auxSort; 
            }
        }
    }

    for (int i = 0; i < len; i++) //Print the final result
    {
        cout << auxArr[i] << "  "; 
    }

    cout << endl; 
    
    delete[] arr; //Delete and free the memory
    arr = auxArr; //Pointer to the new array

    return *arr; //The return must be a pointer
}

int main()
{
    int myLen = 0;
    int* myArr = nullptr; //We first set the array to nullptr
    int myNum;

    while (myLen < 10) //We limit the loop
    {
        cout << "Add a number to the array: ";
        cin >> myNum;
        myLen++;
        cout << endl;

        int* tempArr = new int[myLen];
        
        if (myArr == nullptr)
        {
            myArr = new int[1]; 
        }
        else if (myArr != nullptr) {
            for (int i = 0; i < myLen - 1; i++) {
                tempArr[i] = myArr[i];  
            }
        }
        delete[] myArr;  
        myArr = tempArr;  

        arrFunction(myArr, myNum, myLen);
    }
}
    

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
