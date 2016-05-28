//---------------------------------------------------------------------------

#ifndef UnitFormConfigEquiposH
#define UnitFormConfigEquiposH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TFormConfigEquipos : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label9;
	TImage *Image1;
	TComboBox *ComboBox_Equipos;
	TButton *Button_Exit;
	TButton *Button_guardar;
	TEdit *EditNombre;
	TButton *ButtonActualizar;
	TLabel *Label2;
	TButton *ButtonInitEquipos;
	TLabel *Label3;
	TEdit *EditNumEq;
	TButton *ButtonNumEq;
	TLabeledEdit *LabeledEditSumo;
	TLabeledEdit *LabeledEditFutbol;
	TLabeledEdit *LabeledEditTotal;
	void __fastcall ButtonActualizarClick(TObject *Sender);
	void __fastcall ButtonInitEquiposClick(TObject *Sender);
	void __fastcall Button_guardarClick(TObject *Sender);
	void __fastcall ComboBox_EquiposChange(TObject *Sender);
	void __fastcall Button_ExitClick(TObject *Sender);
	void __fastcall ButtonNumEqClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormConfigEquipos(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormConfigEquipos *FormConfigEquipos;
//---------------------------------------------------------------------------
#endif
