//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormLaberinto.h"
#include "UnitDatos.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormLaberinto *FormLaberinto;

static int id_equipo;
static double pto_total;

void ActualizarComboBox(void)
{
	LeerArchivoTodo();

	FormLaberinto->ComboBox_Equipos->Items->Clear();

	int i=0;

	for(i=0; i<num_equipos; i++)
	{
		FormLaberinto->ComboBox_Equipos->Items->Add(AnsiString(equipo[i].nombre));
	}
}
//---------------------------------------------------------------------------
__fastcall TFormLaberinto::TFormLaberinto(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormLaberinto::Button_ExitClick(TObject *Sender)
{
	GuardarArchivoTodo();
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormLaberinto::ComboBox_EquiposChange(TObject *Sender)
{
	id_equipo = ComboBox_Equipos->ItemIndex;

	LeerArchivoTodo();

	Edit_Temp1->Text = equipo[id_equipo].lab_tiempo1;
	Edit_Temp2->Text = equipo[id_equipo].lab_tiempo2;
	Edit_Temp3->Text = equipo[id_equipo].lab_tiempo3;

	Edit_SalComp->Text = equipo[id_equipo].lab_sal_completa;
	Edit_SalBox->Text = equipo[id_equipo].lab_boxes;
	Edit_SalCompBox->Text = equipo[id_equipo].lab_completa_and_boxes;
	Label_PtoTot->Caption = equipo[id_equipo].lab_puntos;

	if(equipo[id_equipo].lab_best==1)CheckBoxBest->Checked = True;
		else CheckBoxBest->Checked = False;
}
//---------------------------------------------------------------------------

void __fastcall TFormLaberinto::Button_guardarClick(TObject *Sender)
{
	equipo[id_equipo].lab_tiempo1 = Edit_Temp1->Text.ToDouble();
	equipo[id_equipo].lab_tiempo2 = Edit_Temp2->Text.ToDouble();
	equipo[id_equipo].lab_tiempo3 = Edit_Temp3->Text.ToDouble();

	equipo[id_equipo].lab_sal_completa = Edit_SalComp->Text.ToInt();
	equipo[id_equipo].lab_boxes = Edit_SalBox->Text.ToInt();
	equipo[id_equipo].lab_completa_and_boxes = Edit_SalCompBox->Text.ToInt();

	if (CheckBoxBest->Checked) equipo[id_equipo].lab_best = 1;
		else equipo[id_equipo].lab_best = 0;

	equipo[id_equipo].lab_puntos = pto_total;
	equipo[id_equipo].SumPuntosTotal();

	GuardarArchivoTodo();

	ActualizarComboBox();
}
//---------------------------------------------------------------------------

void __fastcall TFormLaberinto::Button_calcClick(TObject *Sender)
{
	static int sal_completa, boxes, completa_and_boxes, best, i;
	static double tiempo[3], tmax;
	double tiempobest = 9999;

	tiempo[0]= Edit_Temp1->Text.ToDouble();
	tiempo[1] = Edit_Temp2->Text.ToDouble();
	tiempo[2] = Edit_Temp3->Text.ToDouble();

	for (i = 0; i < 3; i++) {
		if(tiempo[i] < tiempobest)
			tiempobest = tiempo[i];
	}

	sal_completa = Edit_SalComp->Text.ToInt();
	boxes = Edit_SalBox->Text.ToInt();
	completa_and_boxes = Edit_SalCompBox->Text.ToInt();

	if (CheckBoxBest->Checked) best = 1;
		else best = 0;

	tmax =  LabeledEditTmax->Text.ToDouble();

	pto_total = (60-(60/tmax)*tiempobest)+5*best-3*sal_completa-4*boxes-5*completa_and_boxes;   //ESTA MAL!

	if (pto_total  > 60)
		pto_total = 60;
	if(pto_total < 0)
		pto_total = 0;

	Label_PtoTot->Caption = pto_total;
}
//---------------------------------------------------------------------------

void __fastcall TFormLaberinto::FormShow(TObject *Sender)
{
	LeerArchivoTodo();

	FormLaberinto->ComboBox_Equipos->Items->Clear();

	int i=0;

	for(i=0; i<num_equipos; i++)
	{
		FormLaberinto->ComboBox_Equipos->Items->Add(AnsiString(equipo[i].nombre));
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormLaberinto::ButtonPtoTotalClick(TObject *Sender)
{
	pto_total = LabeledEditPtoTotal->Text.ToDouble();
	Label_PtoTot->Caption = LabeledEditPtoTotal->Text.ToDouble();
}
//---------------------------------------------------------------------------

