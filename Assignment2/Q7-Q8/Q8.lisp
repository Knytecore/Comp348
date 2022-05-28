(defun in-order(tree)
    
    (cond
        ((not (null (car(car (cdr tree))))) ; if has left
        
                (progn 
                    (in-order (car (cdr tree))) ;recurse while tree has a left
                    (setq lst (append lst (list(car tree)))) ; print node
                    (if(not(null (car(cdr (cdr tree)))))(in-order (car(cdr (cdr tree))))) ;continue with right
                )
        )
        
        (t (progn
                (setq lst (append lst (list(car tree)))) ; print node
                (if(not(null (car(cdr (cdr tree)))))(in-order (car(cdr (cdr tree))))) ;continue with right

            )
        )
        
        
    )
)

(defun pre-order(tree)
    

    (if (not(null tree))
        (progn 
            (setq lst (append lst (list(car tree)))) ; print node
            (if (not (null (car(car (cdr tree))))) ; if has left
                (pre-order (car (cdr tree)))
            )
            (pre-order (car(cdr (cdr tree)))) ;continue with right
    
        )
    )
        
        

        
    
)






(setq lst '())
(in-order '(+ (- (1 () ()) (* (4 () ())(7 () ()))) (/ (7 () ()) (6 () ()))))
(print lst)

(setq lst '())
(pre-order '(+ (- (1 () ()) (* (4 () ())(7 () ()))) (/ (7 () ()) (6 () ()))))
(print lst)
