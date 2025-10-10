![image](https://github.com/diogo-adao/libft/assets/142692185/63ed68a2-74a6-4958-8d49-bf8d36a2d98e)

# 🔢 Push_Swap

A program that sorts a stack of integers using only a restricted set of stack operations, developed in **C** as part of the **42 curriculum**.  
This project focuses on **algorithm optimization**, **stack manipulation**, and **problem-solving under constraints**.  


## 📖 Overview

`push_swap` sorts a stack of integers using **two stacks (A and B)** and a limited set of operations:

- **Swap** (`sa`, `sb`, `ss`) – swap the first two elements of a stack  
- **Push** (`pa`, `pb`) – move the top element from one stack to the other  
- **Rotate** (`ra`, `rb`, `rr`) – shift all elements up by one  
- **Reverse Rotate** (`rra`, `rrb`, `rrr`) – shift all elements down by one  

The challenge is to **sort numbers with as few operations as possible**.


## ⚙️ Features

- Sorting integers using **two stacks** and a limited set of operations  
- Algorithm based on **Turk sorting strategy**  
- Validates input: ensures only integers and no duplicates  
- Outputs the sequence of stack operations needed to sort the stack  


## 🧠 Key Concepts

- **Stacks** – using two stacks (A and B) for sorting  
- **Turk algorithm** – a specific sorting strategy to reduce the number of operations  
- **Pointer manipulation** – dynamically managing stack elements  
- **Input validation** – handling errors like duplicates or invalid numbers  
- **Command-line programming** – parsing arguments and outputting operations  


## 🧩 Installation & Usage

```bash
# Clone the repository
git clone https://github.com/diogo-adao/push_swap.git

# Go to the folder
cd push_swap && cd push_swap

# Build the program
make

# Run it
./push_swap <numbers>
```

## 👨‍💻 Author
[Diogo Adão](https://github.com/diogo-adao)


