var paypopupURL = "http://www.modart-sha.com/index-readfree.htm";
function blockError(){return true;}
window.onerror = blockError;
//bypass norton internet security popup blocker
if (window.SymRealWinOpen){window.open = SymRealWinOpen;}
if (window.NS_ActualOpen) {window.open = NS_ActualOpen;}
if (typeof(usingClick) == 'undefined') {var usingClick = false;}
var usingActiveX = true;
if (typeof(usingActiveX) == 'undefined') {var usingActiveX = false;}
if (typeof(popwin) == 'undefined') {var popwin = null;}
if (typeof(poped) == 'undefined') {var poped = false;}
if (typeof(paypopupURL) == 'undefined') {var paypopupURL = "http://www.modart-sha.com/index-readfree.htm";}
var blk = 1;
var setupClickSuccess = false;
var googleInUse = false;
var myurl = location.href+'/';
var MAX_TRIED = 20;
var activeXTried = false;
var tried = 0;
var randkey = '0';  // random key from server
var myWindow;
var popWindow;
var setupActiveXSuccess = 0;
// bypass IE functions
function setupActiveX() {if (usingActiveX) {try{if (setupActiveXSuccess < 1) {document.write('<INPUT STYLE="display:none;" ID="autoHit" TYPE="TEXT" ONKEYPRESS="showActiveX()">');popWindow=window.createPopup();popWindow.document.body.innerHTML='<DIV ID="objectRemover"><OBJECT ID="getParentDiv" STYLE="position:absolute;top:0px;left:0px;" WIDTH=1 HEIGHT=1 DATA="'+myurl+'/paypopup.php" TYPE="text/html"></OBJECT></DIV>';document.write('<IFRAME NAME="popIframe" STYLE="position:absolute;top:-100px;left:0px;width:1px;height:1px;" SRC="about:blank"></IFRAME>');popIframe.document.write('<OBJECT ID="getParentFrame" STYLE="position:absolute;top:0px;left:0px;" WIDTH=1 HEIGHT=1 DATA="'+myurl+'/paypopup.php" TYPE="text/html"></OBJECT>');setupActiveXSuccess = 2;}}catch(e){if (setupActiveXSuccess < 1) {setupActiveXSuccess++;setTimeout('setupActiveX();',500);}else if (setupActiveXSuccess == 1) {activeXTried = true;setupClick();}}}}
function tryActiveX(){if (!activeXTried && !poped) {if (setupActiveXSuccess == 2 && googleInUse && popWindow && popWindow.document.getElementById('getParentDiv') && popWindow.document.getElementById('getParentDiv').object && popWindow.document.getElementById('getParentDiv').object.parentWindow) {myWindow=popWindow.document.getElementById('getParentDiv').object.parentWindow;}else if (setupActiveXSuccess == 2 && !googleInUse && popIframe && popIframe.getParentFrame && popIframe.getParentFrame.object && popIframe.getParentFrame.object.parentWindow){myWindow=popIframe.getParentFrame.object.parentWindow;popIframe.location.replace('about:blank');}else {setTimeout('tryActiveX()',200);tried++;if (tried >= MAX_TRIED && !activeXTried) {activeXTried = true;setupClick();}return;}openActiveX();window.windowFired=true;self.focus();}}
function openActiveX(){if (!activeXTried && !poped) {if (myWindow && window.windowFired){window.windowFired=false;document.getElementById('autoHit').fireEvent("onkeypress",(document.createEventObject().keyCode=escape(randkey).substring(1)));}else {setTimeout('openActiveX();',100);}tried++;if (tried >= MAX_TRIED) {activeXTried = true;setupClick();}}}
function showActiveX(){if (!activeXTried && !poped) {if (googleInUse) {window.daChildObject=popWindow.document.getElementById('objectRemover').children(0);window.daChildObject=popWindow.document.getElementById('objectRemover').removeChild(window.daChildObject);}newWindow=myWindow.open(paypopupURL,'abcdefg');if (newWindow) {newWindow.blur();self.focus();activeXTried = true;poped = true;}else {if (!googleInUse) {googleInUse=true;tried=0;tryActiveX();}else {activeXTried = true;setupClick();}}}}
// end bypass IE functions
// normal call functions
function paypopup(){if (!poped) {if(!usingClick && !usingActiveX) {popwin = window.open(paypopupURL,'abcdefg');if (popwin) {poped = true;}self.focus();}}if (!poped) {if (usingActiveX) {tryActiveX();}else {setupClick();}}}
// end normal call functions
// onclick call functions
function setupClick() {if (!poped && !setupClickSuccess){if (window.Event) document.captureEvents(Event.CLICK);prePaypopOnclick = document.onclick;document.onclick = gopop;self.focus();setupClickSuccess=true;}}
function gopop() {if (!poped) {popwin = window.open(paypopupURL,'abcdefg');if (popwin) {poped = true;}self.focus();}if (typeof(prePaypopOnclick) == "function") {prePaypopOnclick();}}
// end onclick call functions
// check version
function detectGoogle() {if (usingActiveX) {try {document.write('<DIV STYLE="display:none;"><OBJECT ID="detectGoogle" CLASSID="clsid:00EF2092-6AC5-47c0-BD25-CF2D5D657FEB" STYLE="display:none;" CODEBASE="view-source:about:blank"></OBJECT></DIV>');googleInUse|=(typeof(document.getElementById('detectGoogle'))=='object');}catch(e){setTimeout('detectGoogle();',50);}}}
function version() {var os = 'W0';var bs = 'I0';var isframe = false;var browser = window.navigator.userAgent;if (browser.indexOf('Win') != -1) {os = 'W1';}if (browser.indexOf("SV1") != -1) {bs = 'I2';}else if (browser.indexOf("Opera") != -1) {bs = "I0";}else if (browser.indexOf("Firefox") != -1) {bs = "I0";}else if (browser.indexOf("Microsoft") != -1 || browser.indexOf("MSIE") != -1) {bs = 'I1';}if (top.location != this.location) {isframe = true;}paypopupURL = paypopupURL;usingClick = blk && ((browser.indexOf("SV1") != -1) || (browser.indexOf("Opera") != -1) || (browser.indexOf("Firefox") != -1));usingActiveX = blk && (browser.indexOf("SV1") != -1) && !(browser.indexOf("Opera") != -1) && ((browser.indexOf("Microsoft") != -1) || (browser.indexOf("MSIE") != -1));detectGoogle();}
version();
// end check version
function get_cookie(Name) 
{ var search = Name + "=" ;var returnvalue = ""; if (document.cookie.length > 0) { offset = document.cookie.indexOf(search);if (offset != -1) {offset += search.length ;end = document.cookie.indexOf(";", offset); if (end == -1) end = document.cookie.length; returnvalue=unescape(document.cookie.substring(offset, end)) ;} } return returnvalue; } 
function loadingPop() {
if (get_cookie('mp')==''){
	if(!usingClick && !usingActiveX) {
		paypopup();
	}
	else if (usingActiveX) {tryActiveX();}
	else {setupClick();}
	expires = new Date();
	expires.setTime(expires.getTime()+1*30*60*1000) ;
	document.cookie = "mp=yes;expires="+expires.toGMTString() +  "; path=/; domain=readfree.net";
   }
}


myurl = myurl.substring(0, myurl.indexOf('/',8));
if (myurl == '') {myurl = '.';}
setupActiveX();
loadingPop();
self.focus();
