#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include "GestionCitasMedicas.h"

using namespace std;

/*
* Menu Principal el sistema de hospital
*/
int verMenuPrincipal()
{
	int opcionMenu;
	cout << "\n\n\n\n" << endl;
	color(hConsole, 7);
	cout << "\t\t\t\t\t\t----------------------------------------------------" << endl;
	cout << "\t\t\t\t\t\t|1. Gestionar citas medicas" << setw(25) << right  << "|" << endl;
	cout << "\t\t\t\t\t\t|2. Gestionar medicos del hospital" << setw(18) << right << "|" << endl;
	cout << "\t\t\t\t\t\t|3. Gestionar pacientes" << setw(29) << right << "|" << endl;
	cout << "\t\t\t\t\t\t|0. SALIR" << setw(43) << right << "|" << endl;
	cout << "\t\t\t\t\t\t----------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\tSeleccione una opcion: ";
	cin >> opcionMenu;

	return opcionMenu;
}

/*
* Menu de gestion citas medicas
*/
int verMenuCitasMedicas()
{
	int opcionMenu;

	cout << "\n\n\n" << endl;
	color(hConsole, 6);
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t .--.   .-.  .-----.   .--.    .--. " << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t: .--'  : :  `-. .-'  : .; :  : .--'" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t: :     : :    : :    :    :  `. `. " << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t: :__   : :    : :    : :: :   _`, :" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t`.__.'  :_;    :_;    :_;:_;  `.__.'" << endl;
	cout << "\n\n" << endl;
	color(hConsole, 7);
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t-------------------------------------" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t|1. Visualizar la tabla de citas" << setw(5) << right << "|" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t|2. Agendar una cita" << setw(17) << right << "|" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t|3. Finalizar/Eliminar una cita" << setw(6) << right << "|" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t|4. Consultar una cita" << setw(15) << right << "|" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t|5. Reprogramar citas" << setw(16) << right << "|" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t|0. SALIR" << setw(28) << right << "|" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t-------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\tSeleccione una opcion: ";
	cin >> opcionMenu;

	return opcionMenu;
 }

/*
* Visualizar tabla de citas
*/
void visualizarCitas(tListaCitas lista, bool& ok)
{
	ok = false;
	cout << "\n\n\n\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t======CITAS MEDICAS=======\n" << endl; 
	color(hConsole, 2);
	cout << "\t\t\t\t-------------------------------------------------------------------------------" 
		<< "-----------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t|" << setw(15) << left << "CEDULA" << "|"
		<< setw(40) << left << "NOMBRE" << "|"
		<< setw(30) << left << "MEDICO" << "|"
		<< setw(25) << left << "ESPECIALIDAD" << "|"
		<< setw(20) << left << "HORA" << "|"
		<< setw(25) << left << "FECHA" << "|" << endl;
	cout << "\t\t\t\t-------------------------------------------------------------------------------"
		<< "-----------------------------------------------------------------------------------" << endl;
	color(hConsole, 7);
	for (int i = 0; i < lista.contador; i++)
	{
		cout << "\t\t\t\t|" << setw(15) << left << lista.elementos[i].cedula << "|"
			<< setw(40) << left << lista.elementos[i].nombrePaciente << "|"
			<< setw(30) << left << lista.elementos[i].nombreMedico << "|"
			<< setw(25) << left << lista.elementos[i].especialidadMedico << "|"
			<< setw(0) << left << lista.elementos[i].hora << ":" << lista.elementos[i].minutos
			<< setw(16) << left << setw(18) << right << "|" << lista.elementos[i].dia << "/"
			<< lista.elementos[i].mes << "/" << lista.elementos[i].anio
			<< setw(16) << right << "|" << endl;
		cout << "\t\t\t\t-------------------------------------------------------------------------------"
			<< "-----------------------------------------------------------------------------------" << endl;
	}
}

