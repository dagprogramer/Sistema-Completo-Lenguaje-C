#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

struct alumno{
	private:
	int legajo;
	char nombre[50];
	char apellido[50];
	int documento;
	char fecha_inscripcion[50];
	char fecha_nacimiento[50];
	char telefono[50];
	char email[50];
	int activo;
	
	public:
		
		void ConstructorAlumno(int miLegajo,const char miNombre[50],const char miApellido[50],int miDocumento,const char miFecha_inscripcion[50],
		const char miFecha_nacimiento[50],const char miTelefono[50],const char miEmail[50],int miActivo){
			this->legajo=miLegajo;
			strcpy(nombre,miNombre);
			strcpy(apellido,miApellido);
			this->documento=miDocumento;
			strcpy(fecha_inscripcion,miFecha_inscripcion);
			strcpy(fecha_nacimiento,miFecha_nacimiento);
			strcpy(telefono,miTelefono);
			strcpy(email,miEmail);
			this->activo=miActivo;
		}
		
		void Alumno(){
			printf("INGRESE LEGAJO ");
			scanf("%i",&legajo);
			printf("INGRESE NOMBRE ");
			scanf("%s",&nombre);
			printf("INGRESE APELLIDO ");
			scanf("%s",&apellido);
			printf("INGRESE DOCUMENTO ");
			scanf("%i",&documento);
			printf("INGRESE FECHA INSCRIPCION(dd/mm/yy) ");
			scanf("%s",&fecha_inscripcion);
			printf("INGRESE FECHA NACIMIENTO(dd/mm/yy) ");
			scanf("%s",&fecha_nacimiento);
			printf("INGRESE TELEFONO ");
			scanf("%s",&telefono);
			printf("INGRESE EMAIL ");
			scanf("%s",&email);
			printf("INGRESE activo(1-ACTIVO,2-DESACTIVO) ");
			scanf("%i",&activo);
		}
		
		void setLegajo(){
			printf("INGRESE LEGAJO ");
			scanf("%i",&legajo);
		}
		
		int getLegajo(){
			return legajo;
		}
		
		void setNombre(){
			printf("INGRESE NOMBRE ");
			scanf("%s",&nombre);
		}
		
		void setNombreEscrito(const char miNombre[50]){
			strcpy(nombre,miNombre);
		}
		
		char* getNombre(){
			return nombre;
		}
		
		void setApellido(){
			printf("INGRESE APELLIDO ");
			scanf("%s",&apellido);
		}
		
		char* getApellido(){
			return apellido;
		}
		
		void setDocumento(){
			printf("INGRESE DOCUMENTO ");
			scanf("%i",&documento);
		}
		
		int getDocumento(){
			return documento;
		}
		
		void setFechaInscripcion(){
			printf("INGRESE FECHA INSCRIPCION(dd/mm/yy) ");
			scanf("%s",&fecha_inscripcion);
		}
		
		char* getFechaInscripcion(){
			return fecha_inscripcion;
		}
		
		void setFechaNacimiento(){
			printf("INGRESE FECHA NACIMIENTO(dd/mm/yy) ");
			scanf("%s",&fecha_nacimiento);
		}
		
		char* getFechaNacimiento(){
			return fecha_nacimiento;
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
		
		void imprimirDatosAlumno(){
			printf("LEGAJO: %i\n",legajo);
			printf("NOMBRE: %s\n",nombre);
			printf("APELLIDO: %s\n",apellido);
			printf("DOCUMENTO: %i\n",documento);
			printf("FECHA_INSCRIPCION: %s\n",fecha_inscripcion);
			printf("FECHA_NACIMIENTO: %s\n",fecha_nacimiento);
			printf("TELEFONO: %s\n",telefono);
			printf("EMAIL: %s\n",email);
			printf("ACTIVO: %i\n",activo);
		}
		
		void imprimirDatosAlumnoReducido(){
			printf("LEGAJO: %i NOMBRE: %s APELLIDO: %s \n",legajo,nombre,apellido);
		}
};
