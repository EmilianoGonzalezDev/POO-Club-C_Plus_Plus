//---------------------------------------------------------------------------
#pragma hdrstop

#include <jpeg.hpp> //Para poder asignar imagenes .jpg
#include <fstream>
#include <vcl.h>
#include <time.h> // time_t y time()
#include "ClaseSocio.h"
#include "ClaseFunciones.h"
#include "FormularioNuevoSocio.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormNuevoSocio *FormNuevoSocio;
//---------------------------------------------------------------------------

unsigned int numSocio; // Número a asignar al socio (el número se toma de num.txt)
AnsiString rutafotoseleccionada;
ClaseSocio socio;
ClaseFunciones funcion;

//---------------------------------------------------------------------------
__fastcall TFormNuevoSocio::TFormNuevoSocio(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TFormNuevoSocio::btCancelarClick(TObject *Sender)
{
	if(MessageDlg("Se perderá la información proporcionada. ¿Seguro que desea salir?", mtConfirmation,
	   TMsgDlgButtons() << mbYes << mbNo , 0)== mrYes)

	   {FormNuevoSocio->Close();}
}

//---------------------------------------------------------------------------
void TFormNuevoSocio::__limpiar_campos()
{
	cbDiaNacimiento->ClearSelection();
	cbMesNacimiento->ClearSelection();
	cbañoNacimiento->ClearSelection();
	cbTipoDeSocio->ClearSelection();
	cbDiaAlta->ClearSelection();
	cbDiaAlta->Visible = false;
	cbMesAlta->ClearSelection();
	cbMesAlta->Visible = false;
	cbAñoAlta->ClearSelection();
	cbAñoAlta->Visible = false;
	chbHoy->Checked = true;
	cboxMail->ClearSelection();
	eDNI->Clear();
	eNombre->Clear();
	eApellido->Clear();
	eEmail->Clear();
	eTelefono->Clear();
	rbFemenino->Checked=false;
	rbMasculino->Checked=false;
	rbNo->Checked = true;
	memoObserv->Clear();
	memoObserv->Visible = false;
	FotoSocio->Picture->LoadFromFile("imagenes\\fotopordefecto.jpg");
	rutafotoseleccionada = "";
	for(int i=0; i < clDeportes->Count; i++)
			{	clDeportes->Checked[i] = false;
			}

}

//---------------------------------------------------------------------------
void __fastcall TFormNuevoSocio::btReiniciarFormClick(TObject *Sender)
{
	if(MessageDlg("Se borrarán todos los campos ¿Confirmar Acción?", mtConfirmation,
	   TMsgDlgButtons() << mbYes << mbNo , 0)== mrYes)
	{
		__limpiar_campos();
	}
}

//---------------------------------------------------------------------------
void __fastcall TFormNuevoSocio::btCargarFotoClick(TObject *Sender)
{
	// Buscar una foto y guardar su ruta en -rutafotoseleccionada-
	if(OpenPictureDialog1->Execute()) rutafotoseleccionada = OpenPictureDialog1->FileName;
	else rutafotoseleccionada = "";

	if(rutafotoseleccionada.Length() > 6)
			{
			FotoSocio->Picture->LoadFromFile(rutafotoseleccionada);
			}
}

//---------------------------------------------------------------------------
void __fastcall TFormNuevoSocio::FormShow(TObject *Sender)
{
	//Abrir el arhivo num, copiar el número que contiene dentro y
	//asignarlo al label de Número de Socio
	ifstream ifss("num.txt");
	ifss>>numSocio;
	ifss.close();
	lbNumeroDeSocio->Caption=numSocio;
}

//---------------------------------------------------------------------------
void __fastcall TFormNuevoSocio::rbNoClick(TObject *Sender)
{	memoObserv->Visible = false;
}

//---------------------------------------------------------------------------
void __fastcall TFormNuevoSocio::rbSiClick(TObject *Sender)
{	memoObserv->Visible = true;
}

//---------------------------------------------------------------------------
void __fastcall TFormNuevoSocio::chbHoyClick(TObject *Sender)
{
	if(chbHoy->Checked == true)
	{
		cbDiaAlta->Visible = false;
		cbMesAlta->Visible = false;
		cbAñoAlta->Visible = false;
	}
	if(chbHoy->Checked == false)
	{
		cbDiaAlta->Visible = true;
		cbMesAlta->Visible = true;
		cbAñoAlta->Visible = true;
	}
}

//---------------------------------------------------------------------------
void __fastcall TFormNuevoSocio::btListoClick(TObject *Sender)
{
	bool error = false;
	// Si no se completaron los campos obligatorios, informarlo!
	if(eNombre->Text=="" || eApellido->Text=="" || eDNI->Text=="" || cbTipoDeSocio->Text=="")
	{	ShowMessage("- NOMBRE\n- APELLIDO\n- DNI\n- TIPO DE SOCIO\ncampos obligatorios");
		error = true;
	}

	//Fecha de Nacimiento
	AnsiString fechanacim;
	fechanacim = funcion.__obtenerfecha(cbDiaNacimiento,cbMesNacimiento,cbañoNacimiento);
	if (fechanacim == 1) {error = true;}

	//Crear varible con la fecha actual
	time_t tiempo;
	struct tm * fechasistema;
	time (&tiempo);
	fechasistema = localtime (&tiempo);

	//fecha de Ingreso
	AnsiString fechaingreso;
	if(chbHoy->Checked == true)
	{
		char fechaactual[11];
		strftime(fechaactual,11,"%Y-%m-%d",fechasistema); //strftime convierte la hora a String con el formato indicado entre comillas
		fechaingreso = fechaactual;
	}
	if(chbHoy->Checked == false)
	{
		fechaingreso = funcion.__obtenerfecha(cbDiaAlta,cbMesAlta,cbAñoAlta);
		if (fechaingreso == 1) {error = true;}
	}

	//***Si está todo Ok, proceder***
	if(error == false)
	{
		//Aumentar una unidad el Número de socio guardado en num.txt
		remove("num.txt");
		ofstream ofss("num.txt");
		ofss<<numSocio+1;


		//Si se seleccionó una foto, Moverla a la carpeta "fotos" del programa (\Win32\Debug\fotos)
		//y nombrarla con el num de socio asignado
		char ext[4] = "";
		if(rutafotoseleccionada.Length() > 6)
		{
			strcpy(ext,(strchr(rutafotoseleccionada.c_str(),'.')));//obtener extension
			FotoSocio->Picture->SaveToFile("fotos\\" + (AnsiString)numSocio + ext); //Renombrar y guardar foto
		}

		//Masculino, Femenino o Sin informar
		char S = 'I'; //indefinido
		if (rbMasculino->Checked == true) S = 'M';
		if (rbFemenino->Checked == true) S = 'F';

		//Observaciones
		if (rbNo->Checked == true) memoObserv->Clear();

		//Mail
		AnsiString mail;
		if((eEmail->Text != "") && (cboxMail->Text!= ""))
			mail = eEmail->Text + "@" + cboxMail->Text;

		//Deportes
		AnsiString dep = "";
		for(int i=0; i < clDeportes->Count; i++)
		{
			if(clDeportes->Checked[i])
				{dep = dep + "-" + clDeportes->Items->Strings[i] + " ";
				}
		}

		//Cargar datos en el objeto -socio- de la clase ClaseSocio
		socio.__cargarDatos(fechanacim, eNombre->Text, eApellido->Text, eTelefono->Text, mail, dep,
					cbTipoDeSocio->Text, memoObserv->Lines->Text, fechaingreso, S, eDNI->Text.ToInt(), numSocio,
					ext,false);

		//Guardar la info del objeto -socio- en el archivo binario
		funcion.__guardarDatos(socio);

		//Cerrar
		FormNuevoSocio->Close();
		ShowMessage("Dado de alta correctamente");
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormNuevoSocio::FormClose(TObject *Sender, TCloseAction &Action)
{
	__limpiar_campos();
}

void __fastcall TFormNuevoSocio::eDNIExit(TObject *Sender)
{
	unsigned int DniIngresado;
	if (eDNI->Text != "")
	{
		DniIngresado = eDNI->Text.ToInt();
		ifstream ifst;
		int registros;
		bool bandera;
		ClaseSocio aux;
		ifst.open("lista",ios::in|ios::ate|ios::binary);
		registros = ifst.tellg()/sizeof(ClaseSocio);
		ifst.seekg(0,ios::beg);
		for(int i=0; i<registros; i++)
			{
				ifst.read((char*)&aux,sizeof(ClaseSocio));
				if(aux.dni == DniIngresado)
				{
					ShowMessage("Ya existe un socio registrado con ese DNI. El Número de socio es:");
					ShowMessage(aux.socionumero);
					bandera = 1;
					i = registros;
				}
			}
		if (bandera == 1) btListo->Enabled = false;
		else btListo->Enabled = true;
		ifst.close();
	}

}
//---------------------------------------------------------------------------

