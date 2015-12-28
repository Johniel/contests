<?php

function f($n)
{
    $cnt = 0;
    for ($i = 1; $i * $i <= $n; ++$i) {
        if ($n % $i == 0) {
            $cnt += 2;
            if ($i * $i == $n) --$cnt;
        }
    }
    return $cnt;
}

$sum = 0;
for ($i = 1; ; ++$i) {
    $sum += $i;
    if (500 < f($sum)) {
        echo $sum . "\n";
        break;
    }
}