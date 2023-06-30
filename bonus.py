
import sys

print(
  ''
  .join(
    map(
      lambda line:
        line
          .replace(".h\"\n", "_bonus.h\"\n")
          .replace("_H\n", "_BONUS_H\n")
          .replace(".h      ", "_bonus.h"),
      sys.stdin.readlines()
    )
  ),
  end=''
)
