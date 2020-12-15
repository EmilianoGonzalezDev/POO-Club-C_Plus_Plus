object FormConfiguraciones: TFormConfiguraciones
  Left = 0
  Top = 0
  Caption = 'Configuraciones'
  ClientHeight = 284
  ClientWidth = 387
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
  object lbMontoCuota: TLabel
    Left = 24
    Top = 32
    Width = 139
    Height = 13
    Caption = 'Monto actual de cuota: $'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lbMaxCuotas: TLabel
    Left = 24
    Top = 82
    Width = 194
    Height = 13
    Caption = 'Marcar como deudor y dar de baja'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 24
    Top = 96
    Width = 176
    Height = 13
    Caption = 'cuando la deuda en cuotas sea:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lbGenerarCuota: TLabel
    Left = 24
    Top = 138
    Width = 165
    Height = 13
    Caption = 'Generar Cuota el dia n'#250'mero:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label1: TLabel
    Left = 24
    Top = 154
    Width = 71
    Height = 13
    Caption = 'de cada mes'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lboxMontoCuota: TListBox
    Left = 232
    Top = 27
    Width = 48
    Height = 25
    TabStop = False
    Enabled = False
    ExtendedSelect = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ItemHeight = 13
    ParentFont = False
    TabOrder = 0
  end
  object btEditarMonto: TButton
    Left = 299
    Top = 27
    Width = 74
    Height = 25
    Caption = 'Editar'
    TabOrder = 1
    OnClick = btEditarMontoClick
  end
  object btListo: TBitBtn
    Left = 304
    Top = 233
    Width = 75
    Height = 43
    Hint = 'dar de alta al nuevo socio'
    Caption = 'Listo'
    Kind = bkOK
    NumGlyphs = 2
    ParentShowHint = False
    ShowHint = True
    TabOrder = 6
    OnClick = btListoClick
  end
  object lboxMaxDeuda: TListBox
    Left = 232
    Top = 82
    Width = 48
    Height = 25
    TabStop = False
    Enabled = False
    ExtendedSelect = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ItemHeight = 13
    ParentFont = False
    TabOrder = 2
  end
  object btEditarMaxDeuda: TButton
    Left = 299
    Top = 82
    Width = 75
    Height = 25
    Caption = 'Editar'
    TabOrder = 3
    OnClick = btEditarMaxDeudaClick
  end
  object btEditarDiaCuota: TButton
    Left = 299
    Top = 138
    Width = 75
    Height = 25
    Caption = 'Editar'
    TabOrder = 5
    OnClick = btEditarDiaCuotaClick
  end
  object lboxDiaCuota: TListBox
    Left = 232
    Top = 138
    Width = 48
    Height = 25
    Enabled = False
    ExtendedSelect = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ItemHeight = 13
    ParentFont = False
    TabOrder = 4
  end
  object btEditarPass: TButton
    Left = 24
    Top = 233
    Width = 209
    Height = 25
    Caption = 'EditarContrase'#241'a de Administrador'
    TabOrder = 7
    OnClick = btEditarPassClick
  end
end
