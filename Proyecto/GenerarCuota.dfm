object FormGenerarCuota: TFormGenerarCuota
  Left = 0
  Top = 0
  Caption = 'Generar Cuota'
  ClientHeight = 354
  ClientWidth = 587
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
    Left = 16
    Top = 8
    Width = 547
    Height = 19
    Caption = 
      'Aumentar en 1 unidad la cantidad de cuotas adeudadas por los soc' +
      'ios activos'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 16
    Top = 158
    Width = 530
    Height = 19
    Caption = 
      'Reducir en 1 unidad la cantidad de cuotas adeudadas por los soci' +
      'os activos'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object lbMesUltimaCuota: TLabel
    Left = 181
    Top = 292
    Width = 11
    Height = 16
    Caption = 'M'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lbAnioUltimaCuota: TLabel
    Left = 209
    Top = 292
    Width = 10
    Height = 16
    Caption = 'A'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 16
    Top = 292
    Width = 151
    Height = 16
    Caption = #218'ltima cuota generada:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 199
    Top = 292
    Width = 8
    Height = 16
    Caption = '/'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object btGenerarCuota: TButton
    Left = 216
    Top = 33
    Width = 153
    Height = 80
    Caption = 'Generar Cuota'
    TabOrder = 0
    OnClick = btGenerarCuotaClick
  end
  object btEliminarCuota: TButton
    Left = 216
    Top = 183
    Width = 153
    Height = 42
    Caption = 'Eliminar una cuota'
    TabOrder = 1
    OnClick = btEliminarCuotaClick
  end
  object btCancelar: TBitBtn
    Left = 474
    Top = 292
    Width = 89
    Height = 38
    Caption = 'Salir'
    Kind = bkCancel
    NumGlyphs = 2
    TabOrder = 2
  end
end
