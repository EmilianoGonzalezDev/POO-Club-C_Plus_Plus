//---------------------------------------------------------------------------
#pragma hdrstop


#include <vcl.h>
#include <time.h> // time_t y time()
#include <fstream>

#include "PRINCIPAL.h"
#include "FormularioNuevoSocio.h"
#include "ListaDeSocios.h"
#include "NuevoPago.h"
#include "ListaDePagos.h"
#include "GenerarCuota.h"
#include "ClaseFunciones.h"
#include "FormContrasenia.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

	char diaCuota[3]; //dia que se debe generar la cuota
	char mesUltimaCuota[3]; //strcpy(mesUltimaCuota,"");
	char anioUltimaCuota[5]; //strcpy(anioUltimaCuota,"");
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btAgregarSocioClick(TObject *Sender)
{
	FormNuevoSocio->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btVerListadoSociosClick(TObject *Sender)
{
	FormListaDeSocios->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btAdministracionClick(TObject *Sender)
{
	FormPass->Show();
	FormPass->mostrarFormX = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btNuevoPagoClick(TObject *Sender)
{
	FormPago->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btListadoPagosClick(TObject *Sender)
{
	FormListaDePagos->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::btGenerarCuotaClick(TObject *Sender)
{
    FormPass->Show();
	FormPass->mostrarFormX = 2;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormShow(TObject *Sender)
{
	char diaActual[3];
	char mesActual[3];
	char anioActual[5];
	ifstream ifs;
	ofstream ofs;
	AnsiString leido;

	ClaseFunciones Funcion;
	int cuotas_a_generar;
	bool error = 0;
	bool generarcuota = 0;

	time_t tiempo;
	struct tm * fechasistema;
	time (&tiempo);
	fechasistema = localtime (&tiempo); //Obtener fecha actual (La que indica la PC)

	strftime(diaActual,3,"%d",fechasistema); //Obtener Número de Día, del Mes Actual
	strftime(mesActual,3,"%m",fechasistema); //Obtener Mes Actual
	strftime(anioActual,5,"%Y",fechasistema); //Obtener Año Actual

	ifstream ifsCuota("DiaCuota.txt"); //Leer que dia se debe generar la cuota
	ifsCuota>>diaCuota;
	ifsCuota.close();

	ifs.open("MesUltimaCuota.txt"); //Leer Mes de Ultima Cuota Generada
	ifs>>mesUltimaCuota;
	ifs.close();
	leido = mesUltimaCuota;
	if (leido == ""){ofs.open("MesUltimaCuota.txt"); ofs<<mesActual; strcpy(mesUltimaCuota,mesActual);ofs.close();}

	ifs.open("AnioUltimaCuota.txt"); //Leer Anio de Ultima Cuota Generada
	ifs>>anioUltimaCuota;
	ifs.close();
	leido = anioUltimaCuota;
	if (leido == ""){ofs.open("AnioUltimaCuota.txt"); ofs<<anioActual; strcpy(anioUltimaCuota,anioActual);ofs.close();}

	int difAnios = strcmp(anioActual,anioUltimaCuota);
	int difMeses = strcmp(mesActual,mesUltimaCuota);
	int difDias  = strcmp(diaActual,diaCuota);

	AnsiString MES = mesActual;
	AnsiString ANIO = anioActual;
	AnsiString MENSAJE = "Se generará 1 cuota correspondiente al mes " + MES + " del " + ANIO + ". ¿Continuar?";


	if((difAnios>1) || (difAnios<0) || (difMeses>1) || ((difMeses<-1) && (MES != "01")) || ((difMeses<0) && ((int)difAnios == 0)) ) {error = 1;}
	else
	{
		if(difAnios == 0) //Si el año actual es el mismo que el de última cuota generada
		{
			if(difMeses == 1) //y el mes actual es 1 unidad mayor
			{
				if(difDias >= 0) //y estamos en fecha de generación de cuota
				{
					cuotas_a_generar = 1;			//Generar 1 Cuota
				}
			}
		}
		else
		{
			if(difAnios == 1) 	//Si el año actual es 1 unidad mayor que el de última cuota generada
			{
				if(MES == "01")	//y es Enero
				{
					if(difDias >= 0) 	//y estamos en fecha de generación de cuota
					{
						cuotas_a_generar = 1;	//Generar 1 Cuota
					}
				}
			}
		}
	}


	//Generar y Guardar info de Cuota
	if(cuotas_a_generar == 1)
	{
		if(atoi(diaActual)>20) generarcuota = 1; //Si ya es mas de 20 y no se ha generado la cuota, generarla sin preguntar
		else {if(MessageDlg(MENSAJE, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo , 0)== mrYes) {generarcuota = 1;}} //sino, dar aviso y consultar

		if(generarcuota == 1)
		  {
			Funcion.__generarCuota(1);
			ShowMessage("Se ha generado la cuota correspondiente a " + MES + "/" + ANIO);

			remove("MesUltimaCuota.txt");
			ofstream archivoCuota("MesUltimaCuota.txt");
			archivoCuota<<mesActual;
			archivoCuota.close();

			remove("anioUltimaCuota.txt");
			ofstream archivoAnio("anioUltimaCuota.txt");
			archivoAnio<<anioActual;
			archivoAnio.close();
		  }
	}

	if(error == 1)
	{
		ShowMessage("ATENCIÓN: La fecha del sistema es incorrecta, por favor corrija la fecha");
		btAgregarSocio->Enabled = false;
		btVerListadoSocios->Enabled = false;
		btAdministracion->Enabled = false;
		btNuevoPago->Enabled = false;
		btListadoPagos->Enabled = false;
		btGenerarCuota->Enabled = false;
	}


}
//---------------------------------------------------------------------------

