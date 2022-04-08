Autor: Dawid Bytys

Katalog zawiera dwa programy:

1.  Program, ktory wypisuje identyfikatory UID, GID, PID, PPID, PGID dla danego procesu. (get_ids.c)
2.  Program, ktory wypisuje identyfikatory dla procesu macierzystego oraz wszystkich procesow potomnych, przy pomocy funkcji execl. (processes.c, get_ids.c)

Jak uruchomić:

```bash
$ make run program=<plik_wykonawczy.x>
```
