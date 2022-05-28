(defun sub-list3(list from to)
    (setq size (length list))

    (if (> from size)
        (return-from sub-list3 nil))

    (if (> to size)
        (return-from sub-list3 nil))
    
    
    (setq sub3 ()) 
    (setq counter 0) 
    (loop for a in list do
        (setq counter (+ counter 1))
        (if (and (>= counter x) (<= counter y))
            (setq sub3 (cons a sub3)))
    ) 
    ;not reversing list will output the reversed list
    (return-from sub-list3 sub3) 
    )
    (print (sub-list3 '(1 4 10)2 3))  
    (print (sub-list3 '(1 7 12)0 1)) 
    (print (sub-list3 '(1 6 12)4 2)) 
    (print (sub-list3 '(1 6 12)))