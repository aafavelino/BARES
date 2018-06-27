# Projeto BARES
Basic Arithmetic Expression Evaluator based on Stacks

## Descrição

O BARES (Basic ARithmetic Expression Evaluator based on Stacks) e um avaliador de expressoes baseado em pilhas que recebe um conjunto de expressoes e verifica se as mesmas sao validas
retornando o resultado da operacao, caso seja invalida o erro sera mostrado na coluna da espressao. Vale salientar que cada expressao deve estar em uma linha do arquivo 
para ser valida, quebras de linha na expressao torna-a invalida para calculos. Cada valor de expressao tem o tamanho de um inteiro, ou seja, deve estar entre -32767 e 32767. 
Abaixo segue uma tabela de operacoes suportadas pelo BARES.

### Operadores Suportados

| Simbolo | Operacoes            | Precedencia   |
| :----:  | -------------------- | :-----------: |
| __@__   | Menos unario         | 1             |
| __^__   | Exponenciacao        | 2             |
| __/__   | Divisao              | 3             |
| __%__   | Modulo               | 3             |
| __*__   | Multiplicacao        | 3             |
| __-__   | Subtracao            | 4             |
| __+__   | Adicao               | 4             |
| __()__  | Parenteses           | 5             |


## Compilação

g++ -std=c++11 -pedantic -I include/ src/drive.cpp -o bin/exe 


## Execução

Dentro da pasta BARES execute:

$ ./bin/exe data/data.txt 

## Lista de erros que o programa trata
1. Numeric constant out of range: Um dos operandos da expressao esta fora da faixa permitida.
Ex.: 1000000 − 2, coluna 1.

2. Ill-formed expression or missing term detected: Em alguma parte da expressao esta faltando um operando ou existe algum operando em formato errado.
Ex.: 2+, coluna 3; ou 3 ∗ d, coluna 5.

3. Invalid operand: Existe um sımbolo correspondente a um operador que nao esta na lista de operadores validos.
Ex.: 2 = 3, coluna 3; ou 2.3+4, coluna 2.

4. Extraneous symbol: Aparentemente o programa encontrou um sımbolo extra “perdido” na expressao.
Ex.: 2 ∗ 3 4, coluna 7 ou (−3∗4)(10∗5), coluna 7.

5. Mismatch ’)’: Existem um parˆentese fechando sem ter um parentese abrindo correspondente.
Ex.: )2−4, coluna 1; ou 2 − 4), coluna 6; ou 2) − 4. coluna 2.

6. Lost operator: Apareceu um operador sem seus operandos.
2 ∗∗ 3,coluna4;ou/5 ∗ 10,coluna 1.

7. Missing closing ‘)’ to match opening ‘)’ at: Esta faltando um parentese de fechamento ’)’ para um parentese de abertura ‘(’ correspondente.
Ex.: ((2%3) ∗ 8, coluna 1.

8. Division by zero!: Houve divisao cujo quociente e zero.
Ex.: 3/(1 − 1); ou 10/(3 ∗ 3ˆ−2). Nestes casos nao e preciso informar a coluna.

9. Numeric overflow error!: Acontece quando uma operacao dentro da expressao ou a expressao inteira estoura o limite das constantes numericas definidos na Secao 1.
Ex.: 20 ∗ 20000. Nestes casos nao e preciso informar a coluna.

## Autores:
* Adelino Afonso Fernandes Avelino - adelino-afonso@hotmail.com

* Irene Ginani Costa Pinheiro - ireneginani@gmail.com


