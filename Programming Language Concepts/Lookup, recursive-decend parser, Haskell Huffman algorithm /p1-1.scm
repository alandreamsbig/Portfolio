;; Alan Tsai
;; PA2 Problem 1 (i)
;;Reference: https://stackoverflow.com/questions/24873201/how-should-a-scheme-recursive-function-return-the-binding-with-the-specified-nam
(define (lookup name assoc_list) ;define the lookup function
  (if (null? assoc_list) '() ;returns empty list if no assoc_list
      (if (equal? name (car (car assoc_list))) ;checks if name matches the name in the list
                  (car assoc_list) ;print if matches
          (lookup name (cdr assoc_list))))) ;lookup iterate if no match found in the list

(define list1 '( (name "Alan") (height "5'7") (email "ayt32@drexel.edu")))

(display list1)
(display "\n")
(lookup 'name list1)
(lookup 'height list1)
(lookup 'nonexistent list1)
