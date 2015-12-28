(ns euler23.core)

(def N 28123)

(defn is-abundant-number [n]
  (->> (range 1 n)
    (filter #(<= (* %1 %1) n))
    (filter #(= (mod n %1) 0))
    (map #(let [a %1
                b (/ n %1)]
            (if (= a b) (list a 0) (list a b))))
    (flatten)
    (reduce +)
    (< (* 2 n))))

(= (filter is-abundant-number (range 1 104))
   (list 12 18 20 24 30 36 40 42 48 54 56 60 66 70 72 78 80 84 88 90 96 100 102))

(defn -main []
  (let [abundant (filter is-abundant-number (range 1 (+ N 1)))]
    (->> (map (fn [n]
                (map (fn [m]
                       (+ m n))
                     abundant))
              abundant)
      (map (fn [ns]
             (take-while (fn [n] (<= n N)) ns)))
      (map set)
      (reduce clojure.set/union)
      (reduce +)
      (- (/ (* N (+ N 1)) 2)))))
