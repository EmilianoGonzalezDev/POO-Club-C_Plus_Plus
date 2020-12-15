//---------------------------------------------------------------------------

#ifndef ModifConfigH
#define ModifConfigH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TFormModifConfig : public TForm
{
__published:	// IDE-managed Components
	TLabel *lb1;
	TLabel *lbValor;
	TLabel *lb2;
	TBitBtn *btCancelar;
	TEdit *eNuevoValor;
	TBitBtn *btListo;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall btListoClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:
	// User declarations
public:		// User declarations
	__fastcall TFormModifConfig(TComponent* Owner);
	friend class TFormConfiguraciones;
protected:
	int bandera;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormModifConfig *FormModifConfig;
//---------------------------------------------------------------------------
#endif
