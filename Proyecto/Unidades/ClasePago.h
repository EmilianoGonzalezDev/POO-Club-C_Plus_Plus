//---------------------------------------------------------------------------

#ifndef ClasePagoH
#define ClasePagoH

class ClasePago
{
	private:
		int numpago;
		int numsocio;
		char fechapago[11];
		float monto;
		int cantidadabonadas;
	public:
		void __cargarpago(int,int,int);
		friend class TFormListaDePagos;

};
//---------------------------------------------------------------------------
#endif
