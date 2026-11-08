//Calculadora em C

#include <stdio.h>
#include <stdlib.h>

// ---------- tela ----------
void limparTela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// ---------- operações (uma conta cada) ----------
double somar(double a, double b)       { return a + b; }
double subtrair(double a, double b)    { return a - b; }
double multiplicar(double a, double b) { return a * b; }
double dividir(double a, double b)     { return a / b; }

// ---------- comando antes da conta ----------
// Devolve 0 = é uma conta, 1 = sair (N), 2 = limpar tela (C)
int lerComando()
{
    char c;
    scanf(" %c", &c);

    if (c == 'n' || c == 'N')
    {
        return 1;
    }
    if (c == 'c' || c == 'C')
    {
        return 2;
    }

    ungetc(c, stdin);   // não era comando: devolve o caractere para a leitura da conta
    return 0;
}

// ---------- leitura ----------
int lerConta(double numeros[], char operadores[])
{
    int qtd = 1;
    char op;

    scanf("%lf", &numeros[0]);
    scanf(" %c", &op);

    while (op != '=' && qtd < 50)
    {
        if (op != '+' && op != '-' && op != '*' && op != '/')
        {
            return -1;
        }

        operadores[qtd - 1] = op;
        scanf("%lf", &numeros[qtd]);
        qtd++;

        scanf(" %c", &op);
    }

    return qtd;
}

// ---------- remoção ----------
void removerNumero(double numeros[], int qtd, int pos)
{
    for (int j = pos; j < qtd - 1; j++)
    {
        numeros[j] = numeros[j + 1];
    }
}

void removerOperador(char operadores[], int qtd, int pos)
{
    for (int j = pos; j < qtd - 1; j++)
    {
        operadores[j] = operadores[j + 1];
    }
}

// ---------- primeira passada: so * e / ----------
int resolverMultDiv(double numeros[], char operadores[], int qtdNumeros)
{
    int i = 0;

    while (i < qtdNumeros - 1)
    {
        if (operadores[i] == '*' || operadores[i] == '/')
        {
            double r;

            if (operadores[i] == '*')
            {
                r = multiplicar(numeros[i], numeros[i + 1]);
            }
            else
            {
                if (numeros[i + 1] == 0)
                {
                    return -1;
                }
                r = dividir(numeros[i], numeros[i + 1]);
            }

            numeros[i] = r;
            removerNumero(numeros, qtdNumeros, i + 1);
            removerOperador(operadores, qtdNumeros - 1, i);
            qtdNumeros--;
        }
        else
        {
            i++;
        }
    }

    return qtdNumeros;
}

// ---------- segunda passada: so + e - ----------
double resolverSomaSub(double numeros[], char operadores[], int qtdNumeros)
{
    double resultado = numeros[0];

    for (int k = 0; k < qtdNumeros - 1; k++)
    {
        if (operadores[k] == '+')
        {
            resultado = somar(resultado, numeros[k + 1]);
        }
        else
        {
            resultado = subtrair(resultado, numeros[k + 1]);
        }
    }

    return resultado;
}

// ---------- chefe ----------
int main()
{
	printf("Calculadora Inteligente, faca as operacoes com o = no final.\n");
    while (1)
    {
        printf("Digite a conta e termine com = (N sai, C limpa a tela)\n> ");

        int comando = lerComando();

        if (comando == 1)
        {
            break;
        }
        if (comando == 2)
        {
            limparTela();
            continue;
        }

        double numeros[50];
        char operadores[49];

        int qtd = lerConta(numeros, operadores);

        if (qtd == -1)
        {
            printf("Operador invalido.\n");
            while (getchar() != '\n');
        }
        else
        {
            qtd = resolverMultDiv(numeros, operadores, qtd);

            if (qtd == -1)
            {
                printf("Erro: divisao por zero.\n");
            }
            else
            {
                double resultado = resolverSomaSub(numeros, operadores, qtd);
                printf("Resultado: %.2f\n", resultado);
            }
        }

        printf("\n");
    }

    return 0;
}
