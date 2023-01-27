#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "GestionPacientes.h"

using namespace std;


/*
*Visualiza el menu de gestion de los pacientes
*/
int verMenuPacientes() {
	int opcionMenu1;

	cout << "\n\n\n\n\n\n" << endl;
	color(pConsole, 6);
	cout << "\t\t\t\t\t\t\t\t\t\t\t.---.    .--.    .--.   .-.   .--.   .-..-.  .-----.   .--.    .--. " << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t: .; :  : .; :  : .--'  : :  : .--'  : `: :  `-. .-'  : .--'  : .--'" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t:  _.'  :    :  : :     : :  : `;    : .` :    : :    : `;    `. `. " << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t: :     : :: :  : :__   : :  : :__   : :. :    : :    : :__    _`, :" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t:_;     :_;:_;  `.__.'  :_;  `.__.'  :_;:_;    :_;    `.__.'  `.__.'" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t" << endl;
	color(pConsole, 7);
	cout << "\t\t\t\t\t\t\t\t\t\t\t----------------------------------" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t|1. Visualizar info Pacientes     |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t|2. Agregar Paciente              |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t|3. Consultar Paciente            |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t|4. Eliminar Paciente             |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t|5. Modificar Paciente            |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t|0. SALIR                         |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t-----------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tSeleccione una opcion: ";
	cin >> opcionMenu1;

	return opcionMenu1;


}

/*
* Visualiza en forma de tabla los pacientes del Hospital
*/
void visualizarPacientes(tLisaPacientes lista, bool& ok) {
	ok = false;
	cout << "\n\n\n\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t======P A C I E N T E S=======\n" << endl;
	color(pConsole, 2);
	cout << "\t\t\t-------------------------------------------------------------------------------"
		<< "------------------------------------------------"
		<< "-----------------------------------------------------------------------" << endl;
	cout << "\t\t\t|" << setw(15) << left << "CEDULA" << "|"
		<< setw(40) << left << "NOMBRE" << "|"
		<< setw(25) << left << "TIPO DE SANGRE " << "|"
		<< setw(20) << left << "TELEFONO" << "|"
		<< setw(40) << left << "DIRECCION" << "|"
		<< setw(16) << left << "EDAD" << "|"
		<< setw(17) << left << "PESO" << "|"
		<< setw(16) << left << "ESTATURA" << "|" << endl;
	cout << "\t\t\t-------------------------------------------------------------------------------"
		<< "------------------------------------------------"
		<< "-----------------------------------------------------------------------" << endl;
	color(pConsole, 7);
	for (int i = 0; i < lista.contador; i++)
	{
		cout << "\t\t\t|" << setw(15) << left << lista.datosPersonales[i].cedula << "|"
			<< setw(40) << left << lista.datosPersonales[i].nombre << "|"
			<< setw(25) << left << lista.datosPersonales[i].tipoSangre<< "|"
			<< setw(20) << left << lista.datosPersonales[i].telefono << "|"
			<< setw(40) << left << lista.datosPersonales[i].direccion << "|" 
			<< setw(16) << left << lista.datosPersonales[i].edad << "|"
			<< lista.datosPersonales[i].peso << "kg" << setw(12) << right << "|" <<
			lista.datosPersonales[i].estatura << "m"
			<< setw(12) << right << "|" << endl;
		cout << "\t\t\t--------------------------------------------------------------------------------"
			<< "------------------------------------------------"
			<< "----------------------------------------------------------------------" << endl;
	}
}

