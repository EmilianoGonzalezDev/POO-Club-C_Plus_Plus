//---------------------------------------------------------------------------
#pragma hdrstop

#include <vcl.h>
#include <fstream>
#include "EditarSocio.h"
#include "ListaDeSocios.h"
#include "ClaseSocio.h"
#include "ClaseFunciones.h"
#include <jpeg.hpp> //Para poder asignar imagenes .jpg
#include <time.h> //time_t y time()


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormEditarSocio *FormEditarSocio;

AnsiString rutafotoselecc;
ClaseSocio socioaeditar;
ClaseFunciones func;

//---------------------------------------------------------------------------
__fastcall TFormEditarSocio::TFormEditarSocio(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------
void TFormEditarSocio::GetSocio(ClaseSocio objeto)
{  	s = objeto;
}

//---------------------------------------------------------------------------
void __fastcall TFormEditarSocio::FormShow(TObject *Sender)
{

	if((s.eliminado == false) || (s.eliminado == 'H'))
	{
		btEliminar->Visible = true;
		btReAlta->Visible = false;
	}

	if(s.eliminado == 'B')
	{
		btEliminar->Visible = false;
		btReAlta->Visible = true;
	}

		/*Cargar datos en Formulario: */

	lbNumeroDeSocio->Caption = s.socionumero;
	eNombre->Text = s.nombre;
	cbTipoDeSocio->Text = s.tipodesocio;
	memoDep->Text = s.deportes;
	memoObserv->Text = s.observaciones;
	eEmail->Text = s.mail;
	eDNI->Text = s.dni;
	eApellido->Text = s.apellido;
	eTelefono->Text = s.tel;

	if(s.sexo == 'F') rbFemenino->Checked=true;
	else if(s.sexo == 'M') rbMasculino->Checked=true;
	else {rbFemenino->Checked=false; rbMasculino->Checked=false;}

	//fecha de nacimiento
	if(strlen(s.fechanac) > 9)
		{
			char dia[3]="";  strncat(dia, s.fechanac, 2);
			char mes[3]="";  strncat(mes, strchr(s.fechanac,'/')+1, 2);
			char anio[5]=""; strncat(anio, strrchr(s.fechanac,'/')+1, 4);

			cbDiaNacimiento->Text = dia;
			cbMesNacimiento->Text = mes;
			cbañoNacimiento->Text = anio;

		}
	else
		{ 	cbDiaNacimiento->Text = "";
			cbMesNacimiento->Text = "";
			cbañoNacimiento->Text = "";
		}

	//foto
	if(strlen(s.extension) > 3)
	{
		String rutafoto;
		rutafoto = "fotos\\" + static_cast<String>(s.socionumero) + s.extension;

		FotoSocio->Picture->LoadFromFile(rutafoto);
		lbSinFoto->Visible = false;
		FotoSocio->Visible = true;
	}
	else
	{
			FotoSocio->Visible = false;
			lbSinFoto->Visible = true;
	}

}

//---------------------------------------------------------------------------
void __fastcall TFormEditarSocio::btCargarFotoClick(TObject *Sender)
{
	if(OpenPictureDialog1->Execute())
	{
		rutafotoselecc = OpenPictureDialog1->FileName;
		if(rutafotoselecc.Length() > 6)
			{FotoSocio->Picture->LoadFromFile(rutafotoselecc);
             lbSinFoto->Visible = false;
			 FotoSocio->Visible = true;
			}
	}
}

//---------------------------------------------------------------------------

void __fastcall TFormEditarSocio::btEliminarClick(TObject *Sender)
{
	 if(MessageDlg("El socio será dado de baja. ¿Continuar?", mtConfirmation,
	   TMsgDlgButtons() << mbYes << mbNo , 0)== mrYes)
	  {
		modificarEstado('B');
		ShowMessage("Dado de baja correctamente");
	  }
}
//---------------------------------------------------------------------------



void __fastcall TFormEditarSocio::btReAltaClick(TObject *Sender)
{
	 if(MessageDlg("Se volverá a dar de alta. ¿Continuar?", mtConfirmation,
	   TMsgDlgButtons() << mbYes << mbNo , 0)== mrYes)
	  {
		modificarEstado(false);
		ShowMessage("Dado de alta correctamente");
	  }
}
//---------------------------------------------------------------------------

void TFormEditarSocio::modificarEstado(char nuevoestado)
{
 	ClaseSocio socioleido;
	bool bandera  = false;
	int registro = 0;
	fstream fs;

	fs.open("lista",ios::in|ios::out|ios::binary);
	while(bandera == false)
	{
		fs.read((char*)&socioleido,sizeof(ClaseSocio));
		if (socioleido.socionumero == s.socionumero) // si se encontró al socio
		{
			s.eliminado = nuevoestado;				 //asignarle el nuevo estado
			if(nuevoestado == false)                 //si el nuevo estado era volver a darlo de alta:
			{
				int maxdeuda;
				ifstream ifss("MaxDeuda.txt");
				ifss>>maxdeuda;
				ifss.close();
				if(s.cuotas_adeudadas >= maxdeuda)  //si está igual o por encima del límite de deuda
				{
					s.eliminado = 'D';              //marcarlo como deudor
					s.cuotas_adeudadas = maxdeuda;  //y asignarle la deuda mAxima actual (por si la deuda que tenia era mayor)
				}
				strcpy(s.tipodesocio,"COMUN");
			}
			fs.seekp(registro * sizeof(ClaseSocio),ios::beg);
			fs.write((char*)&s,sizeof(ClaseSocio));
			bandera = true;
		}
		else registro++;
	}
	fs.close();
	FormEditarSocio->Close();
	FormListaDeSocios->Close();
}

void TFormEditarSocio::GetNumFila(int num)
{
	numfila = num;
}

void __fastcall TFormEditarSocio::btListoClick(TObject *Sender)
{
	 if(MessageDlg("Se aplicarán las moficaciones. ¿Continuar?", mtConfirmation,
	   TMsgDlgButtons() << mbYes << mbNo , 0)== mrYes)
	  {
			bool error = false;
			// Si no se completaron los campos obligatorios, informarlo!
			if(eNombre->Text=="" || eApellido->Text=="" || eDNI->Text=="" || cbTipoDeSocio->Text=="")
			{	ShowMessage("- NOMBRE\n- APELLIDO\n- DNI\n- TIPO DE SOCIO\ncampos obligatorios");
				error = true;
			}

			//Fecha de Nacimiento
			AnsiString fechanacim;
			fechanacim = func.__obtenerfecha(cbDiaNacimiento,cbMesNacimiento,cbañoNacimiento);
			if (fechanacim == 1) {error = true;}


			//***Si está todo Ok, proceder***
			if(error == false)
			{

				//Si se seleccionó una foto, Moverla a la carpeta "fotos" del programa (\Win32\Debug\fotos)
				//y nombrarla con el num de socio asignado
				char ext[4] = "";
				if(rutafotoselecc.Length() > 6)
				{
					strcpy(ext,(strchr(rutafotoselecc.c_str(),'.')));//obtener extension
					FotoSocio->Picture->SaveToFile("fotos\\" + (AnsiString)s.socionumero + ext);
				}
				else strcpy(ext, s.extension);


				//Masculino, Femenino o Sin informar
				char Sexo = 'I'; //indefinido
				if (rbMasculino->Checked == true) Sexo = 'M';
				if (rbFemenino->Checked == true) Sexo = 'F';

				//Cargar datos en el objeto -socio- de la clase ClaseSocio
				socioaeditar.__cargarDatos(fechanacim, eNombre->Text, eApellido->Text, eTelefono->Text, eEmail->Text, memoDep->Text,
							cbTipoDeSocio->Text, memoObserv->Lines->Text,s.fecha_de_ingreso, Sexo, eDNI->Text.ToInt(), s.socionumero,
							ext, s.eliminado);

				//Guardar la info del objeto -socio- en el archivo binario
				func.__modificarDatos(socioaeditar);

				//Cerrar
				ShowMessage("Datos actualizados correctamente");
				FormEditarSocio->Close();
				FormListaDeSocios->listar();
		  }
	}

}
//---------------------------------------------------------------------------

