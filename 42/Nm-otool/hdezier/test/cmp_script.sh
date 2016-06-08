#!/bin/bash
diff <(~/code/meuh/42/Nm-otool/hdezier/nm $1) <(nm $1)