/*
* Carga todos los datos guardados en el archivo txt
*/
void cargarDatosPacientes(tLisaPacientes& lista) {
	char aux;
	ifstream archivo;
	lista.contador = 0;
	archivo.open("Registro_Pacientes.txt");
	if (!(archivo.is_open()))
		cout << "\aError al abrir el archivo" << endl;
	else
	{
		//cout << "Archivo abierto!!" << endl;  //<---- Debuggin
		archivo >> lista.datosPersonales[lista.contador].cedula;
		while ((lista.datosPersonales[lista.contador].cedula != "XXX") && (lista.contador < DATOSMAXIMOSPACIENTES))
		{
			archivo.ignore();
			getline(archivo, lista.datosPersonales[lista.contador].nombre);
			archivo >> lista.datosPersonales[lista.contador].tipoSangre;
			archivo >> lista.datosPersonales[lista.contador].telefono;
			archivo.ignore();
			getline(archivo, lista.datosPersonales[lista.contador].direccion);
			archivo >> lista.datosPersonales[lista.contador].edad;
			archivo >> lista.datosPersonales[lista.contador].peso;
			archivo >> lista.datosPersonales[lista.contador].estatura;
			archivo.get(aux);
			lista.contador++;
			archivo >> lista.datosPersonales[lista.contador].cedula;
		}
		archivo.close();
	}


}

