#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

struct profesor{
	private:
	int id_profesor;
	char apellido[50];
	char nombre[50];
	char telefono[50];
	char email[50];
	int activo;
	
	public:
		
		void ConstructorProfesor(int miId_profesor,const char miApellido[50],const char miNombre[50],const char miTelefono[50],
		const char miEmail[50],int miActivo){
			this->id_profesor=miId_profesor;
			strcpy(apellido,miApellido);
			strcpy(nombre,miNombre);
			strcpy(telefono,miTelefono);
			strcpy(email,miEmail);
			this->activo=miActivo;
		}
		
		void Profesor(){
			printf("INGRESE ID ");
			scanf("%i",&id_profesor);
			printf("INGRESE APELLIDO ");
			scanf("%s",&apellido);
			printf("INGRESE NOMBRE ");
			scanf("%s",&nombre);
			printf("INGRESE TELEFONO ");
			scanf("%s",&telefono);
			printf("INGRESE EMAIL ");
			scanf("%s",&email);
			printf("INGRESE ACTIVO(1-ACTIVO,2-DESACTIVO) ");
			scanf("%i",&activo);
		}
		
		void setId(){
			printf("INGRESE ID ");
			scanf("%i",&id_profesor);
		}
		
		int getId(){
			return id_profesor;
		}
		
		void setApellido(){
			printf("INGRESE APELLIDO ");
			scanf("%s",&apellido);
		}
		
		char* getApellido(){
			return apellido;
		}
		
		void setNombre(){
			printf("INGRESE NOMBRE ");
			scanf("%s",&nombre);
		}
		
		char* getNombre(){
			return nombre;
		}
		
		void setTelefono(){
			printf("INGRESE TELEFONO ");
			scanf("%s",&telefono);
		}
		
		char* getTelefono(){
			return telefono;
		}
		
		void setEmail(){
			printf("INGRESE EMAIL ");
			scanf("%s",&email);
		}
		
		char* getEmail(){
			return email;
		}
		
		void setActivo(){
			printf("INGRESE ACTIVO(1-ACTIVO,2-DESACTIVO) ");
			scanf("%i",&activo);
		}
		
		int getActivo(){
			return activo;
		}
		
		void setDesactivo(int desactivo){
			this->activo=desactivo;
		}
		
		void imprimirDatosProfesor(){
			printf("ID_PROFESOR: %i \n",id_profesor);
			printf("APELLIDO: %s \n",apellido);
			printf("NOMBRE: %s \n",nombre);
			printf("TELEFONO: %s \n",telefono);
			printf("EMAIL: %s \n",email);
			printf("ACTIVO: %i \n",activo);
		}
		
		void imprimirDatosProfesorReducido(){
			printf("ID: %i APELLIDO: %s NOMBRE: %s\n",id_profesor,apellido,nombre);
		}
};
