(defun sub-list3(list from &optional (to (length list)))

    (defun rev (list) ;Results are reversed, we need to reverse the list to obtain the right order
    (do ((list list (rest list))
       (reversed '() (list* (first list) reversed)))
      ((endp list) reversed)))
      
    (setq size (length list)) ;size variable to determine out of bounds
    
    (if (> from to) ; from greater than to
        (return-from sub-list3(rev(sub-list3 list to from )))) ;returns NIL if from greater than to
     
    (if (or(> from size)(<= from 0)) ; out of bound index
        (setq from 1)) ;Set from to 1
        
    (if (> to size) ; checking index for out of bound
        (setq to (length list))) ;returns NIL if from is not on the list

  
    (setq sub ()) ; Creating list to display
    (setq count 0) ; index from to poition
   
    (loop for a in list do     ;Going through list elements
        (setq count (+ count 1))
        (if (and (>= count from) (<= count to))
            (setq sub (cons a sub)))
    ) 
    

    
        (setq sub (rev sub)) ;reversed list placed into sub
    (return-from sub-list3 sub) ;sub list is returned
    )                  
         
         
(print  (sub-list3 '(1 4 10) 3 2)) ; Examples
(print   (sub-list3 '(1 4 10) 3)) ; Examples
(print    (sub-list3 '(1 7 12) 4 0)) ; Examples
(print   (sub-list3 '(1 6 12))) ; Examples
