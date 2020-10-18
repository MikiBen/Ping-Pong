//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *paletka1;
        TImage *paletka2;
        TImage *pilka;
        TShape *tlo;
        TButton *Button1;
        TTimer *TimerPilka;
        TTimer *TimerGora;
        TTimer *TimerDol;
        TTimer *TimerLGora;
        TTimer *TimerLDol;
        TLabel *dlaKogoPunkt;
        TLabel *wynik;
        TShape *Shape1;
        TLabel *nrunda;
        TLabel *nowaGra;
        TLabel *odbicia;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall TimerDolTimer(TObject *Sender);
        void __fastcall TimerGoraTimer(TObject *Sender);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall TimerLGoraTimer(TObject *Sender);
        void __fastcall TimerLDolTimer(TObject *Sender);
        void __fastcall TimerPilkaTimer(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall nrundaClick(TObject *Sender);
        void __fastcall nowaGraClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
