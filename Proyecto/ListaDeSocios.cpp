//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <fstream>

#include "ListaDeSocios.h"
#include "EditarSocio.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TFormListaDeSocios *FormListaDeSocios;
int auxfila = 0;
int columna, fila;
int bandera = 0;
vector< pair<int, ClaseSocio> >::iterator it;
int cantidadregistros;
int tupla; //indica en que fila cargar los datos

//.---------------------------------------------------------------------------
__fastcall TFormListaDeSocios::TFormListaDeSocios(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------
 void TFormListaDeSocios::listar()
 {
	ifstream ifs;
	int activos = 0, dadosDeBaja = 0, honorarios = 0, deudores = 0; //Contadores de Tipos de Socios
	tupla = 1;
	bool b = cbBaja->Checked;

	//Limpiar Buscador
	eBuscar->Clear();

	//Abrir archivo y contar cantidad de registros
	ifs.open("lista",ios::in|ios::ate|ios::binary);
	cantidadregistros = ifs.tellg()/sizeof(ClaseSocio);
			//grillaSocios->RowCount = cantidadregistros+1;

	//Leer los datos del archivo, cargarlos en la grilla y guardarlos en el vector
	v.reserve(cantidadregistros);
	ClaseSocio aux;
	ifs.seekg(0,ios::beg);
	for(int fila=1; fila<=cantidadregistros; fila++)
	{
		ifs.read((char*)&aux,sizeof(ClaseSocio));
		if(b==false)
		{
			if(aux.eliminado != 'B')
			{
				grillaSocios->Cells[0][tupla] = aux.socionumero;
				grillaSocios->Cells[1][tupla] = aux.dni;
				grillaSocios->Cells[2][tupla] = aux.apellido;
				grillaSocios->Cells[3][tupla] = aux.nombre;
				grillaSocios->Cells[4][tupla] = aux.eliminado;
				grillaSocios->Cells[5][tupla] = aux.cuotas_adeudadas;
				tupla++;
			}
		}
		else
		{
			grillaSocios->Cells[0][fila] = aux.socionumero;
			grillaSocios->Cells[1][fila] = aux.dni;
			grillaSocios->Cells[2][fila] = aux.apellido;
			grillaSocios->Cells[3][fila] = aux.nombre;
			grillaSocios->Cells[4][fila] = aux.eliminado;
			grillaSocios->Cells[5][fila] = aux.cuotas_adeudadas;
		}

		switch(aux.eliminado)
		{
			case 'B': dadosDeBaja++; break;
			case 'H': honorarios++; break;
			case 'D': deudores++; break;
			default: activos++;
		}

		v.push_back( make_pair(aux.socionumero, aux) );
	}
	ifs.close();

   if(b == false) grillaSocios->RowCount = tupla;
   else grillaSocios->RowCount = cantidadregistros+1;

	lActivos->Caption = activos;
	lDeBaja->Caption = dadosDeBaja;
	lHonorarios->Caption = honorarios;
	lDeudores->Caption = deudores;

 }

//---------------------------------------------------------------------------
void __fastcall TFormListaDeSocios::FormShow(TObject *Sender)
{
	//Escribir Indices en primer fila
	grillaSocios->Cells[0][0]="Socio Número";
	grillaSocios->Cells[1][0]="DNI";
	grillaSocios->Cells[2][0]="Apellido";
	grillaSocios->Cells[3][0]="Nombre";
	grillaSocios->Cells[4][0]="Estado";
	grillaSocios->Cells[5][0]="Cuotas Adeudadas";
	grillaSocios->Cells[6][0]="+ INFO";

	listar();
}

//---------------------------------------------------------------------------
// Al pasar el mouse por la columna 6, muestra un Panel
// con la información completa
//
void __fastcall TFormListaDeSocios::grillaSociosMouseMove(TObject *Sender,
		TShiftState Shift, int X, int Y) // guarda en X e Y las coordenadas actuales del mouse
{
	 grillaSocios->MouseToCell(X, Y, columna, fila); //Convierte las coordenadas del mouse a numero de fila y de columna
	 if((columna==6) && (fila!=0))
	 {
		if (auxfila != fila) //Entrar sólo si se cambió de fila
		{
			ClaseSocio aux;
            for( it = v.begin(); it != v.end(); it++ )
				{
					if(it->first == grillaSocios->Cells[0][fila])
					{
						aux = it->second;
					}
				}

			//Preparar Panel
			auxfila = fila;
			lbSinFoto->Visible = true;
			Foto->Visible = false;
			infoPanel->Visible = true;
			infoPanel->Top = Y-40; //Ubica el panel a la altura de la fila
			memoDeportes->Visible = false;
			memoObserv->Visible = false;
			memoDeportes->Clear();
			memoObserv->Clear();

			//Cargar info en pannel
			lbNom->Caption = aux.nombre;
			lbApe->Caption = aux.apellido;
			lbDni->Caption = aux.dni;
			lbNac->Caption = aux.fechanac;
			lbSexo->Caption = aux.sexo;
			lbMail->Caption = aux.mail;
			lbTipo->Caption = aux.tipodesocio;
			lbFAlta->Caption = aux.fecha_de_ingreso;
			lbCel->Caption = aux.tel;
			lbNumSoc->Caption = aux.socionumero;
			if(strlen(aux.deportes) > 1)
			{
				memoDeportes->Visible = true;
				memoDeportes->Lines->Add(aux.deportes);
			}
			if(strlen(aux.observaciones) > 1)
			{
				memoObserv->Visible = true;
				memoObserv->Text = aux.observaciones;
			}


			//cargar foto en Panel
			if(strlen(aux.extension) > 3) //Si posee una foto, entra al if y se carga la misma
			{
				lbSinFoto->Visible = false;
				Foto->Visible = true;
				AnsiString ruta;
				AnsiString num = aux.socionumero;
				AnsiString ext = aux.extension;
				ruta = "fotos\\" + num + ext;
				Foto->Picture->LoadFromFile(ruta);
			}
		 }
		 infoPanel->Visible = true;
	 }
	 else {infoPanel->Visible = false;}

}

//---------------------------------------------------------------------------
void __fastcall TFormListaDeSocios::btCerrarClick(TObject *Sender)
{   FormListaDeSocios->Close();
}

//---------------------------------------------------------------------------
void __fastcall TFormListaDeSocios::FormClose(TObject *Sender, TCloseAction &Action)
{
    auxfila = 0;
	v.clear(); //al cerrarse limpia el vector
}

//---------------------------------------------------------------------------
void __fastcall TFormListaDeSocios::btEditarInfoClick(TObject *Sender)
{
	ClaseSocio aux;
				for( it = v.begin(); it != v.end(); it++ )
				{
					if(it->first == grillaSocios->Cells[0][fila])
					{
						aux = it->second;
					}
				}
	FormEditarSocio->GetSocio(aux); //FormEditarSocio tiene una variable de tipo ClaseSocio en la que se va a copiar el objeto aux
    FormEditarSocio->GetNumFila(fila);
	FormEditarSocio->ShowModal() ;
}

//---------------------------------------------------------------------------


void __fastcall TFormListaDeSocios::eBuscarChange(TObject *Sender)
{
	if((eBuscar->Text != "") && (eBuscar->Text != "0"))
	{
		int r=0;
		auxfila = 0;
		for( it = v.begin(); it != v.end(); it++ )
		{
			if(v[r].first == eBuscar->Text.ToInt())
			{
				grillaSocios->RowCount = 2;
				grillaSocios->Cells[0][1] = v[r].second.socionumero;
				grillaSocios->Cells[1][1] = v[r].second.dni;
				grillaSocios->Cells[2][1] = v[r].second.apellido;
				grillaSocios->Cells[3][1] = v[r].second.nombre;
				grillaSocios->Cells[4][1] = v[r].second.eliminado;
				grillaSocios->Cells[5][1] = v[r].second.cuotas_adeudadas;
			}
			else r++;
		}
	}
	else
	{
		int f=1;
		int r=0;
		if((cbBaja->Checked) == true) grillaSocios->RowCount = cantidadregistros+1;
		else grillaSocios->RowCount = tupla;
		for( it = v.begin(); it != v.end(); it++ )
		{
			grillaSocios->Cells[0][f] = v[r].second.socionumero;
			grillaSocios->Cells[1][f] = v[r].second.dni;
			grillaSocios->Cells[2][f] = v[r].second.apellido;
			grillaSocios->Cells[3][f] = v[r].second.nombre;
			grillaSocios->Cells[4][f] = v[r].second.eliminado;
			grillaSocios->Cells[5][f] = v[r].second.cuotas_adeudadas;
		}
	}

}
//---------------------------------------------------------------------------



void __fastcall TFormListaDeSocios::FormMouseEnter(TObject *Sender)
{
   infoPanel->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormListaDeSocios::cbBajaClick(TObject *Sender)
{
	listar();
}
//---------------------------------------------------------------------------

