#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

struct ctrlMateria{
	
	void insertMateria(struct materia materia){
		FILE *f;
		f=fopen("Archivos/materia.txt","a");
		if(f==NULL){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		fprintf(f,"%i %s %i %i %i %i %i \n",materia.getIdMateria(),materia.getNombre(),materia.getIdCarrera(),
		materia.getIdProfesor(),materia.getAnioCursada(),materia.getPromocion(),materia.getActivo());
		rewind(f);
		fclose(f);
	}
	
	void updateMateria(struct materia miMateria){
		struct materia materia;
		struct materia auxiliar;
		bool encontrado=false;
		FILE *f1;
		f1=fopen("Archivos/materia.txt","r");
		
		FILE *f2;
		f2=fopen("Archivos/auxiliar.txt","w");
		if((f1==NULL) && (f2==NULL)){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		int id_materia;
	    char nombre[50];
	    int id_carrera;
	    int id_profesor;
	    int anio_cursada;
	    int promocion;
	    int activo;
	    int cont=0;
	    while(!feof(f1)){
	    	fscanf(f1,"%i%s%i%i%i%i%i\n",&id_materia,&nombre,&id_carrera,&id_profesor,&anio_cursada,&promocion,&activo);
	    	materia.ConstructorMateria(id_materia,nombre,id_carrera,id_profesor,anio_cursada,promocion,activo);
	    	if(materia.getIdMateria()==miMateria.getIdMateria()){
	    		auxiliar=miMateria;
	    		materia=auxiliar;
	    		encontrado=true;
			}
			fprintf(f2,"%i %s %i %i %i %i %i \n",materia.getIdMateria(),materia.getNombre(),materia.getIdCarrera(),
		    materia.getIdProfesor(),materia.getAnioCursada(),materia.getPromocion(),materia.getActivo());
		}
		rewind(f1);
		rewind(f2);
		fclose(f1); 
		fclose(f2);
		remove("Archivos/materia.txt");
		rename("Archivos/auxiliar.txt","Archivos/materia.txt");
	}
	
	struct materia getMateriaById(int miId){
		struct materia materia;
		struct materia miMateria;
		FILE *f;
		f=fopen("Archivos/materia.txt","r");
		if(f==NULL){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		
		int id_materia;
	    char nombre[50];
	    int id_carrera;
	    int id_profesor;
	    int anio_cursada;
	    int promocion;
	    int activo;
	    int cont=0;
	    while(!feof(f)){
	    	fscanf(f,"%i%s%i%i%i%i%i\n",&id_materia,&nombre,&id_carrera,&id_profesor,&anio_cursada,&promocion,&activo);
	    	materia.ConstructorMateria(id_materia,nombre,id_carrera,id_profesor,anio_cursada,promocion,activo);
	    	if(materia.getIdMateria()==miId){
	    		miMateria=materia;
			}
		}
		rewind(f);
	    fclose(f);
	    return miMateria;
	}
	
	bool existeMateria(struct materia materia,int idSeleccionado){
		bool existe=false;
		if(materia.getIdMateria()==idSeleccionado){
			existe=true;
		}
		return existe;
	}
	
	void getAllMateria(){
		struct materia materia;
		FILE *f;
		f=fopen("Archivos/materia.txt","r");
		if(f==NULL){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		
		int id_materia;
	    char nombre[50];
	    int id_carrera;
	    int id_profesor;
	    int anio_cursada;
	    int promocion;
	    int activo;
	    int cont=0;
	    while(!feof(f)){
	    	fscanf(f,"%i%s%i%i%i%i%i\n",&id_materia,&nombre,&id_carrera,&id_profesor,&anio_cursada,&promocion,&activo);
	    	materia.ConstructorMateria(id_materia,nombre,id_carrera,id_profesor,anio_cursada,promocion,activo);
	    	materia.imprimirDatosMateria();
	    	printf("\n");
		}
		rewind(f);
	    fclose(f);
	}
	
	void getAllMateriaReducido(){
		struct materia materia;
		FILE *f;
		f=fopen("Archivos/materia.txt","r");
		if(f==NULL){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		
		int id_materia;
	    char nombre[50];
	    int id_carrera;
	    int id_profesor;
	    int anio_cursada;
	    int promocion;
	    int activo;
	    int cont=0;
	    while(!feof(f)){
	    	fscanf(f,"%i%s%i%i%i%i%i\n",&id_materia,&nombre,&id_carrera,&id_profesor,&anio_cursada,&promocion,&activo);
	    	materia.ConstructorMateria(id_materia,nombre,id_carrera,id_profesor,anio_cursada,promocion,activo);
	    	materia.imprimirDatosMateriaReducido();
	    	printf("\n");
		}
		rewind(f);
	    fclose(f);
	}
};
