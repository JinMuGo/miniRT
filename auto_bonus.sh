#!/bin/sh

set -e

find . -name "*.c" | sed s/\\.c$// | xargs -I {} sh -c "python3 ./bonus.py < {}.c > ./{}_bonus.c && rm -f {}.c";
find . -name "*.h" | sed s/\\.h$// | xargs -I {} sh -c "python3 ./bonus.py < {}.h > ./{}_bonus.h && rm -f {}.h";

