(defun sub-list(list from &optional (to (length list)))
    (setq size (length list)) ;size variable to determine out of bounds
     
    (if (or(> from size)(<= from 0)) ; out of bound index
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
         
         
(print  (sub-list '(1 4 10) 2 3)) ; Examples
(print   (sub-list '(1 4 10) 2)) ; Examples
(print   (sub-list '(1 7 12) 1 4)) ; Examples
(print   (sub-list '(1 7 12) 0 1)) ; Examples
(print  (sub-list '(1 6 12) 4 2)) ; Examples