/*
* Agrega nuevos pacientes a la tabla
*/
void agregarPaciente(tLisaPacientes& lista, tPacientes pacientes) 
{
	int auxiliar;
	string datosCorrectos, retorno;
	cout << "\n\n\n\n\n\n\n\n" << endl;
	if (lista.contador > DATOSMAXIMOSPACIENTES)
	{
		color(pConsole, 12);
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-----------------" << endl;
		cout << "\a\t\t\t\t\t\t\t\t\t\t\t\t\tLista Llena!!|" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-----------------" << endl;
		color(pConsole, 7);
	}
	else
	{
		do
		{
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t=====Agregar Paciente=====\n" << endl;
			do
			{
				auxiliar = 0;
				cout << "\t\t\t\t\t\t\t\t\t\t\t\tCedula: ";
				cin >> pacientes.cedula;
				for (int i = 0; i < lista.contador; i++)
				{
					if (pacientes.cedula == lista.datosPersonales[i].cedula)
					{
						color(pConsole, 12);
						cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t|   \aERROR Cedula igual!!   |" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-------------------------------" << endl;
						color(pConsole, 7);
						auxiliar++;
					}
				}
			} while (auxiliar != 0);
			cin.ignore();
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tNombre y Apellido: ";
			getline(cin, pacientes.nombre);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tTipo de sangre: ";
			cin >> pacientes.tipoSangre;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tTelefono: ";
			cin >> pacientes.telefono;
			cin.ignore();
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tDireccion: ";
			getline(cin, pacientes.direccion);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tEdad: ";
			cin >> pacientes.edad;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tPeso: ";
			cin >> pacientes.peso;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tEstatura: ";
			cin >> pacientes.estatura;
			cout << endl << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tCedula: " << pacientes.cedula << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tNombre: " << pacientes.nombre << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tTipo de Sangre: " << pacientes.tipoSangre << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tTelefono: " << pacientes.telefono << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tDireccion: " << pacientes.direccion << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tEdad: " << pacientes.edad << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tPeso: " << pacientes.peso << "kg" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tEstatura: " << pacientes.estatura << "m" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tDatos Correctos(s/n)?: ";
			cin >> datosCorrectos;
			if (datosCorrectos == "s" || datosCorrectos == "S")
			{
				system("cls");
				color(pConsole, 10);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-----------------------------------" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t| \aPaciente agregado correctamente |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-----------------------------------" << endl;
				color(pConsole, 7);
				lista.datosPersonales[lista.contador] = pacientes;
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
* Busca un Paciente en especifico
* por su numero de cedula
*/
void consultarPaciente(tLisaPacientes lista) 
{
	int posicion;
	string cedula;

	cout << "\n\n\n\n\n\n\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t=====Consultar Medico======\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tN# de Cedula: ";
	cin >> cedula;
	posicion = retornarPosicion(lista, cedula);
	if (posicion == -1)
	{
		system("cls");
		color(pConsole, 12);
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t----------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t| \aPaciente no encontrad@ |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t----------------------------" << endl;
		color(pConsole, 7);
	}
	else
	{
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t======P A C I E N T E S=======\n" << endl;
		color(pConsole, 2);
		cout << "\t\t\t-------------------------------------------------------------------------------"
			<< "------------------------------------------------"
			<< "-----------------------------------------------------------------------" << endl;
		cout << "\t\t\t|" << setw(15) << left << "CEDULA" << "|"
			<< setw(40) << left << "NOMBRE" << "|"
			<< setw(25) << left << "TIPO DE SANGRE " << "|"
			<< setw(20) << left << "TELEFONO" << "|"
			<< setw(40) << left << "DIRECCION" << "|"
			<< setw(16) << left << "EDAD" << "|"
			<< setw(17) << left << "PESO" << "|"
			<< setw(16) << left << "ESTATURA" << "|" << endl;
		cout << "\t\t\t-------------------------------------------------------------------------------"
			<< "------------------------------------------------"
			<< "-----------------------------------------------------------------------" << endl;
		color(pConsole, 7);
		for (int i = 0; i < lista.contador; i++)
		{
			cout << "\t\t\t|" << setw(15) << left << lista.datosPersonales[i].cedula << "|"
				<< setw(40) << left << lista.datosPersonales[i].nombre << "|"
				<< setw(25) << left << lista.datosPersonales[i].tipoSangre << "|"
				<< setw(20) << left << lista.datosPersonales[i].telefono << "|"
				<< setw(40) << left << lista.datosPersonales[i].direccion << "|"
				<< setw(16) << left << lista.datosPersonales[i].edad << "|"
				<< lista.datosPersonales[i].peso << "kg" << setw(12) << right << "|" <<
				lista.datosPersonales[i].estatura << "m"
				<< setw(12) << right << "|" << endl;
			cout << "\t\t\t--------------------------------------------------------------------------------"
				<< "------------------------------------------------"
				<< "----------------------------------------------------------------------" << endl;
		}
		system("pause");
		system("cls");
	}
	
}

/*
* Elimina un paciente en especifico
* por medio del numero de cedula
*/
void eliminarPaciente(tLisaPacientes& lista) 
{
	int posicion;
	string cedula, sino;

	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t=====ELIMINAR UN PACIENTE=====\n" << endl;
	color(pConsole, 3);
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t-----------------------------------------" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t|Ingrese el N# para eliminar la paciente|" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t|perteneciente a este                   |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t-----------------------------------------" << endl;
	color(pConsole, 7);
	cout << "\t\t\t\t\t\t\t\t\t\t\t\tN# Cedula: ";
	cin >> cedula;
	posicion = retornarPosicion(lista, cedula);
	if (posicion == -1)
	{
		system("cls");
		color(pConsole, 12);
		cout << "\t\t\t\t\t\t\t\t\t\t----------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t| \aPaciente no encontrad@ |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t----------------------------" << endl;
		color(pConsole, 7);
	}
	else
	{
		cout << "\t\t\t\t\t\t\t\t\t\t\t---------------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t| Esta segur@ de eliminar al Paciente(s/n)?: ";
		cin >> sino;
		cout << "\t\t\t\t\t\t\t\t\t\t\t---------------------------------------------" << endl;
		
		if (sino == "s")
		{
			system("cls");
			for (int i = posicion; i < lista.contador; i++)
			{
				lista.datosPersonales[i] = lista.datosPersonales[i + 1];
			}
			lista.contador--;
			color(pConsole, 10);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t---------------------------" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t| \a Paciente eliminado   |" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t---------------------------" << endl;
			color(pConsole, 7);
		}
		else
			system("cls");
	}
}

/*
* Guarda los pacientes en el archivo txt
*/
void guardarPacientes(const tLisaPacientes lista) 
{
	ofstream archivo;
	archivo.open("Registro_Pacientes.txt");
	for (int i = 0; i < lista.contador; i++)
	{
		archivo << lista.datosPersonales[i].cedula << endl;
		archivo << lista.datosPersonales[i].nombre << endl;
		archivo << lista.datosPersonales[i].tipoSangre << endl;
		archivo << lista.datosPersonales[i].telefono << endl;
		archivo << lista.datosPersonales[i].direccion << endl;
		archivo << lista.datosPersonales[i].edad << endl;
		archivo << lista.datosPersonales[i].peso << endl;
		archivo << lista.datosPersonales[i].estatura << endl;
		archivo << endl;
	}
	archivo << "XXX" << endl;
	archivo.close();
}

/*
* Retorna el valor de la posicion
*/
int retornarPosicion(tLisaPacientes lista, string cedulaBusqueda)
{
	int poisicion = -1;

	for (int i = 0; i < lista.contador; i++)
	{
		if (lista.datosPersonales[i].cedula == cedulaBusqueda)
		{
			poisicion = i;
		}
	}
	return poisicion;
}

/*
* Menu para modificar datos de los pacientes
*/
int verMenuModificarPacientes()
{
	int opcionMenu;

	cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t   ====Modificar Datos=====\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t-----------------------------" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t|1. Telefono                 |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t|2. Direccion                |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t|3. Edad                     |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t|4. Peso                     |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t|5. Estatura                 |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t|0. SALIR/Guardar Cambios    |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t-----------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\tEscoga una opcion: ";
	cin >> opcionMenu;

	return opcionMenu;
}

/*
* Modificar los datos
*/
void modificarPacienteDireccion(tLisaPacientes& lista, tPacientes pacientes)
{
	string cedula, sino;
	int posicion;
	tLisaPacientes auxliar;

	cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t=========Modificar Direccion========" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\tN# de Cedula: ";
	cin >> cedula;
	cout << endl << endl;
	posicion = retornarPosicion(lista, cedula);
	if (posicion == -1)
	{
		system("cls");
		color(pConsole, 12);
		cout << "\t\t\t\t\t\t\t\t\t\t----------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t| \aPaciente no encontrad@ |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t----------------------------" << endl;
		color(pConsole, 7);
	}
	else
	{
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t======INFORMACION PACIENTES=======\n" << endl;
		color(pConsole, 2);
		cout << "\t\t\t-------------------------------------------------------------------------------"
			<< "------------------------------------------------"
			<< "-----------------------------------------------------------------------" << endl;
		cout << "\t\t\t|" << setw(15) << left << "CEDULA" << "|"
			<< setw(40) << left << "NOMBRE" << "|"
			<< setw(25) << left << "TIPO DE SANGRE " << "|"
			<< setw(20) << left << "TELEFONO" << "|"
			<< setw(40) << left << "DIRECCION" << "|"
			<< setw(16) << left << "EDAD" << "|"
			<< setw(17) << left << "PESO" << "|"
			<< setw(16) << left << "ESTATURA" << "|" << endl;
		cout << "\t\t\t-------------------------------------------------------------------------------"
			<< "------------------------------------------------"
			<< "-----------------------------------------------------------------------" << endl;
		color(pConsole, 7);
		for (int i = 0; i < lista.contador; i++)
		{
			if (i == posicion)
			{
				cout << "\t\t\t|" << setw(15) << left << lista.datosPersonales[i].cedula << "|"
					<< setw(40) << left << lista.datosPersonales[i].nombre << "|"
					<< setw(25) << left << lista.datosPersonales[i].tipoSangre << "|"
					<< setw(20) << left << lista.datosPersonales[i].telefono << "|"
					<< setw(40) << left << lista.datosPersonales[i].direccion << "|"
					<< setw(16) << left << lista.datosPersonales[i].edad << "|"
					<< lista.datosPersonales[i].peso << "kg" << setw(12) << right << "|" <<
					lista.datosPersonales[i].estatura << "m"
					<< setw(12) << right << "|" << endl;
				cout << "\t\t\t--------------------------------------------------------------------------------"
					<< "------------------------------------------------"
					<< "----------------------------------------------------------------------" << endl;
			}
		}
		cin.ignore();
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tDireccion: ";
		pacientes = lista.datosPersonales[posicion];
		getline(cin, pacientes.direccion);
		cout << "\n\n" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t         Nuevos Datos" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tCedula: " << pacientes.cedula << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tNombre: " << pacientes.nombre << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tTipo de Sangre: " << pacientes.tipoSangre << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tTelefono: " << pacientes.telefono << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tDireccion: " << pacientes.direccion << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tEdad: " << pacientes.edad << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tPeso: " << pacientes.peso << "kg" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tEstatura: " << pacientes.estatura << "m" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t| Esta segur@ de modificar la paciente(s/n)?: ";
		cin >> sino;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------------------------------------" << endl;
		if (sino == "s")
		{
			/*
			* Modifica los datos
			*/
			system("cls");
			lista.datosPersonales[posicion].direccion = pacientes.direccion;
			color(pConsole, 12);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t| \a Paciente modificado  |" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------" << endl;
			color(pConsole, 7);
		}
		else
			system("cls");
	}
}
void modificarPacienteTelefono(tLisaPacientes& lista, tPacientes pacientes)
{
	string cedula, sino;
	int posicion;
	tLisaPacientes auxliar;

	cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t=========Modificar Telefono========" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\tN# de Cedula: ";
	cin >> cedula;
	posicion = retornarPosicion(lista, cedula);
	if (posicion == -1)
	{
		system("cls");
		color(pConsole, 12);
		cout << "\t\t\t\t\t\t\t\t\t\t----------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t| \aPaciente no encontrad@ |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t----------------------------" << endl;
		color(pConsole, 7);
	}
	else
	{
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t======INFORMACION PACIENTES=======\n" << endl;
		color(pConsole, 2);
		cout << "\t\t\t-------------------------------------------------------------------------------"
			<< "------------------------------------------------"
			<< "-----------------------------------------------------------------------" << endl;
		color(pConsole, 7);
		cout << "\t\t\t|" << setw(15) << left << "CEDULA" << "|"
			<< setw(40) << left << "NOMBRE" << "|"
			<< setw(25) << left << "TIPO DE SANGRE " << "|"
			<< setw(20) << left << "TELEFONO" << "|"
			<< setw(40) << left << "DIRECCION" << "|"
			<< setw(16) << left << "EDAD" << "|"
			<< setw(17) << left << "PESO" << "|"
			<< setw(16) << left << "ESTATURA" << "|" << endl;
		cout << "\t\t\t-------------------------------------------------------------------------------"
			<< "------------------------------------------------"
			<< "-----------------------------------------------------------------------" << endl;
		for (int i = 0; i < lista.contador; i++)
		{
			if (i == posicion)
			{
				cout << "\t\t\t|" << setw(15) << left << lista.datosPersonales[i].cedula << "|"
					<< setw(40) << left << lista.datosPersonales[i].nombre << "|"
					<< setw(25) << left << lista.datosPersonales[i].tipoSangre << "|"
					<< setw(20) << left << lista.datosPersonales[i].telefono << "|"
					<< setw(40) << left << lista.datosPersonales[i].direccion << "|"
					<< setw(16) << left << lista.datosPersonales[i].edad << "|"
					<< lista.datosPersonales[i].peso << "kg" << setw(12) << right << "|" <<
					lista.datosPersonales[i].estatura << "m"
					<< setw(12) << right << "|" << endl;
				cout << "\t\t\t--------------------------------------------------------------------------------"
					<< "------------------------------------------------"
					<< "----------------------------------------------------------------------" << endl;
			}
		}
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tTelefono: ";
		pacientes = lista.datosPersonales[posicion];
		cin >> pacientes.telefono;
		cout << "\n\n" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t         Nuevos Datos" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tCedula: " << pacientes.cedula << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tNombre: " << pacientes.nombre << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tTipo de Sangre: " << pacientes.tipoSangre << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tTelefono: " << pacientes.telefono << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tDireccion: " << pacientes.direccion << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tEdad: " << pacientes.edad << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tPeso: " << pacientes.peso << "kg" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tEstatura: " << pacientes.estatura << "m" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t| Esta segur@ de modificar la paciente(s/n)?: ";
		cin >> sino;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------------------------------------" << endl;
		if (sino == "s")
		{
			/*
			* Modifica los datos
			*/
			system("cls");
			lista.datosPersonales[posicion].telefono = pacientes.telefono;
			color(pConsole, 12);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t| \a Paciente modificado  |" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------" << endl;
			color(pConsole, 7);
		}
		else
			system("cls");
	}
}
void modificarPacienteEdad(tLisaPacientes& lista, tPacientes pacientes)
{
	string cedula, sino;
	int posicion;
	tLisaPacientes auxliar;

	cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t=========Modificar Edad========" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\tN# de Cedula: ";
	cin >> cedula;
	posicion = retornarPosicion(lista, cedula);
	if (posicion == -1)
	{
		system("cls");
		color(pConsole, 12);
		cout << "\t\t\t\t\t\t\t\t\t\t----------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t| \aPaciente no encontrad@ |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t----------------------------" << endl;
		color(pConsole, 7);
	}
	else
	{
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t======INFORMACION PACIENTES=======\n" << endl;
		color(pConsole, 2);
		cout << "\t\t\t-------------------------------------------------------------------------------"
			<< "------------------------------------------------"
			<< "-----------------------------------------------------------------------" << endl;
		cout << "\t\t\t|" << setw(15) << left << "CEDULA" << "|"
			<< setw(40) << left << "NOMBRE" << "|"
			<< setw(25) << left << "TIPO DE SANGRE " << "|"
			<< setw(20) << left << "TELEFONO" << "|"
			<< setw(40) << left << "DIRECCION" << "|"
			<< setw(16) << left << "EDAD" << "|"
			<< setw(17) << left << "PESO" << "|"
			<< setw(16) << left << "ESTATURA" << "|" << endl;
		cout << "\t\t\t-------------------------------------------------------------------------------"
			<< "------------------------------------------------"
			<< "-----------------------------------------------------------------------" << endl;
		color(pConsole, 7);
		for (int i = 0; i < lista.contador; i++)
		{
			if (i == posicion)
			{
				cout << "\t\t\t|" << setw(15) << left << lista.datosPersonales[i].cedula << "|"
					<< setw(40) << left << lista.datosPersonales[i].nombre << "|"
					<< setw(25) << left << lista.datosPersonales[i].tipoSangre << "|"
					<< setw(20) << left << lista.datosPersonales[i].telefono << "|"
					<< setw(40) << left << lista.datosPersonales[i].direccion << "|"
					<< setw(16) << left << lista.datosPersonales[i].edad << "|"
					<< lista.datosPersonales[i].peso << "kg" << setw(12) << right << "|" <<
					lista.datosPersonales[i].estatura << "m"
					<< setw(12) << right << "|" << endl;
				cout << "\t\t\t--------------------------------------------------------------------------------"
					<< "------------------------------------------------"
					<< "----------------------------------------------------------------------" << endl;
			}
		}
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tEdad: ";
		pacientes = lista.datosPersonales[posicion];
		cin >> pacientes.edad;
		cout << "\n\n" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t         Nuevos Datos" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tCedula: " << pacientes.cedula << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tNombre: " << pacientes.nombre << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tTipo de Sangre: " << pacientes.tipoSangre << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tTelefono: " << pacientes.telefono << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tDireccion: " << pacientes.direccion << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tEdad: " << pacientes.edad << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tPeso: " << pacientes.peso << "kg" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tEstatura: " << pacientes.estatura << "m" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t| Esta segur@ de modificar la paciente(s/n)?: ";
		cin >> sino;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------------------------------------" << endl;
		if (sino == "s")
		{
			/*
			* Modifica los datos
			*/
			system("cls");
			lista.datosPersonales[posicion].edad = pacientes.edad;
			color(pConsole, 10);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t| \a Paciente modificado  |" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------" << endl;
			color(pConsole, 7);
		}
		else
			system("cls");
	}
}
void modificarPacientePeso(tLisaPacientes& lista, tPacientes pacientes)
{
	string cedula, sino;
	int posicion;
	tLisaPacientes auxliar;

	cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t=========Modificar Peso========" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\tN# de Cedula: ";
	cin >> cedula;
	posicion = retornarPosicion(lista, cedula);
	if (posicion == -1)
	{
		system("cls");
		color(pConsole, 12);
		cout << "\t\t\t\t\t\t\t\t\t\t----------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t| \aPaciente no encontrad@ |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t----------------------------" << endl;
		color(pConsole, 7);
	}
	else
	{
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t======INFORMACION PACIENTES=======\n" << endl;
		color(pConsole, 2);
		cout << "\t\t\t-------------------------------------------------------------------------------"
			<< "------------------------------------------------"
			<< "-----------------------------------------------------------------------" << endl;
		cout << "\t\t\t|" << setw(15) << left << "CEDULA" << "|"
			<< setw(40) << left << "NOMBRE" << "|"
			<< setw(25) << left << "TIPO DE SANGRE " << "|"
			<< setw(20) << left << "TELEFONO" << "|"
			<< setw(40) << left << "DIRECCION" << "|"
			<< setw(16) << left << "EDAD" << "|"
			<< setw(17) << left << "PESO" << "|"
			<< setw(16) << left << "ESTATURA" << "|" << endl;
		cout << "\t\t\t-------------------------------------------------------------------------------"
			<< "------------------------------------------------"
			<< "-----------------------------------------------------------------------" << endl;
		color(pConsole, 7);
		for (int i = 0; i < lista.contador; i++)
		{
			if (i == posicion)
			{
				cout << "\t\t\t|" << setw(15) << left << lista.datosPersonales[i].cedula << "|"
					<< setw(40) << left << lista.datosPersonales[i].nombre << "|"
					<< setw(25) << left << lista.datosPersonales[i].tipoSangre << "|"
					<< setw(20) << left << lista.datosPersonales[i].telefono << "|"
					<< setw(40) << left << lista.datosPersonales[i].direccion << "|"
					<< setw(16) << left << lista.datosPersonales[i].edad << "|"
					<< lista.datosPersonales[i].peso << "kg" << setw(12) << right << "|" <<
					lista.datosPersonales[i].estatura << "m"
					<< setw(12) << right << "|" << endl;
				cout << "\t\t\t--------------------------------------------------------------------------------"
					<< "------------------------------------------------"
					<< "----------------------------------------------------------------------" << endl;
			}
		}
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tPeso: ";
		pacientes = lista.datosPersonales[posicion];
		cin >> pacientes.peso;
		cout << "\n\n" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t         Nuevos Datos" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tCedula: " << pacientes.cedula << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tNombre: " << pacientes.nombre << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tTipo de Sangre: " << pacientes.tipoSangre << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tTelefono: " << pacientes.telefono << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tDireccion: " << pacientes.direccion << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tEdad: " << pacientes.edad << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tPeso: " << pacientes.peso << "kg" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tEstatura: " << pacientes.estatura << "m" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t| Esta segur@ de modificar la paciente(s/n)?: ";
		cin >> sino;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------------------------------------" << endl;
		if (sino == "s")
		{
			/*
			* Modifica los datos
			*/
			system("cls");
			lista.datosPersonales[posicion].peso = pacientes.peso;
			color(pConsole, 10);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t| \a Paciente modificado  |" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------" << endl;
			color(pConsole, 7);
		}
		else
			system("cls");
	}
}
void modificarPacienteEstatura(tLisaPacientes& lista, tPacientes pacientes)
{
	string cedula, sino;
	int posicion;
	tLisaPacientes auxliar;

	cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t=========Modificar Peso========" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\tN# de Cedula: ";
	cin >> cedula;
	posicion = retornarPosicion(lista, cedula);
	if (posicion == -1)
	{
		system("cls");
		color(pConsole, 12);
		cout << "\t\t\t\t\t\t\t\t\t\t----------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t| \aPaciente no encontrad@ |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t----------------------------" << endl;
		color(pConsole, 7);
	}
	else
	{
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t======INFORMACION PACIENTES=======\n" << endl;
		color(pConsole, 2);
		cout << "\t\t\t-------------------------------------------------------------------------------"
			<< "------------------------------------------------"
			<< "-----------------------------------------------------------------------" << endl;
		cout << "\t\t\t|" << setw(15) << left << "CEDULA" << "|"
			<< setw(40) << left << "NOMBRE" << "|"
			<< setw(25) << left << "TIPO DE SANGRE " << "|"
			<< setw(20) << left << "TELEFONO" << "|"
			<< setw(40) << left << "DIRECCION" << "|"
			<< setw(16) << left << "EDAD" << "|"
			<< setw(17) << left << "PESO" << "|"
			<< setw(16) << left << "ESTATURA" << "|" << endl;
		cout << "\t\t\t-------------------------------------------------------------------------------"
			<< "------------------------------------------------"
			<< "-----------------------------------------------------------------------" << endl;
		color(pConsole, 7);
		for (int i = 0; i < lista.contador; i++)
		{
			if (i == posicion)
			{
				cout << "\t\t\t|" << setw(15) << left << lista.datosPersonales[i].cedula << "|"
					<< setw(40) << left << lista.datosPersonales[i].nombre << "|"
					<< setw(25) << left << lista.datosPersonales[i].tipoSangre << "|"
					<< setw(20) << left << lista.datosPersonales[i].telefono << "|"
					<< setw(40) << left << lista.datosPersonales[i].direccion << "|"
					<< setw(16) << left << lista.datosPersonales[i].edad << "|"
					<< lista.datosPersonales[i].peso << "kg" << setw(12) << right << "|" <<
					lista.datosPersonales[i].estatura << "m"
					<< setw(12) << right << "|" << endl;
				cout << "\t\t\t--------------------------------------------------------------------------------"
					<< "------------------------------------------------"
					<< "----------------------------------------------------------------------" << endl;
			}
		}
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tEstatura: ";
		pacientes = lista.datosPersonales[posicion];
		cin >> pacientes.estatura;
		cout << "\n\n" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t         Nuevos Datos" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tCedula: " << pacientes.cedula << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tNombre: " << pacientes.nombre << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tTipo de Sangre: " << pacientes.tipoSangre << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tTelefono: " << pacientes.telefono << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tDireccion: " << pacientes.direccion << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tEdad: " << pacientes.edad << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tPeso: " << pacientes.peso << "kg" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tEstatura: " << pacientes.estatura << "m" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t| Esta segur@ de modificar la paciente(s/n)?: ";
		cin >> sino;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t----------------------------------------------" << endl;
		if (sino == "s")
		{
			/*
			* Modifica los datos
			*/
			system("cls");
			lista.datosPersonales[posicion].estatura = pacientes.estatura;
			color(pConsole, 10);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t| \a Paciente modificado  |" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t---------------------------" << endl;
			color(pConsole, 7);
		}
		else
			system("cls");
	}
}

void ordenarDatos(tLisaPacientes& lista)
{
	tPacientes auxiliar;
	for (int i = 0; i < lista.contador; i++)
	{
		for (int j = i + 1; j < lista.contador; j++)
		{
			if (lista.datosPersonales[i].nombre > lista.datosPersonales[j].nombre)
			{
				auxiliar = lista.datosPersonales[i];
				lista.datosPersonales[i] = lista.datosPersonales[j];
				lista.datosPersonales[j] = auxiliar;
			}
		}
	}
}