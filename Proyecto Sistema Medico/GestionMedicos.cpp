#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "GestionMedicos.h"

using namespace std;

/*
* Menu Medicos
*/

int verMenuMedicos()
{
	int opcionMenu1;

	cout << "\n\n\n\n\n\n" << endl;
	color(mConsole, 6);
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t.-..-.   .--.   .---.   .-.   .--.    .--.    .--. " << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t: `' :  : .--'  : .  :  : :  : .--'  : ,. :  : .--'" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t: .. :  : `;    : :: :  : :  : :     : :: :  `. `. " << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t: :; :  : :__   : :; :  : :  : :__   : :; :   _`, :" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t:_;:_;  `.__.'  :___.'  :_;  `.__.'  `.__.'  `.__.'" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << endl;
	color(mConsole, 7);
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t--------------------------------------" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t|1. Visualizar infor Medicos          |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t|2. Agregar Medico                    |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t|3. Buscar Medico                     |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t|4. Eliminar Medico                   |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t|5. Modificar datos del Medico        |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t|0. SALIR                             |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t--------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\tSeleccione una opcion: ";
	cin >> opcionMenu1;

	return opcionMenu1;
}

/*
* Visualizar Medicos
*/
void visualizarMedicos(tListaMedicos lista, bool& ok) {
	ok = false;
	cout << "\n\n\n\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t======INFORMACION MEDICOS=======\n" << endl;
	color(mConsole, 2);
	cout << "\t\t\t\t\t\t\t-------------------------------------------------------------------------------"
		<< "----------------------------------------------" << endl;
	cout << "\t\t\t\t\t\t\t|" << setw(15) << left << "CEDULA" << "|"
		<< setw(40) << left << "NOMBRE" << "|"
		<< setw(30) << left << "ESPECIALIDAD" << "|"
		<< setw(20) << left << "TELEFONO" << "|"
		<< setw(0) << left << "EDAD" << setw(11) << right <<  "|" << endl;

	cout << "\t\t\t\t\t\t\t-------------------------------------------------------------------------------"
		<< "----------------------------------------------" << endl;
	color(mConsole, 7);
	for (int i = 0; i < lista.contador; i++)
	{
		cout << "\t\t\t\t\t\t\t|" << setw(15) << left << lista.datos[i].cedula << "|"
			<< setw(40) << left << lista.datos[i].nombre << "|"
			<< setw(30) << left << lista.datos[i].especialidad << "|"
			<< setw(20) << left << lista.datos[i].telefono << "|"
			<< setw(0) << left << lista.datos[i].edad << setw(13) << right << "|"
			<< endl;

		cout << "\t\t\t\t\t\t\t-------------------------------------------------------------------------------"
			<< "----------------------------------------------" << endl;
	}
}



/*
* Carga los datos del archivo txt
*/
void cargarDatosMedicos(tListaMedicos& lista) {
	char aux;
	ifstream archivo;
	lista.contador = 0;
	archivo.open("Registro_Medicos.txt");
	if (!(archivo.is_open()))
		cout << "\aError al abrir el archivo" << endl;
	else
	{
		//cout << "Archivo abierto!!" << endl;  //<---- Debuggin
		archivo >> lista.datos[lista.contador].cedula;
		while ((lista.datos[lista.contador].cedula != "XXX") && (lista.contador < DATOSMAXIMOS))
		{
			archivo.ignore();
			getline(archivo, lista.datos[lista.contador].nombre);
			getline(archivo, lista.datos[lista.contador].especialidad);
			getline(archivo, lista.datos[lista.contador].telefono);
			archivo >> lista.datos[lista.contador].edad;
			archivo.get(aux);
			lista.contador++;
			archivo >> lista.datos[lista.contador].cedula;
		}
		archivo.close();
	}
}


/*
* Guardar Datos en Registro_Medicos.txt
*/
void guardarMedicos(const tListaMedicos lista) {
	ofstream archivo;
	archivo.open("Registro_Medicos.txt");
	for (int i = 0; i < lista.contador; i++)
	{
		archivo << lista.datos[i].cedula << endl;
		archivo << lista.datos[i].nombre << endl;
		archivo << lista.datos[i].especialidad << endl;
		archivo << lista.datos[i].telefono << endl;
		archivo << lista.datos[i].edad << endl;

		archivo << endl;
	}
	archivo << "XXX" << endl;
	archivo.close();

}


