(reduce + (map #(- %1 48) (map int (.toString (reduce * (map bigint (range 1 100)))))))
