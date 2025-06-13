
O algoritmo percorre a grade 9x9 do Sudoku tentando preencher cada célula vazia com valores de 1 a 9. Antes de inserir um valor, ele verifica se a inserção respeita as três regras do Sudoku:

1. O número não pode repetir na **linha**.
2. O número não pode repetir na **coluna**.
3. O número não pode repetir no **bloco 3x3**.

Se todas as verificações passarem, o número é inserido e o algoritmo avança para a próxima célula. Caso não seja possível avançar (i.e., a escolha atual leva a um impasse), o algoritmo desfaz a última escolha (backtracking) e tenta outra alternativa.

## Estrutura

`is_valid`: Função que verifica se é válido inserir um número na posição atual.
`solve`: Função principal de backtracking que tenta resolver o Sudoku recursivamente.

# Complexidade

'TEMPO': O caso médio, considerando varios valores já preenchidos o backtracking não é muito exigente, porém no caso extremo a complexidade é O(9^81) considerando todas celulas vazias
'MEMORIA': O(1) da grade, O(n) da pilha onde n =< 81 (numero de celulas vazias).
