//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormMain.h"
#include "UnitFormVelocistas.h"
#include "UnitFormAbout.h"
#include "UnitFormSelectores.h"
#include "UnitFormLaberinto.h"
#include "UnitFormConfigEquipos.h"
#include "UnitFormPassWord.cpp"
#include "UnitFormDisplayPtoTot.h"
#include "UnitDatos.h"
//---------------------------------------------------------------------------
//#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMain *FormMain;

//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::Salir1Click(TObject *Sender)
{
	FormMain->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::Button_ExitClick(TObject *Sender)
{
	GuardarArchivoTodo();
	FormMain->Close();
}
//---------------------------------------------------------------------------



void __fastcall TFormMain::ButtonVeloClick(TObject *Sender)
{
	/*LeerArchivoTodo();

	FormVelocistas->ComboBox_Equipos->Items->Clear();

	int i=0;

	for(i=0; i<20; i++)
	{
		FormVelocistas->ComboBox_Equipos->Items->Add(AnsiString(equipo[i].nombre));
	}*/
	FormVelocistas->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::Sobre1Click(TObject *Sender)
{
	FormAbout->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TFormMain::ButtonSelectoresClick(TObject *Sender)
{
	LeerArchivoTodo();

	FormSelectores->ComboBox_Equipos->Items->Clear();

	int i=0;

	for(i=0; i<20; i++)
	{
		FormSelectores->ComboBox_Equipos->Items->Add(AnsiString(equipo[i].nombre));
	}
	FormSelectores->ShowModal();
}
//---------------------------------------------------------------------------




void __fastcall TFormMain::ButtonConfigEqClick(TObject *Sender)
{
	FormConfigEquipos->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TFormMain::Button_loguearClick(TObject *Sender)
{
	if (!loged)
	{
		FormPassword->ShowModal();
	}else{
		loged = false;
		//Bloquear Botones
		Button_loguear->Caption = "Log In";
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ButtonDisplayPtoTotalClick(TObject *Sender)
{
	if (FormDisplayPtoTot->Visible)
	{
		FormDisplayPtoTot->Close();
		ButtonDisplayPtoTotal->Caption = "Abrir Marcador";
	}else{
		FormDisplayPtoTot->Show();
		ButtonDisplayPtoTotal->Caption = "Cerrar Marcador";
    }

}
//---------------------------------------------------------------------------

void __fastcall TFormMain::FormClose(TObject *Sender, TCloseAction &Action)
{
	GuardarArchivoTodo();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::FormCreate(TObject *Sender)
{
	LeerArchivoTodo();
	//LeerNumEq();
	//RellenarVectores();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::Button2Click(TObject *Sender)
{
	int i;
	for(i=0; i<20; i++)
	{
		//ShowMessage(vector_eq_id_orden[i]);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::Button3Click(TObject *Sender)
{
	//RellenarVectores();
	//OrdenarEquipos();
    int i;
	for(i=0; i<20; i++)
	{
		//ShowMessage(vector_eq_id_orden[i]);
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormMain::ButtonLaberintoClick(TObject *Sender)
{
	FormLaberinto->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ButtonActValClick(TObject *Sender)
{
	if(FormDisplayPtoTot->TimerAct->Enabled)
	{
		FormDisplayPtoTot->TimerAct->Enabled = false;
		ButtonActVal->Caption = "Activar Marcador";
	}else{
		FormDisplayPtoTot->TimerAct->Enabled = true;
		ButtonActVal->Caption = "Desact. Marcador";
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormMain::ButtonCronoResetClick(TObject *Sender)
{
	ResetCrono();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ButtonCronoActClick(TObject *Sender)
{
	if(FormDisplayPtoTot->TimerCrono->Enabled)
	{
		FormDisplayPtoTot->TimerCrono->Enabled = false;
		ButtonCronoAct->Caption = "INICIAR";
	}else{
		FormDisplayPtoTot->TimerCrono->Enabled = true;
		ButtonCronoAct->Caption = "PARAR";
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::Manualfunciones1Click(TObject *Sender)
{
	ShowMessage("Proximamente...");
}
//---------------------------------------------------------------------------

