//---------------------------------------------------------------------------

#pragma hdrstop

#include "ClasePago.h"
#include "ClaseFunciones.h"
#include <fstream>
#include <cstring>
#include "NuevoPago.h"

void ClasePago::__cargarpago(int n_socio, int cantidadcuotas, int montoactual)
{
	ifstream ifs;
	ofstream ofs;
	ClaseFunciones funcion;

	//Numero de Pago
	int n_pago;
	ifs.open("numpago.txt");
	ifs>>n_pago;
	ifs.close();
	remove("numpago.txt");
	ofs.open("numpago.txt");
	ofs<<n_pago+1;
	ofs.close();

	//Fecha de Pago
	char fechaactual[11];
	time_t tiempo;
	struct tm * fechasistema;
	time (&tiempo);
	fechasistema = localtime (&tiempo);
	strftime(fechaactual,11,"%Y-%m-%d",fechasistema);

	//Cargar Datos
	this->numsocio = n_socio;
	this->numpago = n_pago;
	this->cantidadabonadas = cantidadcuotas;
	this->monto = cantidadcuotas * montoactual;
	strcpy(this->fechapago,fechaactual);
}
//---------------------------------------------------------------------------
#pragma package(smart_init)

/*
	int numpago;
	int numsocio;
	char fechapago[11];
	float monto;
*/
