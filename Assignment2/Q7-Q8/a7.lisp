(defun isBST(tree)
    (cond
        ((listp tree) (progn 
                            (print tree)
                            (let ((node (car tree))) ;Get node
                            (terpri)
                            (terpri)
                            (princ "Node: ")
                            (print node)
                            (let ((left (car(car (cdr tree))))) ;Get left sub-tree value
                            (terpri)
                            (princ "Left: ")
                            (print left)
                            (let ((right (car(car(cdr(cdr tree)))))) ;Get right sub-tree value
                            (terpri)
                            (princ "Right: ")
                            (print right)
                            (terpri)

                            (and 
                                                            
                                (or (null right)(and (> right node)(isBST (car(cdr(cdr tree)))))) ;call on right sub-tree
                                (or (null left)(and (<= left node)(isBST (car (cdr tree))))) ;call on left sub-tree


                            )
                            

                            )
                            )
                            )

                        )
        )
        
        ((null tree) t)
        
        
    )
)

(print(isBST '(8 (3 (1 () ()) (6 (4 () ())(7 () ()))) (10 () (14 (12 () ()) ())))))
