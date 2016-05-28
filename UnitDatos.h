//---------------------------------------------------------------------------

#ifndef UnitDatosH
#define UnitDatosH
//---------------------------------------------------------------------------
#define MAX_NOMBRE 20

#include <vector>
#include <vcl.h>
using namespace std;


//---------------------------------------------------------------------------

int num_equipos = 14;
//int vector_eq_id_orden[20];
//double vector_eq_val_orden[20];

void EscribirNumEq(void);
void LeerNumEq(void);
void OrdenarEquipos(void);
void RellenarVectores(void);

void LeerArchivoTodo(void);
void GuardarArchivoTodo(void);


class CVelocistas
{
 public:
	int vel_atajo, vel_obs_tunel, vel_obs_puente, vel_curvas, vel_best;  //Bonus
	int vel_sal_parcial, vel_sal_completa, vel_boxes, vel_completa_and_boxes; //SANCIONES
	double vel_tiempo1, vel_tiempo2;
	double vel_puntos;

};

class CSelectores
{
public:
	int sel_snitch_dorada, sel_piezas_negras; //BONUS
	int sel_piezas_blancas, sel_sal_completa, sel_boxes, sel_completa_and_boxes; //SANCIONES
	double sel_tiempo1;
	double sel_puntos;
};

class CLaberinto
{
public:
	int lab_best; //BONUS
	int lab_sal_completa, lab_boxes, lab_completa_and_boxes; //SANCIONES
	double lab_tiempo1, lab_tiempo2, lab_tiempo3;
	double lab_puntos;
};

class CEquipo : public CVelocistas, public CSelectores, public CLaberinto    //Herencia
{
public:
	int id_equipo;
	char nombre[MAX_NOMBRE];
	double sum_puntos, fut_puntos;
	double puntos_total;

	//Metodos publicos
	void NuevoEquipo(void);
	void LeerArchivo(int id_file);
	void GuardarArchivo(int id_file);
	void SumPuntosTotal(void);
};



//vector <CEquipo*> Equipos;
//CEquipo *NuevoEquipo;

extern CEquipo equipo[20];
//---------------------------------------------------------------------------
#endif
