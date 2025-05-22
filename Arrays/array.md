✅ Definition

- An array is a collection of fixed-size elements of the same data type stored in contiguous memory locations.

- Used to store multiple values under a single variable name.

🔧 Declaration Syntax

data_type array_name[size];

📌 Example:

int numbers[5]; // declares an array of 5 integers

🧠 Initialization

int numbers[5] = {1, 2, 3, 4, 5};

- Can also omit size if initializing:

int numbers[] = {1, 2, 3};

🔢 Accessing Elements

- Index starts from 0.

cout << numbers[0]; // prints first element
numbers[1] = 10; // assigns 10 to the second element

🔄 Traversing Arrays

Use loops (usually for):

for (int i = 0; i < 5; i++) {
cout << numbers[i];
}

⚠️ Important Points

    Array size must be a constant (in basic C++).

    Accessing out-of-bound index gives undefined behavior.

    Arrays can be of any data type (int, float, char, etc.).

🧰 Multidimensional Arrays

int matrix[2][3] = {
{1, 2, 3},
{4, 5, 6}
};

🎯 Common Use Cases

    Storing a list of elements (e.g., scores, names).

    Loop-based processing of collections.

    Foundations for more complex data structures (e.g., matrices, strings, etc.).
