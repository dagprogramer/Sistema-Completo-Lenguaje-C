#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>

 struct loguin{
	private:
	char usuario[50];
	char contrasenia[50];
	
	public:
		
		void ConstructorLoguin(const char miUsuario[50],const char miContrasenia[50]){
			strcpy(usuario,miUsuario);
			strcpy(contrasenia,miContrasenia);
		}
		
		void Loguin(){
			printf("INGRESE USUARIO ");
			scanf("%s",&usuario);
			printf("INGRESE CONTRASENIA ");
			scanf("%s",&contrasenia);
		}
		
		void setUsuario(){
			printf("INGRESE USUARIO ");
			scanf("%s",&usuario);
		}
		
		char* getUsuario(){
			return usuario;
		}
		
		void setContrasenia(){
			printf("INGRESE CONTRASENIA ");
			scanf("%s",&contrasenia);
		}
		
		char* getContrasenia(){
			return contrasenia;
		}
		
		void imprimirDatosLoguin(){
			printf("USUARIO: %s \n",usuario);
			printf("CONTRASENIA: %s \n",contrasenia);
		}
	
	    void imprimirDatosLoguinReducido(){
	    	printf("USUARIO: %s CONTRASENIA: %s \n",usuario,contrasenia);
		}
};

