//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <stdio.h>
#include <vcl/registry.hpp>

// 4 Janv 2010: Ajout de translation pour ï et ç et ú
// 12 Janv 2010: Version bilingue
// 14 Aout 2010: Version avec inversion possible de la valeur alphabetique
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


TForm1 *Form1;
TRegistryIniFile *SettingsFile;
int LangType = 0;  // 0 == Francais, 1 = Anglais  , etc
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1Change(TObject *Sender)
{
        int i, j;
        int v = 0, StrlenAll = 0;
        int v_26 = 0;
        int LetterCounter = 0;
        char Buffer[1000];
        char ASCIIBuffer[1000];
        char ASCIIBufferTemp[100];
        char digit_only[100];
        int  valeur_decimale = 0;
        int  PhoneValue = 0;

        //Edit1->GetTextBuf(Buffer,250);
        //itoa(strlen(Buffer),Buffer,10);
        //Label8->Caption = Buffer;

        Edit1->GetTextBuf(Buffer,999);
        StrlenAll = strlen(Buffer);

        digit_only[0] = '\0';
        ASCIIBuffer[0] = '\0';
        for (i = 0, j = 0; i < strlen(Buffer); i++)
        {
                if(Buffer[i] == ' ')
                        continue;
                        
                if(Buffer[i] == 'à')
                   Buffer[i] = 'a';
                if(Buffer[i] == 'À')
                   Buffer[i] = 'a';
                if(Buffer[i] == 'â')
                   Buffer[i] = 'a';
                if(Buffer[i] == 'Â')
                   Buffer[i] = 'a';
                if(Buffer[i] == 'é')
                   Buffer[i] = 'e';

                if(Buffer[i] == 'É')  // Avril 2010: ajout des Majuscules accentuées
                   Buffer[i] = 'e';
                if(Buffer[i] == 'è')
                   Buffer[i] = 'e';
                if(Buffer[i] == 'È')
                   Buffer[i] = 'e';
                if(Buffer[i] == 'ë')
                   Buffer[i] = 'e';
                if(Buffer[i] == 'Ë')
                   Buffer[i] = 'e';
                if(Buffer[i] == 'ê')
                   Buffer[i] = 'e';
                if(Buffer[i] == 'Ê')
                   Buffer[i] = 'e';

                if(Buffer[i] == 'î')
                   Buffer[i] = 'i';
                if(Buffer[i] == 'Î')
                   Buffer[i] = 'i';
                if(Buffer[i] == 'ï')
                   Buffer[i] = 'i';
                if(Buffer[i] == 'Ï')
                   Buffer[i] = 'i';
                if(Buffer[i] == 'ì')
                   Buffer[i] = 'i';
                if(Buffer[i] == 'Ì')
                   Buffer[i] = 'i';

                if(Buffer[i] == 'ò')
                   Buffer[i] = 'o';
                if(Buffer[i] == 'Ò')
                   Buffer[i] = 'o';
                if(Buffer[i] == 'ô')
                   Buffer[i] = 'o';
                if(Buffer[i] == 'Ô')
                   Buffer[i] = 'o';
                if(Buffer[i] == 'ö')
                   Buffer[i] = 'o';
                if(Buffer[i] == 'Ö')
                   Buffer[i] = 'o';

                if(Buffer[i] == 'ù')
                   Buffer[i] = 'u';
                if(Buffer[i] == 'Ù')
                   Buffer[i] = 'u';
                if(Buffer[i] == 'û')
                   Buffer[i] = 'u';
                if(Buffer[i] == 'Û')
                   Buffer[i] = 'u';
                if(Buffer[i] == 'ú')
                   Buffer[i] = 'u';

                if(Buffer[i] == 'ç')
                   Buffer[i] = 'c';
                if(Buffer[i] == 'Ç')
                   Buffer[i] = 'c';

                if(isalpha(Buffer[i]))
                {
                        v = v + (toupper(Buffer[i])-0x40);
                        // ajout Aout 2010 pour valeur inverse de la valeur alpha : ie: a = 26, b = 25 etc ...
                        v_26 = v_26 + 27 -((toupper(Buffer[i])-0x40));
                        LetterCounter++;
                }
                if(isdigit(Buffer[i]))
                {
                        valeur_decimale = valeur_decimale + (Buffer[i] - 0x30);
                        digit_only[j++] = Buffer[i];
                        digit_only[j] = '\0';
                }

                sprintf(ASCIIBufferTemp,"%d ", (unsigned int)Buffer[i] > 127 ? 256 + (unsigned int)Buffer[i] : (unsigned int)Buffer[i]);
                strcat(ASCIIBuffer,ASCIIBufferTemp);

                // evaluer la valeur numerique telephonique des lettres
                // Ajout Aout 2010 V1.93
                switch (Buffer[i])
                {
                    	case 'A':	case 'B':	case 'C':
                    	case 'a':	case 'b':	case 'c':
                    		PhoneValue += 2;
                    		break;
                    	case 'D': case 'E': case 'F':
                    	case 'd': case 'e': case 'f':
                    		PhoneValue += 3;
                    		break;
                    	case 'G': case 'H': case 'I':
                    	case 'g': case 'h': case 'i':
                    		PhoneValue += 4;
                    		break;
                    	case 'J': case 'K': case 'L':
                    	case 'j': case 'k': case 'l':
                    		PhoneValue += 5;
                    		break;
                    	case 'M': case 'N': case 'O':
                    	case 'm': case 'n': case 'o':
                    		PhoneValue += 6;
                    		break;
                    	case 'P': case 'Q': case 'R': case 'S':
                    	case 'p': case 'q': case 'r': case 's':
                    		PhoneValue += 7;
                    		break;
                    	case 'T': case 'U': case 'V':
                    	case 't': case 'u': case 'v':
                    		PhoneValue += 8;
                    		break;
                    	case 'W': case 'X': case 'Y': case 'Z':
                    	case 'w': case 'x': case 'y': case 'z':
                    		PhoneValue += 9;
                    		break;
                }
        }

        // Changement July 8, 2006
        itoa(LetterCounter,Buffer,10);
        //Label8->Caption = Buffer;
        sprintf(Buffer,"%d / %d / %d",LetterCounter,strlen(digit_only),StrlenAll);
        Label8->Caption = Buffer;

        itoa(v,Buffer,10);
        Label1->Caption = Buffer;

        itoa(v_26,Buffer,10);
        Label_Alpha26->Caption = Buffer;

        itoa(PhoneValue,Buffer,10);
        Label_AlphaTel->Caption = Buffer;

        itoa(valeur_decimale,Buffer,10);
        Label4->Caption = Buffer;

        v = 0;
        if(strlen(digit_only) == 1)
           v = digit_only[0] - 0x30;
        else
        {
           while(strlen(digit_only) > 1)
           {
                for(i = 0, v = 0; i < strlen(digit_only); i++)
                {
                        v = v + (digit_only[i] - 0x30);
                }
                itoa(v,digit_only,10);
           }
        }

        itoa(v,digit_only,10);
        Label7->Caption = digit_only;

        Edit1->GetTextBuf(Buffer,250);
        strrev(Buffer);
        MaskEdit1->Text = Buffer;

        StaticText1->Caption = ASCIIBuffer;

        // Cas du digital root mixt
        // On va prendre les digits de la valeur alpha du texte et les coupler avec ceux du digital root
        // et refaire un digital root avec le tout
        // exemple: zephyr064: alpha=98 dr = 1 et drmix sur 981 = 9
        strcpy(digit_only,Label1->Caption.c_str());
        strcat(digit_only,Label7->Caption.c_str());
        //Label13->Caption = digit_only;

        v = 0;
        if(strlen(digit_only) == 1)
           v = digit_only[0] - 0x30;
        else
        {
           while(strlen(digit_only) > 1)
           {
                for(i = 0, v = 0; i < strlen(digit_only); i++)
                {
                        v = v + (digit_only[i] - 0x30);
                }
                itoa(v,digit_only,10);
           }
        }
        itoa(v,digit_only,10);
        Label13->Caption = digit_only;

        // Idem root mix pour cas a=26
        strcpy(digit_only,Label_Alpha26->Caption.c_str());
        strcat(digit_only,Label7->Caption.c_str());
        //Label13->Caption = digit_only;

        v = 0;
        if(strlen(digit_only) == 1)
           v = digit_only[0] - 0x30;
        else
        {
           while(strlen(digit_only) > 1)
           {
                for(i = 0, v = 0; i < strlen(digit_only); i++)
                {
                        v = v + (digit_only[i] - 0x30);
                }
                itoa(v,digit_only,10);
           }
        }
        itoa(v,digit_only,10);
        LabelRoot26->Caption = digit_only;

        // Idem root mix pour cas a=Tel
        strcpy(digit_only,Label_AlphaTel->Caption.c_str());
        strcat(digit_only,Label7->Caption.c_str());
        //Label13->Caption = digit_only;

        v = 0;
        if(strlen(digit_only) == 1)
           v = digit_only[0] - 0x30;
        else
        {
           while(strlen(digit_only) > 1)
           {
                for(i = 0, v = 0; i < strlen(digit_only); i++)
                {
                        v = v + (digit_only[i] - 0x30);
                }
                itoa(v,digit_only,10);
           }
        }
        itoa(v,digit_only,10);
        Label_RootTel->Caption = digit_only;


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
     Edit1->Text = "";
     Edit1->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == VK_RETURN)
                Edit1->Text = "";


}
//---------------------------------------------------------------------------




