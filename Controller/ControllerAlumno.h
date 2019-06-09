#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

struct ctrlAlumno{
	
	void insertAlumno(struct alumno alumno){
		FILE *f;
		f=fopen("Archivos/alumno.txt","a");
		if(f==NULL){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		fprintf(f,"%i %s %s %i %s %s %s %s %i \n",alumno.getLegajo(),alumno.getNombre(),alumno.getApellido(),
		alumno.getDocumento(),alumno.getFechaInscripcion(),alumno.getFechaNacimiento(),alumno.getTelefono(),
		alumno.getEmail(),alumno.getActivo());
		rewind(f);
		fclose(f);
	}
	
	void updateAlumno(struct alumno miAlumno){
		struct alumno alumno;
		struct alumno auxiliar;
		bool encontrado=false;
		FILE *f1;
		f1=fopen("Archivos/alumno.txt","r");
		
		FILE *f2;
		f2=fopen("Archivos/auxiliar.txt","w");
		if((f1==NULL) && (f2==NULL)){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		
		int legajo;
	    char nombre[50];
	    char apellido[50];
	    int documento;
	    char fecha_inscripcion[50];
	    char fecha_nacimiento[50];
	    char telefono[50];
	    char email[50];
	    int activo;
		while(!feof(f1)){
			fscanf(f1,"%i%s%s%i%s%s%s%s%i\n",&legajo,&nombre,&apellido,&documento,&fecha_inscripcion,
		    &fecha_nacimiento,&telefono,&email,&activo);
		    alumno.ConstructorAlumno(legajo,nombre,apellido,documento,fecha_inscripcion,fecha_nacimiento,
		    telefono,email,activo);
		    if(alumno.getLegajo()==miAlumno.getLegajo()){
		    	auxiliar=miAlumno;
		    	alumno=auxiliar;
		    	encontrado=true;
			}
			fprintf(f2,"%i %s %s %i %s %s %s %s %i \n",alumno.getLegajo(),alumno.getNombre(),alumno.getApellido(),
		    alumno.getDocumento(),alumno.getFechaInscripcion(),alumno.getFechaNacimiento(),alumno.getTelefono(),
		    alumno.getEmail(),alumno.getActivo());
		}
		rewind(f1);
		rewind(f2);
		fclose(f1); 
		fclose(f2);
		remove("Archivos/alumno.txt");
		rename("Archivos/auxiliar.txt","Archivos/alumno.txt");
	}
	
	struct alumno getAlumnoById(int miLegajo){
		struct alumno alumno;
		struct alumno miAlumno;
		FILE *f;
		f=fopen("Archivos/alumno.txt","r");
		if(f==NULL){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		
	    int legajo;
	    char nombre[50];
	    char apellido[50];
	    int documento;
	    char fecha_inscripcion[50];
	    char fecha_nacimiento[50];
	    char telefono[50];
	    char email[50];
	    int activo;
	    
	    while(!feof(f)){
	    	fscanf(f,"%i%s%s%i%s%s%s%s%i\n",&legajo,&nombre,&apellido,&documento,&fecha_inscripcion,
		    &fecha_nacimiento,&telefono,&email,&activo);
		    alumno.ConstructorAlumno(legajo,nombre,apellido,documento,fecha_inscripcion,fecha_nacimiento,
		    telefono,email,activo);
		    if(alumno.getLegajo()==miLegajo){
		    	miAlumno=alumno;
			}
		}
		rewind(f);
	    fclose(f);
	    return miAlumno;
	}
	
	bool existeAlumno(struct alumno miAlumno,int idSeleccionado){
		bool existe=false;
		if(miAlumno.getLegajo()==idSeleccionado){
			existe=true;
		}
		return existe;
	}
	
	void getAllAlumno(){
		struct alumno alumno;
		FILE *f;
		f=fopen("Archivos/alumno.txt","r");
		if(f==NULL){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		
	    int legajo;
	    char nombre[50];
	    char apellido[50];
	    int documento;
	    char fecha_inscripcion[50];
	    char fecha_nacimiento[50];
	    char telefono[50];
	    char email[50];
	    int activo;
	    
	    while(!feof(f)){
	    	fscanf(f,"%i%s%s%i%s%s%s%s%i\n",&legajo,&nombre,&apellido,&documento,&fecha_inscripcion,
		    &fecha_nacimiento,&telefono,&email,&activo);
		    alumno.ConstructorAlumno(legajo,nombre,apellido,documento,fecha_inscripcion,fecha_nacimiento,
		    telefono,email,activo);
		    alumno.imprimirDatosAlumno();
		    printf("\n");
		}
		rewind(f);
	    fclose(f);
	}
	
	void getAllAlumnoReducido(){
		struct alumno alumno;
		FILE *f;
		f=fopen("Archivos/alumno.txt","r");
		if(f==NULL){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		
	    int legajo;
	    char nombre[50];
	    char apellido[50];
	    int documento;
	    char fecha_inscripcion[50];
	    char fecha_nacimiento[50];
	    char telefono[50];
	    char email[50];
	    int activo;
	    
	    while(!feof(f)){
	    	fscanf(f,"%i%s%s%i%s%s%s%s%i\n",&legajo,&nombre,&apellido,&documento,&fecha_inscripcion,
		    &fecha_nacimiento,&telefono,&email,&activo);
		    alumno.ConstructorAlumno(legajo,nombre,apellido,documento,fecha_inscripcion,fecha_nacimiento,
		    telefono,email,activo);
		    alumno.imprimirDatosAlumnoReducido();
		    printf("\n");
		}
		rewind(f);
	    fclose(f);
	}
	
	void getAllLegajo(){
		struct alumno alumno;
		FILE *f;
		f=fopen("Archivos/alumno.txt","r");
		if(f==NULL){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		
	    int legajo;
	    char nombre[50];
	    char apellido[50];
	    int documento;
	    char fecha_inscripcion[50];
	    char fecha_nacimiento[50];
	    char telefono[50];
	    char email[50];
	    int activo;
	    
	    while(!feof(f)){
	    	fscanf(f,"%i%s%s%i%s%s%s%s%i\n",&legajo,&nombre,&apellido,&documento,&fecha_inscripcion,
		    &fecha_nacimiento,&telefono,&email,&activo);
		    alumno.ConstructorAlumno(legajo,nombre,apellido,documento,fecha_inscripcion,fecha_nacimiento,
		    telefono,email,activo);
		    alumno.imprimirDatosAlumnoReducido();
		    printf("\n");
		}
		rewind(f);
	    fclose(f);
	}
	
	
};


