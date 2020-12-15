//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ModifConfig.h"
#include "Configuraciones.h"
#include <fstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormModifConfig *FormModifConfig;

//---------------------------------------------------------------------------
__fastcall TFormModifConfig::TFormModifConfig(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TFormModifConfig::FormClose(TObject *Sender, TCloseAction &Action)

{
	eNuevoValor->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TFormModifConfig::btListoClick(TObject *Sender)
{
	if(eNuevoValor->Text != "")
	{
		switch(bandera)
		{
		case 1:
			FormConfiguraciones->lboxMontoCuota->Items->Text = eNuevoValor->Text;break;
		case 2:
			if(eNuevoValor->Text.ToInt() > 0)
			{
				FormConfiguraciones->lboxMaxDeuda->Items->Text = eNuevoValor->Text;
			}
			else ShowMessage("El valor no puede ser 0");
			break;
		case 3:
			if((eNuevoValor->Text.ToInt() > 0) && (eNuevoValor->Text.ToInt() < 21))
			{
				AnsiString valor;
				if(eNuevoValor->Text.ToInt() < 10) valor = "0" + eNuevoValor->Text;
				else valor = eNuevoValor->Text;
				FormConfiguraciones->lboxDiaCuota->Items->Text = valor;
			}
			else ShowMessage("Debe ingresar un número de día del 1 al 20");
			break;
		case 4:
			int nuevopass;
			nuevopass = eNuevoValor->Text.ToInt();
			remove("P//P.txt");
			ofstream ofP("P//P.txt");
			ofP<<nuevopass;
			ofP.close();
			ShowMessage("Se ha modificado la contraseña correctamente");
			break;
		}
	}
	else ShowMessage("Ningún valor ingresado. No se realizaron modificaciones");

}
//---------------------------------------------------------------------------

void __fastcall TFormModifConfig::FormShow(TObject *Sender)
{
	if(bandera == 4) eNuevoValor->PasswordChar = '*';
	else eNuevoValor->PasswordChar = false;
}
//---------------------------------------------------------------------------

