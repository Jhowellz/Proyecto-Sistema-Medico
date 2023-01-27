#pragma once
#include <iostream>
#include <Windows.h>
#define color SetConsoleTextAttribute //Define una "variable" que haga referencia al atributo SetConsoleTextAttribute
static HANDLE mConsole = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;

/*
* Numero Maximo de Citas agendadas
*/
const int DATOSMAXIMOS = 100;

/*
* Estrucutras de Datos / Medicos
*/
typedef struct
{
	string nombre;
	string cedula;
	string especialidad;
	string telefono;
	int edad;
}tMedicos;
typedef struct
{
	tMedicos datos[DATOSMAXIMOS];
	int contador;
}tListaMedicos;

/*
* Visualiza el menu de gestion de los medicos
*/
int verMenuMedicos();

/*
* Muestra los datos en una tabla
* llama a un valor de tipo "tListaMedicos"
* donde se encuentran almacenados los datos
*
* ok <--- Variable para verificacion de correcto funcionamiento
*/
void visualizarMedicos(tListaMedicos lista, bool& ok);

/*
* Cargar datos guardados en el archivo
* llamada al tipo de archivo tListaMedicos
* donde se iran guardando los datos
* extraidos del archivo
*/
void cargarDatosMedicos(tListaMedicos& lista);

/*
* Funcion para agregar nuevos medicos
* al sistema del hospital.
*
* tListaMedicos <--- guarda la estrucutra de  las citas medicas en la estructura de la "lista"
* tMedicos <--- Almacena directamente en la estructura
*/
void agregarMedico(tListaMedicos& lista, tMedicos medicos);

/*
* Consultar == Buscar
* Funcion encargada de buscar "-----" en la
* lista de citas agendadaas
*
* "------" <--- dato a buscar
*/
void consultarMedico(tListaMedicos lista);

/*
* Funcion encargada de la eliminacion de una medico
* por medio del uso de algoritmos
*/
void eliminarMedico(tListaMedicos& lista);

/*
* Retorna la posicion del medico por medio
* de la busqueda de la cedula del mismo
*/
int retornarPosicion(tListaMedicos lista, string cedulaBusqueda);

/*
* Guardar los datos de los medicos en el archvio .txt
*/
void guardarMedicos(const tListaMedicos lista);

/*
* Menu para modificar datos de MEdicos
*/
int verMenuModificarMedico();

/*
* Modificar los datos personales del Medico
* 
* posicionDato <--- Utilizada para conocer el dato a modificar de la lista
* tListaMedicos <--- guarda la estrucutra de  las citas medicas en la estructura de la "lista"
* tMedicos <--- Almacena directamente en la estructura
*/
void modificarMedicoNombre(tListaMedicos& lista, tMedicos medicos);
void modificarMedicoCedula(tListaMedicos& lista, tMedicos medicos);
void modificarMedicoEspecialidad(tListaMedicos& lista, tMedicos medicos);
void modificarMedicoTelefono(tListaMedicos& lista, tMedicos medicos);
void modificarMedicoEdad(tListaMedicos& lista, tMedicos medicos);

/*
* Ordenamiento de las citas por medio del
* metodo de "------"
*/
void ordenarListaMedicos(tListaMedicos& lista);