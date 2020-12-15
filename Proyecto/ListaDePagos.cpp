//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <fstream>
#include "ListaDePagos.h"
#include "ClasePago.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormListaDePagos *FormListaDePagos;
//---------------------------------------------------------------------------
__fastcall TFormListaDePagos::TFormListaDePagos(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormListaDePagos::FormShow(TObject *Sender)
{
	int cantidadregistros;
		ifstream ifs;

		//Escribir Indices en primer fila
		grillaPagos->Cells[0][0]="Pago N°";
		grillaPagos->Cells[1][0]="Socio N°";
		grillaPagos->Cells[2][0]="Fecha de Pago";
		grillaPagos->Cells[3][0]="Monto Abonado";
		grillaPagos->Cells[4][0]="Cuotas Abonadas";

		//Abrir archivo y agregar a la grilla una fila (vacia) por cada registro
		ifs.open("lista_pagos",ios::in|ios::ate|ios::binary);
		cantidadregistros = ifs.tellg()/sizeof(ClasePago);
		grillaPagos->RowCount = cantidadregistros+1;

		//Leer los datos del archivo y cargarlos en la grilla
		ClasePago aux;
		ifs.seekg(0,ios::beg);
		for(int fila=1; fila<=cantidadregistros; fila++)
		{
			ifs.read((char*)&aux,sizeof(ClasePago));
			grillaPagos->Cells[0][fila] = aux.numpago;
			grillaPagos->Cells[1][fila] = aux.numsocio;
			grillaPagos->Cells[2][fila] = aux.fechapago;
			grillaPagos->Cells[3][fila] = aux.monto;
			grillaPagos->Cells[4][fila] = aux.cantidadabonadas;
			//v.push_back( make_pair(aux.socionumero, aux) );
		}
		ifs.close();
}
//---------------------------------------------------------------------------
