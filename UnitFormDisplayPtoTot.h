//---------------------------------------------------------------------------

#ifndef UnitFormDisplayPtoTotH
#define UnitFormDisplayPtoTotH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ValEdit.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TFormDisplayPtoTot : public TForm
{
__published:	// IDE-managed Components
	TTimer *TimerAct;
	TListView *ListView;
	TTimer *TimerCrono;
	TLabel *LabelCrono;
	TImage *Image1;
	TImage *Image_logoORC;
	TLabel *Label1;
	TLabel *Label2;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall TimerCronoTimer(TObject *Sender);
	void __fastcall TimerActTimer(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TFormDisplayPtoTot(TComponent* Owner);
};
void ResetCrono(void);
//---------------------------------------------------------------------------
extern PACKAGE TFormDisplayPtoTot *FormDisplayPtoTot;
//---------------------------------------------------------------------------
#endif
