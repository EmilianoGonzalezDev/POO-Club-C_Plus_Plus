object FormListaDePagos: TFormListaDePagos
  Left = 0
  Top = 0
  Caption = 'Lista De Pagos'
  ClientHeight = 618
  ClientWidth = 527
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
  object grillaPagos: TStringGrid
    Left = 8
    Top = 8
    Width = 513
    Height = 602
    Ctl3D = True
    DefaultColWidth = 100
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    ParentCtl3D = False
    ScrollBars = ssVertical
    TabOrder = 0
  end
end
