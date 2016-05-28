//---------------------------------------------------------------------------

#ifndef UnitFormLaberintoH
#define UnitFormLaberintoH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TFormLaberinto : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label_PtoTot;
	TLabel *Label6;
	TLabel *Label9;
	TImage *Image1;
	TComboBox *ComboBox_Equipos;
	TButton *Button_Exit;
	TButton *Button_calc;
	TButton *Button_guardar;
	TGroupBox *GroupBox_Bonus;
	TCheckBox *CheckBoxBest;
	TGroupBox *GroupBox1;
	TLabel *Label5;
	TLabel *Label7;
	TLabel *Label8;
	TUpDown *UpDownSalComp;
	TUpDown *UpDownSalBox;
	TUpDown *UpDownBoxComp;
	TEdit *Edit_SalComp;
	TEdit *Edit_SalCompBox;
	TEdit *Edit_SalBox;
	TGroupBox *GroupBox2;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label10;
	TEdit *Edit_Temp1;
	TEdit *Edit_Temp2;
	TLabel *Label4;
	TEdit *Edit_Temp3;
	TLabeledEdit *LabeledEditTmax;
	TLabeledEdit *LabeledEditPtoTotal;
	TButton *ButtonPtoTotal;
	void __fastcall Button_ExitClick(TObject *Sender);
	void __fastcall ComboBox_EquiposChange(TObject *Sender);
	void __fastcall Button_guardarClick(TObject *Sender);
	void __fastcall Button_calcClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ButtonPtoTotalClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormLaberinto(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormLaberinto *FormLaberinto;
//---------------------------------------------------------------------------
#endif
