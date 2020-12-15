//---------------------------------------------------------------------------

#ifndef PRINCIPALH
#define PRINCIPALH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TBitBtn *btAgregarSocio;
	TBitBtn *btVerListadoSocios;
	TBitBtn *btAdministracion;
	TBitBtn *btNuevoPago;
	TBitBtn *btListadoPagos;
	TBitBtn *btGenerarCuota;
	void __fastcall btAgregarSocioClick(TObject *Sender);
	void __fastcall btVerListadoSociosClick(TObject *Sender);
	void __fastcall btAdministracionClick(TObject *Sender);
	void __fastcall btNuevoPagoClick(TObject *Sender);
	void __fastcall btListadoPagosClick(TObject *Sender);
	void __fastcall btGenerarCuotaClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
