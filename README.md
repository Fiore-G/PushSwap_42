Sobre el proyecto
Push_swap es un proyecto de algoritmia simple con el objetivo de ordenar datos enteros utilizando 2 stacks y un conjunto de instrucciones para manipular ambos stacks, ésto hay que hacerlo con el mínimo de instrucciones posibles.

Las instrucciones son:
🔸sa: (swap a) Intercambia los dos primeros elementos del stack a. No hace nada si hay uno o menos elementos.
🔸sb: (swap b) Intercambia los dos primeros elementos del stack b. No hace nada si hay uno o menos elementos.
🔸ss: (sa y sb a la vez)
🔸pa: (push a) Toma el primer elemento del stack b y lo pone el primero en el stack a. No hace nada si b está vacío.
🔸pb: (push b) Toma el primer elemento del stack a y lo pone el primero en el stack b. No hace nada si a está vacío.
🔸ra: (rotate a) Desplaza hacia arriba todos los elementos del stack a una posición, de forma que el primer elemento se convierte en el último.
🔸rb: (rotate b) Desplaza hacia arriba todos los elementos del stack b una posición, de forma que el primer elemento se convierte en el último.
🔸rr: (ra y rb a la vez) 
🔸rra: (reverse rotate a) Desplaza hacia abajo todos los elementos del stack a una posición, de forma que el último elemento se convierte en el primero.
🔸rrb: (reverse rotate b) Desplaza hacia abajo todos los elementos del stack b una posición, de forma que el último elemento se convierte en el primero.
🔸rrr: (rra y rrb a la vez)
