#!/usr/bin/env nu
qmk compile -kb crkbd -km tobias
loop { qmk flash -kb crkbd -km tobias }

