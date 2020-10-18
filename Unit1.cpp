//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//void skucha();


TForm1 *Form1;


int x=-4;
int y=-4;

int liczbaOdbic=0;
int punktyLewego=0;
int punktyPrawego=0;
int zdobywcaPunktu=0;

 void skucha()
{
         if(zdobywcaPunktu==1)
         {
                Form1->dlaKogoPunkt -> Caption = "Punkt dla gracza prawego ->";
                }
          else  {
          Form1->dlaKogoPunkt->Caption = " <- Punkt dla gracza lewgo ";
               }
         AnsiString wynikLewego, wynikPrawego, iloscOdbic;
          wynikLewego = IntToStr(punktyLewego);
          wynikPrawego = IntToStr(punktyPrawego);

        Form1-> wynik->Caption =  wynikLewego + " : "  + wynikPrawego;
           iloscOdbic = IntToStr(liczbaOdbic);
        Form1->odbicia->Caption = "Iloœæ odbiæ: " +  iloscOdbic;

        Form1->dlaKogoPunkt->Left = Form1->tlo->Width/2-Form1->dlaKogoPunkt->Width/2;
        Form1->wynik->Left = Form1->tlo->Width/2-Form1->wynik->Width/2;
        Form1->odbicia->Left = Form1->tlo->Width/2-Form1->odbicia->Width/2;
        Form1->nrunda->Left = Form1->tlo->Width/2-Form1->nrunda->Width/2;
        Form1->nowaGra->Left= Form1->tlo->Width/2-Form1->nowaGra->Width/2;

        Form1->dlaKogoPunkt->Top = 10;
        Form1->wynik->Top = 60;
        Form1->odbicia->Top = 110;
        Form1->nrunda->Top = 180;
        Form1->nowaGra->Top = 230;
         x=-4;
         y=-4;




        Form1->nowaGra->Enabled=true;
        Form1->nrunda->Enabled=true;

        Form1->dlaKogoPunkt->Visible=true;
        Form1->nowaGra->Visible=true;
        Form1->nrunda->Visible=true;
        Form1->odbicia->Visible=true;
        Form1->wynik->Visible=true;
}



//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        dlaKogoPunkt->Visible=false;
        nowaGra->Visible=false;
        nrunda->Visible=false;
        odbicia->Visible=false;
        wynik->Visible=false;

        Form1->nowaGra->Enabled=false;
        Form1->nrunda->Enabled=false;

         Button1->Left= tlo->Width/2-Button1->Width/2;
         Button1->Top = 10;



}




//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{

        paletka1->Top = tlo->Height/2 -paletka1->Height/2 ;
        paletka2->Top = tlo->Height/2 -paletka2->Height/2;
        pilka->Top = tlo->Height/2 -pilka->Height/2 ;

        paletka1->Left = 50;
        paletka2->Left = tlo->Width-50-paletka2->Width;
        pilka->Left = tlo->Width/2-pilka->Width/2;

        paletka1->Visible = true;
        paletka2->Visible = true;
        pilka->Visible = true;
        Button1->Visible =false;

        TimerPilka->Enabled= true;


}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == VK_UP) TimerGora->Enabled= true;
        if(Key == VK_DOWN) TimerDol->Enabled= true;
        if(Key == 0x41) TimerLGora->Enabled= true;
        if(Key == 0x5A) TimerLDol->Enabled= true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerDolTimer(TObject *Sender)
{
          if(paletka2->Top<tlo->Height-20-paletka2->Height) paletka2->Top +=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerGoraTimer(TObject *Sender)
{
            if(paletka2->Top>20) paletka2->Top -=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == VK_UP) TimerGora->Enabled= false;
        if(Key == VK_DOWN) TimerDol->Enabled= false;
        if(Key == 0x41) TimerLGora->Enabled= false;
        if(Key == 0x5A) TimerLDol->Enabled= false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerLGoraTimer(TObject *Sender)
{
                if(paletka1->Top>20) paletka1->Top -=10;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerLDolTimer(TObject *Sender)
{
                 if(paletka1->Top<tlo->Height-20-paletka1->Height) paletka1->Top +=10;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::TimerPilkaTimer(TObject *Sender)
{
                pilka->Left +=x;
                pilka->Top +=y;

//Uderzanie od scian
               if(pilka->Top<=0) y=-y;
               if(pilka->Top>=tlo->Height-pilka->Height-5) y=-y;
               //if(pilka->Left<=0)x=-x;
              // if(pilka->Left>=tlo->Width-pilka->Width-5)x=-x;


               //uderzanie od paletki lewej
               if((pilka->Top+pilka->Height >=paletka1->Top  && pilka->Top-pilka->Height<=paletka1->Top+paletka1->Height)
               && pilka->Left<=paletka1->Left+paletka1->Width &&
                pilka->Left>=paletka1->Left+paletka1->Width - 20)
                {
                x=-x;
                if(x>0)
                x++;
                else x--;
                 liczbaOdbic++;
                zdobywcaPunktu=2;
                if(TimerPilka->Interval>1)TimerPilka->Interval--;
                }
               //uderzanie od paletki prawej
               if((pilka->Top+pilka->Height>=paletka2->Top&&pilka->Top-pilka->Height<=paletka2->Top+paletka2->Height)
               && pilka->Left+pilka->Width>=paletka2->Left &&
                pilka->Left+pilka->Width<=paletka2->Left+20)
                {
                x=-x;
                if(x>0)
                x++;
                else x--;
                liczbaOdbic++;
                zdobywcaPunktu=1;
                if(TimerPilka->Interval>2)TimerPilka->Interval--;



                }//skucha

               if(pilka->Left<=paletka1->Left-pilka->Width)
                        {
                        TimerPilka->Enabled = false;
                        punktyPrawego++;
                        skucha();
                         }
               if(pilka->Left>=paletka2->Left+paletka2->Width)
                        {
                        TimerPilka->Enabled = false;
                        punktyLewego++;
                        skucha();
                         }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{

            if(Application->MessageBox("Witaj w mojej grze :)\n\n"
                                       "Sterowanie lewej paletki A oraz Z\n"
                                       "Sterowanie prawej paletki strza³ka do gór i w dó³\n\n"
                                       "Zaczynamy ?"
            ," PingPong Miko³aja",MB_YESNO| MB_ICONQUESTION)==IDNO)
            {
             Application->Terminate();
            }
}
//---------------------------------------------------------------------------



void __fastcall TForm1::nrundaClick(TObject *Sender)
{

        dlaKogoPunkt->Visible=false;
        nowaGra->Visible=false;
        nrunda->Visible=false;
        odbicia->Visible=false;
        wynik->Visible=false;

        Form1->nowaGra->Enabled=false;
        Form1->nrunda->Enabled=false;

                pilka->Top = tlo->Height/2 -pilka->Height/2 ;
                pilka->Left = tlo->Width/2-pilka->Width/2;
                liczbaOdbic=0;

                TimerPilka->Enabled= true;


}
//---------------------------------------------------------------------------

void __fastcall TForm1::nowaGraClick(TObject *Sender)
{
        dlaKogoPunkt->Visible=false;
        nowaGra->Visible=false;
        nrunda->Visible=false;
        odbicia->Visible=false;
        wynik->Visible=false;

        Form1->nowaGra->Enabled=false;
        Form1->nrunda->Enabled=false;

                pilka->Top = tlo->Height/2 -pilka->Height/2 ;
                pilka->Left = tlo->Width/2-pilka->Width/2;
                liczbaOdbic=0;
                punktyLewego=0;
                punktyPrawego=0;
                TimerPilka->Enabled= true;
}
//---------------------------------------------------------------------------

