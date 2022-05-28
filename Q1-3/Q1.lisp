(defun sub-list(list from to)
    (setq size (length list)) ;size variable to determine out of bounds
     
    (if (> from size) ; out of bound index
        (return-from sub-list nil)) ;returns NIL if from is not on the list
        
    (if (> to size) ; checking index for out of bound
        (return-from sub-list nil)) ;"to" should be default as NIL..should be optional
  
    (setq sub ()) ; Creating list to display
    (setq count 0) ; index from to poition
   
    (loop for a in list do     ;Going through list elements
        (setq count (+ count 1))
        (if (and (>= count from) (<= count to))
            (setq sub (cons a sub)))
    ) 
    
    (defun rev (list) ;Results are reversed, we need to reverse the list to obtain the right order
    (do ((list list (rest list))
       (reversed '() (list* (first list) reversed)))
      ((endp list) reversed)))
    
        (setq sub (rev sub)) ;reversed list placed into sub
    (return-from sub-list sub) ;sub list is returned
    )                  
         
         
(print (sub-list '(1 6 12 5) 2 4)) ; Examples