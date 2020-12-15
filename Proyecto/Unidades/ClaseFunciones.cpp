//---------------------------------------------------------------------------
#pragma hdrstop

#include <fstream>
#include "ClaseFunciones.h"



//---------------------------------------------------------------------------
void ClaseFunciones::__guardarDatos(ClaseSocio S)
{
	ofstream ofs;
	ofs.open("lista",ios::out|ios::app|ios::binary);
	if (ofs.is_open())
	{
		ofs.write((char*)&S,sizeof(ClaseSocio));
	}
	else ShowMessage("Error al abrir el archivo");
	ofs.close();
}

void ClaseFunciones::__modificarDatos(ClaseSocio SocioEditado)
{
	fstream fs;
	fs.open("lista",ios::in|ios::out|ios::ate|ios::binary);
	if (fs.is_open())
	{
		int cantidadregistros;
		cantidadregistros = fs.tellg()/sizeof(ClaseSocio);
		ClaseSocio aux;
		fs.seekg(0,ios::beg);
		for(int fila=1; fila<=cantidadregistros; fila++)
		{
			fs.read((char*)&aux,sizeof(ClaseSocio));
			if(aux.socionumero == SocioEditado.socionumero)
			{
				fs.seekp(fs.tellg() - sizeof(ClaseSocio) , ios::beg);
				fs.write((char*)&SocioEditado,sizeof(ClaseSocio));
			}

		}
	}
	else ShowMessage("Error al abrir el archivo");
	fs.close();
}

//---------------------------------------------------------------------------
void ClaseFunciones::__guardarPago(ClasePago P)
{
	ofstream ofs;
	ofs.open("lista_pagos",ios::out|ios::app|ios::binary);
	if (ofs.is_open())
	{
		ofs.write((char*)&P,sizeof(ClasePago));
	}
	else ShowMessage("Error al abrir el archivo");
	ofs.close();
}

//---------------------------------------------------------------------------
void ClaseFunciones::__generarCuota(int n) //Modifica en n la cantidad de cuotas adeudadas
{

	int Nregistros; //número de registros (Cantidad de 'socios' en el archivo binario)
	ClaseSocio aux;

	fstream fs;
	fs.open("lista",ios::in|ios::out|ios::ate|ios::binary);
	Nregistros = fs.tellg()/sizeof(ClaseSocio);

	fs.seekg(0,ios::beg);

	for(int i=0; i<Nregistros; i++)
	{
		fs.seekg(i * sizeof(ClaseSocio),ios::beg);
		fs.read((char*)&aux,sizeof(ClaseSocio));
		if ((aux.eliminado == false) || (aux.eliminado == 'D'))// Entra sólo si es socio Activo o Deudor
		{
			aux.modificarDeuda(n);
			fs.seekp(i * sizeof(ClaseSocio),ios::beg);
			fs.write((char*)&aux,sizeof(ClaseSocio));
		}
	}
	fs.close();
}
//---------------------------------------------------------------------------
AnsiString ClaseFunciones::__obtenerfecha(TComboBox *dia, TComboBox *mes, TComboBox *anio)
{
  AnsiString fecha;
  if(dia->Text != "" || mes->Text != "" || anio->Text != "") //Comprobar que si ingresa fecha, sea completa
  {
	fecha = dia->Text + "/"+ mes->Text + "/" + anio->Text;
	if (fecha.Length() < 10) //si está incompleta, informar
	{
		ShowMessage("Fecha Incompleta");
		fecha = 1;
	}
	else
	{
		//COMPROBAR FECHA
		int D = dia->Text.ToInt();
		int M = mes->Text.ToInt();
		int A = anio->Text.ToInt();
		bool bisiesto = false;

		if(A%4==0 && A%100!=100 || A%400==0) bisiesto = true; //Anio es bisiesto?

		if(D>0 && D<32 && M>0 && M<13 && A>1929)
		{
			if(M==2 && ((D>29 && bisiesto) || (D>28 && !bisiesto))) {fecha = 1; ShowMessage("Fecha Incorrecta");}
			if((M==4 || M==6 || M==9 || M==11) && D>30) {fecha = 1; ShowMessage("Fecha Incorrecta");}
		}
	}
  }
  return fecha;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
