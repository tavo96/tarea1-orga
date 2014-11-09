// queue::push/pop
#include "Mascota.h"
#include "Evaluador.h"
#include <iostream>
#include <list>
#include <fstream>
using namespace std;

//Escribe los datos del objeto mascota dado en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varias mascotas en un solo archivo
void escribir(string nombre_archivo, Mascota*mascota, int posicion)
{
    ofstream out(nombre_archivo.c_str(),ios::in|ios::binary);//Abrimos el archivo en modo binario
    out.seekp(24*posicion);//Especificamos en que posicion se escribira
    out.write((char*)&mascota->edad,4);//Escribimos la edad y cuanto espacio en la ram tendra
    out.write(mascota->nombre.c_str(),20);//Escribimos el nombre y cuanto espacion en la ram tendra
    out.close();//Cerramos el archivo


}

//Devuelve una mascota previamente escrita (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varias mascotas de un solo archivo
Mascota* leer(string nombre_archivo, int posicion)
{
    ifstream in(nombre_archivo.c_str());//Abrimos el archivo
    in.seekg(24*posicion);// Nos situamos en la posicion a leer
    char nombre[20];//Declaramos una variable char para guardar el nombre de la mascota
    int edad;// Declaramos una variable int para guardar el nombre de la mascota
    in.read((char*)&edad,4);//Obtenemos la edad en modo lectura y la guardamos en la variable declarada anteriormente
    in.read(nombre,20);//Obtenemos el nombre en modo lectura y la guardamos en la variable declarada anteriormente
    in.close();// Cerramos el archivo

    return new Mascota(edad,nombre);// Devolvemos la edad y el nombre en al posicion dada
}


//Devuelve un vector que contenga todas las mascotas previamente escritas (con la funcion escribir()) en un archivo binario con nombre dado
//Nota: El vector debe contener las mascotas ordenadas de acuerdo a la posicion en la que se escribieron
vector<Mascota*> leerTodos(string nombre_archivo)
{
    vector<Mascota*>respuesta;//Creamos un vector
    ifstream in(nombre_archivo.c_str());// Abrimos el archivo
    in.seekg(0,ios::end);// Nos situamos al final del programa
    int tam = in.tellg()/24;//Obtenemos el tamaño del archivo
    in.seekg(0);//
//Creamos un ciclo
    for(int i = 0; i < tam;i++)
    {
        int edad; //Declaramos una variable char para guardar el nombre de la mascota
        char nombre[20];//Declaramos una variable char para guardar el nombre de la mascota

        in.read((char*)&edad,4);//Obtenemos la edad en modo lectura y la guardamos en la variable declarada anteriormente
        in.read(nombre,20);//Obtenemos el nombre en modo lectura y la guardamos en la variable declarada anteriormente


        respuesta.push_back(new Mascota(edad,nombre));//Se ingresa los objetos en el vector


        }
     in.close();// Cerramos el archivo
    return respuesta;//Retornamos el Vector
}

int main ()
{
    evaluar();
    return 0;
}
