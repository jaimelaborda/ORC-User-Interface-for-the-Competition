//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("UnitFormMain.cpp", FormMain);
USEFORM("UnitFormLaberinto.cpp", FormLaberinto);
USEFORM("UnitFormVelocistas.cpp", FormVelocistas);
USEFORM("UnitFormSelectores.cpp", FormSelectores);
USEFORM("UnitFormDisplayPtoTot.cpp", FormDisplayPtoTot);
USEFORM("UnitFormConfigEquipos.cpp", FormConfigEquipos);
USEFORM("UnitFormAbout.cpp", FormAbout);
USEFORM("UnitFormPassWord.cpp", FormPassword);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		TStyleManager::TrySetStyle("Carbon");
		Application->Title = "Olympic Robotic Challenge v1.0";
		Application->CreateForm(__classid(TFormMain), &FormMain);
		Application->CreateForm(__classid(TFormVelocistas), &FormVelocistas);
		Application->CreateForm(__classid(TFormAbout), &FormAbout);
		Application->CreateForm(__classid(TFormSelectores), &FormSelectores);
		Application->CreateForm(__classid(TFormLaberinto), &FormLaberinto);
		Application->CreateForm(__classid(TFormConfigEquipos), &FormConfigEquipos);
		Application->CreateForm(__classid(TFormDisplayPtoTot), &FormDisplayPtoTot);
		Application->CreateForm(__classid(TFormPassword), &FormPassword);
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