/*
* Agregar un nuevo medico
*/
void agregarMedico(tListaMedicos& lista, tMedicos medicos)
{
	int auxiliar;
	string datosCorrectos, retorno;
	cout << "\n\n\n\n\n\n\n\n" << endl;
	if (lista.contador > DATOSMAXIMOS)
	{
		color(mConsole, 12);
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-----------------" << endl;
		cout << "\a\t\t\t\t\t\t\t\t\t\t\t\t\tLista Llena!!|" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-----------------" << endl;
		color(mConsole, 7);
	}
	else
	{
		do
		{
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t=====Agregar Medico=====\n" << endl;
			do
			{
				auxiliar = 0;
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tCedula: ";
				cin >> medicos.cedula;
				for (int i = 0; i < lista.contador; i++)
				{
					if (medicos.cedula == lista.datos[i].cedula)
					{
						color(mConsole, 12);
						cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t|   \aERROR Cedula igual!!   |" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-------------------------------" << endl;
						color(mConsole, 7);
						auxiliar++;
					}
				}
			} while (auxiliar != 0);
			cin.ignore();
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tNombre y Apellido: ";
			getline(cin, medicos.nombre);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tEspecialidad: ";
			getline(cin, medicos.especialidad);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tTelefono: ";
			cin >> medicos.telefono;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tEdad: ";
			cin >> medicos.edad;
			cout << endl << endl << endl << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tCedula: " << medicos.cedula << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tNombre: " << medicos.nombre << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tEspecialidad: " << medicos.especialidad << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tTelefono: " << medicos.telefono << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tEdad: " << medicos.edad << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tDatos Correctos(s/n)?: ";
			cin >> datosCorrectos;
			if (datosCorrectos == "s" || datosCorrectos == "S")
			{
				system("cls");
				color(mConsole, 10);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t|  \aMedico agregado correctamente |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------" << endl;
				color(mConsole, 7);
				lista.datos[lista.contador] = medicos;
				lista.contador++;
				datosCorrectos = "n";
			}
			else
			{
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tIngresar otros datos(s/n)?: ";
				cin >> datosCorrectos;
				system("cls");
			}
		} while (datosCorrectos == "s" || datosCorrectos == "S");
	}
}


/*
* Busqueda de los medicos
*/
void consultarMedico(tListaMedicos lista) {
	int posicion;
	string cedula;

	cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t=====Consultar Medico======\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\tN# de Cedula: ";
	cin >> cedula;
	posicion = retornarPosicion(lista, cedula);
	if (posicion == -1)
	{
		system("cls");
		color(mConsole, 12);
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t-----------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t| \aMedic@ no encontrad@ |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t-----------------------" << endl;
		color(mConsole, 7);
	}
	else
	{
		color(mConsole, 2);
		cout << "\t\t\t\t\t-------------------------------------------------------------------------------"
			<< "----------------------------------------------" << endl;
		cout << "\t\t\t\t\t|" << setw(15) << left << "CEDULA" << "|"
			<< setw(40) << left << "NOMBRE" << "|"
			<< setw(30) << left << "ESPECIALIDAD" << "|"
			<< setw(20) << left << "TELEFONO" << "|"
			<< setw(0) << left << "EDAD" << setw(11) << right << "|" << endl;

		cout << "\t\t\t\t\t-------------------------------------------------------------------------------"
			<< "----------------------------------------------" << endl;
		color(mConsole, 2);
		for (int i = 0; i < lista.contador; i++)
		{
			if (i == posicion)
			{
				cout << "\t\t\t\t\t|" << setw(15) << left << lista.datos[i].cedula << "|"
					<< setw(40) << left << lista.datos[i].nombre << "|"
					<< setw(30) << left << lista.datos[i].especialidad << "|"
					<< setw(20) << left << lista.datos[i].telefono << "|"
					<< setw(0) << left << lista.datos[i].edad << setw(13) << right << "|"
					<< endl;

				cout << "\t\t\t\t\t-------------------------------------------------------------------------------"
					<< "----------------------------------------------" << endl;
			}
		}
		system("pause");
		system("cls");
	}
	
}


