//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GenerarCuota.h"
#include <fstream>
#include "ClaseSocio.h"
#include "ClaseFunciones.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormGenerarCuota *FormGenerarCuota;
ClaseFunciones Func;

//---------------------------------------------------------------------------
__fastcall TFormGenerarCuota::TFormGenerarCuota(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TFormGenerarCuota::btGenerarCuotaClick(TObject *Sender)
{
	if(MessageDlg("ATENCIÓN: Se Aumentará en una unidad la cantidad de cuotas adeudadas por cada socio. ¿Continuar?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo , 0)== mrYes)
	{
		Func.__generarCuota(1);
		ShowMessage("Cuota Generada Correctamente");
	}
}

//---------------------------------------------------------------------------
void __fastcall TFormGenerarCuota::btEliminarCuotaClick(TObject *Sender)
{
	bool Error = 0;
	if(MessageDlg("-ATENCIÓN- Se Reducirá en una unidad la cantidad de cuotas adeudadas por cada socio. ¿Continuar?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo , 0)== mrYes)
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
				if( (aux.cuotas_adeudadas == 0) && (aux.eliminado != 'H') && (aux.eliminado != 'B') )
				{
					Error = 1;
				}
			}
		}
		else ShowMessage("Error al abrir el archivo");
		fs.close();

		if(Error == 0)
		{
			Func.__generarCuota(-1);
			ShowMessage("Cuota Eliminada Correctamente");
		}
		else {ShowMessage("ACCIÓN NO PERMITIDA. (Hay socios con deuda en cuotas = 0). No se eliminó la cuota");}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormGenerarCuota::FormShow(TObject *Sender)
{
	char mesUC[3];
	char anioUC[5];

	ifstream ifsM("MesUltimaCuota.txt"); //Leer Mes de Ultima Cuota Generada
	ifsM>>mesUC ;
	ifsM.close();

	ifstream ifsA("AnioUltimaCuota.txt"); //Leer Anio de Ultima Cuota Generada
	ifsA>>anioUC ;
	ifsA.close();

	lbMesUltimaCuota->Caption = mesUC;
	lbAnioUltimaCuota->Caption = anioUC;
}
//---------------------------------------------------------------------------


