//---------------------------------------------------------------------------

#ifndef Unit_MainH
#define Unit_MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm_Main : public TForm
{
__published:	// IDE-managed Components
  TOpenDialog *OpenDialog;
  TPanel *Panel;
  TButton *Button_LoadTemplate;
  TButton *Button_SelectFiles;
  TPageControl *PageControl;
  TTabSheet *TabSheet_Template;
  TTabSheet *TabSheet_Output;
  TMemo *Memo_Template;
  TMemo *Memo_Output;
  TButton *Button_Save;
  void __fastcall Button_SelectFilesClick(TObject *Sender);
  void __fastcall Button_LoadTemplateClick(TObject *Sender);
private:	// User declarations
  void OutputStart(void);
  void OutputEntry(AnsiString FileName, AnsiString FileExt);
  void OutputEnd(void);
  void ReplaceAll(AnsiString &Line, AnsiString From, AnsiString To);
public:		// User declarations
  __fastcall TForm_Main(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_Main *Form_Main;
//---------------------------------------------------------------------------
#endif
