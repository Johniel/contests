(reduce + (map #(- (int %1) 48) (.toString (reduce * (map bigint (repeat 1000 2))))))
