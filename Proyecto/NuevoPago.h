//---------------------------------------------------------------------------

#ifndef NuevoPagoH
#define NuevoPagoH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TFormPago : public TForm
{
__published:	// IDE-managed Components
	TLabel *lbNumSocio;
	TEdit *eNumSocio;
	TLabel *lbAabonar;
	TLabel *lbMontoTotal;
	TLabel *lbMontoCuota;
	TLabel *lbPeso;
	TLabel *lbPeso2;
	TLabel *lbMontoActual;
	TLabel *lbAbonar;
	TBitBtn *btCancelar;
	TEdit *eCuotas;
	TButton *btListo;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall eCuotasChange(TObject *Sender);
	void __fastcall btListoClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TFormPago(TComponent* Owner);
	float montocuota;
	int maxdeuda;
	friend class ClasePago;

};
//---------------------------------------------------------------------------
extern PACKAGE TFormPago *FormPago;
//---------------------------------------------------------------------------
#endif
