object Form_Main: TForm_Main
  Left = 797
  Top = 296
  Width = 779
  Height = 613
  Caption = 'Build List Utility'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel: TPanel
    Left = 0
    Top = 0
    Width = 771
    Height = 41
    Align = alTop
    TabOrder = 0
    object Button_LoadTemplate: TButton
      Left = 8
      Top = 8
      Width = 89
      Height = 25
      Caption = 'Load Template'
      TabOrder = 0
      OnClick = Button_LoadTemplateClick
    end
    object Button_SelectFiles: TButton
      Left = 104
      Top = 8
      Width = 75
      Height = 25
      Caption = 'Select Files'
      TabOrder = 1
      OnClick = Button_SelectFilesClick
    end
    object Button_Save: TButton
      Left = 184
      Top = 8
      Width = 75
      Height = 25
      Caption = 'Save'
      TabOrder = 2
    end
  end
  object PageControl: TPageControl
    Left = 0
    Top = 41
    Width = 771
    Height = 538
    ActivePage = TabSheet_Template
    Align = alClient
    TabIndex = 0
    TabOrder = 1
    object TabSheet_Template: TTabSheet
      Caption = 'Template'
      object Memo_Template: TMemo
        Left = 0
        Top = 0
        Width = 763
        Height = 510
        Align = alClient
        Lines.Strings = (
          'Memo_Template')
        TabOrder = 0
      end
    end
    object TabSheet_Output: TTabSheet
      Caption = 'Output'
      ImageIndex = 1
      object Memo_Output: TMemo
        Left = 0
        Top = 0
        Width = 763
        Height = 510
        Align = alClient
        Lines.Strings = (
          'Memo_Output')
        ScrollBars = ssBoth
        TabOrder = 0
        WordWrap = False
      end
    end
  end
  object OpenDialog: TOpenDialog
    Options = [ofAllowMultiSelect, ofPathMustExist, ofFileMustExist, ofEnableSizing]
    Left = 272
    Top = 8
  end
end
