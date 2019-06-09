#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

struct ctrlCarrera{	
		
	void insertCarrera(struct carrera carrera){
		FILE *f;
		f=fopen("Archivos/carrera.txt","a");
		if(f==NULL){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		fprintf(f,"%i %s %i %i \n",carrera.getId(),carrera.getNombre(),carrera.getDuracion(),carrera.getActivo());
		rewind(f);
		fclose(f);
	}
	
	void updateCarrera(struct carrera miCarrera){
		struct carrera carrera;
		struct carrera auxiliar;
		bool encontrado=false;
		FILE *f1;
		f1=fopen("Archivos/carrera.txt","r");
		
		FILE *f2;
		f2=fopen("Archivos/auxiliar.txt","w");
		if((f1==NULL) && (f2==NULL)){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		
		int id_carrera;
	    char nombre[50];
	    int duracion;
	    int activo;
	    while(!feof(f1)){
	    	fscanf(f1,"%i%s%i%i\n",&id_carrera,&nombre,&duracion,&activo);
	    	carrera.ConstructorCarrera(id_carrera,nombre,duracion,activo);
	    	if(carrera.getId()==miCarrera.getId()){
	    		auxiliar=miCarrera;
	    		carrera=auxiliar;
	    		encontrado=true;
			}
			fprintf(f2,"%i %s %i %i \n",carrera.getId(),carrera.getNombre(),carrera.getDuracion(),carrera.getActivo());
		}
		rewind(f1);
		rewind(f2);
		fclose(f1); 
		fclose(f2);
		remove("Archivos/carrera.txt");
		rename("Archivos/auxiliar.txt","Archivos/carrera.txt");
	}
	
	struct carrera getCarreraById(int miId){
		struct carrera carrera;
		struct carrera miCarrera;
		FILE *f;
		f=fopen("Archivos/carrera.txt","r");
		if(f==NULL){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		
		int id_carrera;
	    char nombre[50];
	    int duracion;
	    int activo;
	    int cont=0;
	    while(!feof(f)){
	    	fscanf(f,"%i%s%i%i\n",&id_carrera,&nombre,&duracion,&activo);
	    	carrera.ConstructorCarrera(id_carrera,nombre,duracion,activo);
	    	if(carrera.getId()==miId){
	    		miCarrera=carrera;
			}
		}
		rewind(f);
	    fclose(f);
	    return miCarrera;
	}
	
	bool existeCarrera(struct carrera miCarrera,int idSeleccionado){
		bool existe=false;
		if(miCarrera.getId()==idSeleccionado){
			existe=true;
		}
		return existe;
	}
	
	void getAllCarrera(){
		struct carrera carrera;
		FILE *f;
		f=fopen("Archivos/carrera.txt","r");
		if(f==NULL){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		
		int id_carrera;
	    char nombre[50];
	    int duracion;
	    int activo;
	    int cont=0;
	    while(!feof(f)){
	    	fscanf(f,"%i%s%i%i\n",&id_carrera,&nombre,&duracion,&activo);
	    	carrera.ConstructorCarrera(id_carrera,nombre,duracion,activo);
	    	carrera.imprimirDatosCarrera();
	    	printf("\n");
		}
		rewind(f);
	    fclose(f);
	}
	
	void getAllCarreraReducido(){
		struct carrera carrera;
		FILE *f;
		f=fopen("Archivos/carrera.txt","r");
		if(f==NULL){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		
		int id_carrera;
	    char nombre[50];
	    int duracion;
	    int activo;
	    int cont=0;
	    while(!feof(f)){
	    	fscanf(f,"%i%s%i%i\n",&id_carrera,&nombre,&duracion,&activo);
	    	carrera.ConstructorCarrera(id_carrera,nombre,duracion,activo);
	    	carrera.imprimirDatosCarreraReducido();
	    	printf("\n");
		}
		rewind(f);
	    fclose(f);
	}
};
