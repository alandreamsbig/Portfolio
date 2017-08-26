;;Alan Tsai
;;Problem 2 4.4
;;Reference: https://github.com/steveshogren/sicp/blob/master/4.1-Exercises.rkt

(define (quoted? exp)
  (tagged-list? exp 'quote))

(define (tagged-list? exp tag)
  (if (pair? exp)
      (eq? (car exp) tag)
      false))

(define (text-of-quotation exp) (cadr exp))
  
(define (and? exp) (tagged-list? exp 'and))
(define (eval-and exp env)
  (define (inner exps)
    (if (empty? exps)
        #t
        (if (eval (car exps) env)
            (inner (cdr exps))
            #f)))
  (inner exp))


(define (or? exp) (tagged-list? exp 'or))
(define (eval-or exp env)
  (define (inner exps)
    (if (empty? exps)
        #f
        (let ((e (eval (car exps) env)))
          (if e
              e
              (inner (cdr exps))))))
  (inner exp))

(display "Enter (and #t #t #f) or (or #t #f #t) to test the code\n")

(and #t #t #f)
(or #t #f #t)
