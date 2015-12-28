(require 'dash)

(defun gcd (a b)
  (if (= b 0)
      a
    (gcd (min a b) (mod (max a b) (min a b)))))

(defun lcm (a b)
  (/ (* a b) (gcd a b)))

(-reduce 'lcm '(1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20))
