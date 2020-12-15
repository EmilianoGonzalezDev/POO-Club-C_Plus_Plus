//---------------------------------------------------------------------------


#pragma hdrstop

#include <vcl.h>
#include <fstream>
#include "NuevoPago.h"
#include "ClasePago.h"
#include "ClaseFunciones.h"
#include "ClaseSocio.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormPago *FormPago;

//---------------------------------------------------------------------------
__fastcall TFormPago::TFormPago(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TFormPago::FormShow(TObject *Sender)
{
	//Abrir el arhivo MontoCuota, copiar el número que contiene dentro y
	//asignarlo al label lbMontoCuota
	ifstream IFS("MontoCuota.txt");
	IFS>>montocuota;
	IFS.close();

    ifstream ifss("MaxDeuda.txt");
	ifss>>maxdeuda;
	ifss.close();

	lbMontoActual->Caption=montocuota;
	lbAbonar->Caption = montocuota;

	eCuotas->Text = '1';
}

//---------------------------------------------------------------------------
void __fastcall TFormPago::eCuotasChange(TObject *Sender)
{
	if(eCuotas->Text != "")
	lbAbonar->Caption = eCuotas->Text.ToInt() * montocuota;
	else lbAbonar->Caption = 0;
}

//---------------------------------------------------------------------------
void __fastcall TFormPago::btListoClick(TObject *Sender)
{
	if( (eNumSocio->Text == "") || (eCuotas->Text == "") )
	{
		MessageDlg("Debe completar ambos campos",  mtInformation, TMsgDlgButtons() << mbOK, 0);
	}
	else
	{
		int Nregistros; //Cantidad de socios en la lista de socios
		int bandera = 1; // 0=todo ok;	 1=Socio Inexistente;	 2=A pagar es mayor que deuda;	3=Socio Deudor debe pagar maxdeuda
		unsigned int numsocio = eNumSocio->Text.ToInt();
		int cuotasapagar =  eCuotas->Text.ToInt();
		fstream fs;
		fs.open("lista",ios::in|ios::out|ios::ate|ios::binary);
		Nregistros = fs.tellg()/sizeof(ClaseSocio);
		ClaseSocio aux;
		fs.seekg(0,ios::beg);

		for(int i=0; i<Nregistros; i++) //recorre la lista buscando al socio
		{
			fs.seekg(i * sizeof(ClaseSocio),ios::beg);
			fs.read((char*)&aux,sizeof(ClaseSocio));

			if (aux.socionumero == numsocio) // si lo encuentra, entra
			{
				if(cuotasapagar > aux.cuotas_adeudadas) //*impide pagar mas que la deuda
				{
					bandera = 2;
					i = Nregistros; // <- para salir del bucle
				}
				else if((aux.eliminado == 'D') && (cuotasapagar != maxdeuda))
				{
					bandera = 3;
					i = Nregistros;
                }
				else //si la cantidad de cuotas es correcta genera y guarda el pago
				{
					ClaseFunciones funcion;
					ClasePago pago;
					pago.__cargarpago(numsocio, cuotasapagar, this->montocuota);
					funcion.__guardarPago(pago);

					aux.modificarDeuda(-cuotasapagar); // disminuye la cantidad de cuotas adeudadas
					fs.seekp(i * sizeof(ClaseSocio),ios::beg);
					fs.write((char*)&aux,sizeof(ClaseSocio));
					bandera = 0;
					i = Nregistros; // <- para salir del bucle

				}
			}
			else
			{
				fs.seekp(i * sizeof(ClaseSocio),ios::beg); // si no encontró al socio, lo busca en la siguiente línea
			}
		}

	if (bandera == 0) {ShowMessage("Pago ingresado correctamente"); FormPago->Close(); }
	if (bandera == 1){MessageDlg("N° de socio Inexistente",  mtInformation, TMsgDlgButtons() << mbOK, 0);}
	if (bandera == 2){MessageDlg("Cuotas a pagar es mayor que Cuotas adeudadas",  mtInformation, TMsgDlgButtons() << mbOK, 0);}
	if (bandera == 3){MessageDlg("Socio Deudor. Para Re-Alta debe abonar en cuotas: ",  mtInformation, TMsgDlgButtons() << mbOK, 0); ShowMessage(maxdeuda);}

	fs.close();
	}
}

//---------------------------------------------------------------------------

void __fastcall TFormPago::FormClose(TObject *Sender, TCloseAction &Action)
{
	eNumSocio->Clear();
	//eCuotas->Clear();
}
//---------------------------------------------------------------------------