/*
* Eliminar datos de un medico
*/
void eliminarMedico(tListaMedicos& lista) {
	int posicion;
	string cedula, sino;

	cout << "\n\n\n\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t     =====ELIMINAR UN MEDICO=====\n" << endl;
	color(mConsole, 3);
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t|Ingrese el N# para eliminar al medico|" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t|perteneciente a este                 |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
	color(mConsole, 7);
	cout << "\t\t\t\t\t\t\t\t\t\t\t\tN# Cedula: ";
	cin >> cedula;
	posicion = retornarPosicion(lista, cedula);
	if (posicion == -1)
	{
		system("cls");
		color(mConsole, 12);
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-----------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t|\aMedic@ no encontrad@!!|" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-----------------------" << endl;
		color(mConsole, 7);
	}
	else
	{
		cout << "\t\t\t\t\t\t\t\t\t\t\t----------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t| Esta segur@ de eliminar al Medico(s/n)?: ";
		cin >> sino;
		cout << "\t\t\t\t\t\t\t\t\t\t\t----------------------------------------" << endl;
		if (sino == "s")
		{
			system("cls");
			for (int i = posicion; i < lista.contador; i++)
			{
				lista.datos[i] = lista.datos[i + 1];
			}
			lista.contador--;
			color(mConsole, 10);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t----------------------" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t| \a Medico eliminado   |" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t----------------------" << endl;
			color(mConsole, 7);
		}
	}
}
int retornarPosicion(tListaMedicos lista, string cedulaBusqueda)
{
	int poisicion = -1;

	for (int i = 0; i < lista.contador; i++)
	{
		if (lista.datos[i].cedula == cedulaBusqueda)
		{
			poisicion = i;
		}
	}
	return poisicion;
}

