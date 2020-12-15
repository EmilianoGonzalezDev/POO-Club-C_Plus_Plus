//---------------------------------------------------------------------------

#ifndef EditarSocioH
#define EditarSocioH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.CheckLst.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include "ClaseSocio.h"
using namespace std;

//---------------------------------------------------------------------------
class TFormEditarSocio : public TForm
{
__published:	// IDE-managed Components
	TLabel *lbObservac;
	TLabel *lbTipoDeSocio;
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
	TRadioGroup *RadioGroup1;
	TMemo *memoObserv;
	TComboBox *cbTipoDeSocio;
	TEdit *eEmail;
	TEdit *eTelefono;
	TButton *btCargarFoto;
	TRadioButton *rbFemenino;
	TRadioButton *rbMasculino;
	TEdit *eDNI;
	TComboBox *cbañoNacimiento;
	TComboBox *cbMesNacimiento;
	TComboBox *cbDiaNacimiento;
	TEdit *eNombre;
	TEdit *eApellido;
	TBitBtn *btListo;
	TBitBtn *btCancelar;
	TOpenPictureDialog *OpenPictureDialog1;
	TMemo *memoDep;
	TLabel *lbSinFoto;
	TBitBtn *btEliminar;
	TBitBtn *btReAlta;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btCargarFotoClick(TObject *Sender);
	void __fastcall btEliminarClick(TObject *Sender);
	void __fastcall btReAltaClick(TObject *Sender);
	void __fastcall btListoClick(TObject *Sender);
private:
	ClaseSocio s;
	int numfila; //fila desde la que se accedió
public:
	__fastcall TFormEditarSocio(TComponent* Owner);
	void GetSocio(ClaseSocio); //obtener el objeto de tipo ClaseSocio que se va a modificar
	void GetNumFila(int); //fila desde la que se accedió
	void modificarEstado(char);// indicar si esta dado de baja o no, etc.

};
//---------------------------------------------------------------------------
extern PACKAGE TFormEditarSocio *FormEditarSocio;
//---------------------------------------------------------------------------
#endif
