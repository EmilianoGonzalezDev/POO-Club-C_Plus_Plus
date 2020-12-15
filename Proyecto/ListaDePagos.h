//---------------------------------------------------------------------------

#ifndef ListaDePagosH
#define ListaDePagosH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TFormListaDePagos : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *grillaPagos;
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormListaDePagos(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormListaDePagos *FormListaDePagos;
//---------------------------------------------------------------------------
#endif