// retiré Dec 2020
void __fastcall TForm1::Label5Click(TObject *Sender)
{
        //ShellExecute(0, "open",  "http://opusterra.gel.usherbrooke.ca/", "", "",  SW_SHOWNORMAL);
        if (LangType == 0)
               ShellExecute(0, "open",  "http://opusterra.gel.usherbrooke.ca/Calculateur.shtml", "", "",  SW_SHOWNORMAL);
        else
                ShellExecute(0, "open",  "http://opusterra.gel.usherbrooke.ca/Calculateur.shtml#EnglishCalc", "", "",  SW_SHOWNORMAL);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
       bool x;
       SettingsFile = new TRegistryIniFile(String("Software\\") + Application->Title);
       LangType = SettingsFile->ReadInteger("Attribs", "LangType", 0);
       x = SettingsFile->ReadBool("Attribs", "Inv", false);

       SwitchLanguage(LangType);
       delete SettingsFile;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::LangBtnClick(TObject *Sender)
{
       SettingsFile = new TRegistryIniFile(String("Software\\") + Application->Title);
       // Application->MessageBox(Application->Title.c_str(), NULL, MB_OK);
       if (LangType == 0)
            SwitchLanguage(1);
       else
           SwitchLanguage(0);
       SettingsFile->WriteInteger("Attribs", "LangType", LangType);
       delete SettingsFile;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SwitchLanguage(int ToLangType)
{
        switch( ToLangType)
        {
                case 0:   // Francais
                   //LangBtn->Caption = "E";
                   Label9->Caption = "Nombre de lettres/digits/total";
                   Label2->Caption = "Total alphabétique";
                   Label3->Caption = "Addition des nombres (checksum)";
                   Label6->Caption = "Racine digitale";
                   Label12->Caption = "Racine digitale mixte";
                   Label11->Caption = "Valeurs ASCII décimales";
                   Label10->Caption = "Texte renversé";
                   Label17->Caption = "Tél.";
                   Button1->Caption = "Eff";
                   LangBtn->Glyph->LoadFromResourceName((unsigned int)HInstance, "IDB_BITMAP_UK");
                   LangType = ToLangType;
                   break;
                case 1:  // Anglais
                   //LangBtn->Caption = "F";
                   Label9->Caption ="# Letters/digits/total" ;
                   Label2->Caption = "Alpha Value";
                   Label3->Caption = "Checksum";
                   Label6->Caption = "Digital root";
                   Label12->Caption = "Joint digital root";
                   Label11->Caption = "Decimal ASCII values";
                   Label10->Caption = "Reversed text";
                   Label17->Caption = "Tel.";
                   Button1->Caption = "Clr";
                   LangBtn->Glyph->LoadFromResourceName((unsigned int)HInstance, "IDB_BITMAP_QC");
                   LangType = ToLangType;
                   break;
        }
}
//---------------------------------------------------------------------------


