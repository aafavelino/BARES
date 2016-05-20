/*!
 *  @file header.inl
 *  @brief Implementação da Classe conjuntura
 *
 *  Arquivo com a construção das funções da classe conjuntura
 */

#include "header.h"
// Construtor
conjuntura::conjuntura(){
    this->fila_infixa = new QueueAr<std::string>;
    this->fila_posfixa = new QueueAr<std::string>;
    resultado = 0;
}
// Desconstrutor
conjuntura::~conjuntura(){
    delete this->fila_infixa;
    delete this->fila_posfixa;
    }
// Pega a precedência
int conjuntura::get_precedencia(std::string op)const
{
    if (op == "@")
        return 1;
    if (op == "^")
        return 2;
    if (op == "*" || op == "/" || op == "%")
        return 3;
    if (op == "+" || op == "-")
        return 4;
    if (op == ")" || op == "(")
        return 5;

    return 0;
}
// Verifica operador
bool conjuntura::eh_operador_antes(char op)const
{
    if (op == '*' or op == '/' or op == '+'  or
        op == '%' or op == '^' or op == '@')
{
        return true;
    }else{
        return false;
    }
}
// Verifica operador
bool conjuntura::eh_operador_completa(char op)const
{
    if (op == '*' or op == '/' or op == '+' or op == '(' or op == ')' or
        op == '%' or op == '^' or op == '@' or op == '-')
{
        return true;
    }else{
        return false;
    }
}
// Verifica operador
bool conjuntura::eh_operador(std::string op)const
{
    if (op == "*" or op == "/" or op == "+" or op == "-" or op == "(" or op == ")" or
        op == "%" or op == "@" or op == "^")
{
        return true;
    }else{
        return false;
    }
}
// Verifica se é dígito
bool conjuntura::eh_digito(char op)const
{
    if (op >= 48 and op <= 57)
{
        return true;
    }else{
        return false;
    }
}

/*
 *1. Numeric constant out of range: Um dos operandos da expressao esta fora da faixa permitida.
 *Ex.: 1000000 − 2, coluna 1.
 *
 *2. Ill-formed expression or missing term detected: Em alguma parte da expressao esta faltando um operando ou existe algum operando em formato errado.
 *Ex.: 2+, coluna 3; ou 3 ∗ d, coluna 5.
 *
 *3. Invalid operand: Existe um sımbolo correspondente a um operador que nao esta na lista de operadores validos.
 *Ex.: 2 = 3, coluna 3; ou 2.3+4, coluna 2.
 *
 *4. Extraneous symbol: Aparentemente o programa encontrou um sımbolo extra “perdido” na expressao.
 *Ex.: 2 ∗ 3 4, coluna 7 ou (−3∗4)(10∗5), coluna 7.
 *
 *5. Mismatch ’)’: Existem um parˆentese fechando sem ter um parentese abrindo correspondente.
 *Ex.: )2−4, coluna 1; ou 2 − 4), coluna 6; ou 2) − 4. coluna 2.
 *
 *6. Lost operator: Apareceu um operador sem seus operandos.
 *2 ∗∗ 3,coluna4;ou/5 ∗ 10,coluna1.
 *
 *7. Missing closing ‘)’ to match opening ‘)’ at: Esta faltando um parentese de fechamento ’)’ para um parentese de abertura ‘(’ correspondente.
 *Ex.: ((2%3) ∗ 8, coluna 1.
 *
 *8. Division by zero!: Houve divisao cujo quociente  e zero.
 *Ex.: 3/(1 − 1); ou 10/(3 ∗ 3ˆ−2). Nestes casos nao e preciso informar a coluna.
 *
 *9. Numeric overflow error!: Acontece quando uma operacao dentro da expressao ou a expressao inteira estoura o limite das constantes numericas definidos na Secao 1.
 *Ex.: 20 ∗ 20000. Nestes casos nao e preciso informar a coluna.
 */

