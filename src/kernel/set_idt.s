global set_idt

set_idt:
  mov eax, [esp+4]
  lidt [eax]
  ret

