(defun flatten-nums-nodup(flist)
    (if (null flist)); check if the list is null
    nil
    (if (listp flist)); check if it's a list. if yes, will recurse on the head of the list
    (findcharacter(remove-duplicates(append (flatten-nums-nodup(car flist))(flatten-nums-nodup (cdr flist)))))
    (cons flist ())); if it's an atom, it will be added to an empty list


(defun findcharacter (newlist);help to find the character
    (if (null newlist)); check if the list is null... otherwise I get stack overflow message
    nil
    (if(not(numberp (car newlist)))); check if it's a character
    (findcharacter(cdr newlist)) ; if yes recurse on the tail of the list
    (cons(car newlist) (findcharacter(cdr newlist))))

(print(flatten-nums-nodup '(1 2 (3 1) (a 2.5) (2 4.5) ((1 2)))))
