(defun depth (list)
                (if (listp list)
                    (+ 1 (reduce #'max (mapcar #'depth list)
                                 :initial-value -1))
                    0))
                    


(print (depth NIL))
(print  (depth 1))
(print  (depth '(1)))
(print (depth '((2))))
(print (depth '((2)(3 (6))(4))))