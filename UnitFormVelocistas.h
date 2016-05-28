//---------------------------------------------------------------------------

#ifndef UnitFormVelocistasH
#define UnitFormVelocistasH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.DockTabSet.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Tabs.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TFormVelocistas : public TForm
{
__published:	// IDE-managed Components
	TComboBox *ComboBox_Equipos;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label_PtoTot;
	TLabel *Label6;
	TButton *Button_Exit;
	TButton *Button_calc;
	TButton *Button_guardar;
	TEdit *Edit_Temp1;
	TEdit *Edit_Temp2;
	TGroupBox *GroupBox_Bonus;
	TCheckBox *CheckBoxAtajo;
	TCheckBox *CheckBoxTunel;
	TCheckBox *CheckBoxPuente;
	TCheckBox *CheckBoxCurvas;
	TCheckBox *CheckBoxBest;
	TGroupBox *GroupBox1;
	TLabel *Label4;
	TEdit *Edit_SalPar;
	TUpDown *UpDownSalPar;
	TUpDown *UpDownSalComp;
	TUpDown *UpDownSalBox;
	TUpDown *UpDownBoxComp;
	TEdit *Edit_SalComp;
	TEdit *Edit_SalCompBox;
	TLabel *Label5;
	TLabel *Label7;
	TLabel *Label8;
	TGroupBox *GroupBox2;
	TLabel *Label9;
	TLabel *Label10;
	TEdit *Edit_SalBox;
	TImage *Image1;
	void __fastcall Button_ExitClick(TObject *Sender);
	void __fastcall ComboBox_EquiposChange(TObject *Sender);
	void __fastcall Button_guardarClick(TObject *Sender);
	void __fastcall Button_calcClick(TObject *Sender);
	void __fastcall UpDownSalParChangingEx(TObject *Sender, bool &AllowChange, int NewValue,
          TUpDownDirection Direction);
	void __fastcall UpDownSalCompChangingEx(TObject *Sender, bool &AllowChange, int NewValue,
          TUpDownDirection Direction);
	void __fastcall UpDownSalBoxChangingEx(TObject *Sender, bool &AllowChange, int NewValue,
          TUpDownDirection Direction);
	void __fastcall UpDownBoxCompChangingEx(TObject *Sender, bool &AllowChange, int NewValue,
          TUpDownDirection Direction);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormVelocistas(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormVelocistas *FormVelocistas;
//---------------------------------------------------------------------------
#endif
