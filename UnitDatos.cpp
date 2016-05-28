//---------------------------------------------------------------------------

#pragma hdrstop

#include "UnitDatos.h"
#include <stdio.h>
#include <vcl.h>
//---------------------------------------------------------------------------

 /*CVelocistas::CVelocistas(void)
{
	id_equipo=0;
	atajo=0; obs_tunel=0; obs_puente=0; curvas=0; best=0;  //Bonus
	sal_parcial=0; sal_completa=0; boxes=0; completa_and_boxes=0; //SANCIONES
	tiempo1=0; tiempo2=0;
	puntos_velocistas=0;
}*/

void CEquipo::LeerArchivo(int id_file)
{
	FILE *F;

	F = fopen("file_equipo.bin", "rb");

	fseek(F, id_equipo*sizeof(CEquipo), SEEK_SET);
	fread(&equipo[id_equipo], sizeof(CEquipo), 1, F);

	fclose(F);
}

void CEquipo::GuardarArchivo(int id_file)
{

	FILE *F;

	F = fopen("file_equipo.bin", "wb");

	fseek(F, id_equipo*sizeof(CEquipo), SEEK_SET);
	//ShowMessage("Escribiendo archivo...");
	fwrite(&equipo[id_equipo], sizeof(CEquipo), 1, F);

	fclose(F);
}

/*void CEquipo::NuevoEquipo(void)
{
	int new_id;

	NuevoEquipo = new CEquipo;

	new_id = Equipos.size() + 1;
	NuevoEquipo.id_equipo = new_id;
	ShowMessage(NuevoEquipo.id_equipo);

	Equipos.push_back(NuevoEquipo);
}   */

void LeerArchivoTodo(void)
{
	FILE *F;

	F = fopen("file_equipo_todo.bin", "rb");

	if(!F)
	{
		ShowMessage("Error al leer archivo");
		//exit(-1);
	}

	fseek(F,0 , SEEK_SET);
	fread(equipo, sizeof(CEquipo), 20, F);

	fclose(F);
}

void GuardarArchivoTodo(void)
{
	FILE *F;

	F = fopen("file_equipo_todo.bin", "wb");

	fseek(F,0 , SEEK_SET);
	fwrite(equipo, sizeof(CEquipo), 20, F);

	fclose(F);
}

void CEquipo::SumPuntosTotal(void)
{
	puntos_total = vel_puntos + sel_puntos + lab_puntos + sum_puntos + fut_puntos;
}

void EscribirNumEq(void)
{
	FILE *F;

	F = fopen("file_num_eq.bin", "w");

	fseek(F, 0, SEEK_SET);
	fwrite(&num_equipos, sizeof(int), 1, F);

	fclose(F);

}
void LeerNumEq(void)
{
	FILE *F;

	F = fopen("file_num_eq.bin", "r");

	fseek(F, 0, SEEK_SET);
	fread(&num_equipos, sizeof(int), 1, F);

	fclose(F);
}

/*void OrdenarEquipos(void)
{
	int i, j, temp_id;
	double temp_val;

	/*for (i = 0; i < 20; i++) {
		ShowMessage(vector_eq_id_orden[i]);
	}
	for (i=1; i<20; i++)
	{
		for (j=0 ; j<20 - i; j++)
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
	for (i = 0; i < 20; i++) {
		ShowMessage(vector_eq_id_orden[i]);
	}

}

void RellenarVectores(void)
{
	int i;
	for (i = 0; i < 20; i++) {
		vector_eq_id_orden[i] = i;
		vector_eq_val_orden[i] = equipo[i].puntos_total;

		//ShowMessage(AnsiString(vector_eq_id_orden[i]) + vector_eq_val_orden[i]);
	}
} */

CEquipo equipo[20];
//---------------------------------------------------------------------------
#pragma package(smart_init)
