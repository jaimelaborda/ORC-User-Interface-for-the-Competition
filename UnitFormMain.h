//---------------------------------------------------------------------------

#ifndef UnitFormMainH
#define UnitFormMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
	TButton *Button_Exit;
	TMainMenu *MainMenu;
	TGroupBox *Pruebas;
	TButton *ButtonVelo;
	TButton *ButtonSelectores;
	TButton *ButtonLaberinto;
	TMenuItem *Archivo1;
	TMenuItem *Pruebas1;
	TMenuItem *Info1;
	TMenuItem *Manualfunciones1;
	TMenuItem *Sobre1;
	TMenuItem *Velocistas1;
	TMenuItem *Laberinto1;
	TMenuItem *Salir1;
	TImage *Image_logoORC;
	TButton *Button_loguear;
	TButton *ButtonConfigEq;
	TImage *Image1;
	TGroupBox *GroupBoxHerramientas;
	TButton *ButtonDisplayPtoTotal;
	TGroupBox *GroupBoxDisplay;
	TButton *ButtonActVal;
	TGroupBox *GroupBox1;
	TButton *ButtonCronoAct;
	TButton *ButtonCronoReset;
	TLabel *Label1;
	void __fastcall Salir1Click(TObject *Sender);
	void __fastcall Button_ExitClick(TObject *Sender);
	void __fastcall ButtonVeloClick(TObject *Sender);
	void __fastcall Sobre1Click(TObject *Sender);
	void __fastcall ButtonSelectoresClick(TObject *Sender);
	void __fastcall ButtonConfigEqClick(TObject *Sender);
	void __fastcall Button_loguearClick(TObject *Sender);
	void __fastcall ButtonDisplayPtoTotalClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall ButtonLaberintoClick(TObject *Sender);
	void __fastcall ButtonActValClick(TObject *Sender);
	void __fastcall ButtonCronoResetClick(TObject *Sender);
	void __fastcall ButtonCronoActClick(TObject *Sender);
	void __fastcall Manualfunciones1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