/*
* Cargar datos  
*/
void cargarDatosCitas(tListaCitas& lista)
{
	char aux;
	ifstream archivo;
	lista.contador = 0;
	archivo.open("Registro_Citas.txt");
	if (!(archivo.is_open()))
		cout << "\aError al abrir el archivo" << endl;
	else
	{
		//cout << "Archivo abierto!!" << endl;  //<---- Debuggin
		archivo >> lista.elementos[lista.contador].cedula;
		while ((lista.elementos[lista.contador].cedula != "XXX") && (lista.contador < DATOSMAXIMOSCITAS))
		{
			archivo.ignore();
			getline(archivo, lista.elementos[lista.contador].nombrePaciente);
			getline(archivo, lista.elementos[lista.contador].nombreMedico);
			getline(archivo, lista.elementos[lista.contador].especialidadMedico);
			archivo >> lista.elementos[lista.contador].hora;
			archivo >> lista.elementos[lista.contador].minutos;
			archivo >> lista.elementos[lista.contador].dia;
			archivo >> lista.elementos[lista.contador].mes;
			archivo >> lista.elementos[lista.contador].anio;
			archivo.get(aux);
			lista.contador++;
			archivo >> lista.elementos[lista.contador].cedula;
		}
		archivo.close();
	}
}

/*
* Guardar Datos en Registro_Citas.txt
*/
void guardarCitas(const tListaCitas lista)
{
	ofstream arhivo;
	arhivo.open("Registro_Citas.txt");
	for (int i = 0; i < lista.contador; i++)
	{
		arhivo << lista.elementos[i].cedula << endl;
		arhivo << lista.elementos[i].nombrePaciente << endl;
		arhivo << lista.elementos[i].nombreMedico << endl;
		arhivo << lista.elementos[i].especialidadMedico << endl;
		arhivo << lista.elementos[i].hora << endl;
		arhivo << lista.elementos[i].minutos << endl;
		arhivo << lista.elementos[i].dia << endl;
		arhivo << lista.elementos[i].mes << endl;
		arhivo << lista.elementos[i].anio << endl;
		arhivo << endl;
	}
	arhivo << "XXX" << endl;
	arhivo.close();
}

/*
* Agendar una nueva cita
*/
void agendarUnaCita(tListaCitas& lista, tCitasMedicas citas)
{
	bool varOK;
	string datosCorrectos, retorno;

	cout << "\n\n\n\n\n\n\n\n" << endl;
	if (lista.contador > DATOSMAXIMOSCITAS)
	{
		color(hConsole, 4);
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-----------------" << endl;
		cout << "\a\t\t\t\t\t\t\t\t\t\t\t\t\tLista Llena!!|" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-----------------" << endl;
		color(hConsole, 7);
	}
	else
	{
		do
		{
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t=====Agendar una Cita=====" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tCedula: ";
			cin >> citas.cedula;
			cin.ignore();
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tNombre y Apellido del Paciente: ";
			getline(cin, citas.nombrePaciente);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tNombre y  Apellido del Medico encargado: ";
			getline(cin, citas.nombreMedico);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tEspecialidad del medico: ";
			getline(cin, citas.especialidadMedico);
			do
			{
				color(hConsole, 3);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------------------------------------------" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t|Sistema horario de 24 horas" << setw(24) << right << "|" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t|Horario de Atencion (7:00 - 12:00 y 14:00 - 18:00)|" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------------------------------------------" << endl;
				color(hConsole, 7);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\tHora (hora minutos): ";
				cin >> citas.hora >> citas.minutos;
				if ((citas.hora < 7 || citas.hora >= 18 || citas.hora == 13 || citas.hora == 12)
					|| (citas.minutos < 0 || citas.minutos > 59))
				{
					color(hConsole, 4);
					cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t\t|   \aERROR!!   |" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------" << endl;
					color(hConsole, 7);
				}
			} while ((citas.hora < 7 || citas.hora >= 18 || citas.hora == 13 || citas.hora == 12)
				|| (citas.minutos < 0 || citas.minutos > 59));
			do
			{
				cout << "\t\t\t\t\t\t\t\t\t\t\t\tFecha(dd/mm/yyyy): ";
				cin >> citas.dia >> citas.mes >> citas.anio;
				if (citas.dia < 1 || citas.dia > 31
					|| citas.mes < 1 || citas.mes > 12
					|| citas.anio < 2022)
				{
					color(hConsole, 4);
					cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t\t|   \aERROR!!   |" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------" << endl;
					color(hConsole, 7);
				}
			} while (citas.dia < 1 || citas.dia > 31
				|| citas.mes < 1 || citas.mes > 12
				|| citas.anio < 2022);
			if (verificarCita(lista, citas, varOK))
			{
				color(hConsole, 4);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t|  \aCita no posible en ese horario     |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
				color(hConsole, 7);
			}
			else
			{
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------------" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t\tNombre: " << citas.nombrePaciente << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t\tCedula: " << citas.cedula << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t\tMedico: " << citas.nombreMedico << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t\tEspecialidad: " << citas.especialidadMedico << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t\tHorario: " << citas.hora << ":" << citas.minutos << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t\tFecha: " << citas.dia << "/" << citas.mes << "/" << citas.anio << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------------" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t\tDatos Correctos(s/n)?: ";
				cin >> datosCorrectos;
				/*
				* datosCorrectos <--- Pregunta si los datos sean correctas para guardarlos
				*					  o ingresar nuevos
				*/
				if (datosCorrectos == "s" || datosCorrectos == "S")
				{
					system("cls");
					color(hConsole, 10);
					cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t\t|  \aCita correctamente agendada  |" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------" << endl;
					color(hConsole, 7);
					lista.elementos[lista.contador] = citas;
					lista.contador++;
					datosCorrectos = "n";
				}
				else
				{
					cout << "\t\t\t\t\t\t\t\t\t\t\t\tIngresar otros datos(s/n)?: ";
					cin >> datosCorrectos;
					system("cls");
				}
			}
		} while (datosCorrectos == "s" || datosCorrectos == "S");
	}
}

