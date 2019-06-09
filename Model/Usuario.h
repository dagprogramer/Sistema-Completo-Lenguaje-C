#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

struct usuario{
	private:
	int id_usuario;
	char usuario[50];
	char contrasenia[50];
	int activo;
	
	public:
		
		void ConstructorUsuario(int miId_usuario,const char miUsuario[50],const char miContrasenia[50],
		int miActivo){
			this->id_usuario=miId_usuario;
			strcpy(usuario,miUsuario);
			strcpy(contrasenia,miContrasenia);
			this->activo=miActivo;
		}
		
		void Usuario(){
			printf("INGRESE ID ");
			scanf("%i",&id_usuario);
			printf("INGRESE USUARIO ");
			scanf("%s",&usuario);
			printf("INGRESE CONTRASENIA ");
			scanf("%s",&contrasenia);
			printf("INGRESE ACTIVO(1-ACTIVO,2-DESACTIVO) ");
			scanf("%i",&activo);
		}
		
		void setId(){
			printf("INGRESE ID ");
			scanf("%i",&id_usuario);
		}
		
		int getId(){
			return id_usuario;
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
		
		void imprimirDatosUsuario(){
			printf("ID_USUARIO: %i \n",id_usuario);
			printf("USUARIO: %s \n",usuario);
			printf("CONTRASENIA: %s \n",contrasenia);
			printf("ACTIVO: %i \n",activo);
		}
		
		void imprimirDatosUsuarioReducido(){
			printf("ID: %i USUARIO: %s \n",id_usuario,usuario);
		}
};
