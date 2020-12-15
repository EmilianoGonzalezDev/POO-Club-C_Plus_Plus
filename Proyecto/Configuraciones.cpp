//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Configuraciones.h"
#include "ModifConfig.h"
#include "ClaseSocio.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormConfiguraciones *FormConfiguraciones;

//---------------------------------------------------------------------------
__fastcall TFormConfiguraciones::TFormConfiguraciones(TComponent* Owner)
	: TForm(Owner)
{


}
//---------------------------------------------------------------------------
void __fastcall TFormConfiguraciones::FormShow(TObject *Sender)
{
	lboxMontoCuota->Items->LoadFromFile("MontoCuota.txt");
	lboxMaxDeuda->Items->LoadFromFile("MaxDeuda.txt");
	lboxDiaCuota->Items->LoadFromFile("DiaCuota.txt");
}

//---------------------------------------------------------------------------
void __fastcall TFormConfiguraciones::btEditarMontoClick(TObject *Sender)
{
  band = 1;
  FormModifConfig->lbValor->Caption = lboxMontoCuota->Items->operator [](0);
  FormModifConfig->bandera = 1;
  FormModifConfig->ShowModal();
}

//---------------------------------------------------------------------------

void __fastcall TFormConfiguraciones::btEditarMaxDeudaClick(TObject *Sender)
{
	band = 2;
	FormModifConfig->lbValor->Caption = lboxMaxDeuda->Items->operator [](0);
	FormModifConfig->bandera = 2;
	FormModifConfig->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormConfiguraciones::btEditarDiaCuotaClick(TObject *Sender)
{
	band = 3;
	FormModifConfig->lbValor->Caption = lboxDiaCuota->Items->operator [](0);
	FormModifConfig->bandera = 3;
	FormModifConfig->ShowModal();

}

//---------------------------------------------------------------------------

void __fastcall TFormConfiguraciones::btEditarPassClick(TObject *Sender)
{
  int pass;
  ifstream ifP("P//P.txt");
  ifP>>pass;
  ifP.close();
  band = 4;
  FormModifConfig->lbValor->Caption = "(oculto)";
  FormModifConfig->bandera = 4;
  FormModifConfig->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormConfiguraciones::btListoClick(TObject *Sender)
{
	switch(band)
	{
		case 1:
			FormConfiguraciones->lboxMontoCuota->Items->SaveToFile("MontoCuota.txt");
			break;
		case 3:
			FormConfiguraciones->lboxDiaCuota->Items->SaveToFile("DiaCuota.txt");
			break;
		case 2:
			//Leer la máxima deuda permitida anterior
			int maxAnterior;
			ifstream ifss("MaxDeuda.txt");
			ifss>>maxAnterior;
			ifss.close();

			//Leer el nuevo máximo configurado
			int maxNuevo = lboxMaxDeuda->Items->operator [](0).ToInt();
			FormConfiguraciones->lboxMaxDeuda->Items->SaveToFile("MaxDeuda.txt");

			//Verificar cada socio y modificar su estado si es necesario
			int Nregistros;
			ClaseSocio aux;
			fstream fs;
			fs.open("lista",ios::in|ios::out|ios::ate|ios::binary);
			Nregistros = fs.tellg()/sizeof(ClaseSocio);
			fs.seekg(0,ios::beg);

			for(int i=0; i<Nregistros; i++)
			{
				fs.seekg(i * sizeof(ClaseSocio),ios::beg);
				fs.read((char*)&aux,sizeof(ClaseSocio));
				if (aux.eliminado != 'B')
				{
					if((maxNuevo > maxAnterior) && (aux.eliminado == 'D') && (aux.cuotas_adeudadas < maxNuevo))
					{
						   aux.eliminado = false; //si quedó por debajo del límite, volverlo a dar de alta
					}
					if((maxNuevo < maxAnterior) && (aux.eliminado != 'D') && (aux.cuotas_adeudadas >= maxNuevo))
					{
						   aux.eliminado = 'D'; //si quedó igual o sobre el límite, darlo de baja y marcarlo como deudor
					}
					fs.seekp(i * sizeof(ClaseSocio),ios::beg);
					fs.write((char*)&aux,sizeof(ClaseSocio));
				}
			}
			fs.close();
			break;
	}
}