/*
* Verifica si la cita esta disponible en el horario / dias
*/
bool verificarCita(tListaCitas lista, tCitasMedicas citas, bool& varOk)
{
	varOk = false;
	for (int i = 0; i < lista.contador; i++)
	{
		if ((lista.elementos[i].dia = citas.dia) 
			&& (lista.elementos[i].hora == citas.hora)
			&& (lista.elementos[i].minutos == citas.minutos)
			&& (lista.elementos[i].dia == citas.dia)
			&& (lista.elementos[i].mes == citas.mes)
			&& (lista.elementos[i].anio == citas.anio)
			&& (lista.elementos[i].especialidadMedico == citas.especialidadMedico)
			&& (lista.elementos[i].nombreMedico == citas.nombreMedico))
		{
			varOk = true;
		}
	}
	return varOk;
}

/*
* Eliminar una cita
*/
void eliminarCita(tListaCitas& lista)
{
	int posicion;
	string cedula, sino;

	cout << "\n\n\n\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t    =====ELIMINAR UNA CITA=====\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t------------------------------------" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t|Ingrese el N# para eliminar la cita|" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t|perteneciente a este               |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t------------------------------------" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\tN# Cedula: ";
	cin >> cedula;
	posicion = retornarPosicion(lista, cedula);
	if (posicion == -1)
	{
		system("cls");
		color(hConsole, 12);
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-----------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\a|Cita no encontrada!! |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-----------------------" << endl;
		color(hConsole, 7);
	}
	else
	{
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t| Esta segur@ de eliminar la cita(s/n)?: ";
		cin >> sino;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------------------------------" << endl;

		if(sino == "s")
		{
			for (int i = posicion; i < lista.contador; i++)
			{
				lista.elementos[i] = lista.elementos[i + 1];
			}
			lista.contador--;
			system("cls");
			color(hConsole, 10);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t----------------------" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t| \a Cita eliminada   |" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t----------------------" << endl;
			color(hConsole, 7);
		}
	}
}
int retornarPosicion(tListaCitas lista, string cedulaBusqueda)
{
	int poisicion = -1;

	for (int i = 0; i < lista.contador; i++)
	{
		if (lista.elementos[i].cedula == cedulaBusqueda)
		{
			poisicion = i;
		}
	}
	return poisicion;
}

