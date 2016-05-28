//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormPassWord.h"
#include "UnitFormMain.h"
#include "UnitFormConfigEquipos.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#define PASS1 "arduinomola"
#define PASS2 "adminadmin"
TFormPassword *FormPassword;

bool loged = false;
//---------------------------------------------------------------------------
__fastcall TFormPassword::TFormPassword(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormPassword::OKBtnClick(TObject *Sender)
{
	UnicodeString pass = Password->Text;

	if(pass == PASS1 | pass == PASS2)
	{
		if (pass == PASS1)   //Usuario normal
		{
			//Desbloquear botones normales
			FormMain->ButtonConfigEq->Enabled = true;
		}
		if (pass == PASS2)  //Usuario Admin
		{
			//Desbloquear botones normales
			FormConfigEquipos->ButtonInitEquipos->Enabled = true;
		}

		loged = true;
		Password->Text = "";
		FormMain->Button_loguear->Caption = "Log out";
		Close();
	}else{
		ShowMessage("¡Contraseña Incorrecta!");
		Password->Text = "";
		//MessageDlg("Contraseña Incorrecta", mtWarning, mbOK);
	}

}
//---------------------------------------------------------------------------
void __fastcall TFormPassword::CancelBtnClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
