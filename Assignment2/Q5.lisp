(defun tribonacci-seq-recursive (val)

    (defun tribonacci-seq (value)
        
        (cond
            ((= value 1) 0)
            ((= value 2) 0)
            ((= value 3) 1)
            ((> value 3)(+ (tribonacci-seq (- value 1)) (tribonacci-seq (- value 2)) (tribonacci-seq (- value 3))))
    
    
        )
    
    )  
    
    (if (> val 0) (progn
                    (push (tribonacci-seq val) lst)
                    (tribonacci-seq-recursive (- val 1))
                
                )
    
    )

)

(defun tribonacci-seq-iterative (val)

    (progn
        (setq temp1 0)
        (setq temp2 0)
        (setq temp3 1)
        (if (> val 0)(setq lst (append lst (list 0))))
        (if (> val 1)(setq lst (append lst (list 0))))
        (if (> val 2)(setq lst (append lst (list 1))))
        (dotimes (number (- val 3))

            (setq temp4 (+ temp3 temp2 temp1))
            (setq lst (append lst (list temp4)))
            (setq temp1 temp2)
            (setq temp2 temp3)
            (setq temp3 temp4)
        )
        


    )
)



(terpri)
(princ "Calling tribonacci with iterative function: ")
(setq lst '())
(tribonacci-seq-iterative 0)
(print lst)
(setq lst '())
(tribonacci-seq-iterative 7)
(print lst)
(setq lst '())
(tribonacci-seq-iterative 1)
(print lst)


(terpri)
(terpri)
(princ "Calling tribonacci with recursive function: ")
(setq lst '())
(tribonacci-seq-recursive 0)
(print lst)

(setq lst '())
(tribonacci-seq-recursive 7)
(print lst)

(setq lst '())
(tribonacci-seq-recursive 1)
(print lst)