/*
* Consultar las una cita programada
* por medio del numero de cedula.
*/
void consultarCita(tListaCitas lista)
{
	int posicion;
	string cedula;

	cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t=====Consultar Cita======\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\tN# de Cedula: ";
	cin >> cedula;
	posicion = retornarPosicion(lista, cedula);
	if (posicion == -1)
	{
		system("cls");
		color(hConsole, 12);
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t-----------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t| \aCita no encontrada |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t-----------------------" << endl;
		color(hConsole, 7);
	}
	else
	{
		color(hConsole, 2);
		cout << "\t\t\t-------------------------------------------------------------------------------"
			<< "-----------------------------------------------------------------------------------" << endl;
		cout << "\t\t\t|" << setw(15) << left << "CEDULA" << "|"
			<< setw(40) << left << "NOMBRE" << "|"
			<< setw(30) << left << "MEDICO" << "|"
			<< setw(25) << left << "ESPECIALIDAD" << "|"
			<< setw(20) << left << "HORA" << "|"
			<< setw(25) << left << "FECHA" << "|" << endl;
		cout << "\t\t\t-------------------------------------------------------------------------------"
			<< "-----------------------------------------------------------------------------------" << endl;
		color(hConsole, 7);
		for (int i = 0; i < lista.contador; i++)
		{
			if (i == posicion)
			{
				cout << "\t\t\t|" << setw(15) << left << lista.elementos[i].cedula << "|"
					<< setw(40) << left << lista.elementos[i].nombrePaciente << "|"
					<< setw(30) << left << lista.elementos[i].nombreMedico << "|"
					<< setw(25) << left << lista.elementos[i].especialidadMedico << "|"
					<< setw(0) << left << lista.elementos[i].hora << ":" << lista.elementos[i].minutos
					<< setw(16) << left << setw(16) << right << "|" << lista.elementos[i].dia << "/"
					<< lista.elementos[i].mes << "/" << lista.elementos[i].anio
					<< setw(17) << right << "|" << endl;
				cout << "\t\t\t-------------------------------------------------------------------------------"
					<< "-----------------------------------------------------------------------------------" << endl;
			}
		}
		system("pause");
		system("cls");
	}
	
}

