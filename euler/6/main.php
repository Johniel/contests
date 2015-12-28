<?php

$n = 0;
$m = 0;

for ($i = 0; $i <= 100; ++$i) {
    $m += $i;
}
$m = $m * $m;

for ($i = 0; $i <= 100; ++$i) {
    $m -= $i * $i;
}
echo $m . "\n";
