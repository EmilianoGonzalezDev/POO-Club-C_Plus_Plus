//---------------------------------------------------------------------------

#include <vcl.h>
#include <fstream>
#pragma hdrstop

#include "FormContrasenia.h"
#include "Configuraciones.h"
#include "GenerarCuota.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormPass *FormPass;
//---------------------------------------------------------------------------
__fastcall TFormPass::TFormPass(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormPass::FormShow(TObject *Sender)
{
	ePass->Clear();
	ifstream ifP("P//P.txt");
	ifP>>P;
	ifP.close();
}
//---------------------------------------------------------------------------
void __fastcall TFormPass::btAceptarClick(TObject *Sender)
{
	FormPass->Close();
	if(ePass->Text == P)
	{
		switch(mostrarFormX)
		{
			case 1: FormConfiguraciones->ShowModal(); break;
			case 2: FormGenerarCuota->ShowModal(); break;
		}
	}
	else ShowMessage("Contraseña Incorrecta");
}
//---------------------------------------------------------------------------
void __fastcall TFormPass::btCancelarClick(TObject *Sender)
{
	FormPass->Close();
}
//---------------------------------------------------------------------------
