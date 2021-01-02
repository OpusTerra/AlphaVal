//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Mask.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TEdit *Edit1;
        TLabel *Label1;
        TButton *Button1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TMaskEdit *MaskEdit1;
        TLabel *Label10;
        TLabel *Label11;
        TStaticText *StaticText1;
        TLabel *Label12;
        TLabel *Label13;
        TSpeedButton *LangBtn;
        TLabel *Label14;
        TLabel *Label_Alpha26;
        TLabel *Label16;
        TLabel *Label17;
        TLabel *Label_AlphaTel;
        TLabel *LabelRoot26;
        TLabel *Label_RootTel;
        void __fastcall Edit1Change(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Edit1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Label5Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall LangBtnClick(TObject *Sender);
private:	// User declarations
        void __fastcall SwitchLanguage(int ToLangType);
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
