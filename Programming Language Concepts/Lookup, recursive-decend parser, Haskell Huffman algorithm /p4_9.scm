;;Alan Tsai
;;Problem 4.9
;;Reference: https://github.com/ajkitson/sicp/blob/master/ch4/4.9.scm

(define (tagged-list? exp tag)
  (if (pair? exp)
      (eq? (car exp) tag)
      false))

(define (while? exp) (tagged-list? exp 'while))
(define (pred exp) (cadr exp))
(define (body exp) (caddr exp))
(define (while->comb exp)
  (list 'begin (list 'define (list 'iter-name)
                     (list 'if
                           (pred exp)
                           (list 'begin
                                 (body exp)
                                 (list 'iter-name))
                           'done))
        (list 'iter-name)))
(while->comb '(while (true) (body)))
