//---------------------------------------------------------------------------
#ifndef ClaseFuncionesH
#define ClaseFuncionesH
#include <vcl.h>
#include "ClaseSocio.h"
#include "ClasePago.h"

class ClaseFunciones
{
	private:
	public:
		void __guardarDatos(ClaseSocio);
		void __guardarPago(ClasePago);
		void __modificarDatos(ClaseSocio);
		void __generarCuota(int);
		AnsiString __obtenerfecha(TComboBox *,TComboBox *,TComboBox *);

};

//---------------------------------------------------------------------------
#endif
