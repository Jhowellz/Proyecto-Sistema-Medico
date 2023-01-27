#pragma once
#include <iostream>
#include <Windows.h>
#define color SetConsoleTextAttribute //Define una "variable" que haga referencia al atributo SetConsoleTextAttribute
static HANDLE pConsole = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

/*
* Numero Maximo de pacientes
*/
const int DATOSMAXIMOSPACIENTES = 100;

/*
* Estrucutras de Datos / Pacientes
*/
typedef struct
{
	string cedula;
	string nombre;
	string tipoSangre;
	string telefono;
	string direccion;
	int edad;
	float peso;
	float estatura;
}tPacientes;
typedef struct
{
	tPacientes datosPersonales[DATOSMAXIMOSPACIENTES];
	int contador;
}tLisaPacientes; 

/*
*Visualiza el menu de gestion de los medicos
*/
int verMenuPacientes();

/*
* Muestra los datos en una tabla
* llama a un valor de tipo "tLisaPacientes"
* donde se encuentran almacenados los datos
*
* ok <--- Variable para verificacion de correcto funcionamiento
*/
void visualizarPacientes(tLisaPacientes lista, bool& ok);

/*
* Cargar datos guardados en el archivo
* llamada al tipo de archivo tLisaPacientes
* donde se iran guardando los datos
* extraidos del archivo
*/
void cargarDatosPacientes(tLisaPacientes& lista);

/*
* Funcion para agregar nuevos pacientes
* al sistema del hospital.
*
* tListaMedicos <--- guarda la estrucutra de  las citas medicas en la estructura de la "lista"
* tMedicos <--- Almacena directamente en la estructura
*/
void agregarPaciente(tLisaPacientes& lista, tPacientes pacientes);

/*
* Consultar == Buscar
* Funcion encargada de buscar "-----" en la
* lista de citas agendadaas
*
* "------" <--- dato a buscar
*/
void consultarPaciente(tLisaPacientes lista);

/*
* Funcion encargada de la eliminacion de una paciente
* por medio del uso de algoritmos
*
* posicionDato <--- Utilizada para conocer el dato a eliminar de la lista
*/
void eliminarPaciente(tLisaPacientes& lista);
int retornarPosicion(tLisaPacientes lista, string cedulaBusqueda);

/*
* Guardar los datos de los pacientes en el archvio .txt
*/
void guardarPacientes(const tLisaPacientes lista);

/*
* Menu para modificar datos de Pacientes
*/
int verMenuModificarPacientes();

/*
* Modificar los datos personales del Paciente
*
* posicionDato <--- Utilizada para conocer el dato a modificar de la lista
* tLisaPacientes <--- guarda la estrucutra de  las citas medicas en la estructura de la "lista"
* tPacientes <--- Almacena directamente en la estructura
*/
void modificarPacienteTelefono(tLisaPacientes& lista, tPacientes pacientes);
void modificarPacienteDireccion(tLisaPacientes& lista, tPacientes pacientes);
void modificarPacienteEdad(tLisaPacientes& lista, tPacientes pacientes);
void modificarPacientePeso(tLisaPacientes& lista, tPacientes pacientes);
void modificarPacienteEstatura(tLisaPacientes& lista, tPacientes pacientes);

/*
* Ordenar Datos
*/
void ordenarDatos(tLisaPacientes& lista);