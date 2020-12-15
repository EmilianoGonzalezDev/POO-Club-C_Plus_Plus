//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("PRINCIPAL.cpp", Form1);
USEFORM("NuevoPago.cpp", FormPago);
USEFORM("ModifConfig.cpp", FormModifConfig);
USEFORM("EditarSocio.cpp", FormEditarSocio);
USEFORM("Configuraciones.cpp", FormConfiguraciones);
USEFORM("FormularioNuevoSocio.cpp", FormNuevoSocio);
USEFORM("ListaDeSocios.cpp", FormListaDeSocios);
USEFORM("ListaDePagos.cpp", FormListaDePagos);
USEFORM("GenerarCuota.cpp", FormGenerarCuota);
USEFORM("FormContrasenia.cpp", FormPass);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		TStyleManager::TrySetStyle("Iceberg Classico");
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TFormNuevoSocio), &FormNuevoSocio);
		Application->CreateForm(__classid(TFormListaDeSocios), &FormListaDeSocios);
		Application->CreateForm(__classid(TFormEditarSocio), &FormEditarSocio);
		Application->CreateForm(__classid(TFormPago), &FormPago);
		Application->CreateForm(__classid(TFormListaDePagos), &FormListaDePagos);
		Application->CreateForm(__classid(TFormConfiguraciones), &FormConfiguraciones);
		Application->CreateForm(__classid(TFormModifConfig), &FormModifConfig);
		Application->CreateForm(__classid(TFormGenerarCuota), &FormGenerarCuota);
		Application->CreateForm(__classid(TFormPass), &FormPass);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
