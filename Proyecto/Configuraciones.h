//---------------------------------------------------------------------------

#ifndef ConfiguracionesH
#define ConfiguracionesH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <fstream>
//---------------------------------------------------------------------------
class TFormConfiguraciones : public TForm
{
__published:	// IDE-managed Components
	TLabel *lbMontoCuota;
	TListBox *lboxMontoCuota;
	TButton *btEditarMonto;
	TBitBtn *btListo;
	TLabel *lbMaxCuotas;
	TLabel *Label2;
	TListBox *lboxMaxDeuda;
	TButton *btEditarMaxDeuda;
	TLabel *lbGenerarCuota;
	TButton *btEditarDiaCuota;
	TListBox *lboxDiaCuota;
	TLabel *Label1;
	TButton *btEditarPass;
	void __fastcall btEditarMontoClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btEditarMaxDeudaClick(TObject *Sender);
	void __fastcall btListoClick(TObject *Sender);
	void __fastcall btEditarDiaCuotaClick(TObject *Sender);
	void __fastcall btEditarPassClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormConfiguraciones(TComponent* Owner);
	friend class TFormModifConfig;
	int band;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormConfiguraciones *FormConfiguraciones;
//---------------------------------------------------------------------------
#endif
