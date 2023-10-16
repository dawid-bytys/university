# Czy podany kod jest poprawny składniowo w Pythonie? Jeśli nie, to dlaczego?


# 1. Kod jest poprawny składniowo, lecz nie jest to zalecana konwencja (oddzielanie średnikiem), aczkolwiek jest to dozowolone.
"""
x = 2; y = 3;
if (x > y):
    result = x;
else:
    result = y;
"""


# 2. Kod nie jest poprawny składniowo, poniewaz interpreter Pythona rozróznia bloku kodu za pomocą wcięc, a tutaj takiego brakuje po dwukropku.
"""
for i in "axby": if ord(i) < 100: print(i)
"""


# 3. Ten kod jest poprawny składniowo, uzywamy tutaj z tzw. shorthand if else
"""
for i in "axby": print(ord(i) if ord(i) < 100 else i)
"""
