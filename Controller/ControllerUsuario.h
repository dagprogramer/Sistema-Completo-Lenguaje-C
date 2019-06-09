#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

struct ctrlUsuario{
	
	int cantidad;
	
	void insertUsuario(struct usuario usuario){
		FILE *f;
		f=fopen("Archivos/usuario.txt","a");
		if(f==NULL){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		fprintf(f,"%i %s %s %i \n",usuario.getId(),usuario.getUsuario(),usuario.getContrasenia(),usuario.getActivo());
		rewind(f);
		fclose(f);
	}
	
	void updateUsuario(struct usuario* misUsuarios){
		FILE *f;
		f=fopen("Archivos/usuario.txt","w");
		if(f==NULL){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		for(int i=0;i<cantidad;i++){
			fprintf(f,"%i %s %s %i \n",misUsuarios[i].getId(),misUsuarios[i].getUsuario(),
			misUsuarios[i].getContrasenia(),misUsuarios[i].getActivo());
		}
		rewind(f);
		fclose(f);
	}
	
	struct usuario* getAllUsuario(){
		struct usuario miUsuario;
		static struct usuario misUsuarios[100];
		FILE *f;
		f=fopen("Archivos/usuario.txt","r");
		if(f==NULL){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		
		int id_usuario;
	    char usuario[50];
	    char contrasenia[50];
	    int activo;
	    int cont=0;
		while(!feof(f)){
			fscanf(f,"%i%s%s%i\n",&id_usuario,&usuario,&contrasenia,&activo);
			miUsuario.ConstructorUsuario(id_usuario,usuario,contrasenia,activo);
			misUsuarios[cont]=miUsuario;
			cont++;
		}
		rewind(f);
	    fclose(f);
	    cantidad=cont;
	    return misUsuarios;
	}
	
	void imprimirUsuarios(struct usuario* misUsuarios){
		for(int i=0;i<cantidad;i++){
			printf("USUARIO: %i\n",i+1);
			misUsuarios[i].imprimirDatosUsuario();
			printf("\n");
		}
	}
};
