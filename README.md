[readme_md.md](https://github.com/user-attachments/files/34549356/readme_md.md)
# Calculadora Inteligente em C 🧮

Uma calculadora de linha de comando desenvolvida em linguagem C que suporta expressões matemáticas contínuas, respeitando a ordem de precedência das operações (multiplicação, divisão, soma e subtração) e oferecendo comandos interativos de controle de tela e fluxo.

## 🚀 Funcionalidades

* **Expressões Contínuas:** Permite digitar operações completas em uma única linha (ex: `5 + 3 * 2 - 8 / 4 =`).
* **Precedência de Operadores:** Resolve corretamente primeiro as multiplicações e divisões, antes de prosseguir com as somas e subtrações.
* **Tratamento de Erros:**
  * Alerta para divisão por zero.
  * Validação de operadores e entradas inválidas.
* **Comandos de Controle:**
  * `C` ou `c`: Limpa a tela do terminal.
  * `N` ou `n`: Encerra a execução do programa.
* **Compatibilidade:** Funções de limpeza de tela adaptáveis para sistemas Windows (`cls`) e Unix/Linux/macOS (`clear`).

---

## 🛠️ Tecnologias Utilizadas

* **Linguagem C** (Padrão C99 ou superior)
* Bibliotecas Padrão: `<stdio.h>` e `<stdlib.h>`

---

## ⚙️ Como Compilar e Executar

Certifique-se de ter um compilador C instalado na sua máquina (como o `gcc`).

1. **Clone o repositório:**
   ```bash
   git clone https://github.com/SEU-USUARIO/SEU-REPOSITORIO.git
   cd SEU-REPOSITORIO
   ```

2. **Compile o código:**
   ```bash
   gcc CalculadoraInteligente.cpp -o calculadora
   ```
   *(Nota: O arquivo possui extensão `.cpp`, mas o código é 100% estruturado em C puro).*

3. **Execute o programa:**
   * **No Linux / macOS:**
     ```bash
     ./calculadora
     ```
   * **No Windows:**
     ```cmd
     calculadora.exe
     ```

---

## 💡 Como Usar

Ao iniciar o programa, digite a sua expressão matemática seguida pelo sinal de igual (`=`) para obter o resultado instantaneamente.

**Exemplo de uso no terminal:**
```text
Calculadora Inteligente, faca as operacoes com o = no final.
Digite a conta e termine com = (N sai, C limpa a tela)
> 10 + 5 * 2 =
Resultado: 20.00

Digite a conta e termine com = (N sai, C limpa a tela)
> c
```

---

## 👨‍💻 Autor

Desenvolvido por **Gustavo** como parte de seus estudos práticos em algoritmos, estruturas de dados e lógica de programação em C.
