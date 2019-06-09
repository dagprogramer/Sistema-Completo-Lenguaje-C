#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

struct ctrlNota{
	
	int cantidad;
	
	void insertNota(struct nota nota){
		FILE *f;
		f=fopen("Archivos/nota.txt","a");
		if(f==NULL){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		fprintf(f,"%i %i %i %i %s %i %i \n",nota.getId(),nota.getLegajo(),nota.getIdMateria(),
		nota.getValor(),nota.getFecha(),nota.getTipoExamen(),nota.getActivo());
		rewind(f);
		fclose(f);
	}
	
	void updateNota(struct nota miNota){
		struct nota nota;
		struct nota auxiliar;
		bool encontrado=false;
		FILE *f1;
		f1=fopen("Archivos/nota.txt","r");
		
		FILE *f2;
		f2=fopen("Archivos/auxiliar.txt","w");
		if((f1==NULL) && (f2==NULL)){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		int id_nota;
	    int legajo;
	    int id_materia;
	    int valor;
	    char fecha[50];
	    int tipo_exmanen;
	    int activo;
		while(!feof(f1)){
			fscanf(f1,"%i%i%i%i%s%i%i\n",&id_nota,&legajo,&id_materia,&valor,&fecha,&tipo_exmanen,&activo);
			nota.ConstructorNota(id_nota,legajo,id_materia,valor,fecha,tipo_exmanen,activo);
			if(nota.getId()==miNota.getId()){
				auxiliar=miNota;
				nota=auxiliar;
				encontrado=true;
			}
			fprintf(f2,"%i %i %i %i %s %i %i \n",nota.getId(),nota.getLegajo(),nota.getIdMateria(),
		    nota.getValor(),nota.getFecha(),nota.getTipoExamen(),nota.getActivo());
		}
		rewind(f1);
		rewind(f2);
		fclose(f1); 
		fclose(f2);
		remove("Archivos/nota.txt");
		rename("Archivos/auxiliar.txt","Archivos/nota.txt");
	}
	
	struct nota getNotaById(struct alumno alumno,int miId){
		struct nota nota;
		struct nota miNota;
		bool encontrado=false;
		FILE *f;
		f=fopen("Archivos/nota.txt","r");
		if(f==NULL){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		
		int id_nota;
	    int legajo;
	    int id_materia;
	    int valor;
	    char fecha[50];
	    int tipo_exmanen;
	    int activo;
		while(!feof(f)){
			fscanf(f,"%i%i%i%i%s%i%i\n",&id_nota,&legajo,&id_materia,&valor,&fecha,&tipo_exmanen,&activo);
			nota.ConstructorNota(id_nota,legajo,id_materia,valor,fecha,tipo_exmanen,activo);
			if(nota.getLegajo()==alumno.getLegajo()){
				if(nota.getId()==miId){
					miNota=nota;
				}
			}
		}
		rewind(f);
	    fclose(f);
	    return miNota;
	}
	
	bool existeNota(struct nota nota,int idSeleccionado){
		bool existe=false;
		if(nota.getId()==idSeleccionado){
			existe=true;
		}
		return existe;
	}
	
	int getAllNotaByLegajo(struct alumno alumno){
		struct nota nota;
		bool encontrado=false;
		int cant=0;
		FILE *f;
		f=fopen("Archivos/nota.txt","r");
		if(f==NULL){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		
		int id_nota;
	    int legajo;
	    int id_materia;
	    int valor;
	    char fecha[50];
	    int tipo_exmanen;
	    int activo;
		while(!feof(f)){
			fscanf(f,"%i%i%i%i%s%i%i\n",&id_nota,&legajo,&id_materia,&valor,&fecha,&tipo_exmanen,&activo);
			nota.ConstructorNota(id_nota,legajo,id_materia,valor,fecha,tipo_exmanen,activo);
			if(nota.getLegajo()==alumno.getLegajo()){
				nota.imprimirNota();
				printf("\n");
				cant++;
				encontrado=true;
			}
		}
		rewind(f);
	    fclose(f);
	    return cant;
	}
};