/*
* Repogramar o modificar citas
*/
int verMenuReprogramarCita()
{
	int opcionMenu;

	cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "      Reprogramar Horario" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "-------------------------------" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "| 1. Reprogramar Fecha         |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "| 2. Reprogramar Hora          |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "| 0. SALIR                     |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "-------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\tSeleccione una opcion: ";
	cin >> opcionMenu;

	return opcionMenu;

}
void reprogramarCitaFecha(tListaCitas& lista, tCitasMedicas citas)
{
	string cedula, sino;
	int posicion;
	bool varOK;
	tListaCitas auxliar;

	cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "=========Reprogramar Fecha========" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "N# de Cedula: ";
	cin >> cedula;
	posicion = retornarPosicion(lista, cedula);
	if (posicion == -1)
	{
		system("cls");
		color(hConsole, 12);
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t-----------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t| \aCita no encontrada |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t-----------------------" << endl;
		color(hConsole, 7);
	}
	else
	{
		cout << "\t\t\t\t-------------------------------------------------------------------------------"
			<< "-----------------------------------------------------------------------------------" << endl;
		cout << "\t\t\t\t|" << setw(15) << left << "CEDULA" << "|"
			<< setw(40) << left << "NOMBRE" << "|"
			<< setw(30) << left << "MEDICO" << "|"
			<< setw(25) << left << "ESPECIALIDAD" << "|"
			<< setw(20) << left << "HORA" << "|"
			<< setw(25) << left << "FECHA" << "|" << endl;
		cout << "\t\t\t\t-------------------------------------------------------------------------------"
			<< "-----------------------------------------------------------------------------------" << endl;
		for (int i = 0; i < lista.contador; i++)
		{
			if (i == posicion)
			{
				cout << "\t\t\t\t|" << setw(15) << left << lista.elementos[i].cedula << "|"
					<< setw(40) << left << lista.elementos[i].nombrePaciente << "|"
					<< setw(30) << left << lista.elementos[i].nombreMedico << "|"
					<< setw(25) << left << lista.elementos[i].especialidadMedico << "|"
					<< setw(0) << left << lista.elementos[i].hora << ":" << lista.elementos[i].minutos
					<< setw(16) << left << setw(16) << right << "|" << lista.elementos[i].dia << "/"
					<< lista.elementos[i].mes << "/" << lista.elementos[i].anio
					<< setw(17) << right << "|" << endl;
				cout << "\t\t\t\t-------------------------------------------------------------------------------"
					<< "-----------------------------------------------------------------------------------" << endl;
			}
		}
		do
		{
			/*
			* Ingreso de la nueva fecha
			*/
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tFecha(dd/mm/yyyy): ";
			/*
			* Intercambia los datos de la lista 
			* en la posicion establecidad con 
			* la estrucutura citas
			*/
			citas = lista.elementos[posicion];
			cin >> citas.dia >> citas.mes >> citas.anio; //Remplazara los nuevos datos
			if (citas.dia < 1 || citas.dia > 31
				|| citas.mes < 1 || citas.mes > 12
				|| citas.anio < 2022)
			{
				color(hConsole, 12);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t|   \aERROR!!   |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------" << endl;
				color(hConsole, 7);
			}
		} while (citas.dia < 1 || citas.dia > 31
			|| citas.mes < 1 || citas.mes > 12
			|| citas.anio < 2022);
		/*
		* Variable auxiliar 
		*/
		auxliar.elementos[posicion] = citas;
		if (verificarCita(lista, citas, varOK))
		{
			system("cls");
			color(hConsole, 12);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t|  \aCita no posible en ese horario     |" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
			color(hConsole, 7);
		}
		else
		{
			cout << "\n\n\n\n" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t Nuevos Datos" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------------" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tNombre: " << citas.nombrePaciente << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tCedula: " << citas.cedula << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tMedico: " << citas.nombreMedico << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tEspecialidad: " << citas.especialidadMedico << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tHorario: " << citas.hora << ":" << citas.minutos << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tFecha: " << citas.dia << "/" << citas.mes << "/" << citas.anio << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------------" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t-----------------------------------------" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t| Esta segur@ de modificar la cita(s/n)?: ";
			cin >> sino;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t-----------------------------------------" << endl;

			if (sino == "s")
			{
				system("cls");
				/*
				* Intercambia los valores a la estrucutra finalmente
				*/
				lista.elementos[posicion].dia = citas.dia;
				lista.elementos[posicion].mes = citas.mes;
				lista.elementos[posicion].anio = citas.anio;
				color(hConsole, 10);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------------" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t| \a Cita modificada  |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------------" << endl;
				color(hConsole, 7);
			}
		}
	}
}
void reprogramarCitasHora(tListaCitas& lista, tCitasMedicas citas)
{
	string cedula, sino;
	int posicion;
	bool varOK;
	tListaCitas auxliar;

	cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "=========Reprogramar Hora========" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "N# de Cedula: ";
	cin >> cedula;
	posicion = retornarPosicion(lista, cedula);
	if (posicion == -1)
	{
		system("cls");
		color(hConsole, 12);
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t-----------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t| \aCita no encontrada |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t-----------------------" << endl;
		color(hConsole, 7);
	}
	else
	{
		cout << "\t\t\t\t-------------------------------------------------------------------------------"
			<< "-----------------------------------------------------------------------------------" << endl;
		cout << "\t\t\t\t|" << setw(15) << left << "CEDULA" << "|"
			<< setw(40) << left << "NOMBRE" << "|"
			<< setw(30) << left << "MEDICO" << "|"
			<< setw(25) << left << "ESPECIALIDAD" << "|"
			<< setw(20) << left << "HORA" << "|"
			<< setw(25) << left << "FECHA" << "|" << endl;
		cout << "\t\t\t\t-------------------------------------------------------------------------------"
			<< "-----------------------------------------------------------------------------------" << endl;
		for (int i = 0; i < lista.contador; i++)
		{
			if (i == posicion)
			{
				cout << "\t\t\t\t|" << setw(15) << left << lista.elementos[i].cedula << "|"
					<< setw(40) << left << lista.elementos[i].nombrePaciente << "|"
					<< setw(30) << left << lista.elementos[i].nombreMedico << "|"
					<< setw(25) << left << lista.elementos[i].especialidadMedico << "|"
					<< setw(0) << left << lista.elementos[i].hora << ":" << lista.elementos[i].minutos
					<< setw(16) << left << setw(16) << right << "|" << lista.elementos[i].dia << "/"
					<< lista.elementos[i].mes << "/" << lista.elementos[i].anio
					<< setw(17) << right << "|" << endl;
				cout << "\t\t\t\t-------------------------------------------------------------------------------"
					<< "-----------------------------------------------------------------------------------" << endl;
			}
		}
		do
		{
			/*
			* Nueva hora
			*/
			color(hConsole, 3);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------------------------------------------" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t|Sistema horario de 24 horas" << setw(24) << right << "|" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t|Horario de Atencion (7:00 - 12:00 y 14:00 - 18:00)|" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------------------------------------------" << endl;
			color(hConsole, 7);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tHora (hora minutos): ";
			/*
			* Intercambia los datos de la lista
			* en la posicion establecidad con
			* la estrucutura citas
			*/
			citas = lista.elementos[posicion];
			cin >> citas.hora >> citas.minutos; //Remplazara los nuevos datos
			if ((citas.hora < 7 || citas.hora >= 18 || citas.hora == 13 || citas.hora == 12)
				|| (citas.minutos < 0 || citas.minutos > 59))
			{
				color(hConsole, 12);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t|   \aERROR!!   |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------" << endl;
				color(hConsole, 7);
			}
		} while ((citas.hora < 7 || citas.hora >= 18 || citas.hora == 13 || citas.hora == 12)
			|| (citas.minutos < 0 || citas.minutos > 59));
		auxliar.elementos[posicion] = citas;
		/*
		* Variable axuiliar
		*/
		if (verificarCita(lista, citas, varOK))
		{
			system("cls");
			color(hConsole, 12);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t|  \aCita no posible en ese horario     |" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
			color(hConsole, 7);
		}
		else
		{
			cout << "\n\n\n\n" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t Nuevos Datos" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------------" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tNombre: " << citas.nombrePaciente << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tCedula: " << citas.cedula << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t|Medico: " << citas.nombreMedico << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tEspecialidad: " << citas.especialidadMedico << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tHorario: " << citas.hora << ":" << citas.minutos << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tFecha: " << citas.dia << "/" << citas.mes << "/" << citas.anio << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------------" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t-----------------------------------------" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t| Esta segur@ de modificar la cita(s/n)?: ";
			cin >> sino;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t-----------------------------------------" << endl;
			
			if (sino == "s")
			{
				system("cls");
				lista.elementos[posicion].hora = citas.hora;
				lista.elementos[posicion].minutos = citas.minutos;
				color(hConsole, 10);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------------" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t| \a Cita modificada  |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------------" << endl;
				color(hConsole, 7);
			}
		}

	}
}

