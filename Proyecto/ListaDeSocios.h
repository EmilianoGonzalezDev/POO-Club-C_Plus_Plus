//---------------------------------------------------------------------------

#ifndef ListaDeSociosH
#define ListaDeSociosH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <vector>
#include <utility> // pair
#include "ClaseSocio.h"

using namespace std;

//---------------------------------------------------------------------------
class TFormListaDeSocios : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *grillaSocios;
	TPanel *infoPanel;
	TButton *btEditarInfo;
	TButton *btCerrar;
	TImage *Foto;
	TLabel *lbSinFoto;
	TLabel *lb8;
	TLabel *lbDeportes;
	TLabel *lbObservac;
	TLabel *lb10;
	TLabel *lb9;
	TLabel *lbNumSoc;
	TLabel *lb6;
	TLabel *lb7;
	TLabel *lb5;
	TLabel *lb3;
	TLabel *lb2;
	TLabel *lb4;
	TLabel *lb1;
	TLabel *lbNom;
	TLabel *lbApe;
	TLabel *lbDni;
	TLabel *lbNac;
	TLabel *lbSexo;
	TLabel *lbMail;
	TLabel *lbCel;
	TLabel *lbTipo;
	TLabel *lbFAlta;
	TMemo *memoObserv;
	TMemo *memoDeportes;
	TEdit *eBuscar;
	TLabel *lbBuscar;
	TLabel *L1;
	TLabel *L2;
	TLabel *L3;
	TLabel *lActivos;
	TLabel *lDeBaja;
	TLabel *lHonorarios;
	TLabel *L4;
	TLabel *lDeudores;
	TCheckBox *cbBaja;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall grillaSociosMouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y);
	void __fastcall btCerrarClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall btEditarInfoClick(TObject *Sender);
	void __fastcall eBuscarChange(TObject *Sender);
	void __fastcall FormMouseEnter(TObject *Sender);
	void __fastcall cbBajaClick(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TFormListaDeSocios(TComponent* Owner);
	void listar();
	vector< pair<int, ClaseSocio> > v;
	friend class TFormEditarSocio;


};
//---------------------------------------------------------------------------
extern PACKAGE TFormListaDeSocios *FormListaDeSocios;
//---------------------------------------------------------------------------
#endif
