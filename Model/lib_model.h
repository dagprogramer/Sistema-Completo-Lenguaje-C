#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "Accion.h"
#include "Alumno.h"
#include "Carrera.h"
#include "Correlativa.h"
#include "Loguin.h"
#include "Materia.h"
#include "Nota.h"
#include "Profesor.h"
#include "TipoExamen.h"
#include "Usuario.h"

struct estructuras{
	//estructuras(1-loguin,2-accion,3-carrera,4-alumno,5-profesor,6-materia,7-correlativa,8-tipoExamen,9-nota)
	private:
	struct loguin loguin;
	struct accion accion;
	struct carrera carrera;
	struct alumno alumno;
	struct profesor profesor;
	struct materia materia;
	struct correlativa correlativa;
	struct tipoExamen tipoExamen;
	struct nota nota;
	
	public:
		
		void setFormularioLoguin(){
			loguin.Loguin();
		}
		
		struct loguin getDatosLoguin(){
			return loguin;
		}
		
		void setFormularioAccion(){
			accion.Accion();
		}
		
		struct accion getDatosAccion(){
		    return accion;
		}
		
		void setFormularioCarrera(){
			carrera.Carrera();
		}
		
		struct carrera getDatosCarrera(){
			return carrera;
		}
		
		void setFormularioAlumno(){
			alumno.Alumno();
		}
		
		struct alumno getDatosAlumno(){
			return alumno;
		}
		
		void setFormularioProfesor(){
			profesor.Profesor();
		}
		
		struct profesor getDatosProfesor(){
			return profesor;
		}
		
		void setFormularioMateria(){
			materia.Materia();
		}
		
		void setMateria(struct materia miMateria){
			this->materia=miMateria;
		}
		
		struct materia getDatosMateria(){
			return materia;
		}
		
		void setFormularioCorrelativa(){
			correlativa.Correlativa();
		}
		
		void setCorrelativa(struct correlativa miCorrelativa){
			this->correlativa=miCorrelativa;
		}
		
		struct correlativa getDatosCorrelativa(){
			return correlativa;
		}
		
		void setFormularioTipoExamen(){
			tipoExamen.TipoExamen();
		}
		
		struct tipoExamen getDatosTipoExamen(){
			return tipoExamen;
		}
		
		void setFormularioNotas(){
			nota.Nota();
		}
		
		void setNota(struct nota miNota){
			this->nota=miNota;
		}
		
		struct nota getDatosNotas(){
			return nota;
		} 
};

