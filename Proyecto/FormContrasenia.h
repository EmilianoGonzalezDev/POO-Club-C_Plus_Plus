//---------------------------------------------------------------------------

#ifndef FormContraseniaH
#define FormContraseniaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TFormPass : public TForm
{
__published:	// IDE-managed Components
	TEdit *ePass;
	TButton *btAceptar;
	TLabel *Label1;
	TButton *btCancelar;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btAceptarClick(TObject *Sender);
	void __fastcall btCancelarClick(TObject *Sender);
private:	// User declarations
	long int P;
public:		// User declarations
	int mostrarFormX;//indica cual de los Form debe mostar si se ingresa bien el pass
	__fastcall TFormPass(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPass *FormPass;
//---------------------------------------------------------------------------
#endif
