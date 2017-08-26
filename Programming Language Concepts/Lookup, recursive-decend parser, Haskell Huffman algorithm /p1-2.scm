;;Alan Tsai
;;PA2 Problem 1 (ii)
;;Refernece: https://stackoverflow.com/questions/24873201/how-should-a-scheme-recursive-function-return-the-binding-with-the-specified-nam
(define (lookup name assoc_list)
  (if (null? assoc_list) '()
      (if (equal? name (car (car assoc_list)))
                  (car assoc_list)
          (lookup name (cdr assoc_list)))))

(define (lookup-env name environment) ;defines the look-env function
  (if (null? environment) '() ;returns null list if no environment
      (let ((check (lookup name (car environment)))) ;check assoc_list
      (if (null? check) ;if not in the list
          (lookup-env name (cdr environment)) ;check the rest of environment list
          check))))

(define envList '( (school "Drexel") (city "Philly") (building "UCross")))
(define env (list envList) )

(display env)
(display "\n")

;;Tests
(lookup-env 'school env)
(lookup-env 'building env)
(lookup-env 'nonexistent env)
