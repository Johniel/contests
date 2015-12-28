(def f (lazy-cat (list (bigint 1) (bigint 1)) (map + f (rest f))))
(inc (second (first (filter #(<= 1000 (count (str (first %1)))) (map list f (range))))))
