object FormPass: TFormPass
  Left = 0
  Top = 0
  Caption = 'Contrase'#241'a'
  ClientHeight = 153
  ClientWidth = 352
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 23
    Width = 308
    Height = 19
    Caption = 'Ingrese contrase'#241'a de Administrador '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object ePass: TEdit
    Left = 24
    Top = 48
    Width = 303
    Height = 21
    MaxLength = 20
    NumbersOnly = True
    TabOrder = 0
  end
  object btAceptar: TButton
    Left = 214
    Top = 88
    Width = 113
    Height = 49
    Cursor = crHandPoint
    Caption = 'Aceptar'
    Default = True
    ElevationRequired = True
    TabOrder = 1
    OnClick = btAceptarClick
  end
  object btCancelar: TButton
    Left = 24
    Top = 88
    Width = 113
    Height = 49
    Cursor = crHandPoint
    Caption = 'Cancelar'
    TabOrder = 2
    OnClick = btCancelarClick
  end
end