// Tokenização
bool conjuntura::token(const char * aux, int t)
{
    char arq;
    char arq1 [50];
    string def[50];
    int i = 0;
    int var;
    int k = 0, j = 0, cont = 0, cont1 = 0, cont3 = 0, col=0, col1[50], slave = 0;
    std::string coluna[50];

            for ( j = 0; j < t ; j++){
            if (eh_digito(aux[j]) and ((aux[j+1] ==' ') or (aux[j+1] == '\t')) and eh_digito(aux[j+2])){
                    cout << "Extraneous symbol: column " << j+3  << "." <<  endl;
                    return false;
            }else if (eh_operador_antes(aux[j]) and ((aux[j+1] ==' ') or (aux[j+1] == '\t') or eh_operador_antes(aux[j+1])) and eh_operador_antes(aux[j+2])){
                    cout << "Extraneous symbol: column " << j+3 << "." << endl;
                    return false;
                }
            if (((aux[j]==')') and (aux[j+1]=='('))){
                cout << "Extraneous symbol: column " << j+2 << "." << endl;
                return false;
            }
            if (!((aux[j]==')') and (aux[j+1]=='('))){
                if ((eh_operador_antes(aux[j])) and (eh_operador_antes(aux[j+1]))){
                     cout << "Lost operator: column " << j+2 << "." << endl;
                     return false;
                 }
            }
             if ((eh_operador_antes(aux[j])) and ((aux[j+1] ==' ') or (aux[j+1] == '\t')) and (eh_operador_completa(aux[j+2]))){
                     cout << "Lost operator: column " << j  << "." <<  endl;
                     return false;
            }
           if ((aux[j]=='(') and (((aux[j+1] != '(')) and (!(eh_digito(aux[j+1]))) and (aux[j+1] != ' ') and (aux[j+1] != '-') and (aux[j+1] != '\t'))){
                    cout << "Lost operator: column " << j+1  << "."  << endl;
                    return false;
            }
            if ((aux[j]==')') and ((aux[j-1] != ')') and (!(eh_digito(aux[j-1]))) and (aux[j-1] != ' ') and (aux[j-1] != '-') and (j>0)and (aux[j-1] != '\t'))){
                    cout << "Lost operator: column " << j   << "." << endl;
                    return false;
            }
            if ((aux[j] == 33) or (aux[j] == 35) or (aux[j] == 36) or (aux[j] == 44) or (aux[j] == 46) or (aux[j] == 38) or ((aux[j] >= 58) and (aux[j] <= 62)) or (aux[j] ==91) or (aux[j] == 93)){
                cout << "Invalid operand: column " << j+1  << "."  << endl;
                return false;
            }else if ((!(eh_digito(aux[j]))) and (aux[j] != '-') and (!(eh_operador_completa(aux[j]))) and (aux[j] != ' ') and (aux[j] != '\t') and (aux[j] != '\n')){
                cout << "Ill-formed expression or missing term detected: column " << j+1 << "." << endl;
                return false;
            }
            if ((aux[j] != ' ') and (aux[j] != '\t')){
               arq1[k] = aux[j];
               k++;
            }

            if ((arq1[0] == 47) or (arq1[0] == 94) or (arq1[0] == 42) or (arq1[0] == 37)){
                cout << "Lost operator: column " << 1  << "." << endl;
                return false;
            }
            if (aux[j]=='('){
                cont++;
                slave = j;
                coluna[slave] = "(";
            }
            if (aux[j]==')'){
                cont1++;
                col = j+1;
                coluna[slave] = " ";
            }
            }
            if (k<=2){
                cout << "Ill-formed expression or missing term detected: column "<< k+1  << "." << endl;
                return false;
            }
            for (int a = 0; a < k; a++){
                if ((!(eh_digito(arq1[a]))) and (arq1[a+1] == '-')  and (eh_digito(arq1[a+2])))
                     arq1[a+1] = '@';
             }
            if (cont1 > cont)
            {
                cout << "Mismatch ')': column " << col  << "." << endl;
                return false;
            }
             if (cont > cont1)
            {
                for (int i = j; i >= 0; i--)
                {
                    if(coluna[i] == "("){
                        slave = i;
                        break;
                    }
                }
                cout << "Missing closing ')' to match opening '(' at: column " << slave+1  << "." << endl;
                return false;
            }
            for (int u = 0; u < k; u++)
            {
                if ((arq1[u] >= 48) and (arq1[u] <=57))
                {
                    def[cont3] = def[cont3] + arq1[u];
                }else{
                    cont3++;
                    def[cont3] = arq1[u];
                    if (eh_digito(arq1[u+1]))
                    cont3++;
                }
            }
            for (int q =0; q <= j; q++){
                if (!(eh_operador(def[q])))
                {
                    var = atoi(def[q].c_str());
                    if (var > 32767 or var < -32767){
                        cout << "Numeric constant out of range: column " << q+1  << "." << endl;
                        return false;
                    }

                }

            }
                for (int y = 0; y <= cont3; y++)
                {
                    if (def[y]!= " " and def[y] != "\t" and def[y] != "\n")
                    {
                         fila_infixa->enqueue(def[y]);
                    }
                }

        return true;

}

