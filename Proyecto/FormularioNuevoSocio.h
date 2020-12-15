//---------------------------------------------------------------------------

#ifndef FormularioNuevoSocioH
#define FormularioNuevoSocioH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.CheckLst.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
//---------------------------------------------------------------------------
class TFormNuevoSocio : public TForm
{
__published:	// IDE-managed Components
	TLabel *lbObservaciones;
	TLabel *lbTipoDeSocio;
	TLabel *lbArroba;
	TLabel *lbEmail;
	TLabel *lbNumeroDeSocio;
	TLabel *lbSocioNum;
	TLabel *lbTelefono;
	TLabel *lbDeportes;
	TImage *FotoSocio;
	TLabel *lbSexo;
	TLabel *lbDNI;
	TLabel *lbApellido;
	TLabel *lbNacimiento;
	TLabel *lbNombre;
	TMemo *memoObserv;
	TCheckListBox *clDeportes;
	TComboBox *cbTipoDeSocio;
	TComboBox *cboxMail;
	TEdit *eEmail;
	TEdit *eTelefono;
	TButton *btCargarFoto;
	TRadioButton *rbFemenino;
	TRadioButton *rbMasculino;
	TRadioGroup *RadioGroup1;
	TEdit *eDNI;
	TComboBox *cbañoNacimiento;
	TComboBox *cbMesNacimiento;
	TComboBox *cbDiaNacimiento;
	TEdit *eNombre;
	TEdit *eApellido;
	TBitBtn *btListo;
	TBitBtn *btCancelar;
	TBitBtn *btReiniciarForm;
	TOpenPictureDialog *OpenPictureDialog1;
	TLabel *lbFechaIngreso;
	TComboBox *cbAñoAlta;
	TComboBox *cbMesAlta;
	TComboBox *cbDiaAlta;
	TCheckBox *chbHoy;
	TRadioGroup *groupBoxNoSi;
	TRadioButton *rbSi;
	TRadioButton *rbNo;
	void __fastcall btCancelarClick(TObject *Sender);
	void __fastcall btReiniciarFormClick(TObject *Sender);
	void __fastcall btCargarFotoClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btListoClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall chbHoyClick(TObject *Sender);
	void __fastcall rbNoClick(TObject *Sender);
	void __fastcall rbSiClick(TObject *Sender);
	void __fastcall eDNIExit(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormNuevoSocio(TComponent* Owner);
	void __limpiar_campos();
};
//---------------------------------------------------------------------------
extern PACKAGE TFormNuevoSocio *FormNuevoSocio;
//---------------------------------------------------------------------------

#endif
