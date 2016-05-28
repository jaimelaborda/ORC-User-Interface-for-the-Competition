//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "UnitFormDisplayPtoTot.h"
#include "UnitDatos.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormDisplayPtoTot *FormDisplayPtoTot;

int minut=0, sec=0;
//---------------------------------------------------------------------------
__fastcall TFormDisplayPtoTot::TFormDisplayPtoTot(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void ResetCrono(void)
{
	minut = 0;
	sec = 0;

	FormDisplayPtoTot->LabelCrono->Caption = "00:00";
}
void __fastcall TFormDisplayPtoTot::FormShow(TObject *Sender)
{
	if (Screen->MonitorCount>1)
	{
		int MonitorTop = Screen->Monitors[1]->Top;
		int MonitorLeft = Screen->Monitors[1]->Left;
		int MonitorWidth = Screen->Monitors[1]->Width;
		int MonitorHeight = MonitorTop + Screen->Monitors[1]->Height;
		//MonitorWidth = MonitorLeft + Screen->Monitors[1]->Width; // Will be about zero if the 2nd monitor is to the left of the default monitor

		//ShowMessage(MonitorTop);
		//ShowMessage(MonitorLeft);
		//ShowMessage(MonitorWidth);
		//ShowMessage(MonitorHeight);

		FormDisplayPtoTot->Top = MonitorTop;
		FormDisplayPtoTot->Left = MonitorLeft;
		FormDisplayPtoTot->Width = MonitorWidth;
		FormDisplayPtoTot->Height = MonitorHeight;
	}

		/* AJUSTE A LA PANTALLA ->NO FUNCIONA
		TListColumn *ListCol;

		ListView->Columns->Clear();

		ListCol = ListView->Columns->Add();
		ListCol->Caption = "PUESTO";
		ShowMessage(80/1040*ListView->Width);
		ListCol->Width = (int)(80/1040*ListView->Width);
		ListCol = ListView->Columns->Add();
		ListCol->Caption = "EQUIPO";
		ListCol->Width = (int)340/1040*ListView->Width;
		ListCol = ListView->Columns->Add();
		ListCol->Caption = "VELOCISTAS";
		ListCol->Width = (int)110/1040*ListView->Width;
		ListCol = ListView->Columns->Add();
		ListCol->Caption = "LABERINTO";
		ListCol->Width = (int)110/1040*ListView->Width;
		ListCol = ListView->Columns->Add();
		ListCol->Caption = "SUMO";
		ListCol->Width = (int)110/1040*ListView->Width;
		ListCol = ListView->Columns->Add();
		ListCol->Caption = "FURBOL";
		ListCol->Width = (int)80/1040*ListView->Width;
		ListCol = ListView->Columns->Add();
		ListCol->Caption = "TOTAL";
		ListCol->Width = (int)90/1040*ListView->Width;*/
}
//---------------------------------------------------------------------------





void __fastcall TFormDisplayPtoTot::TimerCronoTimer(TObject *Sender)
{


	if(sec == 59){
		sec=0;
		minut++;
	}else{
		sec++;
	}


	char tira[10];
	sprintf(tira, "%.2d:%.2d", minut, sec);

	LabelCrono->Caption = tira;
}
//---------------------------------------------------------------------------

void __fastcall TFormDisplayPtoTot::TimerActTimer(TObject *Sender)
{
	ListView->Clear();

	TListItem *ListIt;

	int i, j, temp_id;
	double temp_val;
	char tira[20];

	static int vector_eq_id_orden[20];
	static double vector_eq_val_orden[20];

	for(i=0; i<num_equipos; i++)     //Rellena el vector con los datos de equipo
	{
		vector_eq_id_orden[i] = i;
		vector_eq_val_orden[i] = equipo[i].puntos_total;
	}

	//OrdenarEquipos();
	for (i=1; i<num_equipos; i++)
	{
		for (j=0 ; j<num_equipos - i; j++)
		{
			if (vector_eq_val_orden[j] > vector_eq_val_orden[j+1])
			{
				temp_id = vector_eq_id_orden[j];
				vector_eq_id_orden[j] = vector_eq_id_orden[j+1];
				vector_eq_id_orden[j+1] = temp_id;

				temp_val = vector_eq_val_orden[j];
				vector_eq_val_orden[j] = vector_eq_val_orden[j+1];
				vector_eq_val_orden[j+1] = temp_val;
			}
        }
	}

	for (i=num_equipos-1; i >= 0; i--)
	{
		ListIt = ListView->Items->Add();
		ListIt->Caption = num_equipos-i;
		ListIt->SubItems->Add(equipo[vector_eq_id_orden[i]].nombre);
		sprintf(tira, "%.3f", equipo[vector_eq_id_orden[i]].vel_puntos);
		ListIt->SubItems->Add(tira);
		sprintf(tira, "%.3f", equipo[vector_eq_id_orden[i]].sel_puntos);
		ListIt->SubItems->Add(tira);
		sprintf(tira, "%.3f", equipo[vector_eq_id_orden[i]].lab_puntos);
		ListIt->SubItems->Add(tira);
		sprintf(tira, "%.3f", equipo[vector_eq_id_orden[i]].sum_puntos);
		ListIt->SubItems->Add(tira);
		sprintf(tira, "%.3f", equipo[vector_eq_id_orden[i]].fut_puntos);
		ListIt->SubItems->Add(tira);

		sprintf(tira, "%.3f", equipo[vector_eq_id_orden[i]].puntos_total);
		ListIt->SubItems->Add(tira);
	}

}
//---------------------------------------------------------------------------