/* Converte a expressão infixa para pósfixa
 * Foi utilizada a mesma lógica dada em sala de aula para implementação.
 */
void conjuntura::Infx2Posfx()
{
    StackAr<std::string>  pilha;
    std::string simbol;

    while(!fila_infixa->isEmpty())
    {
        simbol = fila_infixa->dequeue();

        if (!eh_operador(simbol))
        {
            fila_posfixa->enqueue(simbol);

        }

        else if(simbol == "(" or simbol == "@")
        {
            pilha.push(simbol);

        }

        else if(simbol == ")")
        {
                while(!pilha.isEmpty() and pilha.top() != "(")
                {
                    fila_posfixa->enqueue(pilha.pop());
                }

                pilha.pop();
        }
        else
        {
            while(!pilha.isEmpty() and get_precedencia(pilha.top()) <= get_precedencia(simbol))
            {
                fila_posfixa->enqueue(pilha.pop());
            }

                pilha.push(simbol);

        }

    }
    while(!pilha.isEmpty())
    {

        fila_posfixa->enqueue(pilha.pop());
    }

    return ;
}


/* Função para efetuar os cálculos
 * Foi utilizada a mesma lógica dada em sala de aula para implementação.
 */
int conjuntura::avalPosFixa()
{
    int opr1;
    int opr2;
    int cont = 0;
    StackAr<int>  pilha_int;
    std::string simbol;

    while(!fila_posfixa->isEmpty())
    {
        simbol = fila_posfixa->dequeue();
        if (!eh_operador(simbol))
        {
            pilha_int.push(atoi(simbol.c_str()));
            cont++;
        }else if (cont >= 2){

            opr2  = pilha_int.pop();
            opr1  = pilha_int.pop();

            if (simbol == "*")
                resultado = opr1 * opr2;
            else if(simbol == "/"){
                if (opr2 == 0 or (opr1 == 0 and opr2 == 0)){
                    cout << "Division by zero!"<< endl;
                    return EXIT_FAILURE;
                }
                resultado = opr1 / opr2;
            }else if(simbol == "+")
                resultado = opr1 + opr2;
            else if(simbol == "-")
                resultado = opr1 - opr2;
            else if(simbol == "^")
                resultado = pow(opr1,opr2);
            else if(simbol == "%")
                resultado = opr1 % opr2;
            else if(simbol == "@"){ // Não está tratando unário!!!!
                cout << "Division by zero!"<< endl;
                    return EXIT_FAILURE;
            }
            pilha_int.push(resultado);
        }

    }

    if (!pilha_int.isEmpty())
       resultado = pilha_int.pop();
    else
       resultado = 0;

    if (resultado > 32767 or resultado < -32767){
        cout << "Numeric overflow error!"<< endl;
        return EXIT_FAILURE;
    }
    std::cout << resultado << endl;
    return resultado;

}
