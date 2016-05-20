/*!
 *  @mainpage BARES (Basic Arithmetic Expression Evaluator based on Stacks)
 *  @author Adelino Afonso Fernandes Avelino
 *  @author Irene Ginani Costa Pinheiro
 *  @date Maio, 2016
 *  @version 1.0
 *
 *  @file drive.cpp
 *  @brief Arquivo Main
 *
 *  Arquivo com o método Main
 */

#include "header.h"
#include "queuear.h"
#include "stackar.h"

using namespace std;
/**
 * @brief Main 
 *
 * Drive do programa
 */
int main (int argc, char const *argv[]){
	std::ifstream arquivo;
	std::ifstream aux;
	conjuntura conjuntura;
	std::string token;
	char * arq;
	
		if (argc > 1)
		{
			arquivo.open(argv[1], std::fstream::in);
		}else
		{
			std::cout << ">>> O nome do arquivo não foi passado como argumento." << std::endl;
		 	return 0;
		}

		while (!arquivo.eof()){
		    getline(arquivo, token);
		    arq = new char [token.length()+1];
  			std::strcpy (arq, token.c_str());
          
          	if (conjuntura.token(arq, token.length()) == true)
          	{
          		conjuntura.Infx2Posfx();
            	conjuntura.avalPosFixa();
          	}

		}	

    return EXIT_SUCCESS;
}
