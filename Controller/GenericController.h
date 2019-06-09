#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include "ControllerAlumno.h"
#include "ControllerCarrera.h"
#include "ControllerCorrelativa.h"
#include "ControllerLoguin.h"
#include "ControllerMateria.h"
#include "ControllerNota.h"
#include "ControllerProfesor.h"
#include "ControllerTipoExamen.h"
#include "ControllerUsuario.h"

struct ctrlError{
	
	int imprimirErrorCarrera(){
		system("cls");
		printf("EL ID_CARRERA INGRESADO NO ES CORRECTO \n");
		system("pause>null");
		return 0;
	}
	
	int imprimirErrorAlumno(){
		system("cls");
		printf("EL ID_ALUMNO INGRESADO NO ES CORRECTO \n");
		system("pause>null");
		return 1;
	}
	
	void imprimirErrorProfesor(){
		system("cls");
		printf("EL ID_PROFESOR INGRESADO NO ES CORRECTO \n");
		system("pause>null");
	}
	
	void imprimirErrorMateria(){
		system("cls");
		printf("EL ID_MATERIA INGRESADO NO ES CORRECTO \n");
		system("pause>null");
	}
	
	void imprimirErrorCorrelativa(){
		system("cls");
		printf("EL ID_CORRELATIVA INGRESADO NO ES CORRECTO \n");
		system("pause>null");
	}
	
	void imprimirErrorTipoExamen(){
		system("cls");
		printf("EL ID_TIPO_EXAMEN INGRESADO NO ES CORRECTO \n");
		system("pause>null");
	}
	
	void imprimirErrorNota(){
		system("cls");
		printf("EL ID_NOTA INGRESADO NO ES CORRECTO \n");
		system("pause>null");
	}
};
