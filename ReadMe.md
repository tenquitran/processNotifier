processNotifier (the executable named `procNot` to type less) - Linux console program notifying about creation and termination of processes.
Polls the `proc` pseudo-filesystem. Stopped by the `kill` command.

Usage example with the output:

```shell
$ ./procNot&
[1] 545

$ sleep 3
Created processes:
------------------
546: /usr/bin/sleep (running)

$ Terminated processes:
---------------------
546: /usr/bin/sleep (running)
^C
```

Can also be used with the name of the process to watch for:

```shell
$ ./procNot& someProcess
```

Note: `Ctrl+C` is used to get back the terminal prompt.
