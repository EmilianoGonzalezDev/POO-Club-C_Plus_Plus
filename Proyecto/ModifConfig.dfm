object FormModifConfig: TFormModifConfig
  Left = 0
  Top = 0
  Caption = 'Modificar Valor'
  ClientHeight = 152
  ClientWidth = 268
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object lb1: TLabel
    Left = 20
    Top = 25
    Width = 71
    Height = 13
    Caption = 'Valor Actual:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lbValor: TLabel
    Left = 110
    Top = 22
    Width = 6
    Height = 16
    Caption = '-'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lb2: TLabel
    Left = 21
    Top = 51
    Width = 70
    Height = 13
    Caption = 'Nuevo Valor:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object btCancelar: TBitBtn
    Left = 18
    Top = 94
    Width = 73
    Height = 43
    Caption = 'Cancelar'
    Kind = bkCancel
    NumGlyphs = 2
    ParentShowHint = False
    ShowHint = False
    TabOrder = 0
  end
  object eNuevoValor: TEdit
    Left = 97
    Top = 48
    Width = 80
    Height = 21
    MaxLength = 7
    NumbersOnly = True
    TabOrder = 1
  end
  object btListo: TBitBtn
    Left = 175
    Top = 94
    Width = 73
    Height = 43
    Hint = 'dar de alta al nuevo socio'
    Caption = 'Listo'
    Kind = bkOK
    NumGlyphs = 2
    ParentShowHint = False
    ShowHint = True
    TabOrder = 2
    OnClick = btListoClick
  end
end
