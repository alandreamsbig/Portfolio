;;Work Reference citation: http://www.javacms.tech/questions/4782749/scheme-function-returns-step-values-but-doesnt-append-an-empty-list-to-it

(define (iterator L) ;Define a iterator function
  (define (itr start step end) ;define variables
    (lambda () ;lambda function
      (if (< start end) ;if start is less than end
            (begin
              (set! start (+ start step)) ;change the value of start inside the function
              (- start step)) ;subtract step from start
          '() ;else empty list
          )))
  (itr (car L) (car(cdr L)) (car(cdr(cdr L)))))


(define next (iterator '(0 2 7)))
(begin (next) (next) (next) (next) (next))
