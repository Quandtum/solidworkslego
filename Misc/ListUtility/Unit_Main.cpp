//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit_Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_Main *Form_Main;
//---------------------------------------------------------------------------
__fastcall TForm_Main::TForm_Main(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_Main::Button_SelectFilesClick(TObject *Sender)
{
  int Index;
  AnsiString FileName;
  AnsiString FileExt;

  // Set our open dialog options.
  OpenDialog->Options.Clear();
  OpenDialog->Options << ofAllowMultiSelect << ofPathMustExist << ofFileMustExist;

  // Execute our open dialog.
  if (OpenDialog->Execute())
  {
    // Start our output.
    OutputStart();

    // Fill in each entry.
    for (Index = 0; Index < OpenDialog->Files->Count; Index++)
    {
      // Get our file name.
      FileName = ExtractFileName(OpenDialog->Files->Strings[Index]);

      // Get our extension.
      FileExt = ExtractFileExt(OpenDialog->Files->Strings[Index]);

      // Strip the extension from our file name.
      FileName.Delete((FileName.Length() - FileExt.Length() + 1), FileExt.Length());

      // Spit out our template entry.
      OutputEntry(FileName, FileExt);
    }

    // Finish off our output.
    OutputEnd();
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm_Main::Button_LoadTemplateClick(TObject *Sender)
{
  // Set our open dialog options.
  OpenDialog->Options.Clear();
  OpenDialog->Options << ofPathMustExist << ofFileMustExist;

  // Execute our open dialog.
  if (OpenDialog->Execute())
  {
    Memo_Template->Clear();
    Memo_Template->Lines->LoadFromFile(OpenDialog->FileName);
  }
}
//---------------------------------------------------------------------------
void TForm_Main::OutputStart(void)
{
  AnsiString Line;
  int Index;
  Boolean Copy;

  // Clear the output, start fresh.
  Memo_Output->Clear();

  // Blit the contained portions of <TemplateHeader></TemplateHeader> tag
  // pair to our output.
  Copy = false;
  for (Index = 0; Index < Memo_Template->Lines->Count; Index++)
  {
    // Get our current line to work with.
    Line = Memo_Template->Lines->Strings[Index];

    // Check what to do.
    if (Line == "<TemplateHeader>")           Copy = true;
    else if (Line == "</TemplateHeader>")     Copy = false;
    else if (Copy == true)
      Memo_Output->Lines->Add(Line);
  }
}
//---------------------------------------------------------------------------
void TForm_Main::OutputEntry(AnsiString FileName, AnsiString FileExt)
{
  AnsiString Line;
  int Index;
  int Pos;
  Boolean Copy;

  // Blit the contained portions of <TemplateEntry></TemplateEntry> tag
  // pair to our output.
  Copy = false;
  for (Index = 0; Index < Memo_Template->Lines->Count; Index++)
  {
    // Get our current line to work with.
    Line = Memo_Template->Lines->Strings[Index];

    // Check what to do.
    if (Line == "<TemplateEntry>")           Copy = true;
    else if (Line == "</TemplateEntry>")     Copy = false;
    else if (Copy == true)
    {
      ReplaceAll(Line, "%FILENAME%", FileName);
      ReplaceAll(Line, "%EXT%", FileExt);
      Memo_Output->Lines->Add(Line);
    }
  }
}
//---------------------------------------------------------------------------
void TForm_Main::OutputEnd(void)
{
  AnsiString Line;
  int Index;
  Boolean Copy;

  // Blit the contained portions of <TemplateFooter></TemplateFooter> tag
  // pair to our output.
  Copy = false;
  for (Index = 0; Index < Memo_Template->Lines->Count; Index++)
  {
    // Get our current line to work with.
    Line = Memo_Template->Lines->Strings[Index];

    // Check what to do.
    if (Line == "<TemplateFooter>")           Copy = true;
    else if (Line == "</TemplateFooter>")     Copy = false;
    else if (Copy == true)
      Memo_Output->Lines->Add(Line);
  }
}
//---------------------------------------------------------------------------
void TForm_Main::ReplaceAll(AnsiString &Line, AnsiString From, AnsiString To)
{
  int Pos;
  // Replace all occurances of 'From' to 'To'.
  do
  {
    Pos = Line.Pos(From);
    if (Pos != 0)
    {
      Line.Delete(Pos, From.Length());
      Line.Insert(To, Pos);
    }
  } while (Pos != 0);
}
//---------------------------------------------------------------------------
