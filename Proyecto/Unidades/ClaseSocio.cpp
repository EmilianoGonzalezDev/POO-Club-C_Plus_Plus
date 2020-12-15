//---------------------------------------------------------------------------

#pragma hdrstop
#include "ClaseSocio.h"

#include <string.h>
#include <System.Classes.hpp>
#include <vcl.h>
#include <fstream>

using namespace std;

void ClaseSocio::__cargarDatos(AnsiString fNac,AnsiString nom,AnsiString ape,AnsiString t,AnsiString ml,AnsiString dep,
								AnsiString tipo,AnsiString obs,AnsiString fechaingreso,char s,unsigned int doc,
								unsigned int numsocio, char* extens, char estado)
{
			strcpy(this->fechanac,fNac.c_str());
			strcpy(this->nombre,nom.c_str());
			strcpy(this->apellido,ape.c_str());
			strcpy(this->tel,t.c_str());
			strcpy(this->mail,ml.c_str());
			strcpy(this->deportes,dep.c_str());
			strcpy(this->tipodesocio,tipo.c_str());
			strcpy(this->observaciones,obs.c_str());
			strcpy(this->fecha_de_ingreso, fechaingreso.c_str());
			this->sexo = s;
			this->dni = doc;
			this->socionumero = numsocio;
			strcpy(this->extension, extens);
			this->cuotas_adeudadas = 0;


			if(estado != 'B')
			{
			 if(tipo == "HONORARIO")
				{
					strcpy(this->tipodesocio, "HONORARIO");
					this->eliminado = 'H';
				}
			 else
				{
					strcpy(this->tipodesocio, "COMUN");
					this->eliminado = false;
				}
			 }

			 else
			 {
              	if(tipo == "HONORARIO")
				{
					strcpy(this->tipodesocio, "HONORARIO");
					this->eliminado = 'B';
				}
				else
				{
					strcpy(this->tipodesocio, "COMUN");
					this->eliminado = 'B';
				}
			 }
}


//---------------------------------------------------------------------------
//aumenta o disminuye la cantidad de cuotas adeudadas y lo marca/desmarca como Deudor
//
void ClaseSocio::modificarDeuda(int n)
{
	int maxdeuda;
    ifstream ifss("MaxDeuda.txt");
	ifss>>maxdeuda;
	ifss.close();
	int nuevaDeuda = this->cuotas_adeudadas + n;

	if((n>0) && (this->eliminado == false) && (nuevaDeuda >= maxdeuda))
	{
		this->eliminado = 'D';
	}

	if((n<0) && (this->eliminado == 'D') && (nuevaDeuda<maxdeuda))
	{
		this->eliminado = false;
	}

	this->cuotas_adeudadas += n;
}

//---------------------------------------------------------------------------
#pragma package(smart_init)
