#pragma once
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#define color SetConsoleTextAttribute //Define una "variable" que haga referencia al atributo SetConsoleTextAttribute
static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //Define una senguda variable para el cambio de color
using namespace std;

/*
* Numero Maximo de Citas agendadas
*/
const int DATOSMAXIMOSCITAS = 100;

/*
* Estrucutras de Datos / Citas Medicas
*/
typedef struct
{
	string cedula;
	string nombrePaciente;
	string nombreMedico;
	string especialidadMedico;
	int hora;
	int minutos;
	int dia;
	int mes;
	int anio;
}tCitasMedicas;
typedef struct
{
	tCitasMedicas elementos[DATOSMAXIMOSCITAS];
	int contador;
}tListaCitas;

/*
* Funciones
*/

/*
* Visualiza el Menu principal de gestion del 
* sistema de hospital
*/
int verMenuPrincipal();

/*
* Visualiza el menu de gestion de las citas
*/
int verMenuCitasMedicas();

/*
* Muestra los datos en una tabla
* llama a un valor de tipo "tListaCitas" 
* donde se encuentran almacenados los datos
* 
* ok <--- Variable para verificacion de correcto funcionamiento
*/
void visualizarCitas(tListaCitas lista, bool& ok);

/*
* Cargar datos guardados en el archivo
* llamada al tipo de archivo tlistaCitas
* donde se iran guardando los datos
* extraidos del archivo
*/
void cargarDatosCitas(tListaCitas& lista);

/*
* Funcion para agregar nuevas citas
* al sistema de hospital.
* 
* tListaCitas <--- guarda la estrucutra de  las citas medicas en la estructura de la "lista"
* tCitasMedicas <--- Almacena directamente en la estructura
* 
* agendarUnaCita == Agregar una nueva cita.
*/
void agendarUnaCita(tListaCitas& lista, tCitasMedicas citas);

/*
* Verificar el horario de cita agendada 
* no coincida con otro en el mismo horario
*/
bool verificarCita(tListaCitas lista, tCitasMedicas citas, bool& varOk);

/*
* Consultar == Buscar
* Funcion encargada de buscar "-----" en la
* lista de citas agendadaas
* 
* "------" <--- dato a buscar
*/
void consultarCita(tListaCitas lista);

/*
* Funcion encargada de la eliminacion de una cita
* por medio del uso de algoritmos
* 
* posicionDato <--- Utilizada para conocer el dato a eliminar de la lista
*/
void eliminarCita(tListaCitas& lista);

/*
* Retorna la posicion de la lista en base a la busqueda
* de un valor unico --> Cedula
*/
int retornarPosicion(tListaCitas lista, string cedulaBusqueda);

/*
* Guardar los datos de las citas en el archvio .txt
*/
void guardarCitas(const tListaCitas lista);

/*
* Menu para la reprogramar citas
* 
* Reprogramar <--> Modificar
*/
int verMenuReprogramarCita();

/*
* Reprogramar Citas en base a la hora
* o fecha de la misma.
* 
* posicionDato <--- Utilizada para conocer el dato a modificar de la lista
* tListaCitas <--- guarda la estrucutra de  las citas medicas en la estructura de la "lista"
* tCitasMedicas <--- Almacena directamente en la estructura
*/
void reprogramarCitaFecha(tListaCitas& lista, tCitasMedicas citas);
void reprogramarCitasHora(tListaCitas& lista, tCitasMedicas citas);

/*
* Ordenamiento de las citas por medio del 
* metodo de "------"
*/
void ordenarLista(tListaCitas& lista);