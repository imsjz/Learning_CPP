_add_a_and_b:
  CPU指令   运算子
   push   %ebx 
   mov    %eax, [%esp+8] 
   mov    %ebx, [%esp+12]
   add    %eax, %ebx 
   pop    %ebx 
   ret  

_main:
   push   3
   push   2
   call   _add_a_and_b //call调用函数
   add    %esp, 8
   ret