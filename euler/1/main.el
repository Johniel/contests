(require 'dash)

(defun range (a b)
  (let ((n a)
        (l '()))
    (while (<= n b)
      (setq l (append l (list n)))
      (setq n (+ n 1)))
    l))

(-sum (--filter (or (= 0 (mod it 3)) (= 0 (mod it 5))) (range 1 999)))
