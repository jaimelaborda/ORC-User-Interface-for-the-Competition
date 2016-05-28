//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormVelocistas.h"
#include "UnitDatos.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormVelocistas *FormVelocistas;

//VARIABLES GLOBALES---------------------------------------------------------
static int id_equipo = 0;
double pto_total;
//---------------------------------------------------------------------------
void ActualizarComboBox(void)
{
	LeerArchivoTodo();

	FormVelocistas->ComboBox_Equipos->Items->Clear();

	int i=0;

	for(i=0; i<num_equipos; i++)
	{
		FormVelocistas->ComboBox_Equipos->Items->Add(AnsiString(equipo[i].nombre));
	}
}
__fastcall TFormVelocistas::TFormVelocistas(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormVelocistas::Button_ExitClick(TObject *Sender)
{
	FormVelocistas->Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormVelocistas::ComboBox_EquiposChange(TObject *Sender)
{
	id_equipo = FormVelocistas->ComboBox_Equipos->ItemIndex;

	LeerArchivoTodo();

	FormVelocistas->Edit_Temp1->Text = equipo[id_equipo].lab_tiempo1;
	//ShowMessage(equipo[id_equipo].lab_tiempo1);
	FormVelocistas->Edit_Temp2->Text = equipo[id_equipo].lab_tiempo2;

	FormVelocistas->Edit_SalPar->Text = equipo[id_equipo].vel_sal_parcial;
	FormVelocistas->Edit_SalComp->Text = equipo[id_equipo].vel_sal_completa;
	FormVelocistas->Edit_SalBox->Text = equipo[id_equipo].vel_boxes;
	FormVelocistas->Edit_SalCompBox->Text = equipo[id_equipo].vel_completa_and_boxes;
	Label_PtoTot->Caption = equipo[id_equipo].vel_puntos;


	if(equipo[id_equipo].vel_atajo==1) FormVelocistas->CheckBoxAtajo->Checked = True;
		else FormVelocistas->CheckBoxAtajo->Checked = False;
	if(equipo[id_equipo].vel_obs_tunel==1) FormVelocistas->CheckBoxTunel->Checked = True;
		else FormVelocistas->CheckBoxTunel->Checked = False;
	if(equipo[id_equipo].vel_obs_puente==1) FormVelocistas->CheckBoxPuente->Checked = True;
		else FormVelocistas->CheckBoxPuente->Checked = False;
	if(equipo[id_equipo].vel_curvas==1) FormVelocistas->CheckBoxCurvas->Checked = True;
		else FormVelocistas->CheckBoxCurvas->Checked = False;
	if(equipo[id_equipo].vel_best==1) FormVelocistas->CheckBoxBest->Checked = True;
		else FormVelocistas->CheckBoxBest->Checked = False;

}
//---------------------------------------------------------------------------
void __fastcall TFormVelocistas::Button_guardarClick(TObject *Sender)
{
	equipo[id_equipo].vel_tiempo1 = FormVelocistas->Edit_Temp1->Text.ToDouble();
	equipo[id_equipo].vel_tiempo2 = FormVelocistas->Edit_Temp2->Text.ToDouble();

	equipo[id_equipo].vel_sal_parcial = FormVelocistas->Edit_SalPar->Text.ToInt();
	equipo[id_equipo].vel_sal_completa = FormVelocistas->Edit_SalComp->Text.ToInt();
	equipo[id_equipo].vel_boxes = FormVelocistas->Edit_SalBox->Text.ToInt();
	equipo[id_equipo].vel_completa_and_boxes = FormVelocistas->Edit_SalCompBox->Text.ToInt();

	if (FormVelocistas->CheckBoxAtajo->Checked) equipo[id_equipo].vel_atajo = 1;
		else equipo[id_equipo].vel_atajo = 0;
	if (FormVelocistas->CheckBoxTunel->Checked) equipo[id_equipo].vel_obs_tunel =1;
		else equipo[id_equipo].vel_obs_tunel = 0;
	if (FormVelocistas->CheckBoxPuente->Checked) equipo[id_equipo].vel_obs_puente = 1;
		else equipo[id_equipo].vel_obs_puente = 0;
	if (FormVelocistas->CheckBoxCurvas->Checked) equipo[id_equipo].vel_curvas = 1;
		else equipo[id_equipo].vel_curvas = 0;
	if (FormVelocistas->CheckBoxBest->Checked) equipo[id_equipo].vel_best = 1;
		else equipo[id_equipo].vel_best = 0;

	equipo[id_equipo].vel_puntos = pto_total;
	equipo[id_equipo].SumPuntosTotal();

	GuardarArchivoTodo();

	ActualizarComboBox();
}
//---------------------------------------------------------------------------
void __fastcall TFormVelocistas::Button_calcClick(TObject *Sender)
{
	static int sal_parcial, sal_completa, boxes, completa_and_boxes, atajo, tunel, puente, curvas, best;
	static double tiempo1, tiempo2, tiempobest;

	tiempo1 = Edit_Temp1->Text.ToDouble();
	tiempo2 = Edit_Temp2->Text.ToDouble();

	if(tiempo1 > tiempo2)
	{
		tiempobest = tiempo2;
	}else{
		tiempobest = tiempo1;
	}

	sal_parcial = FormVelocistas->Edit_SalPar->Text.ToInt();
	sal_completa = FormVelocistas->Edit_SalComp->Text.ToInt();
	boxes = FormVelocistas->Edit_SalBox->Text.ToInt();
	completa_and_boxes = FormVelocistas->Edit_SalCompBox->Text.ToInt();


	if (FormVelocistas->CheckBoxAtajo->Checked) atajo = 1;
		else atajo = 0;
	if (FormVelocistas->CheckBoxTunel->Checked) tunel =1;
		else tunel = 0;
	if (FormVelocistas->CheckBoxPuente->Checked) puente = 1;
		else puente = 0;
	if (FormVelocistas->CheckBoxCurvas->Checked) curvas = 1;
		else curvas = 0;
	if (FormVelocistas->CheckBoxBest->Checked) best = 1;
		else best = 0;

	//tmax =  LabeledEditTmax->Text.ToDouble();

	pto_total = ((35/tiempobest)*35)+1*atajo+3*tunel+5*puente+1*curvas+2*best-1*sal_parcial-3*sal_completa-4*boxes-5*completa_and_boxes;

	if (pto_total  > 35)
		pto_total = 35;
	if(pto_total < 0)
		pto_total = 0;

	Label_PtoTot->Caption = pto_total;
}
//---------------------------------------------------------------------------
void __fastcall TFormVelocistas::UpDownSalParChangingEx(TObject *Sender, bool &AllowChange,
		  int NewValue, TUpDownDirection Direction)
{
	FormVelocistas->Edit_SalPar->Text = NewValue;
}
//---------------------------------------------------------------------------
void __fastcall TFormVelocistas::UpDownSalCompChangingEx(TObject *Sender, bool &AllowChange,
          int NewValue, TUpDownDirection Direction)
{
	FormVelocistas->Edit_SalComp->Text = NewValue;
}
//---------------------------------------------------------------------------
void __fastcall TFormVelocistas::UpDownSalBoxChangingEx(TObject *Sender, bool &AllowChange,
          int NewValue, TUpDownDirection Direction)
{
	FormVelocistas->Edit_SalBox->Text = NewValue;
}
//---------------------------------------------------------------------------
void __fastcall TFormVelocistas::UpDownBoxCompChangingEx(TObject *Sender, bool &AllowChange,
          int NewValue, TUpDownDirection Direction)
{
	FormVelocistas->Edit_SalCompBox->Text = NewValue;
}
//---------------------------------------------------------------------------

void __fastcall TFormVelocistas::FormShow(TObject *Sender)
{
	LeerArchivoTodo();

	FormVelocistas->ComboBox_Equipos->Items->Clear();

	int i=0;

	for(i=0; i<num_equipos; i++)
	{
		FormVelocistas->ComboBox_Equipos->Items->Add(AnsiString(equipo[i].nombre));
	}
}
//---------------------------------------------------------------------------

