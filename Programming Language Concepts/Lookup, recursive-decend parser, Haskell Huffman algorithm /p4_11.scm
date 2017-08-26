;;Problem 4.11
;;Alan Tsai
;;Reference: http://lawfulsamurai.blogspot.com/2009/01/sicp-section-41-metacircular-evaluator.html
(define (make-binding var val)
  (cons var val))

(define (binding-variable binding)
  (car binding))

(define (binding-value binding)
  (cdr binding))

; (define (make-frame variables values)
;   (cons variables values))
(define (make-frame variables values)
  (list (map make-binding variables values)))

; (define (frame-variables frame) (car frame))
(define (frame-variables frame) (map binding-variable (car frame)))

; (define (frame-values frame) (cdr frame))
(define (frame-values frame) (map binding-value (car frame)))

; (define (add-binding-to-frame! var val frame)
;   (set-car! frame (cons var (car frame)))
;   (set-cdr! frame (cons val (cdr frame))))
(define (add-binding-to-frame! var val frame)
  (set-car! frame (cons (make-binding var val) (car frame))))

(define (set-binding-value! binding val)
  (set-cdr! binding val))

(define (set-variable-value! var val env)
  (define (env-loop env)
    (define (scan bindings)
      (cond ((null? bindings)
             (env-loop (enclosing-environment env)))
            ((eq? var (binding-variable (car bindings)))
             (set-binding-value! (car bindings) val))
            (else (scan (cdr bindings)))))
    (if (eq? env the-empty-environment)
        (error "Unbound variable -- SET!" var)
        (let ((frame (first-frame env)))
          (scan frame))))
  (env-loop env))

(define (define-variable! var val env)
  (let ((frame (first-frame env)))
    (define (scan bindings)
      (cond ((null? bindings)
             (add-binding-to-frame! var val frame))
            ((eq? var (binding-variable (car bindings)))
             (set-binding-value! (car bindings) val))
            (else (scan (cdr bindings)))))
    (scan frame)))
