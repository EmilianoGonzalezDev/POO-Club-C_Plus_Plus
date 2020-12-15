//---------------------------------------------------------------------------

#ifndef ClaseSocioH
#define ClaseSocioH
#include "ClasePERSONA.h"
#include<System.Classes.hpp> //Para  poder usar parámetros del tipo AnsiString en las funciones

class ClaseSocio : public PERSONA
		{
		protected:
			char deportes[40];
			char tipodesocio[20];
			char observaciones[30];
			char fecha_de_ingreso[11];
			unsigned int socionumero; // numero de socio
			char eliminado;
			char extension[4];
			int cuotas_adeudadas;

		public:
			void modificarDeuda(int);
			void __cargarDatos(AnsiString,AnsiString,AnsiString,AnsiString,AnsiString,AnsiString,AnsiString,AnsiString,AnsiString,char,unsigned int,unsigned int, char*, char); //agregar socio
			friend class TFormListaDeSocios;
			friend class TFormEditarSocio;
			friend class TFormGenerarCuota;
			friend class TFormPago;
			friend class TFormConfiguraciones;
			friend class TFormNuevoSocio;
			friend class ClaseFunciones;
		};

//---------------------------------------------------------------------------


#endif
