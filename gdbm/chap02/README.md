# Example gdbm

This example was taken from the [GDBM Manual](https://gnu.org.ua/software/gdbm/manual/intro.html).

```shell
make -f
# Create a database with a file
gdbmtool test.gdbm foo bar
./example test.gdbm foo
```