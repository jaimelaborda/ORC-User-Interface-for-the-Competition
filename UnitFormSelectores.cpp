//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormSelectores.h"
#include "UnitDatos.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormSelectores *FormSelectores;

static int id_equipo=0;
static double pto_total = 0, tmax;
//---------------------------------------------------------------------------
__fastcall TFormSelectores::TFormSelectores(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormSelectores::ComboBox_EquiposChange(TObject *Sender)
{
	id_equipo = ComboBox_Equipos->ItemIndex;

	LeerArchivoTodo();

	Edit_Temp1->Text = equipo[id_equipo].sel_tiempo1;
	Edit_PiezasNegras->Text = equipo[id_equipo].sel_piezas_negras;

	Edit_PiezasBlancas->Text = equipo[id_equipo].sel_piezas_blancas;
	Edit_SalComp->Text = equipo[id_equipo].sel_sal_completa;
	Edit_SalBox->Text = equipo[id_equipo].sel_boxes;
	Edit_SalCompBox->Text = equipo[id_equipo].sel_completa_and_boxes;
	Label_PtoTot->Caption = equipo[id_equipo].sel_puntos;


	if(equipo[id_equipo].sel_snitch_dorada==1) CheckBoxSnitch->Checked = True;
		else CheckBoxSnitch->Checked = False;
}
//---------------------------------------------------------------------------
void __fastcall TFormSelectores::Button_guardarClick(TObject *Sender)
{
	equipo[id_equipo].sel_tiempo1 = Edit_Temp1->Text.ToDouble();
	equipo[id_equipo].sel_piezas_negras = Edit_PiezasNegras->Text.ToInt();

	equipo[id_equipo].sel_piezas_blancas = Edit_PiezasBlancas->Text.ToInt();
	equipo[id_equipo].sel_sal_completa = Edit_SalComp->Text.ToInt();
	equipo[id_equipo].sel_boxes = Edit_SalBox->Text.ToInt();
	equipo[id_equipo].sel_completa_and_boxes = Edit_SalCompBox->Text.ToInt();

	if (CheckBoxSnitch->Checked) equipo[id_equipo].sel_snitch_dorada = 1;
		else equipo[id_equipo].sel_snitch_dorada = 0;

	equipo[id_equipo].sel_puntos = pto_total;

	equipo[id_equipo].SumPuntosTotal();

	GuardarArchivoTodo();

	//ShowMessage("Datos guardados!");
}
//---------------------------------------------------------------------------
void __fastcall TFormSelectores::UpDownPiezasBlancasChangingEx(TObject *Sender, bool &AllowChange,
          int NewValue, TUpDownDirection Direction)
{
	Edit_PiezasBlancas->Text = NewValue;
}
//---------------------------------------------------------------------------
void __fastcall TFormSelectores::UpDownSalCompChangingEx(TObject *Sender, bool &AllowChange,
          int NewValue, TUpDownDirection Direction)
{
	Edit_SalComp->Text = NewValue;
}
//---------------------------------------------------------------------------
void __fastcall TFormSelectores::UpDownSalBoxChangingEx(TObject *Sender, bool &AllowChange,
          int NewValue, TUpDownDirection Direction)
{
	Edit_SalBox->Text = NewValue;
}
//---------------------------------------------------------------------------
void __fastcall TFormSelectores::UpDownBoxCompChangingEx(TObject *Sender, bool &AllowChange,
          int NewValue, TUpDownDirection Direction)
{
	Edit_SalCompBox->Text = NewValue;
}
//---------------------------------------------------------------------------
void __fastcall TFormSelectores::UpDownPiezasNegrasChangingEx(TObject *Sender, bool &AllowChange,
          int NewValue, TUpDownDirection Direction)
{
	Edit_PiezasNegras->Text = NewValue;
}
//---------------------------------------------------------------------------
void __fastcall TFormSelectores::Button_calcClick(TObject *Sender)
{
	static int piezas_negras, piezas_blancas, sal_completa, boxes, completa_and_boxes, snitch_dorada;
	static double tiempo1;

	piezas_negras = Edit_PiezasNegras->Text.ToInt();
	tiempo1 = Edit_Temp1->Text.ToDouble();

	piezas_blancas = Edit_PiezasBlancas->Text.ToInt();
	sal_completa = Edit_SalComp->Text.ToInt();
	boxes = Edit_SalBox->Text.ToInt();
	completa_and_boxes = Edit_SalCompBox->Text.ToInt();

	if (CheckBoxSnitch->Checked) snitch_dorada = 1;
		else snitch_dorada = 0;

	tmax =  LabeledEditTmax->Text.ToDouble();
	if ((pto_total = 70*((tmax)/20)*(piezas_negras/tiempo1) + snitch_dorada*20 - piezas_blancas*2 - sal_completa*3 - boxes*4 - completa_and_boxes*5) > 70)
		pto_total = 70;
	if(pto_total < 0)
		pto_total = 0;

	Label_PtoTot->Caption = pto_total;
	Edit_PtoTot->Text = pto_total;
}
//---------------------------------------------------------------------------
void __fastcall TFormSelectores::Button_ExitClick(TObject *Sender)
{
	FormSelectores->Close();
}
//---------------------------------------------------------------------------


void __fastcall TFormSelectores::ButtonPtoClick(TObject *Sender)
{
	pto_total = Edit_PtoTot->Text.ToDouble();
	equipo[id_equipo].sel_puntos = pto_total;

	equipo[id_equipo].SumPuntosTotal();
	GuardarArchivoTodo();
}
//---------------------------------------------------------------------------