/*
* Modificar Datos de los medicos
*/
int verMenuModificarMedico()
{
	int opcionMenu;

	cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t   ====Modificar Datos=====\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t-----------------------------" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t|1. Nombre                   |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t|2. Cedula                   |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t|3. Especialidad             |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t|4. Telefono                 |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t|5. Edad                     |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t|0. SALIR                    |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t-----------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\tEscoga una opcion: ";
	cin >> opcionMenu;

	return opcionMenu;
}
void modificarMedicoNombre(tListaMedicos& lista, tMedicos medicos)
{
	string cedula, sino;
	int posicion;
	bool varOK;
	tListaMedicos auxliar;

	cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t=========Modificar Nombre========" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\tN# de Cedula: ";
	cin >> cedula;
	posicion = retornarPosicion(lista, cedula);
	if (posicion == -1)
	{
		system("cls");
		color(mConsole, 12);
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t--------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t| \aMedic@ no encontrad@ |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t--------------------------" << endl;
		color(mConsole, 7);
	}
	else
	{
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t======INFORMACION MEDICOS=======\n" << endl;
		cout << "\t\t\t\t\t\t-------------------------------------------------------------------------------"
			<< "----------------------------------------------" << endl;
		cout << "\t\t\t\t\t\t|" << setw(15) << left << "CEDULA" << "|"
			<< setw(40) << left << "NOMBRE" << "|"
			<< setw(30) << left << "ESPECIALIDAD" << "|"
			<< setw(20) << left << "TELEFONO" << "|"
			<< setw(0) << left << "EDAD" << setw(11) << right << "|" << endl;

		cout << "\t\t\t\t\t\t-------------------------------------------------------------------------------"
			<< "----------------------------------------------" << endl;
		for (int i = 0; i < lista.contador; i++)
		{
			if (i == posicion)
			{
				cout << "\t\t\t\t\t\t|" << setw(15) << left << lista.datos[i].cedula << "|"
					<< setw(40) << left << lista.datos[i].nombre << "|"
					<< setw(30) << left << lista.datos[i].especialidad << "|"
					<< setw(20) << left << lista.datos[i].telefono << "|"
					<< setw(0) << left << lista.datos[i].edad << setw(13) << right << "|"
					<< endl;

				cout << "\t\t\t\t\t\t-------------------------------------------------------------------------------"
					<< "----------------------------------------------" << endl;
			}
		}
		cout << endl;
		cin.ignore();
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tNombre: ";
		medicos = lista.datos[posicion];
		getline(cin, medicos.nombre);
		cout << "\n\n\n" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t Nuevos Datos" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tCedula: " << medicos.cedula << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tNombre: " << medicos.nombre << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tEspecialidad: " << medicos.especialidad << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tTelefono: " << medicos.telefono << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tEdad: " << medicos.edad << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t| Esta segur@ de modificar al medioc@(s/n)? |" << endl;
		cin >> sino;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------" << endl;
		if (sino == "s")
		{
			system("cls");
			/*
			* Modifica los datos
			*/
			lista.datos[posicion].nombre = medicos.nombre;
			color(mConsole, 10);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------------------" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t| \a   Medic@ modificad@     |" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------------------" << endl;
			color(mConsole, 7);
		}
		else
			system("cls");
	}
}
void modificarMedicoCedula(tListaMedicos& lista, tMedicos medicos)
{
	string cedula, sino;
	int posicion, aux;
	bool varOK;
	tListaMedicos auxliar;

	cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t=========Modificar Cedula========" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\tN# de Cedula: ";
	cin >> cedula;
	posicion = retornarPosicion(lista, cedula);
	if (posicion == -1)
	{
		system("cls");
		color(mConsole, 12);
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t--------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t| \aMedic@ no encontrad@ |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t--------------------------" << endl;
		color(mConsole, 7);
	}
	else
	{
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t======INFORMACION MEDICOS=======\n" << endl;
		cout << "\t\t\t\t\t\t-------------------------------------------------------------------------------"
			<< "----------------------------------------------" << endl;
		cout << "\t\t\t\t\t\t|" << setw(15) << left << "CEDULA" << "|"
			<< setw(40) << left << "NOMBRE" << "|"
			<< setw(30) << left << "ESPECIALIDAD" << "|"
			<< setw(20) << left << "TELEFONO" << "|"
			<< setw(0) << left << "EDAD" << setw(11) << right << "|" << endl;

		cout << "\t\t\t\t\t\t-------------------------------------------------------------------------------"
			<< "----------------------------------------------" << endl;
		for (int i = 0; i < lista.contador; i++)
		{
			if (i == posicion)
			{
				cout << "\t\t\t\t\t\t|" << setw(15) << left << lista.datos[i].cedula << "|"
					<< setw(40) << left << lista.datos[i].nombre << "|"
					<< setw(30) << left << lista.datos[i].especialidad << "|"
					<< setw(20) << left << lista.datos[i].telefono << "|"
					<< setw(0) << left << lista.datos[i].edad << setw(13) << right << "|"
					<< endl;

				cout << "\t\t\t\t\t\t-------------------------------------------------------------------------------"
					<< "----------------------------------------------" << endl;
			}
		}
		medicos = lista.datos[posicion];
		aux = 0;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tCedula: ";
		cin >> medicos.cedula;
		for (int i = 0; i < lista.contador; i++)
		{
			if (medicos.cedula == lista.datos[i].cedula)
			{
				color(mConsole, 12);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t-------------------------------" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t|   \aERROR Cedula igual!!   |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t-------------------------------" << endl;
				color(mConsole, 7);
				aux++;
			}
		}
		cout << "\n\n\n" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t           Nuevos Datos" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tCedula: " << medicos.cedula << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tNombre: " << medicos.nombre << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tEspecialidad: " << medicos.especialidad << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tTelefono: " << medicos.telefono << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tEdad: " << medicos.edad << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t| Esta segur@ de modificar al medioc@(s/n)?: ";
		cin >> sino;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------" << endl;
		if (sino == "s")
		{
			/*
			* Modifica los datos
			*/
			system("cls");
			lista.datos[posicion].cedula = medicos.cedula;
			color(mConsole, 10);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------------------" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t| \a   Medic@ modificad@     |" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------------------" << endl;
			color(mConsole, 7);
		}
		else
			system("cls");
	}
}
void modificarMedicoEspecialidad(tListaMedicos& lista, tMedicos medicos)
{
	string cedula, sino;
	int posicion;
	bool varOK;
	tListaMedicos auxliar;

	cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t=========Modificar Especialidad========" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\tN# de Cedula: ";
	cin >> cedula;
	posicion = retornarPosicion(lista, cedula);
	if (posicion == -1)
	{
		system("cls");
		color(mConsole, 12);
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t--------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t| \aMedic@ no encontrad@ |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t--------------------------" << endl;
		color(mConsole, 7);
	}
	else
	{
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t======INFORMACION MEDICOS=======\n" << endl;
		cout << "\t\t\t\t\t\t-------------------------------------------------------------------------------"
			<< "----------------------------------------------" << endl;
		cout << "\t\t\t\t\t\t|" << setw(15) << left << "CEDULA" << "|"
			<< setw(40) << left << "NOMBRE" << "|"
			<< setw(30) << left << "ESPECIALIDAD" << "|"
			<< setw(20) << left << "TELEFONO" << "|"
			<< setw(0) << left << "EDAD" << setw(11) << right << "|" << endl;

		cout << "\t\t\t\t\t\t-------------------------------------------------------------------------------"
			<< "----------------------------------------------" << endl;
		for (int i = 0; i < lista.contador; i++)
		{
			if (i == posicion)
			{
				cout << "\t\t\t\t\t\t|" << setw(15) << left << lista.datos[i].cedula << "|"
					<< setw(40) << left << lista.datos[i].nombre << "|"
					<< setw(30) << left << lista.datos[i].especialidad << "|"
					<< setw(20) << left << lista.datos[i].telefono << "|"
					<< setw(0) << left << lista.datos[i].edad << setw(13) << right << "|"
					<< endl;

				cout << "\t\t\t\t\t\t-------------------------------------------------------------------------------"
					<< "----------------------------------------------" << endl;
			}
		}
		cin.ignore();
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tEspecialidad: ";
		medicos = lista.datos[posicion];
		getline(cin, medicos.especialidad);
		cout << "\n\n\n" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t           Nuevos Datos" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tCedula: " << medicos.cedula << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tNombre: " << medicos.nombre << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tEspecialidad: " << medicos.especialidad << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tTelefono: " << medicos.telefono << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tEdad: " << medicos.edad << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t| Esta segur@ de modificar al medioc@(s/n)?: ";
		cin >> sino;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------" << endl;
		if (sino == "s")
		{
			/*
			* Modifica los datos
			*/
			lista.datos[posicion].especialidad = medicos.especialidad;
			color(mConsole, 12);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------------------" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t| \a   Medic@ modificad@     |" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------------------" << endl;
			color(mConsole, 7);
		}
		else
			system("cls");
	}
}
void modificarMedicoTelefono(tListaMedicos& lista, tMedicos medicos)
{
	string cedula, sino;
	int posicion;
	bool varOK;
	tListaMedicos auxliar;

	cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t=========Modificar Telefono========" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\tN# de Cedula: ";
	cin >> cedula;
	posicion = retornarPosicion(lista, cedula);
	if (posicion == -1)
	{
		system("cls");
		color(mConsole, 12);
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t--------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t| \aMedic@ no encontrad@ |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t--------------------------" << endl;
		color(mConsole, 7);
	}
	else
	{
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t======INFORMACION MEDICOS=======\n" << endl;
		cout << "\t\t\t\t\t\t-------------------------------------------------------------------------------"
			<< "----------------------------------------------" << endl;
		cout << "\t\t\t\t\t\t|" << setw(15) << left << "CEDULA" << "|"
			<< setw(40) << left << "NOMBRE" << "|"
			<< setw(30) << left << "ESPECIALIDAD" << "|"
			<< setw(20) << left << "TELEFONO" << "|"
			<< setw(0) << left << "EDAD" << setw(11) << right << "|" << endl;

		cout << "\t\t\t\t\t\t-------------------------------------------------------------------------------"
			<< "----------------------------------------------" << endl;
		for (int i = 0; i < lista.contador; i++)
		{
			if (i == posicion)
			{
				cout << "\t\t\t\t\t\t|" << setw(15) << left << lista.datos[i].cedula << "|"
					<< setw(40) << left << lista.datos[i].nombre << "|"
					<< setw(30) << left << lista.datos[i].especialidad << "|"
					<< setw(20) << left << lista.datos[i].telefono << "|"
					<< setw(0) << left << lista.datos[i].edad << setw(13) << right << "|"
					<< endl;

				cout << "\t\t\t\t\t\t-------------------------------------------------------------------------------"
					<< "----------------------------------------------" << endl;
			}
		}
		cout << "\t\t\t\t\t\t\t\t\t\t\tTelefono: ";
		medicos = lista.datos[posicion];
		cin >> medicos.telefono;
		cout << "\n\n\n" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t           Nuevos Datos" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tCedula: " << medicos.cedula << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tNombre: " << medicos.nombre << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tEspecialidad: " << medicos.especialidad << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tTelefono: " << medicos.telefono << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tEdad: " << medicos.edad << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t| Esta segur@ de modificar al medioc@(s/n)?: ";
		cin >> sino;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------" << endl;
		if (sino == "s")
		{
			/*
			* Modifica los datos
			*/
			system("cls");
			lista.datos[posicion].telefono = medicos.telefono;
			color(mConsole, 10);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------------------" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t| \a   Medic@ modificad@     |" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------------------" << endl;
			color(mConsole, 7);
		}
		else
			system("cls");
	}
}
void modificarMedicoEdad(tListaMedicos& lista, tMedicos medicos)
{
	string cedula, sino;
	int posicion;
	bool varOK;
	tListaMedicos auxliar;

	cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t=========Modificar Edad========" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\tN# de Cedula: ";
	cin >> cedula;
	posicion = retornarPosicion(lista, cedula);
	if (posicion == -1)
	{
		system("cls");
		color(mConsole, 12);
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t--------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t| \aMedic@ no encontrad@ |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t--------------------------" << endl;
		color(mConsole, 7);
	}
	else
	{
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t======INFORMACION MEDICOS=======\n" << endl;
		cout << "\t\t\t\t\t\t-------------------------------------------------------------------------------"
			<< "----------------------------------------------" << endl;
		cout << "\t\t\t\t\t\t|" << setw(15) << left << "CEDULA" << "|"
			<< setw(40) << left << "NOMBRE" << "|"
			<< setw(30) << left << "ESPECIALIDAD" << "|"
			<< setw(20) << left << "TELEFONO" << "|"
			<< setw(0) << left << "EDAD" << setw(11) << right << "|" << endl;

		cout << "\t\t\t\t\t\t-------------------------------------------------------------------------------"
			<< "----------------------------------------------" << endl;
		for (int i = 0; i < lista.contador; i++)
		{
			if (i == posicion)
			{
				cout << "\t\t\t\t\t\t|" << setw(15) << left << lista.datos[i].cedula << "|"
					<< setw(40) << left << lista.datos[i].nombre << "|"
					<< setw(30) << left << lista.datos[i].especialidad << "|"
					<< setw(20) << left << lista.datos[i].telefono << "|"
					<< setw(0) << left << lista.datos[i].edad << setw(13) << right << "|"
					<< endl;

				cout << "\t\t\t\t\t\t-------------------------------------------------------------------------------"
					<< "----------------------------------------------" << endl;
			}
		}
		cout << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tEdad: ";
		medicos = lista.datos[posicion];
		cin >> medicos.edad;
		cout << "\n\n\n" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t           Nuevos Datos" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tCedula: " << medicos.cedula << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tNombre: " << medicos.nombre << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tEspecialidad: " << medicos.especialidad << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tTelefono: " << medicos.telefono << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tEdad: " << medicos.edad << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t| Esta segur@ de modificar al medioc@(s/n)?: ";
		cin >> sino;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t--------------------------------------------" << endl;
		if (sino == "s")
		{
			/*
			* Modifica los datos
			*/
			system("cls");
			lista.datos[posicion].edad = medicos.edad;
			color(mConsole, 12);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------------------" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t| \a   Medic@ modificad@     |" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------------------" << endl;
			color(mConsole, 7);
		}
		else
			system("cls");
	}
}

/*
* Ordenamiento
*/
void ordenarListaMedicos(tListaMedicos& lista)
{
	tMedicos auxiliar;
	for (int i = 0; i < lista.contador; i++)
	{
		for (int j = i + 1; j < lista.contador; j++)
		{
			if (lista.datos[i].nombre > lista.datos[j].nombre)
			{
				auxiliar = lista.datos[i];
				lista.datos[i] = lista.datos[j];
				lista.datos[j] = auxiliar;
			}
		}
	}
}