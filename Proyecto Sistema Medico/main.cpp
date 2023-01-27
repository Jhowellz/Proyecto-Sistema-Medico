#include <iostream>


/*
* Cabeceras de Modulos
*/
#include "GestionCitasMedicas.h";
#include "GestionMedicos.h";
#include "GestionPacientes.h";

using namespace std;

/*
* Programa Principal donde se encontraran
* todas funciones necesarias para su funcionamiento
*/

void titulo();

int main()
{
	//system("color f0");

	tListaCitas listaCitas;
	tLisaPacientes listaPacientes;
	tListaMedicos listaMedicos;

	tCitasMedicas citasMedicas;
	tMedicos medicos;
	tPacientes pacientes;
	bool ok;
	int opcionMenu;
	

	do
	{
		titulo();
		opcionMenu = verMenuPrincipal();
		system("cls");
		switch (opcionMenu)
		{
			case 1:
				/*
				* Gestion Citas
				*/
				cargarDatosCitas(listaCitas);
			
				int opcionMenu;
				do
				{
					cout << "\n\n" << endl;
					opcionMenu = verMenuCitasMedicas();
					system("cls");
					switch (opcionMenu)
					{
						/*
						* Visualizar Citas medicas
						*/
						case 1:
							ordenarLista(listaCitas);
							visualizarCitas(listaCitas, ok);
							cout << "\n\n\n" << endl;
							break;
						case 2:
							/*
							* Agendar una cita
							*/
							agendarUnaCita(listaCitas, citasMedicas);
							guardarCitas(listaCitas);
							break;
						case 3:
							/*
							* Elimina una cita del registro
							*/
							visualizarCitas(listaCitas, ok);
							eliminarCita(listaCitas);
							guardarCitas(listaCitas);
							break;
						case 4:
							/*
							* Consultar la cita de un paciente
							*/
							consultarCita(listaCitas);
							break;
						case 5:
							/*
							* Repogramar Horarios de las citas
							*/
							int opcionMenu;
							do
							{
								opcionMenu = verMenuReprogramarCita();
								system("cls");
								switch (opcionMenu)
								{
								case 1:
									reprogramarCitaFecha(listaCitas, citasMedicas);
									guardarCitas(listaCitas);
									break;
								case 2:
									reprogramarCitasHora(listaCitas, citasMedicas);
									guardarCitas(listaCitas);
									break;
								case 0:
									break;
								default:
									cout << "Opcion Erronea!!" << endl;
									break;
								}
							} while (opcionMenu != 0);
							break;
						case 0:
							break;
						default:
							cout << "Opcion incorrecta" << endl;
							break;
					}
				} while (opcionMenu != 0);
				break;
			case 2:
				/*
				* Gestion de Medicos
				*/
				cargarDatosMedicos(listaMedicos);

				int opcionMenuMedico;
				do
				{
					opcionMenuMedico = verMenuMedicos();
					system("cls");
					switch (opcionMenuMedico)
					{
						case 1:
							ordenarListaMedicos(listaMedicos);
							visualizarMedicos(listaMedicos, ok);
							break;
						case 2:
							agregarMedico(listaMedicos, medicos);
							guardarMedicos(listaMedicos);
							break;
						case 3:
							consultarMedico(listaMedicos);
							break;
						case 4:
							visualizarMedicos(listaMedicos, ok);
							eliminarMedico(listaMedicos);
							guardarMedicos(listaMedicos);
							break;
						case 5:
							/*
							* Modificar Datos
							*/
							int opcionMenuModificar;

							do
							{
								opcionMenuModificar = verMenuModificarMedico();
								system("cls");
								switch (opcionMenuModificar)
								{
								case 1:
									modificarMedicoNombre(listaMedicos, medicos);
									guardarMedicos(listaMedicos);
									break;
								case 2:
									modificarMedicoCedula(listaMedicos, medicos);
									guardarMedicos(listaMedicos);
									break;
								case 3:
									modificarMedicoEspecialidad(listaMedicos, medicos);
									guardarMedicos(listaMedicos);
									break;
								case 4:
									modificarMedicoTelefono(listaMedicos, medicos);
									guardarMedicos(listaMedicos);
									break;
								case 5:
									modificarMedicoEdad(listaMedicos, medicos);
									guardarMedicos(listaMedicos);
									break;
								case 0:
									break;
								default:
									break;
								}
							} while (opcionMenuModificar != 0);
							break;
						case 0:
							break;
					}
				} while (opcionMenuMedico != 0);
				break;
			case 3:
				/*
				* Gestion de Pacientes
				*/
				cargarDatosPacientes(listaPacientes);
				
				int opcionMenuPacientes;
				do
				{
					opcionMenuPacientes = verMenuPacientes();
					system("cls");
					switch (opcionMenuPacientes)
					{
						case 1:
							/*
							* Visualizar los pacientes
							*/
							ordenarDatos(listaPacientes);
							visualizarPacientes(listaPacientes, ok);
							break;
						case 2:
							/*
							* Agregar nuevos datos
							*/
							agregarPaciente(listaPacientes, pacientes);
							guardarPacientes(listaPacientes);
							break;
						case 3:
							/*
							* Consular datos de un paciente
							*/
							consultarPaciente(listaPacientes);
							break;
						case 4:
							/*
							* Eliminar un paciente
							*/
							visualizarPacientes(listaPacientes, ok);
							eliminarPaciente(listaPacientes);
							guardarPacientes(listaPacientes);
							break;
						case 5:
							int opcionMenuModificar;

							do
							{
								opcionMenuModificar = verMenuModificarPacientes();
								system("cls");
								switch (opcionMenuModificar)
								{
									case 1:
										//Telefono
										modificarPacienteTelefono(listaPacientes, pacientes);
										break;
									case 2:
										//Direccion
										modificarPacienteDireccion(listaPacientes, pacientes);
										break;
									case 3:
										//Edad
										modificarPacienteEdad(listaPacientes, pacientes);
										break;
									case 4:
										//Peso
										modificarPacientePeso(listaPacientes, pacientes);
										break;
									case 5:
										//Estatura
										modificarPacienteEstatura(listaPacientes, pacientes);
										break;
									case 0:
										guardarPacientes(listaPacientes);
										break;
									default:
										cout << "\nOpcion Incorrecta!!!" << endl;
										break;
								}
							} while (opcionMenuModificar != 0);
							break;
						case 0:
							break;
						default:
							break;
					}
				} while (opcionMenuPacientes != 0);
				break;
			case 0:
				/*
				* SALIDA del programa
				*/
				return 0;
				break;
			default:
				/*
				* Opcion Incorrecta
				*/
				break;
		}
	} while (opcionMenu != 0);

	return 0;
}
void titulo() 
{
	cout << "\n\n\n\n\n" << endl;
	color(hConsole, 9);
	cout << "\t\t\t\t\t\t" << endl;
	cout << "\t\t\t\t\t\t .::     .::     .::::        .:: ::   .:::::::   .:: .::: .::::::       .:        .::             .:::::::: .:::::::   .:::     .:: " << endl;
	cout << "\t\t\t\t\t\t .::     .::   .::    .::   .::    .:: .::    .:: .::      .::          .: ::      .::             .::       .::    .:: .: .::   .:: " << endl;
	cout << "\t\t\t\t\t\t .::     .:: .::        .::  .::       .::    .:: .::      .::         .:  .::     .::             .::       .::    .:: .:: .::  .:: " << endl;
	cout << "\t\t\t\t\t\t .:::::: .:: .::        .::    .::     .:::::::   .::      .::        .::   .::    .::             .::::::   .:::::::   .::  .:: .:: " << endl;
	cout << "\t\t\t\t\t\t .::     .:: .::        .::       .::  .::        .::      .::       .:::::: .::   .::             .::       .::        .::   .: .:: " << endl;
	cout << "\t\t\t\t\t\t .::     .::   .::     .::  .::    .:: .::        .::      .::      .::       .::  .::             .::       .::        .::    .: :: " << endl;
	cout << "\t\t\t\t\t\t .::     .::     .::::        .:: ::   .::        .::      .::     .::         .:: .::::::::       .:::::::: .::        .::      .:: " << endl;
	cout << "\t\t\t\t" << endl;

}