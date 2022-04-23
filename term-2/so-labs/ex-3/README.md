# Zadanie 3

<div style="text-align: right">Dawid Bytys Kraków 06.04.2022</div>
<br />
<br />

### O programach

- send.c (program do wysyłania sygnału za pomocą funkcji kill oraz za otwierania drugiego programu przy pomocy funkcji execl)
- signal.c (program, który handluje sygnały)
- group.c (program, który uruchamia wątki i nadaje im lidera grupy oraz wysyła sygnały)

### 1. Kompilacja

<br />

```bash
$ make all
```

<br />

### 2. Uruchomienie

<br />

a) program a

```bash
$ make run_send signal_type=<d/i/p> signal_num=<signal_number>
```

b) program c

```bash
$ make run_group signal_type=<d/i/p> signal_num=<signal_number>
```
