//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#include <stdlib.h>
#pragma hdrstop

#include "UnitFormConfigEquipos.h"
#include "UnitDatos.h"
#include "string.h"

#define MAX_NOMBRE 20
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormConfigEquipos *FormConfigEquipos;

static int id_equipo = 0;
//---------------------------------------------------------------------------
void ActualizarComboBox(void)
{
	LeerArchivoTodo();

	FormConfigEquipos->ComboBox_Equipos->Items->Clear();

	int i=0;

	for(i=0; i<num_equipos; i++)
	{
		FormConfigEquipos->ComboBox_Equipos->Items->Add(AnsiString(equipo[i].nombre));
	}
}

__fastcall TFormConfigEquipos::TFormConfigEquipos(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormConfigEquipos::ButtonActualizarClick(TObject *Sender)
{

	LeerArchivoTodo();

	int i;

	FormConfigEquipos->ComboBox_Equipos->Items->Clear();

	for(i=0; i<num_equipos; i++)
	{
		ComboBox_Equipos->Items->Add(AnsiString(equipo[i].nombre));
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormConfigEquipos::ButtonInitEquiposClick(TObject *Sender)
{
	int i;
	char nombre[MAX_NOMBRE];

	for(i=0; i<num_equipos; i++)
	{
		equipo[i].id_equipo = i;
		sprintf(nombre, "Equipo %d", i);
		strcpy(equipo[i].nombre, nombre);
	}
	GuardarArchivoTodo();
}
//---------------------------------------------------------------------------

void __fastcall TFormConfigEquipos::Button_guardarClick(TObject *Sender)
{

	int i;
	char nombre[MAX_NOMBRE];

	wcstombs(nombre, EditNombre->Text.w_str(), 20); //Convierte *w_char del Edit en *char
	strcpy(equipo[id_equipo].nombre, nombre);       //Copia en memoria

	equipo[id_equipo].sum_puntos = LabeledEditSumo->Text.ToDouble();
	equipo[id_equipo].fut_puntos = LabeledEditFutbol->Text.ToDouble();
	equipo[id_equipo].puntos_total = LabeledEditTotal->Text.ToDouble();

	ComboBox_Equipos->Items->Clear();

	for(i=0; i<num_equipos; i++)
	{
		ComboBox_Equipos->Items->Add(AnsiString(equipo[i].nombre));
	}

	equipo[id_equipo].SumPuntosTotal();
	GuardarArchivoTodo();
}
//---------------------------------------------------------------------------

void __fastcall TFormConfigEquipos::ComboBox_EquiposChange(TObject *Sender)
{
	id_equipo = ComboBox_Equipos->ItemIndex;
	EditNombre->Text = equipo[id_equipo].nombre;

	LabeledEditSumo->Text = equipo[id_equipo].sum_puntos;
	LabeledEditFutbol->Text = equipo[id_equipo].fut_puntos;
	LabeledEditTotal->Text = equipo[id_equipo].puntos_total;
}
//---------------------------------------------------------------------------

void __fastcall TFormConfigEquipos::Button_ExitClick(TObject *Sender)
{
	FormConfigEquipos->Close();
}
//---------------------------------------------------------------------------


void __fastcall TFormConfigEquipos::ButtonNumEqClick(TObject *Sender)
{
	num_equipos = EditNumEq->Text.ToInt();

	EscribirNumEq();
}
//---------------------------------------------------------------------------

void __fastcall TFormConfigEquipos::FormShow(TObject *Sender)
{
	ActualizarComboBox();
}
//---------------------------------------------------------------------------

