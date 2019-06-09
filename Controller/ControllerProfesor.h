#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

struct ctrlProfesor{
	
	void insertProfesor(struct profesor profesor){
		FILE *f;
		f=fopen("Archivos/profesor.txt","a");
		if(f==NULL){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		fprintf(f,"%i %s %s %s %s %i \n",profesor.getId(),profesor.getApellido(),profesor.getNombre(),
		profesor.getTelefono(),profesor.getEmail(),profesor.getActivo());
		rewind(f);
		fclose(f);
	}
	
	void updateProfesor(struct profesor miProfesor){
		struct profesor profesor;
		struct profesor auxiliar;
		bool encontrado=false;
		FILE *f1;
		f1=fopen("Archivos/profesor.txt","r");
		
		FILE *f2;
		f2=fopen("Archivos/auxiliar.txt","w");
		if((f1==NULL) && (f2==NULL)){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		
		int id_profesor;
	    char apellido[50];
	    char nombre[50];
	    char telefono[50];
	    char email[50];
	    int activo;
		while(!feof(f1)){
			fscanf(f1,"%i%s%s%s%s%i\n",&id_profesor,&apellido,&nombre,&telefono,&email,&activo);
			profesor.ConstructorProfesor(id_profesor,apellido,nombre,telefono,email,activo);
	        if(profesor.getId()==miProfesor.getId()){
	        	auxiliar=miProfesor;
	        	profesor=auxiliar;
	        	encontrado=true;
			}
			fprintf(f2,"%i %s %s %s %s %i \n",profesor.getId(),profesor.getApellido(),profesor.getNombre(),
		    profesor.getTelefono(),profesor.getEmail(),profesor.getActivo());
		}
		rewind(f1);
		rewind(f2);
		fclose(f1); 
		fclose(f2);
		remove("Archivos/profesor.txt");
		rename("Archivos/auxiliar.txt","Archivos/profesor.txt");
	}
	
	struct profesor getProfesorById(int miId){
		struct profesor profesor;
		struct profesor miProfesor;
		FILE *f;
		f=fopen("Archivos/profesor.txt","r");
		if(f==NULL){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		
		int id_profesor;
	    char apellido[50];
	    char nombre[50];
	    char telefono[50];
	    char email[50];
	    int activo;
		while(!feof(f)){
			fscanf(f,"%i%s%s%s%s%i\n",&id_profesor,&apellido,&nombre,&telefono,&email,&activo);
			profesor.ConstructorProfesor(id_profesor,apellido,nombre,telefono,email,activo);
	        if(profesor.getId()==miId){
	        	miProfesor=profesor;
			}
		}
		rewind(f);
	    fclose(f);
	    return miProfesor;
	}
	
	bool existeProfesor(struct profesor miProfesor,int idSeleccionado){
		bool existe=false;
		if(miProfesor.getId()==idSeleccionado){
			existe=true;
		}
		return existe;
	}
	
	void getAllProfesor(){
		struct profesor profesor;
		FILE *f;
		f=fopen("Archivos/profesor.txt","r");
		if(f==NULL){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		
		int id_profesor;
	    char apellido[50];
	    char nombre[50];
	    char telefono[50];
	    char email[50];
	    int activo;
		while(!feof(f)){
			fscanf(f,"%i%s%s%s%s%i\n",&id_profesor,&apellido,&nombre,&telefono,&email,&activo);
			profesor.ConstructorProfesor(id_profesor,apellido,nombre,telefono,email,activo);
	        profesor.imprimirDatosProfesor();
	        printf("\n");
		}
		rewind(f);
	    fclose(f);
	}
	
	void getAllProfesorReducido(){
		struct profesor profesor;
		FILE *f;
		f=fopen("Archivos/profesor.txt","r");
		if(f==NULL){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		
		int id_profesor;
	    char apellido[50];
	    char nombre[50];
	    char telefono[50];
	    char email[50];
	    int activo;
		while(!feof(f)){
			fscanf(f,"%i%s%s%s%s%i\n",&id_profesor,&apellido,&nombre,&telefono,&email,&activo);
			profesor.ConstructorProfesor(id_profesor,apellido,nombre,telefono,email,activo);
	        profesor.imprimirDatosProfesorReducido();
	        printf("\n");
		}
		rewind(f);
	    fclose(f);
	}
};
