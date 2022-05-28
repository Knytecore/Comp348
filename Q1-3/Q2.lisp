(defun sub-list2(list from to)
    (setq size (length list))

    (if (> from size)
        (return-from sub-list2 nil))

    (if (> to size)
        (return-from sub-list2 nil))

    (setq sub2 ()) 
    (setq counter 0) 

    (loop for a in list do
        (setq counter (+ counter 1))
        (if (and (>= counter from) (<= counter to))
            (setq sub2 (cons a sub2)))
    ) 
    
    (defun rev (list) ;Results are reversed, we need to reverse the list to obtain the right order
    (do ((list list (rest list))
       (reversed '() (list* (first list) reversed)))
      ((endp list) reversed)))
    
        (setq sub2 (rev sub2)) ;reversed list placed into sub
    (return-from sub-list2 sub2) ;sub list is returned
    
      
    (setq sub2 (rev sub2))
    (return-from sub-list2 sub2) 
    )

    (print (sub-list2 '(1 4 10)2 3))  
    (print (sub-list2 '(1 6 12)4 2)) 
    (print (sub-list2 '(1 6 12)))