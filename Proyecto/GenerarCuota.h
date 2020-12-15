//---------------------------------------------------------------------------

#ifndef GenerarCuotaH
#define GenerarCuotaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TFormGenerarCuota : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TButton *btGenerarCuota;
	TLabel *Label2;
	TButton *btEliminarCuota;
	TBitBtn *btCancelar;
	TLabel *lbMesUltimaCuota;
	TLabel *lbAnioUltimaCuota;
	TLabel *Label3;
	TLabel *Label4;
	void __fastcall btGenerarCuotaClick(TObject *Sender);
	void __fastcall btEliminarCuotaClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormGenerarCuota(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormGenerarCuota *FormGenerarCuota;
//---------------------------------------------------------------------------
#endif