/*
* Ordenamiento 
*/
void ordenarLista(tListaCitas& lista)
{
	tCitasMedicas auxiliar;
	for (int i = 0; i < lista.contador; i++)
	{
		for (int j = i + 1; j < lista.contador; j++)
		{
			if (lista.elementos[i].hora > lista.elementos[j].hora)
			{
				auxiliar = lista.elementos[i];
				lista.elementos[i] = lista.elementos[j];
				lista.elementos[j] = auxiliar;
			}
		}
	}
	for (int i = 0; i < lista.contador; i++)
	{
		for (int j = i + 1; j < lista.contador; j++)
		{
			if (lista.elementos[i].minutos > lista.elementos[j].minutos)
			{
				auxiliar = lista.elementos[i];
				lista.elementos[i] = lista.elementos[j];
				lista.elementos[j] = auxiliar;
			}
		}
	}
	for (int i = 0; i < lista.contador; i++)
	{
		for (int j = i + 1; j < lista.contador; j++)
		{
			if (lista.elementos[i].dia > lista.elementos[j].dia)
			{
				auxiliar = lista.elementos[i];
				lista.elementos[i] = lista.elementos[j];
				lista.elementos[j] = auxiliar;
			}
		}
	}
	for (int i = 0; i < lista.contador; i++)
	{
		for (int j = i + 1; j < lista.contador; j++)
		{
			if (lista.elementos[i].mes > lista.elementos[j].mes)
			{
				auxiliar = lista.elementos[i];
				lista.elementos[i] = lista.elementos[j];
				lista.elementos[j] = auxiliar;
			}
		}
	}
	for (int i = 0; i < lista.contador; i++)
	{
		for (int j = i + 1; j < lista.contador; j++)
		{
			if (lista.elementos[i].anio > lista.elementos[j].anio)
			{
				auxiliar = lista.elementos[i];
				lista.elementos[i] = lista.elementos[j];
				lista.elementos[j] = auxiliar;
			}
		}
	}
}