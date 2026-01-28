# 🧮 C-Calc: Shunting-Yard Expression Evaluator

A robust C11 implementation of Edsger Dijkstra's **Shunting-Yard** algorithm. This project converts infix expressions (e.g., `3 + 4 * 2`) into Reverse Polish Notation (RPN) and evaluates the final mathematical result.

## 🚀 Features

* **Expression Parsing**: Full support for floating-point numbers (`double`).
* **Mathematical Operators**: Addition (+), Subtraction (-), Multiplication (*), and Division (/).
* **Operator Precedence**: Correctly handles mathematical hierarchy and nested parentheses.
* **Modular Architecture**: Custom **Stack** implementation based on dynamic linked lists.

## 🛠️ Technologies & Concepts

* **Language**: C (C11 Standard).
* **Algorithms**: Shunting-Yard and RPN Evaluation.
* **Data Structures**: Dynamic Stacks (Linked Lists).
* **Tools**: Makefile for build automation.

## 📁 Project Structure

* `/src`: Implementation files (`.c`).
* `/include`: Prototypes and structure definitions (`.h`).
* `/build`: Object files generated during compilation.

## 💻 How to Compile and Run

Ensure you have `gcc` and `make` installed on your system.

1. **Clone the repository:**
```bash
git clone https://github.com/CODCenzo/Calculator.git
cd Calculator
cd Expression_calculator

```


2. **Compile the project:**
```bash
make

```


3. **Run the application:**
```bash
./calc

```



To remove build files and reset the environment:

```bash
make clean

```

## 🧠 Example

**Input:** `(10 + 2) * 3 / 4`

**RPN Output:** `10 2 + 3 * 4 /`

**Result:** `9.000000`

---

*Developed by [Your Name] - Feel free to reach out on [LinkedIn](https://www.linkedin.com/in/your-profile).*

---

# Português:

# 🧮 C-Calc: Shunting-Yard Expression Evaluator

Uma implementação robusta em C11 do algoritmo **Shunting-Yard** de Edsger Dijkstra, capaz de converter expressões infixas (ex: `3 + 4 * 2`) para Notação Polonesa Reversa (RPN) e calcular seu resultado final.

## 🚀 Funcionalidades
- **Parsing de Expressões**: Suporte a números de ponto flutuante (double).
- **Operadores Matemáticos**: Adição (+), Subtração (-), Multiplicação (*) e Divisão (/).
- **Precedência de Operadores**: Respeita a hierarquia matemática e o uso de parênteses.
- **Arquitetura Modular**: Implementação de Pilha (Stack) baseada em listas ligadas.

## 🛠️ Tecnologias e Conceitos
- **Linguagem**: C (Padrão C11).
- **Algoritmos**: Shunting-Yard e RPN Evaluation.
- **Estruturas de Dados**: Pilhas Dinâmicas.
- **Ferramentas**: Makefile para automação de build.

## 📁 Estrutura do Projeto
- `/src`: Arquivos de implementação (.c).
- `/include`: Protótipos e definições de estruturas (.h).
- `/build`: Arquivos de objeto gerados durante a compilação.

## 💻 Como Compilar e Rodar

Certifique-se de ter o `gcc` e o `make` instalados.

1. Clone o repositório:
   ```bash
   git clone https://github.com/CODCenzo/Calculator.git
    cd Calculator
    Cd Expression_calculator
    make
    ./Calc
    ```
