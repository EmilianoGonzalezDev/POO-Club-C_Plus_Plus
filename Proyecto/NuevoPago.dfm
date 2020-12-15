object FormPago: TFormPago
  Left = 0
  Top = 0
  Caption = 'Ingresar Nuevo Pago'
  ClientHeight = 235
  ClientWidth = 297
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
  object lbNumSocio: TLabel
    Left = 32
    Top = 24
    Width = 80
    Height = 13
    Caption = 'N'#250'mero de Socio'
  end
  object lbAabonar: TLabel
    Left = 32
    Top = 54
    Width = 80
    Height = 13
    Caption = 'Cuotas a abonar'
  end
  object lbMontoTotal: TLabel
    Left = 32
    Top = 120
    Width = 110
    Height = 13
    Caption = 'Monto Total a abonar: '
  end
  object lbMontoCuota: TLabel
    Left = 32
    Top = 93
    Width = 123
    Height = 13
    Caption = 'A abonar por cada cuota:'
  end
  object lbPeso: TLabel
    Left = 160
    Top = 93
    Width = 6
    Height = 13
    Caption = '$'
  end
  object lbPeso2: TLabel
    Left = 160
    Top = 120
    Width = 6
    Height = 13
    Caption = '$'
  end
  object lbMontoActual: TLabel
    Left = 172
    Top = 93
    Width = 6
    Height = 13
    Caption = '0'
  end
  object lbAbonar: TLabel
    Left = 172
    Top = 120
    Width = 6
    Height = 13
    Caption = '0'
  end
  object eNumSocio: TEdit
    Left = 126
    Top = 21
    Width = 99
    Height = 21
    MaxLength = 7
    NumbersOnly = True
    TabOrder = 0
  end
  object btCancelar: TBitBtn
    Left = 8
    Top = 184
    Width = 73
    Height = 43
    Caption = 'Cancelar'
    Kind = bkCancel
    NumGlyphs = 2
    ParentShowHint = False
    ShowHint = False
    TabOrder = 2
  end
  object eCuotas: TEdit
    Left = 126
    Top = 48
    Width = 33
    Height = 21
    Hint = 'Cantidad de cuotas que desea pagar'
    MaxLength = 2
    NumbersOnly = True
    ParentShowHint = False
    ShowHint = True
    TabOrder = 1
    Text = '1'
    OnChange = eCuotasChange
  end
  object btListo: TButton
    Left = 214
    Top = 184
    Width = 75
    Height = 43
    Caption = 'Listo'
    TabOrder = 3
    OnClick = btListoClick
  end
end
