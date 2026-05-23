# 💻 Design and Analysis of Algorithms (DAA) — C++ Implementation Suite

[![C++ Standard](https://img.shields.io/badge/C%2B%2B-11%2F14%2F17-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://en.cppreference.com/)
[![Algorithmic Paradigms](https://img.shields.io/badge/Paradigms-DP%20%7C%20Greedy%20%7C%20Backtracking%20%7C%20D%26C-FF6F61?style=for-the-badge&logo=gitbook&logoColor=white)](#algorithmic-paradigm--complexity-matrix)
[![Academic Level](https://img.shields.io/badge/Semester-4-blueviolet?style=for-the-badge)](#)
[![Status](https://img.shields.io/badge/Build-Passing-brightgreen?style=for-the-badge)](#)

Welcome to the **Design and Analysis of Algorithms (DAA)** suite. This repository houses an industry-grade, clean, and highly documented collection of C++ implementations built during the **Engineering Semester 4** core curriculum. 

The suite is designed to demonstrate deep structural understanding of fundamental and advanced data structures, algorithmic paradigms, rigorous asymptotic time/space complexity analysis, and real-world domain modeling (such as social network traversal, student databases, data compression, and business utility cost optimization).

---

## 🎯 Repository Highlights

- **🔒 Balanced Theory & Practice:** Every program maps to a classic mathematical or real-world problem statement with precise asymptotic bounds.
- **⚡ Modern C++ Standards:** Standard Template Library (STL) utilities (`vector`, `queue`, `priority_queue`, `stack`, `string`, `iomanip`) are leveraged for performance and clean architecture.
- **📂 Binary Persistence:** Includes implementations showing disk-bound storage models, illustrating serialization and deserialization in custom hashing databases.
- **🔬 Algorithmic Diversity:** Covers the four pillars of algorithm design: **Dynamic Programming**, **Greedy Paradigms**, **Divide & Conquer**, and **Backtracking**.

---

## 📂 Project Architecture

A clean mapping of the repository contents, showcasing the implementation files:

```bash
Design-and-Analysis-of-Algorithm/
├── 01knapsack.cpp      # 0/1 Knapsack Problem (Dynamic Programming)
├── avl.cpp             # Height-Balanced AVL Tree Dictionary (LL/RR/LR/RL rotations)
├── graph.cpp           # Adjacency List Social Network Graph (Recursive/Iterative BFS & DFS)
├── hashing.cpp         # Disk-Persistent Hash Table (Linear Probing with/without Replacement)
├── huffman.cpp         # Huffman Coding Data Compression Tree (Greedy Paradigm)
├── mobile.cpp          # Sorting/Searching benchmark suite (Quick Sort, Heap Sort, Binary Search)
├── nqueen.cpp          # N-Queens Chessboard Constraint solver (Backtracking)
├── prims.cpp           # Prim's Minimum Spanning Tree optimizer (Greedy Paradigm)
└── README.md           # Modern Repository Documentation (This file)
```

---

## 📊 Algorithmic Paradigm & Complexity Matrix

Below is a consolidated summary of the algorithmic strategies, data structures, and rigorous time and space complexities implemented throughout this codebase:

| Program Name | Algorithmic Paradigm | Primary Data Structure(s) | Time Complexity (Best / Avg / Worst) | Space Complexity (Auxiliary / Total) |
| :--- | :--- | :--- | :--- | :--- |
| **`01knapsack.cpp`** | Dynamic Programming | 2D Dynamic Array (`vector<vector<int>>`) | $\mathcal{O}(N \cdot W)$ / $\mathcal{O}(N \cdot W)$ / $\mathcal{O}(N \cdot W)$ | $\mathcal{O}(N \cdot W)$ |
| **`avl.cpp`** | Self-Balancing Trees | AVL Tree (Height-Balanced Binary Search Tree) | $\mathcal{O}(\log N)$ / $\mathcal{O}(\log N)$ / $\mathcal{O}(\log N)$ | $\mathcal{O}(N)$ |
| **`graph.cpp`** | Graph Exploration | Linked Adjacency Lists, Stack, Queue | $\mathcal{O}(V + E)$ / $\mathcal{O}(V + E)$ / $\mathcal{O}(V + E)$ | $\mathcal{O}(V + E)$ |
| **`hashing.cpp`** | Hashing & File Serialization | Fixed Array (Hash Table), Binary File Stream | $\mathcal{O}(1)$ / $\mathcal{O}(1)$ / $\mathcal{O}(N)$ | $\mathcal{O}(N)$ |
| **`huffman.cpp`** | Greedy Approach | Priority Queue (Min-Heap), Huffman Tree | $\mathcal{O}(N \log N)$ / $\mathcal{O}(N \log N)$ / $\mathcal{O}(N \log N)$ | $\mathcal{O}(N)$ |
| **`mobile.cpp`** | Divide & Conquer / Sorting | Arrays, Binary Search, Heap Representation | $\mathcal{O}(N \log N)$ / $\mathcal{O}(N \log N)$ / $\mathcal{O}(N^2)$ (Quick Sort) | $\mathcal{O}(\log N)$ (Quick Sort) / $\mathcal{O}(1)$ (Heap Sort) |
| **`nqueen.cpp`** | Backtracking | 1D Recursion Stack Array | $\mathcal{O}(N!)$ / $\mathcal{O}(N!)$ / $\mathcal{O}(N!)$ | $\mathcal{O}(N)$ |
| **`prims.cpp`** | Greedy Approach | 2D Cost Matrix representation | $\mathcal{O}(V^2)$ / $\mathcal{O}(V^2)$ / $\mathcal{O}(V^2)$ | $\mathcal{O}(V^2)$ |

---

## 🔍 Deep-Dive: Program Showcases

Click on a tab below to expand and view detailed descriptions, features, and algorithmic mechanisms for each implementation:

<details>
<summary><b>1. 🎒 Dynamic Programming: 0/1 Knapsack (<code>01knapsack.cpp</code>)</b></summary>
<br>

* **Problem Statement:** Maximize the total value of items placed in a knapsack of maximum weight capacity $W$, without splitting items.
* **Technique Details:** Computes the state transition matrix $B[i][w]$ where:
  $$B[i][w] = \max(val[i] + B[i-1][w-wt[i]], B[i-1][w])$$
* **Key Features:**
  - Displays the full **Dynamic Programming (DP) Table** for runtime state inspection.
  - Performs **Backtracking on DP State Matrix** to identify and output the precise selected items, their individual values, and weights.
</details>

<details>
<summary><b>2. 🌲 Balanced Trees: AVL Dictionary (<code>avl.cpp</code>)</b></summary>
<br>

* **Problem Statement:** Design a dynamic dictionary mapping words to meanings with optimal $\mathcal{O}(\log N)$ retrieval, preventing tree skewness.
* **Technique Details:** Custom node class tracking heights. Incorporates four core self-balancing pointer rotations:
  - **Left-Left (LL)** & **Right-Right (RR)** single rotations.
  - **Left-Right (LR)** & **Right-Left (RL)** double rotations.
* **Key Features:**
  - Dynamic interactive console menu to add words, update definitions, search with visual balance feedback.
  - In-order traversal rendering sorted contents in ascending lexicographical order.
  - Explicit tracking and reporting of path comparisons required for lookups to prove height-balance performance.
</details>

<details>
<summary><b>3. 🌐 Graph Exploration: Facebook Friend Network Traversal (<code>graph.cpp</code>)</b></summary>
<br>

* **Problem Statement:** Model a social network as an unweighted, undirected graph where nodes are users and edges represent mutual friendships. Traverse the connections efficiently.
* **Technique Details:** Custom Graph representation using **Adjacency Lists** for space efficiency. Implements traversals:
  - **Depth First Search (DFS)** (Recursive & Iterative stack-based variants).
  - **Breadth First Search (BFS)** (Iterative queue-based variant).
* **Key Features:**
  - Dynamic graph constructor supporting named nodes and numeric IDs.
  - Robust tracking of disconnected components and visited vertices.
</details>

<details>
<summary><b>4. 🗃️ Hashing & Serialization: Student Database Engine (<code>hashing.cpp</code>)</b></summary>
<br>

* **Problem Statement:** Build a direct-access record file using a hash table to support constant-time CRUD operations.
* **Technique Details:** Implements static Hash mapping $H(k) = k \bmod 10$ with two collision resolution mechanisms:
  - **Linear Probing without Replacement**
  - **Linear Probing with Replacement** (migrates displaced elements to preserve optimal home addresses).
* **Key Features:**
  - Performs **Binary Serialization**; writes the dynamic database structure onto the disk as `student_db.dat` and recovers it at startup.
  - Allows search and real-time modification of marks and records.
</details>

<details>
<summary><b>5. 🗜️ Greedy Approach: Huffman Data Encoder (<code>huffman.cpp</code>)</b></summary>
<br>

* **Problem Statement:** Compress symbolic streams by assigning variable-length binary codes based on historical symbol frequency.
* **Technique Details:** Implements a greedy prefix tree constructed via `std::priority_queue` structured as a min-heap.
* **Key Features:**
  - Accepts user frequencies and builds the tree in $\mathcal{O}(N \log N)$ time.
  - Traverses the optimal tree to generate the compact, unique binary path representations (Prefix Codes).
  - Elegant cleanup module (`freeTree`) ensuring zero memory leaks post-traversal.
</details>

<details>
<summary><b>6. 🏎️ Sort & Search Benchmarking: Mobile Database Analysis (<code>mobile.cpp</code>)</b></summary>
<br>

* **Problem Statement:** Manage customer billing information and verify search/sort performance across multiple paradigms.
* **Technique Details:** Multi-algorithm benchmarking framework:
  - **Quick Sort (Divide & Conquer):** Recursive partition-around-pivot sorting on phone numbers in descending order.
  - **Heap Sort (Greedy/Heap Structure):** Space-optimal in-place array sorting based on binary max-heap transformations on bill amounts.
  - **Binary Search (Divide & Conquer):** Iterative and recursive logarithmic search routines.
* **Key Features:**
  - Direct comparative insights between linear and binary lookups.
  - Verification of passes and element exchanges.
</details>

<details>
<summary><b>7. 👑 Backtracking: N-Queens Constraint Solver (<code>nqueen.cpp</code>)</b></summary>
<br>

* **Problem Statement:** Position $N$ chess queens on an $N \times N$ board such that no two queens share the same row, column, or diagonal.
* **Technique Details:** Depth-first pruning backtracking tree search. Employs a space-saving 1D coordinate state array $X$ where index $j$ represents the row and $X[j]$ represents the column position.
* **Key Features:**
  - Evaluates cell viability on-the-fly (`Place` validation checker).
  - Automatically lists and graphically formats all possible board solutions using clean console icons (`Q` and `.`).
</details>

<details>
<summary><b>8. 🔌 Network Spanning: Prim's Minimum Spanning Tree (<code>prims.cpp</code>)</b></summary>
<br>

* **Problem Statement:** Lease telecommunication links between global corporate branches across multiple countries to minimize total rental costs while maintaining absolute connectivity.
* **Technique Details:** Implements **Prim's Algorithm** (greedy tree growth) starting from an arbitrary vertex.
* **Key Features:**
  - Custom 2D symmetric cost matrices, modeling unconnected nodes with standard high-cost bounds ($999$).
  - Outputs structural vertex pairs representing the Minimum Spanning Tree (MST) and logs total operational overhead.
</details>

---

## 🛠️ Installation & Getting Started

All files are self-contained C++ files with their own driver `main()` functions, ensuring fast compiler loading and direct isolated execution.

### Prerequisites

A modern C++ compiler compatible with **C++11** or above:
* **GCC / G++** (Version 4.8.1+ recommended)
* **Clang** (Version 3.3+ recommended)
* **MSVC** (Visual Studio 2015+ recommended)

### Compiling and Running

Follow these standard commands for clean compiling and running in your terminal shell:

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/Aradhya-Bhagwat/Design-and-Analysis-of-Algorithm.git
   cd Design-and-Analysis-of-Algorithm
   ```

2. **Compile the program:** (For example, to run the AVL Dictionary):
   ```bash
   g++ -std=c++11 avl.cpp -o avl_dictionary
   ```

3. **Execute the compiled binary:**
   * **Windows Powershell/CMD:**
     ```powershell
     .\avl_dictionary.exe
     ```
   * **Linux / macOS Bash:**
     ```bash
     ./avl_dictionary
     ```

---

## 🧑‍💻 Author

- **Aradhya Bhagwat**
  - Course: B.E. Computer Engineering (Semester 4)
  - Topic focus: Design & Analysis of Algorithms, Advanced Data Structures, C++ Systems Programming

---

## 📝 License

This suite is developed as part of academic coursework for Design & Analysis of Algorithms. Feel free to use the source files for study, learning, and algorithmic research.
